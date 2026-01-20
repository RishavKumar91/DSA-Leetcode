class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        unordered_set<int> s;
        for(int i =0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto x:mp ){
            if(s.find(x.second)!=s.end()) return 0;
            s.insert(x.second);
        }
    return 1;
    }
};