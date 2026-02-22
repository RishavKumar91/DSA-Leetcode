class Solution {
public:
void bfs(vector<vector<int>>& rooms,vector<bool>&yup,int i){
    queue<int> q;
    q.push(i);
    yup[i]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int each : rooms[node]){
            if(!yup[each]){
                q.push(each);
                yup[each] =1;
            }
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> yup(n,0);
        bfs(rooms,yup,0);
    for(int i =0;i<n;i++){
        if(!yup[i]) return 0;
    }
    return 1;
    }
};