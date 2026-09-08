class Solution {
public:
    int n;

    void hlpr(int i, int j, string &s, int &start, int &len) {
        while(i >= 0 && j < n && s[i] == s[j]) {
            if(j - i + 1 > len) {
                start = i;
                len = j - i + 1;
            }
            i--;
            j++;
        }
    }

    string longestPalindrome(string s) {
        n = s.size();

        int start = 0;
        int len = 1;

        for(int i = 0; i < n; i++) {
            hlpr(i, i, s, start, len);
            hlpr(i, i + 1, s, start, len);
        }

        return s.substr(start, len);
    }
};