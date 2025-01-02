# include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter rows of matrix : ";
    cin>>m;
    int n;
    cout<<"Enter columns of matrix :";
    cin>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    //spiral
    int minr = 0, minc = 0;
        int maxr = m-1, maxc = n-1;
        int tne = n*m;
        int count = 0;
        vector<int> v;
        while(minr<=maxr && minc<=maxc   )