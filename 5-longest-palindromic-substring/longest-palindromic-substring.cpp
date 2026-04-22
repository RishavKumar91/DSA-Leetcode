class Solution {
public:
    string chck(string &s , int i,int j ){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;j++;
        }
    return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0;i<n;i++){
            string odd = chck(s,i,i);
            string even = chck(s,i,i+1);
            ans = ans.size() > odd.size() ? ans : odd;
            ans = ans.size() > even.size() ? ans : even;
        }
    return ans;
    }
};