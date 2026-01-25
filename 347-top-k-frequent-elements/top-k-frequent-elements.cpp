class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>
    > minH;
        for( auto x:mp){
            pair<int,int> p; p.first = x.second; p.second = x.first;
            minH.push(p);
            if(minH.size()>k) minH.pop();
        }
        vector<int> v;
        while(minH.size()){
            v.push_back(minH.top().second);
            minH.pop();
        }
    return v;
    }
};