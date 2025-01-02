# include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
    return;
}
int main(){
    int x =8, y=6;
    swap(x,y);
    cout<<x<<" "<<y;
    return 0;
}