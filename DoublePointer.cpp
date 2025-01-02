# include<iostream>
using namespace std;
int main(){
    int x = 5;
    int* ptr = &x;
    cout<<&x<<endl;
    cout<<ptr<<endl;
    int** p = &ptr;
    cout<<p<<endl;

    return 0;
}