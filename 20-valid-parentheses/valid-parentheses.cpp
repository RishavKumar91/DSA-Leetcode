class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        int i = 1,n=s.size(); ss.push(s[0]);
        while(i<n){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' )    ss.push(s[i]);
            else{
                // if(s[i]==')' && ss.top()!='(') return 0 ;
                // if(s[i]=='}' && ss.top()!='{') return 0 ;
                // if(s[i]==']' && ss.top()!='[') return 0 ;
                // ss.pop();
                if(ss.empty()) return 0;
                if(ss.top()=='(' && s[i]==')' || ss.top()=='[' && s[i]==']' ||
                ss.top()=='{' && s[i]=='}' ) ss.pop();
                else return 0;
            }
        i++;
        }
        if(ss.empty()) return 1;
        else return 0;
    }
};