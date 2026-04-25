class Solution {
public:
typedef long long ll;
bool chck(ll mi, int k, ll peri, vector<ll> &now){
    int n = now.size();
    vector<ll> ext(2*n);
    for(int i = 0; i < n; i++){
        ext[i] = now[i];
        ext[i+n] = now[i] + peri;
    }
    for(int i = 0; i < n; i++){
        ll prv = ext[i];
        int count = 1;
        int pos = i;
        while(count < k){
            int nxt = lower_bound(ext.begin() + pos + 1,ext.begin() + i + n,prv + mi) - ext.begin();
            if(nxt == i + n) break;
            prv = ext[nxt];
            pos = nxt;
            count++;
        }
        if(count == k && ext[i] + peri - prv >= mi) return true;
    }
return false;
}
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        ll s = (ll)side;
        ll start = 0;
        ll last = 1LL * side*4;
        ll ans =0;
        ll peri = 4 * s;
        vector<ll> now;
            for(auto &p:points){
                ll x = p[0];
                ll y = p[1];
                if(y==0) now.push_back(x);
                else if(x==side) now.push_back(s+y);
                else if(y==side) now.push_back(s*2 + side-x);
                else now.push_back(s*3 + s-y);
            }
        sort(now.begin(),now.end());
        while(start<=last){
            ll mi = start + (last-start)/2;
            if(chck(mi,k,peri,now)){
                ans = mi;
                start = mi+1;
            }
            else{
                last = mi-1;
            }
        }
    return ans;
    }
};