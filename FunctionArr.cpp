# include <iostream>
using namespace std;
void display(int* a, int size){
    //int size = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size;i++){//function Definition
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}
void change(int* b, int size){
    b[0] = 100;
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);//function  calling
    change(arr, size);
    display(arr, size);
    return 0;
}