class Solution {
public:
vector<int> parnt;
vector<int> siz;
int find(int i){
    if(parnt[i] == i) return i;
    return parnt[i] = find(parnt[i]);
}
void Union(int i ,int j ){
    i = find(i);
    j = find(j);
    if(i!=j){
        if(siz[i]>siz[j]) { parnt[j] = i ;siz[i]+=siz[j];}
        else { parnt[i] = j ;siz[j]+=siz[i];}
    }
}
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parnt.resize(n);
        for(int i = 0;i<n;i++) parnt[i] = i;
        siz.resize(n,1);
        for(auto v : allowedSwaps){
            Union(v[0],v[1]);
        }
unordered_map<int,unordered_map<int,int>> fq;
        for(int i = 0;i<n;i++){
            int p = find(i);

            fq[p][source[i]]++;
        }
        int ans = 0;
        for(int i = 0 ;i<n;i++){
            int p = find(i);
            if(fq[p][target[i]] > 0 ) fq[p][target[i]]--;
            else ans++;
        }
    return ans;
    }
};