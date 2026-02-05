class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i =0;i<n;i++){
            pq.push(arr[i]);
        }
        int i =1;
        while(pq.size()){
            if(mp.find(pq.top()) == mp.end() ) mp[pq.top()] = i++;
            pq.pop();
        }
        vector<int> ans(n,-1);
        for(int i =0;i<n;i++){
            ans[i] = mp[arr[i]];
        }
    return ans;
    }
};