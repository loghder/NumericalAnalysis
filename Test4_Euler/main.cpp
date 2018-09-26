#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x,double y){
    return x+y;
}

int main() {
    double h=0.1,y0=1,x0=0,b=1;//i为步长，b是上界
    double yn_1=y0,yn,fx;
    cout<<"x\t改进欧拉\t真实值\t误差\n";
    for (double x = x0; x+h < b; x+=h) {
        double yp=yn_1+h*f(x,yn_1);
        double yq=yn_1+h*f(x+h,yp);
        yn=(yp+yq)/2;
        fx=-x-h-1+2*exp(x+h);
        yn_1=yn;
        cout<<fixed<<setprecision(1)<<x+h<<setprecision(5)<<'\t'<<yn<<'\t'<<fx<<'\t'<<fabs(yn-fx)<<endl;
    }
    return 0;
}