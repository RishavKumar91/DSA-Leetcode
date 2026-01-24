class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    return nums;
    //     int n = nums.size();
    //     priority_queue<int,vector<int>, greater<int>> minHeap;
    //     for(int i =0;i<n;i++){
    //         minHeap.push(nums[i]);
    //     }
    //     for(int i =0;i<n;i++){
    //         nums[i] = minHeap.top();
    //         minHeap.pop();
    //     }
    // return nums;
    }
};