class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        int n = bulbs.size();
        set<int> s;
        for(int i =0;i<n;i++){
            if(s.count(bulbs[i])) s.erase(bulbs[i]);
            else s.insert(bulbs[i]);
        }
        for(auto x : s){
            ans.push_back(x);
        }
    return ans;
    }
};