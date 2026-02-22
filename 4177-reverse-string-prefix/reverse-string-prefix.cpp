class Solution {
public:
    string reversePrefix(string s, int k) {
        string pre = s.substr(0,k);
        string post = s.substr(k);
        reverse(pre.begin(),pre.end());
        return pre+post;
    }
};