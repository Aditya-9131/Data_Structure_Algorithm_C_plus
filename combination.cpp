# include<iostream>
using namespace std;
int fact(int x){
    int fact =1;
    for(int i=1; i<=x; i++){
        fact *=i;
    }
    return fact;
}
int combination(int n, int r){
   int comb = fact(n)/(fact(r)*fact(n-r));
   return comb;
}
int permutation(int n, int r){
    int perm = fact(n)/(fact(n-r));
    return perm;
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int r;
    cout<<"Enter r : ";
    cin>>r;
    int ncr = combination(n,r);
    int npr = permutation(n,r);
    cout<<ncr<<endl<<npr;
    
}