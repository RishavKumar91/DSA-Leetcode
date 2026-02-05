class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i =0;i<n;i++){
            int x  = nums[i];
            int a =i;
            if(x<0){
                for(x;x!=0;x++){
                    a--;
                    if(a==-1) a = n-1;
                }
            }
            if(x>0){
                for(x;x!=0;x--){
                    a++;
                    if(a==n) a = 0;
                }
            }
        ans[i]=nums[a];
        }
        return ans;
    }
};