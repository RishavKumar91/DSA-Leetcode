class Solution {
public:
void rotate(int f,int l,vector<int> &nums){
    while(f<l){
        swap(nums[f],nums[l]);
        f++;
        l--;
    }
}
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        rotate(0,n-1,nums);
        rotate(0,k-1,nums);
        rotate(k,n-1,nums);  
    }
};