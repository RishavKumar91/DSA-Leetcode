class Solution {
public:
    int ans = 1 , n ;
    vector<int> zero , one ; 
    int findval(int val ,int start , vector<int> &nums ){
        int j = lower_bound(nums.begin()+start , nums.end() , val) - nums.begin();
        if(j < n && nums[j] == val) return j;
    return -1 ; 
    }
    
    int hlpr(int i , vector<int> &nums , int change){
        if(change){ if( one[i] != -1) return one[i] ;}
        else {if( zero[i] != -1) return zero[i] ;}
        int currval = nums[i] + change , ans = 1;
        int j = findval(currval , i+1,nums);
        if(j!=-1){
            ans = max(ans , 1 + hlpr(j,nums,1));
        }
        j = findval(currval + 1 , i+1,nums);
        if(j!=-1){
            ans = max(ans , 1 + hlpr(j,nums,0));
        }
        if(change) one[i] = ans ; 
        else zero[i] = ans ; 
    return ans ;
    }
    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end()) ; 
        int ans = 1 ;
        zero.resize(n+1,-1);    one.resize(n+1,-1); 
        for(int i = 0 ; i < n ; i++){
            ans = max(ans,hlpr(i,nums,0));
            ans = max(ans,hlpr(i,nums,1));
        }
    return ans ;
    }
};