class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
    //     priority_queue<int> hp; 
    //     for(int i =0;i<n;i++){
    //         hp.push(nums[i]);
    //     }
    //     for(int i =0;i<k-1;i++){
    //         hp.pop();
    //     }
    // return hp.top();
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<n;i++){
    minHeap.push(nums[i]);
    if(minHeap.size()>k) minHeap.pop();
    }
    return minHeap.top();
    //     sort(nums.begin(),nums.end());
    // return nums[n-k];
    }
};