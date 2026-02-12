class Solution {
public:
bool chck(vector<int> &v){
        int freq = 0;

        for(int i = 0; i < 26; i++){
            if(v[i] == 0 ) continue;
            if(freq==0 )
                freq = v[i];
            if(v[i] != freq)
                return false;
        }
        return 1;
}
    int longestBalanced(string s) {
        int maxans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            vector<int> v(26,0);
            for(int j =i;j<n;j++){
                v[s[j]-'a']++;
                if(chck(v) == 1) maxans = max(maxans,j-i+1);
            }
        }
    return maxans;
    }
};