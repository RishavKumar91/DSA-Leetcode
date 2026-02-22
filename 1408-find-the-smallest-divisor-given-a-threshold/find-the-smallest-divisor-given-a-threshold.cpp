class Solution {
public:
bool chck(int now , vector<int>& nums, int &threshold){
    int n = nums.size();
    int ans = 0;
    for(int i =0;i<n;i++){
        if(nums[i] <= now) ans++;
        else if(nums[i]%now == 0 ) ans+=nums[i]/now;
        else ans += nums[i]/now + 1;
    }

return ans<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int first = 1;
        int last =0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            last = max(last,nums[i]);
        }
        int ans =0;
        while(first<=last){
            int mi = first + (last-first)/2;
            if(chck(mi,nums,threshold)) {
                last = mi-1;
                ans = mi;
            } 
            else{
                first = mi+1;
            }
        }
    return ans;
    }
};