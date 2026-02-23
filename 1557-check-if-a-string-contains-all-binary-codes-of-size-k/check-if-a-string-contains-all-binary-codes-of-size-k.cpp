class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> st;
        for(int i = k;i<=n;i++){
            st.insert(s.substr(i-k,k));
        }
        if(st.size()== pow(2,k)) return 1;
    return 0;
    }
};