class Solution {
public:
int n;
    int hlpr(int i , int j , string &s){
        int count = 0 ;
        while(i >= 0 && j < n && s[i]==s[j]){
            i--;
            j++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        n = s.size();
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            ans += hlpr(i,i,s);
            ans += hlpr(i,i+1,s);
        }
    return ans;
    }
};