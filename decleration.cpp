#include<iostream>
using namespace std;
int main(){
    //int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    // rows -> 3 0-2
    //column -> 3 0-2
    for(int i=0;i<=2;i++){ // i is for row
       for(int j=0;j<=2;j++){
         cout<<arr[0][i]<<" ";
    }
    cout<<endl;
       }
      return 0;
    }
