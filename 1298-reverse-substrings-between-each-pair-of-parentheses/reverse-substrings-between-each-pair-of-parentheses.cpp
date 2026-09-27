class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        int i = 0 , j = n-1 ; 
        unordered_map<int,int> mp; 
        stack<int> st ;
        while(i<n){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                mp[i] = st.top();
                mp[st.top()] = i ;
                st.pop();
            }
        i++;
        }
        i = 0 ;
        bool LtoR = 1;
        string ans;
        while(i<n && i>=0){
            if(s[i] == '(' || s[i] == ')' ){
                LtoR = !LtoR ;
                i = mp[i] + ( LtoR  ? 1 : -1);
            } else if(LtoR){
                ans+=s[i];
                i++;
            } else{
                ans+=s[i];
                i--;
            }
        }
    return ans;
    }
};