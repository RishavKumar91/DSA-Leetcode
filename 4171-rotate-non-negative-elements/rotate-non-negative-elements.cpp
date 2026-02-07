class Solution {
public:
// void rota
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> a;
        int n = nums.size();
        if(n<2) return nums;
        for(int i=0;i<n;i++)
        if(nums[i]>=0) a.push_back(nums[i]);
        if(a.size()!=0) k=k% a.size(); 
        while(k--){
            a.push_back(a.front());
            a.pop_front();
        }
        for(int i =0;i<n;i++){
            if (nums[i]<0) v.push_back(nums[i]);
            else {v.push_back(a.front()); a.pop_front();}
        }
    return v;
    }
};