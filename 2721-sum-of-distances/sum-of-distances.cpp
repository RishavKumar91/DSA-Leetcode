class Solution {
public:
typedef long long ll;
    vector<ll> distance(vector<int>& nums) {
        ll n = nums.size();
        unordered_map<ll,ll> frq;
        unordered_map<ll,ll> sum;
        vector<ll> ans(n,0);
        for(int i = 0;i<n;i++){
            ll frequency = frq[nums[i]];
            ll suum = sum[nums[i]];
            ans[i] = (i*frequency ) - suum;
            frq[nums[i]]++;
            sum[nums[i]]+=i;
        }
        frq.clear();
        sum.clear();
        for(int i = n-1;i>=0;i--){
            ll frequency = frq[nums[i]];
            ll suum = sum[nums[i]];
            ans[i] += suum - ( i*frequency ) ;
            frq[nums[i]]++;
            sum[nums[i]]+=i;
        }
    return ans;
    }
};