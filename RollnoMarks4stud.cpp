# include<iostream>
using namespace std;
int main(){
    //roll no , marks
    // 4 students
    int arr[2][4];
    for(int i=0; i<=1; i++){
        for(int j=0; j<=3; j++){
            cin>>arr[i][j];
        }
    }
    //print
    for(int i=0; i<=1; i++){
        for(int j=0; j<=3; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}