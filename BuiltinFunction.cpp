# include<iostream>
# include<string>
using namespace std;
int main(){
    //string str = "Aditya Kumar";
    //cout<<str.substr();
    string str;
    cout<<"Enter the string : ";
    getline(cin,str);
    int len = str.length();
    cout<<str.substr(len/2);

    return 0;
}