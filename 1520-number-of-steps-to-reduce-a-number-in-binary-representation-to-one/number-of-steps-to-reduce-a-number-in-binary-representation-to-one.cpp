class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s.size()!=1){
            if(s[s.size()-1]=='1'){
                ans+=2;
                int j = s.size()-1;
                while(j>=0 && s[j]=='1'){
                    s[j]='0';
                    j--;
                }
                if(j>=0) s[j]='1';
                else s = '1' + s;
                s.pop_back();
            }
            else{
                ans++;
                s.pop_back();
            }
        }
    return ans;
    }
};