class Solution {
public:
int maxpossible(vector<pair<int,int>> &pairs , int i , int maxDiff){
    int f = i ; 
    int l = pairs.size()-1;
    int ans = i;
    int mxx = pairs[i].first + maxDiff;
    while(f<=l){
        int mid = f + (l-f)/2 ;
        if(pairs[mid].first <= mxx){
            ans = mid;
            f = mid+1;
        }
        else {
            l  = mid-1;
        }
    }
return ans;
}
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> pairs(n);
        vector<int> numstoix(n);
        for(int i = 0 ; i < n ; i++){
            pairs[i] = {nums[i],i};
        }
        sort(pairs.begin(),pairs.end());
        for(int i = 0 ; i < n ; i++){
            numstoix[pairs[i].second] = i;
        }
        int rows = log2(n)+1;
        vector<vector<int>> up(n,vector<int> (rows , 0));

        for(int i = 0 ; i < n ; i++){
            up[i][0] = maxpossible(pairs,i,maxDiff);
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < n; j++) {
                up[j][i] = up[ up[j][i-1] ][ i-1 ];
            }
        }
        vector<int> ans;
        for(auto &q : queries){
            int start = numstoix[q[0]];
            int last = numstoix[q[1]];
            int jumps = 0;
            start > last ? swap(start,last): void();
            if(start == last) {
                ans.push_back(0);
                continue;
            }
            for(int i = rows-1 ; i>=0 ; i--){
                if(up[start][i] < last){
                    start = up[start][i];
                    jumps += 1<<i;
                }
            }
            if(up[start][0] >= last) ans.push_back(jumps+1);
            else ans.push_back(-1);
        }
    return ans;
    }
};