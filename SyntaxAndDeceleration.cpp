# include<iostream>
using namespace std;
int main(){
    int arr[7];
    // Input
    cout<<"Enter the input: ";
    for(int i=0; i<=6; i++){
        cin>>arr[i];
    }
    // Output
     for(int i=0; i<=6; i++){
        cout<<arr[i]<<" ";
     }
    return 0;
}