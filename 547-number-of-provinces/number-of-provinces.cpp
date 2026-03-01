class Solution {
public:
vector<int> parnt;
vector<int> siz;
void make(int i ){
    parnt[i] = i; siz[i]=1;
}
int find(int i ){
    if(parnt[i]==i) return i;
    return parnt[i]= find(parnt[i]);
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
        int n = isConnected.size();
        parnt.resize(n);
        siz.resize(n);
        for(int i =0;i<n;i++){
            make(i);
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    Union(i,j);
                }
            }
        }
        int  ans =0;
        for(int i =0;i<n;i++){
            if(parnt[i]==i) ans++;
        }
    return ans;
    }
};