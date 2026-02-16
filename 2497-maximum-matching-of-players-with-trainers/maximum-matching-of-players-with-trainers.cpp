class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size();
        int n = trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ans = 0;
        int i =0,j=0;
        while(i<m && j<n){
            if(players[i]<=trainers[j]){ ans++; i++ ; j++; }
            else if(players[i]>trainers[j]) j++;
        }
        return ans;
    }
};