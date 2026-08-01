class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> visit(n,0);
        for(int i = 0 ; i < n ;  i++){
            if(visit[i]) continue;
            int count = 0 , curr = i;
            while(!visit[curr] ){
                count++;
                visit[curr] = 1;
                curr = nums[curr];
            }
            ans = max(ans,count);
        }
    return ans;
    }
};