class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // priority_queue<int> maxHeap;
        // vector<int> v; int n = nums.size();
        // priority_queue<int, vector<int>, greater<int>> minHeap;
        // for(int i =0;i<n;i++){
        //     maxHeap.push(nums[i]);
        //     minHeap.push(nums[i]);
        // }
        // while(minHeap.empty() ==0 || maxHeap.empty()==0){
        //     int a = 0;
        //     if(minHeap.size()) a+=minHeap.top();
        //     if(maxHeap.size()) a+=maxHeap.top();
        //     if(a==target) {v.push_back(minHeap.top()) ; v.push_back(maxHeap.top());break;}
        //     else if(a>target) maxHeap.pop();
        //     else minHeap.pop();
        // }
        // vector<int> ans;
        // for(int i =0;i<n;i++){
        //     if(nums[i]==v[0]||nums[i]==v[1]) ans.push_back(i) ; 
        // }
        // int n =nums.size();
        // vector<int> v;
        // unordered_map<int,int> mp;
        // for(int i =0;i<n;i++)
        // mp[nums[i]] =i;
        // for(int i =0;i<n;i++){
        //     int a  = target-nums[i];
        //     if(a==nums[i] && i!=mp[nums[i]]) {v.push_back(i); v.push_back(mp[nums[i]]);break;}
        //     mp.erase(nums[i]);
        //     if(mp.find(a) != mp.end()){ v.push_back(i) ; v.push_back(mp[a]); break;}
        //     mp[nums[i]]=i;
        // }

        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i =0;i<n;i++){
            int rm = target - nums[i];
            if(mp.find(rm)!=mp.end()){ v.push_back(i);v.push_back(mp[rm]);return v; }
            else mp[nums[i]] = i;
        }
        return v;
    }
};