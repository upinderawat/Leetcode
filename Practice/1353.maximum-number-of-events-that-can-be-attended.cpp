#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<vector<int>> expires(100005);
        for (vector<int> v : events) {
            expires[v[0]].push_back(v[1]);
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for (int i = 1; i < 100005; i++) {
            for (int j : expires[i]) {
                pq.push(j);
                // cout<<i<<"\t"<<j<<"\n";
            }
            if (!pq.empty()) {
                cout<<i<<","<<pq.top()<<"\n";
                pq.pop();
                ans++;
            }
            while (!pq.empty() && pq.top() == i) {
                pq.pop();
            }
        }
        
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<std::vector<int>> events={{2,3},{1,5},{2,3},{1,5},{1,5},{1,5}};
    cout<<s.maxEvents(events);
    return 0;
}