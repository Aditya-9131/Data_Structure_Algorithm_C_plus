#include<iostream>
using namespace std;
int power(int a, int b){
    if(a==0 && b==0){
        cout<<"0 raised to the power 0 is not defined ";
        return -100;
    }
    if(a==0) return 0;
    int p = 1;
    for(int i=1; i<=b; i++){
        p *= a;
    }
    return p;
}
int powRec(int a, int b){
     if(b==0) return 1;
     return a*powRec(a,b-1);
}
int main(){
    int a;
    cout<<"Enter base : ";
    cin>>a;
    int b;
    cout<<"Enter exponent : ";
    cin>>b;
    cout<<a<<" raised to the power "<<b<<"is" " :" <<powRec(a,b);
    return 0;
}