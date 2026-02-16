class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        int n = bulbs.size();
        for(int i =0;i<n;i++){
            if(count(ans.begin(),ans.end(),bulbs[i])) erase(ans,bulbs[i]);
            else ans.push_back(bulbs[i]);
        }
        sort(ans.begin(),ans.end());
    return ans;
    }
};