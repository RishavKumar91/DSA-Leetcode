class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int i = 0 , j = n-1 ;
        while(i < n && s[i] == ' ') i++;
        while( j >=0 && s[j] == ' ') j--;
        int ans = 0  ;
        for(i ; i <=j ; i++ ){
            if( i-1 >= 0 && s[i] != ' ' && s[i-1] != ' '  ) continue;
            if(s[i] != ' ') ans++;
        }
    return ans;
    }
};