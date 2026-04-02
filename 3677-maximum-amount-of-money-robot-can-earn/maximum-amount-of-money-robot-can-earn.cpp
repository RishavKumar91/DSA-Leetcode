class Solution {
public:
    int solv(vector<vector<int>> &coins , int count,int i ,int j , 
    vector<vector<vector<int>>> & vec){
        if(i<0 || j<0) return INT_MIN;
        if(i==0 && j==0) return 
                    coins[0][0] >= 0 ? coins[0][0] : count>0 ? 0 :  coins[0][0]; 
        if(vec[i][j][count] != INT_MIN) return vec[i][j][count];
        int tak =   coins[i][j] + max(solv(coins,count,i-1,j,vec) ,
         solv(coins,count,i,j-1,vec));
        int skip = INT_MIN;
        if(coins[i][j]<0 && count>0){
            int lmax =  solv(coins,count-1,i-1,j,vec);
            int tmax =  solv(coins,count-1,i,j-1,vec);
            skip = max(lmax,tmax);
        }

       return  vec[i][j][count] = max(skip,tak);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> vec(
        m,
        vector<vector<int>>(n, vector<int>(3, INT_MIN))
    );
        return solv(coins,2,m-1,n-1,vec);
    }
};