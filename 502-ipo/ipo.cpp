
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> pq;
        int n = capital.size();
        for(int i =0 ; i < n ;i++){
            pq.push_back({capital[i],profits[i]});
        }
        sort(pq.begin(),pq.end());
        priority_queue<int> p;
        int i = 0 ;
        while(k!=0){
            while(i<n && pq[i].first <= w){
                p.push(pq[i].second);
                i++;
            }
            if(p.empty()) break;
            w+=p.top();
            p.pop();
        k--;
        }
    return w;
    }
};