class DSU{
    public:
    vector<int> parnt,siz;
    int comp ;
    DSU(int n){
        comp = n;
        siz.resize(n,1);
        parnt.resize(n);
        for(int i = 0;i<n;i++){
        parnt[i] = i;
        }
    }
    int find(int i){
            if(parnt[i]==i) return i;
            return parnt[i] = find(parnt[i]);
    }
    void Union(int u , int v){
        u = find(u);
        v = find(v);
        if( u == v) return ;
        int x = siz[u];
        int y = siz[v];
        comp--;
        if(x>y){ parnt[v] = u ; siz[u]+=siz[v]; }
        else   { parnt[u] = v ; siz[v]+=siz[u]; }
    }
};
class Solution {
public:
    bool fxnn(int mi,int n, vector<vector<int>>& edges, int k){
        DSU d2(n);
        vector<vector<int>> upcan;
        for(auto a : edges){
            int u = a[0];
            int v = a[1];  int w = a[2];int x = a[3];
            if(x==1  ){
                if(w<mi) return 0;
                d2.Union(u,v);
            }
            else{
                if(w>=mi) d2.Union(u,v);
                else if(2*w >= mi) upcan.push_back({u,v});
            }
         }
        for(auto &a : upcan){
            int u = a[0]; int v = a[1];
            if(d2.find(u) != d2.find(v)){
                if(k==0) return 0;
                d2.Union(u,v);
                k--;
            }
        }
        int root = d2.find(0);
        // for(int i =1;i<n;i++) if(root != d2.find(i)) return 0;
    return d2.comp==1   ;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU d1(n);
        for(auto a : edges){
            int u = a[0];
            int v = a[1];  int w = a[2];int x = a[3];
            if(x==1){
                if(d1.find(u) == d1.find(v)) return -1;
                d1.Union(u,v);
            }
        }
        int first = 0; int last = 2 * 100000; int ans = -1;
        while(first<=last){
            int mi = first + (last-first)/2;
            if(fxnn(mi,n,edges,k)){
                ans = mi;
                first = mi+1;
            }
            else
                last = mi-1;
        }
    return ans;
    }
};