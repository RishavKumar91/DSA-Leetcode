class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> minH;
        priority_queue<int> maxH;
    //    minH.push(-1); maxH.push(-1);
        if(n==1 && target == nums[0]) return {0,0};
        for(int i =0;i<n;i++){
            if(target==nums[i] ){ minH.push(i) ; maxH.push(i);}
        }
    if(maxH.empty()&&minH.empty()) return {-1,-1};
    else if(minH.empty()) return {minH.top(),maxH.top()};
    else if(maxH.empty()) return {minH.top(),maxH.top()};
    return {minH.top(),maxH.top()};
    }
};