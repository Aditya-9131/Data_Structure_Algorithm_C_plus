# include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,99};
    int size = sizeof(arr)/sizeof(arr[9]);
    cout<<size;
    return 0;
}