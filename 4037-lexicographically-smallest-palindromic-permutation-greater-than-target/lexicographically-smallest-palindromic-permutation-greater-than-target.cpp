class Solution {
public:
vector<int> frq;
string ans ;
char m = '\0';
int half ;
    bool hlpr(string &tar , int ix , bool big , string &curr){
        if(ix == half){
            string normal = curr;
            string rv = curr; reverse(rv.begin(),rv.end());
            if(m != '\0' ) normal = normal + m;
            ans = normal + rv;
            if(ans > tar ) return 1;
            return 0;
        }
        for(char ch = 'a' ; ch <= 'z' ; ch++){
            if(frq[ch-'a'] == 0) continue ; 
            if(big == false && ch < tar[ix]) continue;

            curr.push_back(ch);
            frq[ch-'a']--;

            if(hlpr(tar,ix+1,big || ch > tar[ix] , curr)) return 1;

            curr.pop_back();
            frq[ch-'a']++;
        }
    return 0;
    }
    string lexPalindromicPermutation(string s, string target) {
        frq.resize(26,0);
        half = s.size()/2;
        for(char &ch : s) frq[ch-'a']++;

        int odd = 0 ;
        for(int i = 0 ; i < 26 ; i++ ){
            if(frq[i] & 1){
                m = i + 'a';
                odd++;
            }
            frq[i] /= 2 ;
        }
        if(odd > 1) return "" ;
        string curr ;
        if(hlpr(target, 0, false, curr))  return ans;
    return "";
    }
};