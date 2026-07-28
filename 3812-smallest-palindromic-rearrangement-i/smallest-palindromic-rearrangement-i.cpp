class Solution {
public:
    string smallestPalindrome(string s) {
        int arr[26] = {0};
        
        char o = '\0';
        int oo = 0 ; 

        for(char &ch : s) arr[ch  - 'a']++;

        for(int i = 0 ; i < 26 ; i++){
            char ch = i + 'a' ; 
            if(arr[ch-'a'] & (1) )  {o = ch ; oo = arr[ch-'a'] ;  break ; }
        }

        string ans =( oo & 1 )? string( 1  , o ) : "";

        for(int  i = 25  ; i >= 0  ; i-- ){
            int n = arr[i]/2 ;
            char ch = 'a' + i ; 
            string now = string(n , ch);
            ans = now + ans + now ;
        }


    return ans;
    }
};