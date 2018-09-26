#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

/*分别用高斯列主元消去法和直接三角分解法（ LU 分解）求方程
        组的解
系数矩阵：
 10 7 8 7
 7 5 6 5
 8 6 10 9
 7 5 9 10
常向量：
 10
 8
 6
 7
精确解为：（ -60，102，-27，16）
 Test2.txt里的内容备份
 4	10	7	8	7	7	5	6	5	8	6	10	9	7	5	9	10	10	8	6	7
 */


//用于排查错误
void display(string s,double **a,double *b,double n){
    cout<<s<<endl;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            //double有计算误差 所以算出一个非常非常小的数的话，可以认为它是0
            if(fabs(a[i][j])<0.00000005)
                cout<<setw(4)<<0<<'\t';
            else
                cout<<setw(4)<<a[i][j]<<'\t';
        }
        cout<<b[i];
        cout<<endl;
    }
    cout<<endl;
}

void display(string s,double **a,double n){
    cout<<s<<endl;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            //double有计算误差 所以算出一个非常非常小的数的话，可以认为它是0
            if(fabs(a[i][j])<0.00000005)
                cout<<setw(4)<<0<<'\t';
            else
                cout<<setw(4)<<a[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
}

void showResult(double *b,double n){
    cout<<"解为："<<endl<<'(';
    for (int l = 1; l <= n; ++l) {
        cout<<b[l];
        if(l!=n)
            cout<<',';
    }
    cout<<')'<<endl<<endl;
}

void exchange(double &a,double &b){
    double t=a;
    a=b;
    b=t;
}

//因为在子函数中使用new运算符，修改了指针的值
//所以指针也需要引用
void readFile(double **&a,double *&b,int &n){
    ifstream in("Test2.txt");
    in >> n;
    a = new double *[n + 1];
    for (int i = 0; i <= n; ++i) {
        a[i] = new double[n + 1];
    }
    b = new double[n + 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            in >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        in >> b[i];
    }
}

//高斯列主元消去法 150页
//返回的是det的值
double gauss(double **a,double *b,int n){
    cout<<"-->高斯列主元消去法"<<endl;
    double det=1;
    for (int k = 1; k < n; ++k) {
        int i=k;//记录最大元下标
        //按列选主元
        for(int j=k+1;j<n;j++){
            if(a[i][k]<a[j][k])
                i=j;
        }
        if(a[i][k]==0){
            cout<<"此方程组无唯一解"<<endl;
            return 0;
        }
        //换行
        if(i!=k){
            for (int j = k; j <= n; ++j) {
                exchange(a[i][j],a[k][j]);
            }
            exchange(b[i],b[k]);
            det=-det;
        }
        //消元计算,这里和课本150页不一样
        for (int i = k+1; i <= n; ++i) {
            double m=a[i][k]/a[k][k];
            for (int j = k; j <= n; ++j) {
                a[i][j] = a[i][j] - m * a[k][j];
            }
            b[i]=b[i]-m*b[k];
          }
        det=a[k][k]*det;
    }
    display("消元后的矩阵：",a,b,n);
    if(a[n][n]==0){
        cout<<"此方程组无唯一解"<<endl;
        return 0;
    }
    //回代求解
    b[n]=b[n]/a[n][n];
    for (int i = n-1; i >0; --i) {
        double sum=0;
        for (int j = i+1; j <= n; ++j) {
            sum=sum+a[i][j]*b[j];
        }
        b[i]=(b[i]-sum)/a[i][i];
    }
    det=a[n][n]*det;
    showResult(b,n);
    return det;
}

//直接三角分解法 课本153页
void triangle(double **a,double *b,int n){
    cout<<"-->直接三角分解法"<<endl;
    double **u= new double *[n + 1],**l= new double *[n + 1];
    for (int i = 0; i <= n; ++i) {
        u[i] = new double[n + 1];
        l[i] = new double[n + 1];
    }
    for (int i = 1; i <=n ; ++i) {
        u[1][i]=a[1][i];
        l[i][i]=1;
    }
    for (int i = 2; i <=n ; ++i) {
        l[i][1]=a[i][1]/u[1][1];
    }
    //分解公式
    for (int r = 2; r <=n ; ++r) {
        for(int i=r;i<=n;i++){
            double sum=0;
            for (int k = 1; k < r; ++k) {
                sum=sum+l[r][k]*u[k][i];
            }
            u[r][i]=a[r][i]-sum;
        }
        for(int i=r+1;i<=n;i++){
            double sum=0;
            for (int k = 1; k < r; ++k) {
                sum=sum+l[i][k]*u[k][r];
            }
            if(r!=n){
                l[i][r]=(a[i][r]-sum)/u[r][r];
            }
        }
    }
    display("矩阵L：",l,n);
    display("矩阵U：",u,n);
    double *y=new double[n+1],*x=new double[n+1];
    y[1]=b[1];
    for (int i = 2; i <=n; ++i) {
        double sum=0;
        for (int k = 1; k < i; ++k) {
            sum=sum+l[i][k]*y[k];
        }
        y[i]=b[i]-sum;
    }
    x[n]=y[n]/u[n][n];
    for (int i = n-1; i >0; --i) {
        double sum=0;
        for (int k = i+1; k <=n; ++k) {
            sum=sum+u[i][k]*x[k];
        }
        x[i]=(y[i]-sum)/u[i][i];
    }
    showResult(x,n);
}

int main() {
    int n,flag;
    double **a,*b;
    string mark;
    do {
        cout << "-->\n1*读取旧数据\n2*输入新数据\n";
        cin >> flag;
        if (flag == 1) {
            //读取数据
            readFile(a,b,n);
        } else {
            cout << "-->方程组输入" << endl;
            cout << "请输入未知数个数n：";
            cin >> n;
            a = new double *[n + 1];
            for (int i = 0; i <= n; ++i) {
                a[i] = new double[n + 1];
            }
            b = new double[n + 1];
            cout << "请输入系数矩阵a：" << endl;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    cin >> a[i][j];
                }
            }
            cout << "请输入常向量b：" << endl;
            for (int i = 1; i <= n; ++i) {
                cin >> b[i];
            }
            //保存输入的数据到文件
            ofstream out("Test2.txt");
            out << n << '\t';
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    out << a[i][j] << '\t';
                }
            }
            for (int i = 1; i <= n; ++i) {
                out << b[i] << '\t';
            }
            out.close();
        }
        display("输入的矩阵：",a,b,n);
        gauss(a, b, n);
        readFile(a,b,n);//高斯消元后需要重新读取数据
        triangle(a, b, n);
        cout<<"-->是否继续解线性方程组？Y/N"<<endl;
        cin>>mark;
        if(mark=="N")
            break;
    }while(true);
    return 0;
}