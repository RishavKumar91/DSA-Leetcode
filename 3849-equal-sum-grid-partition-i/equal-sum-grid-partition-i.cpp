class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<long long> rowsum(m) , colsum(n);
        long long total = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                rowsum[i] += grid[i][j] ;
                total += grid[i][j];
                colsum[j] += grid[i][j] ;
            }
        }
        // for(int i = 1 ; i < m ; i++ ) rowsum[i] += rowsum[i-1];
        // for(int i = 1 ; i < n ; i++ ) colsum[i] += colsum[i-1];

        long long sum = 0 ;
        for(int i = 0 ; i < m-1 ; i++ ){
            sum += rowsum[i];
            if(2 * sum == total) return 1;            
        }

        sum = 0 ;
        for(int i = 0 ; i < n-1 ; i++ ){
            sum += colsum[i];
            if(2 * sum == total) return 1;            
        }
    return 0;
    }
};