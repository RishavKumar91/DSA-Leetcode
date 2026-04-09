class Solution {
public:
int M = 1e9+7;
typedef long long ll;
ll pow(ll b,ll p){
    if(p==0) return 1;
    ll half = pow(b,p/2);
    if(p%2==0) return (1LL * half%M * half%M)%M;
    return (1LL * half%M * half%M * b%M)%M;
}
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int blocksiz = ceil(sqrt(n));
        unordered_map<int,vector<vector<int>>> smallMap;
        for(auto &q : queries){
            int L = q[0];
            int R = q[1];
            int K = q[2];
            int V = q[3];
            if(K>=blocksiz){
                for(int i = L; i<=R;i+=K){
                    nums[i] = (1LL * nums[i] * V) % M;
                }
            }
            else {
                smallMap[K].push_back(q);
            }
        }

        for(auto [K,allq] : smallMap){
            vector<ll> diff(n,1);
            for(auto &query : allq){
                int L = query[0];
                int R = query[1];
                int V = query[3];
                diff[L] = (diff[L] * V) % M ;
                int stp = (R-L)/K ;
                int outr = 1LL * L + (stp+1)*K;
                if(outr<n)
                diff[outr] = (1LL * diff[outr] * pow(V,M-2))%M ;
            }
            for(int i = K ;i<n;i++){
                diff[i] = (1LL * diff[i] * diff[i-K]) % M;
            }
            for(int i = 0;i<n;i++){
                nums[i] =(1LL * nums[i] * diff[i]) % M;
            }
        }


        int ans = 0;
        for(auto i : nums){
            ans = ans ^ i;
        }
    return ans;
    }
};