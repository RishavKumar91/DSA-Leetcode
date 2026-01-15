class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int f = 0, l = n - 1;
        while (f < l) {
            int mid = f + (l - f) / 2;
            if (nums[mid] > nums[l])  f = mid + 1;
            else  l = mid;
        }
        int rot = f;
        f = 0,l = n - 1;
        while (f <= l) {
            int mid = f + (l - f) / 2;
            int realMid = (mid + rot) % n;
            if (nums[realMid] == target)   return realMid;
            else if (nums[realMid] < target)  f = mid + 1;
            else  l = mid - 1;
        }
    return -1;
    }
};
