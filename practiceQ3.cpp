# include<iostream>
using namespace std;
void oddNumber(int a, int b){
    if(a>b){
        cout<<"Invalid Input"<<endl;
        return;
    }
    for(int i=a; i<=b; i++){
        if(i%2!=0){
            cout<<i<<endl;
        }
    }
}
int main(){
    int a,b;
    cout<<"Enter the number : ";
    cin>>a>>b;
    oddNumber(a,b);
    return 0;
}