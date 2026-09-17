class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int tar) {
        int n = arr.size();
        int i = 0 , j = 0 , ans = INT_MAX ,  sum = 0, bestmin = INT_MAX ;
        vector<int> BestTill(n,INT_MAX);
        while(j < n){
            sum += arr[j];
            while(sum > tar){
                sum -= arr[i];
                i++;
            }
            if(sum == tar){
                int ln = j - i + 1;
                if(i > 0 && BestTill[i-1] != INT_MAX){
                    ans = min(ans,ln + BestTill[i-1]) ; 
                }
                bestmin = min(bestmin,ln);
            }
            BestTill[j] = bestmin;
            j++;
        }
    return ans == INT_MAX ? -1 : ans ;
    }
};