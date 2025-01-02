# include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the sizeOfarray: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the element of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter x element of array: ";
    cin>>x;
    // check mark introduce Boolien
    bool flag = false; // By Default Element is not present
    for(int i=1; i<n; i++){
    if(arr[i]==x) flag = true;       
    }
    if(flag==true) cout<<"Element is present:";
    else cout<<"Element is not found: ";

    return 0;
}