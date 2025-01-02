# include<iostream>
using namespace std;
int main(){
    int arr[5]={1,9,2,3,4};
    cout<<arr<<endl;
    for(int i=0; i<5; i++){
        cout<<&i<<" ";
    }
    return 0;
}