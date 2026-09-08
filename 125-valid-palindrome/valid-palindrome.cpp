class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0 , j = s.size()-1;
        while(i < j){
            while( i < n && !isalnum(s[i])  ) i++;
            while(j >= 0 &&  !isalnum(s[j])  ) j--;
            if(i >= n || j < 0 ) return 1;
            if( tolower(s[i]) != tolower(s[j]) ) return 0;
            i++; j--;
        }
    return 1;
    }
};