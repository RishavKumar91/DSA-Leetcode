class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string a = "";
        for(int i =0;i<n;i++){
            if(isalnum(s[i])){
                a.push_back(tolower(s[i]));
            }
        }
        string b = a;
        reverse(a.begin(),a.end());
        return a==b;
    }
};