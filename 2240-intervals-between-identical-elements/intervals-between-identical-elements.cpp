class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> ans(n);
        unordered_map<int,long long> sum,sum2;
        unordered_map<int,long long> count,count2;
        for(int i = 0 ; i < n ; i++){
            ans[i] +=  1LL * i * count[arr[i]] - sum[arr[i]] ;
            count[arr[i]]++;
            sum[arr[i]] += i ;


            ans[n-i-1] +=  1LL * sum2[arr[n-i-1]] - 1LL * (n-i-1) * count2[arr[n-i-1]];
            count2[arr[n-i-1]]++;
            sum2[arr[n-i-1]] += (n-i-1) ;
        }
        // sum.clear(); count.clear();
        // for(int i = n-1 ; i >=0 ; i--){
            
        // }
    return ans;
    }
};