class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2==1) return 0;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='(' || locked[i] == '0') count++;
            else if(s[i]==')') count--;

            if(count<0) return 0;
        }
        count = 0;
        for(int i = n-1;i>=0;i--){
            if(s[i]==')' || locked[i] == '0') count++;
            else if(s[i]=='(') count--;

            if(count<0) return 0;
        }
    return 1;
    }
};