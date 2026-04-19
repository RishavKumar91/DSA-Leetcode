class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 , j = 0;
        int m = nums1.size() , n = nums2.size();
        int ans = 0;
        while(i!=m && j!=n){
            if(i<=j ) {
                if(nums1[i]<=nums2[j]){
                    ans = max(ans,j-i);
                    j++;
                }
                else 
                    i++;
            }
            else {
                j++;
            }
        }
    return ans;
    }
};