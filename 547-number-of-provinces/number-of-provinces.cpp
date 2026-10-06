class Solution {
public:
vector<int> parnt ; 
int find(int i){
    if(parnt[i] == i) return i;
    return parnt[i] = find(parnt[i]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b) parnt[a] = b ;
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        parnt.assign(V,0);
        for(int i = 0 ; i < V ; i++) parnt[i] = i ;
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                if(isConnected[i][j] == 1) Union(i,j);
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i < V ; i++) if(parnt[i] == i) ans++;
    return ans; 
    }
};