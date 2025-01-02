# include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the sizeOfArray: ";
    cin>>n;
    int arr[n];
    int x;
    cout<<"Enter the element x : ";
    cin>>x;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     bool flag = false; // assume our condition is false
    for(int i=0; i<n; i++){
        if(arr[i]==x)  flag = true;
    }
    if(flag==true) cout<<"present";
    else cout<<"not present";
    int count = 0;
    for(int i=0; i<=n; i++){
        if(arr[i]>x) count++;
    }
    cout<<"\n"<<count;
    return 0;
}