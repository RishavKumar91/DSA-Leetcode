class Solution {
public:
vector<int> parnt ,siz ; 
int find(int i){
    if(parnt[i] == i) return i;
    return parnt[i] = find(parnt[i]);
}
void Union(int u,int v){
    u = find(u);
    v = find(v);
    if(u!=v){
        if(siz[u]>=siz[v]) { parnt[v] =u ; siz[u] += siz[v];}
        else { parnt[u] = v ; siz[v] += siz[u];}
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        parnt.assign(V,0); siz.assign(V,1);
        for(int i = 0 ; i < V ; i++) parnt[i] = i ;
        for(int i = 0 ; i < V ; i++){
            for(int j = i+1 ; j < V ; j++){
                if(isConnected[i][j] == 1) Union(i,j);
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i < V ; i++) if(parnt[i] == i) ans++;
    return ans; 
    }
};