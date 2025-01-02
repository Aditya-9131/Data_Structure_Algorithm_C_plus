# include<iostream>
using namespace std;
int a=9;// global variable
void fun(int x,int y){
cout<<"addresh of fun x "<<&x<<endl;
cout<<"addresh of fun y "<<&y<<endl;
}
void f(){
    cout<<a;
}
int main(){
    //int x=3;
    //int y=7;
    //fun(x,y);
    //cout<<"addresh of main x "<<&x<<endl;
    //cout<<"addresh of main y "<<&y<<endl;
    //int a=9;
    f();
    return 0;
}