# include<iostream>
# include<vector>
using namespace std;
int main(){
    //you need not mention the size
    // inserting / input do not use []
    vector<int> v;// you need not mention size;
    v.push_back(9);
    v.push_back(4);
    v.push_back(5);
    v.push_back(0);
    v.push_back(9);
    v.push_back(4);
    v.push_back(5);
    v.push_back(0);
    //cout<<v[0]<<" "<<v[15];
    cout<<"size is: "<<v.size()<<endl;
    cout<<"capacity is: "<<v.capacity()<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.pop_back();
    v.pop_back();
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}