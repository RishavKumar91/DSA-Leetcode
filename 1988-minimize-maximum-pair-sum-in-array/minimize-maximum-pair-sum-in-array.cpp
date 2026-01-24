class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n = nums.size();//maxx = 0;
        // for(int i =0;i<n/2;i++){
        //     maxx = max(maxx,nums[i] + nums[n-i-1]);
        // }
        // return maxx;
        priority_queue<int> maxH;
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int i = 0;i<n;i++){
            maxH.push(nums[i]);
            minH.push(nums[i]);
        }
        int maxx = 0;
        for(int i =0;i<n/2;i++){
            maxx = max(maxx,maxH.top()+minH.top());
            minH.pop() ; maxH.pop();
        }
        return maxx;
    }
};