class Solution {
public:
vector<int> ans ;
vector<int> visit;
vector<vector<int>> aj; 
    bool dfs(int i , vector<vector<int>> &aj , vector<int> &visit ){
        for(int &ngbr : aj[i]){
            if(visit[ngbr] == 1) continue ;
            if(visit[ngbr] == 2) return 1 ;
            visit[ngbr] = 2 ;
            if(dfs(ngbr,aj,visit)) return 1 ;
        }
        ans.push_back(i);
        visit[i] = 1 ; 
    return 0 ;
    }
    vector<int> findOrder(int num, vector<vector<int>>& prerequisites) {
        aj.resize(num);
        visit.resize(num);
        for(auto &q : prerequisites ){
            aj[q[1]].push_back(q[0]);
        }
        for(int i = 0 ; i < num ; i++){
            if(visit[i] == 0){
                if(dfs(i,aj,visit) == 1) return vector<int> ();
            }
        }
        reverse(ans.begin() , ans.end());
    return ans ;
    }
};