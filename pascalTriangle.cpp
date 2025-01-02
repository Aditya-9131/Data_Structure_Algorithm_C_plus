# include<iostream>
using namespace std;
int fact(int x){
    int fac =1;
    for(int i=1; i<=x; i++){
        fac = fac*i;
    }
    return fac;
}
int combination(int x, int y){
    int comb = fact(x)/(fact(y)*fact(x-y));
    return comb;
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int r;
    cout<<"Enter r : ";
    cin>>r;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
           cout<<combination(i,j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}