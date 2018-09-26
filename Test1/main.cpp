#include <iostream>
using namespace std;

int main() {
    float n=10000,sum1=0,sum2=0;
    for (float i = 1; i <= n; ++i) {
        sum1+=1/i/i;
    }
    for (float i = n; i >=1 ; --i) {
        sum2+=1/i/i;
    }
    cout<<"n从小到大计算所得结果为："<<sum1<<endl;
    cout<<"n从大到小计算所得结果为："<<sum2<<endl;
    return 0;
}