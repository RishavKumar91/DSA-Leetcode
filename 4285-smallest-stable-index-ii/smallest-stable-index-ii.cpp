class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixmax(n,0) , postmin(n,0);
        int maxx = prefixmax[0] = nums[0];
        for(int i = 1 ;  i < n ; i++){
            maxx = max(maxx,nums[i]);
            prefixmax[i] = maxx; 
        }
        int minn = postmin[n-1] = nums[n-1];    
        for(int i = n-2 ; i >= 0 ; i--){
            minn = min(minn,nums[i]);
            postmin[i] = minn;
        }
        for(int i = 0 ; i < n ; i++){
            if(prefixmax[i] - postmin[i]  <=k ) return i;
        }
    return -1 ;
    }
};