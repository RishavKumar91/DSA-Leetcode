class Solution {
public:
long long solv(int i,int j,vector<int> &robot,vector<int> &factory,
    vector<vector<long long>> &dp
                ){
    if(i==robot.size()) return 0;
    if(j==factory.size()) return 1e12;
    if(dp[i][j] != -1) return dp[i][j];
    long long take = abs(factory[j]-robot[i]) + solv(i+1,j+1,robot,factory,dp);
    long long skip = solv(i,j+1,robot,factory,dp);

    return dp[i][j] = min(skip,take);
}
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> fact;
        for(int i = 0;i<factory.size();i++){
            for(int j = 0 ; j < factory[i][1] ;j++){
                fact.push_back(factory[i][0]);
            }
        } 
        vector<vector<long long>> dp(robot.size()+1, vector<long long>(fact.size()+1, -1));
        return solv(0,0,robot,fact,dp);
    }
};