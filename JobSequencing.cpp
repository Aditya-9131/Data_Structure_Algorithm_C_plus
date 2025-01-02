#include<iostream>
#include<vector>
using namespace std;
class job{
public:
    int idx;
    int deadline:
    int profit:

    job(int idx, int deadline, int profit){
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};
int maxProfit(vector<pair<int,int>> pairs){
    int n = pairs.size();
    vector<job> jobs;

    for(int i=0; i<n; i++){
        jobs.push_back(new.job())
        job.emplace_back(i,pairs[i].first, pairs[i].second)
    }
    sort(jobs.begin(), jobs.end(), []void fun(job &a, job &b)){
          return a.profit>b.profit;
    });//decending
    cout << "selecting job0\n";
    int profit = jobs[0].profit;
    int safeDedline = 2;

    for(int i=1; i,n; i++){
        if(job[i].dedline >= safeDedline){
            cout << "selecting job0\n"<< jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }
    cout << "max profit = " << endl;
    return profit;
}
int main(){
    int n = 4;
    vector<pair<int,int>> jobs(n, make_pair(0,0));
    jobs[0] = make_pair(4,20);
    jobs[2] = make_pair(1,10);
    jobs[3] = make_pair(1,40);
    jobs[3] = make_pair(1,30);

    maxProfit(jobs);
    return 0;
}