class Solution {
public:
int M = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> cumsum(n);
        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) pow10[i] = (pow10[i - 1] * 10) % M;
        vector<pair<int ,int>> curranddigit(n);
        long long now = 0LL; int d = 0 ;
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            sum += (s[i]-'0');
            if(s[i] != '0' ) {
                now = (now*10 + s[i]-'0')%M ; d++;
            }
            cumsum[i] = sum % M;
            curranddigit[i] = {now,d};
        }
        vector<int> ans;
        for(auto &q : queries ){
            int l = q[0] , r = q[1];
        int diffdigit = l==0 ? curranddigit[r].second : curranddigit[r].second - curranddigit[l-1].second ;
            long long ll = l==0 ? 0 : curranddigit[l-1].first;
            long long rr = curranddigit[r].first;
            long long put = (rr -  ll* pow10[diffdigit])%M;
            put = (put+M)%M;
            ans.push_back( 1LL *  (cumsum[r] - (l==0  ? 0 : cumsum[l-1]) )%M * put%M );
        }
        return ans;
    }
};