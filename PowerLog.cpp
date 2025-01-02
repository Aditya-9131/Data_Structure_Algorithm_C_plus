#include<iostream>
using namespace std;
int pow(int x, int n){
    if(n==0) return 1;
    return x*pow(x,n-1);
}
int main(){
    pow(3,8);
    return 0;
}