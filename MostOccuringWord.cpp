# include<iostream>
# include<string>
# include<algorithm>
# include<vector>
# include<sstream>
using namespace std;
int main(){
    string str = "Aditya  is a maths teacher . He ia a Dsa mentor as well";
    stringstream ss(str);
    string temp;
    vector<string> v;
    while(ss>>temp){
        cout<<temp<<endl;
        v.push_back(temp);
    }
    for(int i=0; i,v.size();i++){
        cout<<v[i]<<endl;
    }
    cout<<endl;
    sort(v.begin(),v.end());
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}