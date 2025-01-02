#include<iostream>
using namespace std;
void factUpto(int n){
    for(int j=1;j<=n;j++){
        int f = 1;
        for(int i=2;i<=n;i++){
            f *= i;
            cout<<f<<endl;
        }
        cout<<f<<endl;
    }
}
int main(){
   factUpto(5);
}