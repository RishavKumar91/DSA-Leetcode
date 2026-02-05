class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;
        for(int i =0;i<n-1;i++){
            int a = nums[i]; int b = nums[i+1];
            if(a!=b){
                for(int j =a+1;j<b;j++){
                    ans.push_back(j);
                }
            }
        }
    return ans;
    }
};