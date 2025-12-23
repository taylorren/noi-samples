#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int d;

    while(cin>>d && d!=0){
        int CA=100000, US=0;
        double rate;
        for(int i=0;i<d;i++){
            cin>>rate;
            US=max(US,(int)(CA/rate*0.97));
            CA=max(CA,(int)(US*rate*0.97));
        }
        printf("%.2f\n",CA/100.0);
    }
    return 0;
}
