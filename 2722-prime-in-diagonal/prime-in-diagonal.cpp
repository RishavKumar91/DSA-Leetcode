class Solution {
public:
bool isprime(int n ){
    if(n<2) return 0;
    for(int i =2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
    int diagonalPrime(vector<vector<int>>& nums) {

        int  maxx = 0;
        int n = nums.size();
        for(int i =0;i<nums.size() && nums[0][0];i++){
            if(isprime(nums[i][i])) maxx = max(maxx,nums[i][i]);
            if(isprime(nums[i][n-i-1])) maxx = max(maxx,nums[i][n-i-1]);
        }
    return maxx;
    }
};