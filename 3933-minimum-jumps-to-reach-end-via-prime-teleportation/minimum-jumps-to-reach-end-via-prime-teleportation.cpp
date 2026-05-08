class Solution {
public:
vector<bool> prim;
void isprim(int n){
    prim.resize(n+1,1); prim[1] = 0; prim[0] = 0;
    for(int i = 2 ; i*i<=n;i++){
        if(prim[i]==1) {
            for(int j = i+i ; j<=n ; j+=i){
            prim[j] = 0;
            }
        }
    }
    return ;
}
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int ans  = 0;
        unordered_map<int,vector<int>> mp;
        vector<int> visit(n,0);
        int maxval = INT_MIN;
        for(int i = 0;i<n;i++) {mp[nums[i]].push_back(i); maxval = max(maxval,nums[i]);}
        isprim(maxval);

        unordered_set<int> hogaya;
        queue<int> q;
        q.push(0);
        visit[0] = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int now = q.front(); q.pop();
                if(now == n-1) return ans;
                if(now-1 >=0 && visit[now-1]==0) {q.push(now -1);  visit[now-1] = 1;}
                if(now+1 <n  && visit[now+1]==0) {q.push(now +1);  visit[now+1] = 1;}
                if(prim[nums[now]] && !hogaya.count(nums[now]) ) {
                    hogaya.insert(nums[now]);
                    int primvalstart = nums[now];
                    for(int p = primvalstart ; p<=maxval ; p+=primvalstart) {
                        if(mp.count(p)){
                            for(auto a : mp[p]) { if(visit[a]==0) {q.push(a); visit[a] = 1;}}
                        }
                    }
                }
            }
        ans++;
        }
    return -1;
         
    }
};