class Solution {
public:
int n;
    bool chck(int i , int j , string &s){
        while(i<j ){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
    return 1;
    }
    int countSubstrings(string s) {
        n = s.size();
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(chck(i,j,s)) ans++;
            }
        }
    return ans;
    }
};