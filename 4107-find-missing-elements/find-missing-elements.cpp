class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int y = *max_element(nums.begin() , nums.end());
        int z = *min_element(nums.begin() , nums.end());
        vector<int> arr(y+1,0);
        for(int &x : nums) arr[x]++;
        vector<int> ans;
        for(int i = z ; i <= y ; i++) {
            if(arr[i] == 0) ans.push_back(i);
        }
    return ans;
    }
};