class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        priority_queue<int> maxHeap;
        vector<int> v; int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i =0;i<n;i++){
            maxHeap.push(nums[i]);
            minHeap.push(nums[i]);
        }
        while(minHeap.empty() ==0 || maxHeap.empty()==0){
            int a = 0;
            if(minHeap.size()) a+=minHeap.top();
            if(maxHeap.size()) a+=maxHeap.top();
            if(a==target) {v.push_back(minHeap.top()) ; v.push_back(maxHeap.top());break;}
            else if(a>target) maxHeap.pop();
            else minHeap.pop();
        }
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(nums[i]==v[0]||nums[i]==v[1]) ans.push_back(i) ; 
        }
        return ans;
    }
};