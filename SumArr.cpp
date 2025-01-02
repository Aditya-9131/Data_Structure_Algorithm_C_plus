# include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the number: ";
    for(int i=0; i<n; i++){// input
       cin>>arr[i];
    }
    //output
    int sum = 0;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
        sum=sum+arr[i];
    }
    cout<<endl<<sum;
    return 0;
}