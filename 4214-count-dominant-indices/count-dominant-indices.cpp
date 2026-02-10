class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> post(n,0);
        for(int i =n-2;i>=0;i--){
            post[i] = post[i+1] + nums[i+1];
        }
        int count =0;
        for(int i=0;i<n-1;i++){
            if((float)nums[i] > (float)post[i]/(n-i-1)      ) count++;
        }
        return count;
    }
};