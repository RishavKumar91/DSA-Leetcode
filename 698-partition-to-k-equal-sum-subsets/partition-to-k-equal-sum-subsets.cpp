class Solution {
public:
int SUM ;
int rqsum ;
int n;
// vector<vector<vector<int>>> p; 
vector<int> p;
    bool hlpr(vector<int> &nums,int k , int sum , int mask){
        if(k == 0 ) return 1;
        // if(p[k][sum][mask] != -1) return p[k][sum][mask] ;
        if(p[mask] != -1) return p[mask];
        for(int i = 0 ; i < n ; i++){
            
            if( mask & 1<<i ) continue ; // index use ho gaya hai

            if(sum + nums[i] > rqsum) continue;
            if(sum + nums[i] == rqsum) if(hlpr(nums,k-1,0,mask | 1<<i)) return p[mask] =  1; 
            if(sum + nums[i]  < rqsum) if(hlpr(nums,k,sum + nums[i], mask | 1<<i)) 
                return p[mask]= 1; 
        }
    return p[mask] =  0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        SUM = accumulate(nums.begin() , nums.end() , 0); 
        if(SUM % k != 0) return 0 ;
        rqsum = SUM / k ;
        n = nums.size();
        // p.resize(k+1,vector<vector<int>> (rqsum+1,vector<int> (1<<n , -1))); 
        
        p.resize(1<<n,-1);
        return hlpr(nums,k,0,0);
    }
};