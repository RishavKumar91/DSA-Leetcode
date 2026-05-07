class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n =nums.size();
        vector<int> lftmax(n);
        vector<int> rghtmin(n);
        lftmax[0] = nums[0];
        rghtmin[n-1] = nums[n-1];

        for(int i = 1;i<n;i++){
            lftmax[i] = max(lftmax[i-1],nums[i]);
        }
        for(int i = n-2; i>=0;i--){
            rghtmin[i] = min(rghtmin[i+1],nums[i]);
        }
        vector<int> ans(n);
        ans[n-1] = lftmax[n-1];
        for(int i = n- 2; i>=0 ; i--){
            if(lftmax[i] <= rghtmin[i+1]) ans[i] = lftmax[i];
            else ans[i] = ans[i+1]; 

        }
    return ans;
        
    }
};