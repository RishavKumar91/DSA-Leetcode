class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = -1;

        if(k == 1){
            for(int &x : nums) mp[x]++;
            for(auto &x : mp) if(x.second == 1) ans = max(ans,x.first);
            return ans;
        }
        
        for(int i = 0 ; i < n - k+1 ; i++){
            unordered_set<int> st;
            for(int j = i ; j < i + k ; j++){
                st.insert(nums[j]);
            }
            for(int i : st){
                mp[i]++;
            }
        }
        for(auto &x : mp){
            if(x.second == 1) ans = max(ans , x.first);
        }
    return ans;
    }
};