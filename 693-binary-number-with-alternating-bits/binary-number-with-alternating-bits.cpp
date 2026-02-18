class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = bitset<32>(n).to_string();
        int i =0;
        while(s[i]=='0'){
            i++;
        }
        s = s.substr(i);
        for(int i =0;i<s.size()-1;i++){
            if(s[i]==s[i+1]) return 0;
        }
    return 1;
    }
};