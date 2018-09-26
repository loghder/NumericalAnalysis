//
// Created by loghd on 2018/9/18.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

/*
 * 按下列数据
x  0.30 0.42 0.50 0.58 0.66 0.72
y  1.04403 1.08462 1.11803 1.15603 1.19817 1.23223
作五次插值，并求 x 1=0.46，x 2 =0.55，x3 =0.60 时的函数近似值 .
 */

int main() {
    int flag,num=0;//数据个数
    double *x,*y; //存储坐标
    double **z;//存储均差,z[0]指向的数组代表0阶均差 以此类推
    cout<<"1*读取旧数据\n2*输入新数据\n";
    cin>>flag;
    if(flag==1){
        //读取数据
        ifstream in("Test2.txt");
        in>>num;
        x=new double[num];
        y=new double[num];
        z=new double*[num];
        for(int i=0;i<num;i++){
            z[i]=new double[num-i];
        }
        for(int i=0;i<num;i++){
            in>>x[i]>>y[i];
        }
        in.close();
    }
    if(flag==2){
        cout<<"请输入坐标个数\n";
        int i=0;
        cin>>num;
        x=new double[num];
        y=new double[num];
        z=new double*[num];
        for(int i=0;i<num;i++){
            z[i]=new double[num-i];
        }
        while(i<num){
            cout<<"x=";
            cin>>x[i];
            cout<<"y=";
            cin>>y[i];
            cout<<"\n";
            i++;
        }
        //对x的值进行排序，同步修改y的顺序，采用冒泡排序
        for(int i=0;i<num;i++){
            for(int j=0;j<num-i-1;j++){
                if(x[j]>x[j+1]){
                    double temp=x[j];
                    x[j]=x[j+1];
                    x[j+1]=temp;
                    temp=y[j];
                    y[j]=y[j+1];
                    y[j+1]=temp;
                }
            }
        }
        //保存输入的数据到文件
        ofstream out("Test2.txt");
        out<<num<<'\t';
        for(int i=0;i<num;i++){
            out<<x[i]<<'\t'<<y[i]<<'\t';
        }
        out.close();
    }
    //计算均差
    for(int i=0;i<num;i++){
        z[0][i]=y[i];
    }
    for(int i=1;i<num;i++){
        for(int j=0;j<num-i;j++){
            z[i][j]=(z[i-1][j+1]-z[i-1][j])/(x[j+i]-x[j]);
        }
    }
    //输出均差表
    cout<<"均差表："<<endl;
    cout<<"x[k]\tf(x[k])";
    for(int i=1;i<num;i++){
        cout<<'\t'<<i<<"阶均差";
    }
    cout<<endl;
    for(int i=0;i<num;i++){
        cout<<fixed<<setprecision(5)<<x[i]<<'\t';
        for(int j=0;j<=i;j++){
            cout<<fixed<<setprecision(5)<<z[j][i-j]<<'\t';//fixed用于补足0 eg 0.20
        }
        cout<<endl;
    }
    cout<<"请输入要求计算的x，当输入任意字母时，结束程序"<<endl;
    while(true){
        cout<<"x=";
        double xi;
        if((cin>>xi)==0)//当输入的不是数字时
            break;
        //计算y值并输出
        double sum=z[0][0];
        for(int i=1;i<num;i++){
            double mul=1;
            for(int j=0;j<i;j++){
                mul=mul*(xi-x[j]);
            }
            mul*=z[i][0];
            sum+=mul;
        }
        cout<<"y="<<sum<<endl;
    }
    return 0;
}