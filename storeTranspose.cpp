#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter the no of rows :";
    cin>>m;
    int n;
    cout<<"Enter the no of columns :";
    cin>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"\n";
    //print
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
    }
        cout<<endl;
        } 
        int t[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                t[i][j]=arr[j][i];
            }
        }
    for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<t[i][j]<<" ";
            }
            cout<<endl;
        }
    
    return 0;
}