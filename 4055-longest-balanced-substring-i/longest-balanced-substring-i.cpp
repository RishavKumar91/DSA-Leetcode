class Solution {
public:
bool chck(vector<int> &v){
        int freq = 0;

        for(int i = 0; i < 26; i++){
            if(v[i] != 0){
                if(freq == 0)
                    freq = v[i];
                else if(v[i] != freq)
                    return false;
            }
        }
        return freq != 0;
    }
    int longestBalanced(string s) {
        int maxans = 0;
        int n = s.size();
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            vector<int> v(26,0);
            int j = i ;
            for(int j =i;j<n;j++){
                v[s[j]-'a']++;
                if(chck(v) == 1) maxans = max(maxans,j-i+1);
            }
        }
    return maxans;
    }
};