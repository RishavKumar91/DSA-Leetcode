class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& c, int target, vector<int>& temp) {
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < c.size(); i++){
            if(c[i] > target) continue;

            temp.push_back(c[i]);
            solve(i, c, target - c[i], temp); 
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};