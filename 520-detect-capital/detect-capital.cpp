class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cap = 0;
        for(int i =0;i<n;i++){
            if(isupper(word[i])) cap++;
        }
        if(cap==0 || cap==word.size() || (cap==1 && isupper(word[0])) ) return 1;
    return 0;
    }
};