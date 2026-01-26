class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int  n = nums.size();
        int j = 0,i=0,pro=1,maxx=INT_MIN;
        for(int i =0;i<n;i++){
            pro*=nums[i];
            maxx = max(maxx,pro);
            if(pro==0) pro=1;
        }
        pro = 1;
        for(i = n-1;i>=0;i--){
            pro *=nums[i];
            maxx = max(maxx,pro);
            if(pro==0) pro=1;
        }
    return maxx;
    }
};