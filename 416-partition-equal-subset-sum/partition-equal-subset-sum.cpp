class Solution {
public:
int TOTAL ;
int n ;
vector<vector<int>> p;
    int hlpr(int ix , vector<int> &nums,int TOTAL ){
        if(TOTAL == 0) return 1;
        if(ix >= n || TOTAL < 0) return 0;
        if( p[ix][TOTAL] != -1 ) return p[ix][TOTAL];
        int skip = hlpr(ix+1,nums,TOTAL);
        int take = hlpr(ix+1,nums,TOTAL-nums[ix]);
        return p[ix][TOTAL] =  skip || take ;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        TOTAL = accumulate(nums.begin() , nums.end(),0);
        if(TOTAL & 1) return 0;
        p.resize(n+1 , vector<int> ((TOTAL/2) + 1 , -1));
        return hlpr(0,nums,TOTAL/2);
    }
};