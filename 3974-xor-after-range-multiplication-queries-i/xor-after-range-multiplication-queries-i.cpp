class Solution {
public:
    int M =  1e9 +7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for( auto &q : queries){
            for(int i = q[0];i<=q[1];i+=q[2]){
            nums[i] = (1LL *( nums[i] % M) * (q[3] % M)) % M;
            }
        }
        int ans = 0;
        for(int &n : nums){
            ans ^=n;
        }
    return ans;
    }
};