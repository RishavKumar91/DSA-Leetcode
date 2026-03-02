class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v;
        for(int i =0;i<n;i++){
            int x = 0;
            for(int j = n-1;j>=0;j--){
                if(grid[i][j] == 1){
                    break;
                    }
                x++;
            }
            v.push_back(x);
        }
    int swaps = 0;
        for(int i =0;i<n;i++){
            int rqrzro = n-i-1;
            int j = i;
            while(j<n && v[j]<rqrzro){
                j++;
            }
            if(j==n) return -1;
            while(i<j){
                swaps++;
                swap(v[j],v[j-1]);
                j--;
            }
        }
    return swaps;
    }
};