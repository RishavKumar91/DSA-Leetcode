class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = INT_MIN;
        for(int i = 0 ; i<n;i++){
            if(colors[0] != colors[i])         ans = max(ans,i);
            if(colors[n-1] != colors[i]) ans = max(ans,abs(n-1-i));
        }
    return ans;
    }
};