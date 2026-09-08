class Solution {
public:
int n ;
    string hlpr(int i , int j , string &s){
        while(i >= 0 && j < n ){
            if(s[i] == s[j]) {
                i--;
                j++;
            }
            else{
                break;
            }
        }
    return s.substr(i+1,j-i-1); // i+1 se j-1 tak ,  so ln = (j-1) - (i+1) + 1 = j-i-1
    }
    string longestPalindrome(string s) {
        n = s.size();
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            string oans = hlpr(i,i,s);
            string eans = hlpr(i,i+1,s);
            ans = oans.size() > ans.size() ? oans : ans ; 
            ans = eans.size() > ans.size() ? eans : ans ; 
        }
    return ans;
    }
};