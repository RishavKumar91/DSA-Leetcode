class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n =  nums.size();
        int minn = INT_MAX , sminn=INT_MAX;
        for(int i=1;i<n;i++){
            if(nums[i]<minn) {sminn=minn; minn = nums[i];}
            else if(nums[i]<sminn ) sminn = nums[i];
        }
        // priority_queue<int, vector<int>, greater<int>> minH;
        // for(int i =1;i<n;i++) minH.push(nums[i]);
        // int a = minH.top(); minH.pop(); int b = minH.top();
    return nums[0]+minn+sminn;
    }
};