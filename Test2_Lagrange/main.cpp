//
// Created by loghd on 2018/9/18.
//

#include <iostream>
#include <fstream>
using namespace std;

/*
 * 按下列数据
x -3.0 -1.0 1.0 2.0 3.0
y 1.0 1.5 2.0 2.0 1.0
作二次插值，并求 x 1=-2，x 2 =0，x 3=2.75 时的函数近似值
 */

int main() {
    int flag,num;//数据个数
    double *x,*y; //存储坐标
    cout<<"1*读取旧数据\n2*输入新数据\n";
    cin>>flag;
    if(flag==1){
        //读取数据
        ifstream in("Test2.txt");
        in>>num;
        x=new double[num];
        y=new double[num];
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
    cout<<"请输入要求计算的x，当输入任意字母时，结束程序"<<endl;
    while(true){
        cout<<"x=";
        double xi;
        if((cin>>xi)==0)//当输入的不是数字时
            break;
        //自动选择三个点
        //选择j-2，j-1，j这三个下标所对应的点（因为输入的xi可能大于数组x中的所有值）
        //j初始值为2（因为输入的xi可能小于数组中的所有值）
        int j=2;
        for(;j<num;j++){
            if(x[j]>xi)
                break;
        }
        //计算y值并输出
        cout<<"选择插值节点";
        for(int i=0;i<3;i++){
            cout<<"("<<x[j-2+i]<<","<<y[j-2+i]<<")"<<' ';
        }
        cout<<endl;
        double sum=0;
        for(int i=0;i<3;i++){
            double mul=1;
            //i对应x[j-2+i]1
            for(int k=0;k<3;k++){
                if(i!=k){
                    mul=mul*(xi-x[j-2+k])/(x[j-2+i]-x[j-2+k]);
                }
            }
            sum=sum+(mul*y[j-2+i]);
        }
        cout<<"y="<<sum<<endl;
        /*//退出或者继续计算
        cout<<"1*计算下一个x对应的y值\n2*退出\n";
        cin>>flag;
        if(flag==2)
            break;*/
    }
    return 0;
}