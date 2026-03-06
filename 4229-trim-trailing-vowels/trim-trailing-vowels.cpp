class Solution {
public:
    bool isvwl(char ch){
        if(ch=='a' || ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' ) return 1;
        return 0;
    }
    string trimTrailingVowels(string s) {
        while(s.size() > 0 && isvwl(s[s.size()-1]))
        s.pop_back();
    return s;
    }

};