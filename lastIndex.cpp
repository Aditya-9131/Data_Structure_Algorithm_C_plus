# include<iostream>
# include<vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(9);
    v.push_back(8);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(4);

    int x = 40;
    int idx = -1;
    for(int i=0; i<v.size(); i++){
        if(v[i] == x) idx = i;
    }
    cout<<idx;

    return 0;
}