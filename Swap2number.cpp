#include<iostream>
using namespace std;
int swap(int a , int b){
    int temp = a;
    a=b;
    b=temp;
    return swap(a,b);
}
int main(){
    int a;
    cout<<"Enter first number : ";
    cin>>a;
    int b;
    cout<<"Enter second number : ";
    cin>>b;
   int s= swap(a,b);
    cout<<a<<" "<<b;
    return 0;
}