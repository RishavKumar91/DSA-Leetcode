class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int j = s.size()-1;
        int i = 0;
        while(i<j){
            while(i<n &&!isalnum(s[i])) i++;
            while(j>=0 && !isalnum(s[j])) j--;

            if(isalnum(s[i]) && isalnum(s[j])){
                if(tolower(s[i]) == tolower(s[j])) {i++;j--;}
                else return 0;
            }

        }
        return 1;
    }
};