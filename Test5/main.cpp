#include <iostream>
#include <cmath>

using namespace std;

/*分别用下列方法求 f(x)=x3-3x-1=0 在 x0=2 附近的根。根的准确值为
        x*=1.87938524 …，要求准确到四位有效数字，并对比各种算法的计算量。
二分法；（ 2）简单迭代法；（ 3）牛顿迭代法*/
int erfenNum=0;

double f(double x){
    return pow(x,3)-3*x-1;
}

double erfen(double a,double b){
    if(fabs(b-a)<0.0005)//这里是0.0005还是0.001 需要想一下
        return a;
    double middle=(a+b)/2;
    if(f(middle)*f(a)<0){
        erfenNum++;
        return erfen(a,middle);
    }
    else if(f(middle)*f(b)<0) {
        erfenNum++;
        return erfen(middle,b);
    }
    else return middle;
}

void erfenfa(double a,double b){
    cout<<"二分法计算结果："<<erfen(a,b)<<'\t';
    cout<<"迭代次数："<<erfenNum<<endl;//如果erfenNum与erfen(1,2)放在同一行的话，会先输出erfenNum的值，此时为0
    /*cout在执行的时候为从右向左先执行，然后在输出的时候为按照原来的顺序在从左像右的输出。*/
}

void diedai(double x){
    double xn,n=0;
    do{
        xn=x;
        x=pow(3*xn+1,1.0/3);//这里不是1/3
        n++;
    }while(fabs(xn-x)>0.0005&&n<=30);
    if(n>30){
        cout<<"无法用简单迭代法求解"<<endl;
    }
    else{
        cout<<"迭代法计算结果："<<x<<'\t';
        cout<<"迭代次数："<<n<<endl;
    }
}

void newton(double x){
    double xn,n=0;
    do{
        xn=x;
        x=xn-(pow(x,3)-3*x-1)/(3*pow(x,2)-3);//这里不是1/3
        n++;
    }while(fabs(xn-x)>0.0005);
    cout<<"牛顿法计算结果："<<x<<'\t';
    cout<<"迭代次数："<<n<<endl;
}


int main() {
    cout<<"真实值为:1.87938524…，要求准确到四位有效数字"<<endl;
    erfenfa(1.5,2.5);
    diedai(2);
    newton(2);
    return 0;
}