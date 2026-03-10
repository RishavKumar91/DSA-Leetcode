class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> mp;
        int total = 0 , n = nums.size();
        for(int i =0;i<n;i++)
        total= (total%p + nums[i]%p)%p;
        int tar = total%p;
        if(tar== 0 ) return 0;

        mp[0] = -1;
        int j = 0,sum= 0;
        int ans = n;
        while(j<n){
            sum = (sum + nums[j]) % p;
            int fin = (sum-tar+p) % p;
            if(mp.count(fin)) ans = min(ans,j-mp[fin]);
            mp[sum] = j;
            j++;
        }
    return ans==n ? -1 : ans;
    }
};