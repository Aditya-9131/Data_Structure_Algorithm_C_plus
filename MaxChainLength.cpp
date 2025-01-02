#include<iostream>
#include<vector>
using namespace std;
bool compare(pair<int, int>p1, pair<int, int>p1){
    return p1.second<p2.second;
}
int maximumChainLength(vector<pair<int,int>> pairs){
    int n = pairs.size();
    sort(pairs.begin(), pairs.end(), compare);
    int ans = 1;
    int currEnd = pairs[0].second;
    for(int i=1; i<n; i++){
        if(pairs[i].first > currEnd){
            ans++;
            currEnd = pairs[0].second;
        }
    }
    cout <<"max chain length = " << ans << endl;
    return ans;
}
int main(){
    vector<pair<int,int>> pairs(n, make_pair(0,0));
    pair[0] = make_pair(5,24);
    pair[1] = make_pair(30,60);
    pair[2] = make_pair(5,28);
    pair[3] = make_pair(27,40);
    pair[4] = make_pair(50,90);
    maxChainLength(pairs);
    return 0;
}