class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool f = 1;
        int count = 0;
        for(int i =0;i<n;i++){
            if(f!=s[i]-'0') count++;
            f = !f; 
        }
        int ans = count;
        count = 0;
        f = 0;
        for(int i =0;i<n;i++){
            if(f!=s[i]-'0') count++;
            f = !f; 
        }
    return min(count,ans);
    }
};