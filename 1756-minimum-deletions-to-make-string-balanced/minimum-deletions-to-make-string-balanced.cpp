class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int n = s.size();
        stack<char> ch;
        for(int i =0;i<n;i++){
            if(!ch.empty() && ch.top()=='b' && s[i]=='a'){
                ans++;
                ch.pop();
                //ch.push(s[i]);
            }
            else ch.push(s[i]);
        }
    return ans;
    }
};