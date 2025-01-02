# include<iostream>
# include<climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter the SigeOfArray: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max = INT_MIN;
    for(int i=0; i<n; i++){
        if(max<arr[i])
            max = arr[i];
    }
    int smax = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]!=max && smax<arr[i])  
        smax = arr[i];
    }
    cout<<smax;

    return 0;
}