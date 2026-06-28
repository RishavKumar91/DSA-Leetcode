class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n + 1, 0);
        for(int &x : arr){
            count[min(x,n)]++;
        }
        int ans = 1;
        for(int i = 2 ; i <=n ;  i++){
            int curr = ans+count[i];
            ans = min(i,curr);
        }
    return ans;
    }
};