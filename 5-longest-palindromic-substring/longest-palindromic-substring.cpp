class Solution {
public:
int n ;
    pair<int,int> hlpr(int i , int j , string &s){
        while(i >= 0 && j < n ){
            if(s[i] == s[j]) {
                i--;
                j++;
            }
            else{
                break;
            }
        }
    return {i+1 , j-i-1}; // i+1 se j-1 tak ,  so ln = (j-1) - (i+1) + 1 = j-i-1
    }
    string longestPalindrome(string s) {
        n = s.size();
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            pair<int,int> oans = hlpr(i,i,s);
            pair<int,int> eans = hlpr(i,i+1,s);
            // string eans = hlpr(i,i+1,s);
            ans = oans.second > ans.size() ? s.substr(oans.first,oans.second) : ans ; 
            ans = eans.second > ans.size() ? s.substr(eans.first,eans.second) : ans ; 
            // ans = eans.size() > ans.size() ? eans : ans ; 
        }
    return ans;
    }
};