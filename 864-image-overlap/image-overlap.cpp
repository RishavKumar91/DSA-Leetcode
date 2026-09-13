class Solution {
public:
int n;
    int fxn(vector<vector<int>>& img1, vector<vector<int>>& img2 , int r , int c){
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int ni = i + r ;
                int nj = j + c ; 
                if(ni < 0 || ni >=n || nj < 0 || nj >= n) continue;
                if(img1[i][j] == 1 && img2[ni][nj] == 1) ans++;
            }
        }
    return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();
        int ans = 0 ; 
        for(int i = -n+1 ; i < n ; i++){
            for(int j = -n+1 ; j < n ; j++){
                ans = max(ans,fxn(img1,img2,i,j));
            }
        }
    return ans; 
    }
};