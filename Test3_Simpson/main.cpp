#include <iostream>
#include <cmath>
using namespace std;

bool judge(double a,double b){
    if(a>=b){
        cout<<"输入的区间上限大于等于区间下限，请重试"<<endl;
        return true;
    }
    return false;
}

double f(double x){
    if(x==0)
        x=0.000000000000001;
    return sin(x)/(x);
}

int main() {
    cout<<"请依次输入区间端点的值：";
    double a,b,n=10;
    do{
        cin>>a>>b;
        //切分为n个区间
    }while(judge(a,b));
    double h=(b-a)/n,sum=0,sum2=0;
    for (int i = 1; i < n; ++i) {
        sum+=f(a+i*h);
    }
    for (int i = 0; i < n; ++i) {
        sum2+=f(a+i*h+h/2);
    }
    sum=2*sum+4*sum2+f(a)+f(b);
    double result=h/6*sum;
    cout<<"sin(x)/x在输入区间上的积分为："<<result<<endl;
    return 0;
}