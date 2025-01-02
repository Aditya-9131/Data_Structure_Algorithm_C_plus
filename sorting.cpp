# include<iostream>
# include<string>
# include<algorithm>
using namespace std;
int main(){
    string s;
    cout<<"Enter a string: ";
    //cin>>s;
    getline(cin,s);
    sort(s.begin(),s.end() );
    cout<<s;
    return 0;
}