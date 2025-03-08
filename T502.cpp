#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Project{
public:
    int profit;
    int capital;
    Project(int profit_, int capital_): profit(profit_), capital(capital_){}
    bool operator < (const Project& p) const{
        if(capital == p.capital)    return profit > p.profit;
        return capital < p.capital;
    }
};

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    priority_queue<int> pq;
    vector<Project> projects;
    int n = profits.size();
    for(int i = 0; i < n; i++){
        projects.push_back(Project(profits[i], capital[i]));
    }
    sort(projects.begin(), projects.end());
    int i = 0;
    while(k--){
        while(i < n && projects[i].capital <= w){
            pq.push(projects[i].profit);
            i++;
        }
        if(pq.empty()) break;
        w += pq.top();
        pq.pop();
    }
    return w;
}

int main(){
    int k = 2, w = 0;
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 1};
    cout << findMaximizedCapital(k, w, profits, capital) << endl;
    k = 3, w = 0;
    profits = {1, 2, 3}, capital = {0, 1, 2};
    cout << findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}