class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = INT_MIN ; 
        int n = nums.size();
        vector<int> pfx;
        for(int i = 0 ; i < n ; i++){
            mx =  max(nums[i],mx);
            pfx.push_back(mx);
        }
        for(int i = 0 ; i < n ; i ++){
            pfx[i] = __gcd(pfx[i],nums[i]);
        }
        long long ans = 0;
        int i = 0 , j = n-1;
        sort(pfx.begin(),pfx.end());
        while(i<j){
            ans += __gcd(pfx[i] , pfx[j]);
            i++;
            j--;
        }
    
    return ans;
    }
};