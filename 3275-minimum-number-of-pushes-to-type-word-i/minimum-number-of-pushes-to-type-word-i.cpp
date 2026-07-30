class Solution {
public:
    int minimumPushes(string word) {
        unordered_set<char > st;
        for(char &ch : word){ 
            st.insert(ch);
        }
        int sz  = st.size();
        if(sz <= 8 ) return  sz;
        else if(sz <= 16) return 8 + 2*(st.size()-8);
        else if(sz <= 24 ) return 8 + 16 +  3*(st.size()-16) ; 
        return 8 + 16 +  24 + 4*(st.size()-24) ; 
    }
};