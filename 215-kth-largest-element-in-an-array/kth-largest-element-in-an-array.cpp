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

        sort(nums.begin(),nums.end());
    return nums[n-k];
    }
};