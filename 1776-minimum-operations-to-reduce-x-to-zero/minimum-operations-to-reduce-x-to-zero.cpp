class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0) ; 
        int find = sum - x ; 
        int currsum = 0 ;
        int i = 0 , j = 0 ;
        int ans = INT_MAX ; 
        if(x > sum ) return -1;
        while( j < n ){
            currsum += nums[j];
            while(currsum > find ){
                currsum -= nums[i];
                i++;
            }
            if(currsum == find){
                ans = min(ans,n - (j-i+1));
            }
        j++;
        }
    return ans == INT_MAX ? -1 : ans;
    }
};