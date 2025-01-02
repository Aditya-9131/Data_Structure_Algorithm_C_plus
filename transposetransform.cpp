#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter the no of rows/column :";
    cin>>m;
    int arr[m][m];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"\n";
    //print
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
    }
        cout<<endl;
        } 
        cout<<endl;
    for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                //swaping
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
            cout<<endl;
        }
        for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
    cout<<endl;
    }
    
    return 0;
}