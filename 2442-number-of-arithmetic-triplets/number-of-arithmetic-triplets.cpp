class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size(),ans = 0;
        unordered_set<int> s;
        for(int i =0 ; i<n; i++){
            s.insert(nums[i]);
        }
        for(auto x : s){
            if(s.count(x-diff) && s.count(x-(2*diff)) ) ans++;
        }
    return ans;
    }
};