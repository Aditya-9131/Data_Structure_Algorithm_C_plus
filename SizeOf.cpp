# include<iostream>
using namespace std;
int main(){
    bool x =true;
    bool*p = &x;

    int y =5;
    int* p2=&y;
    cout<<&y<<endl;
    cout<<p2;
    return 0;
}