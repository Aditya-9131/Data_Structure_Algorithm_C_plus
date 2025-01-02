# include <iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    int* ptr = arr;
    cout<<ptr<<endl;
    cout<<&arr[0]<<endl;
    ptr[0]=8;
    for(int i=0; i<5; i++){
        cout<<ptr[i]<<" ";
    }
    ptr=arr;
    *ptr = 8;
    ptr++;
    *ptr = 9;
    ptr--;
    for(int i=0; i<5; i++){
        cout<<ptr[i]<<" ";
    }
    return 0;
}