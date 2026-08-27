class Solution {
public:
    string ans;
    vector<int> frq;
    bool solv(int ix , string &target,string &curr,bool big){
        if(ix == target.size()){
            if(big) {ans = curr; return 1;}
            return 0;
        }
        for(char ch = 'a' ; ch <= 'z' ; ch++){
            if(frq[ch - 'a'] == 0 ) continue;
            if(big == 0  && ch < target[ix])  continue;
            frq[ch - 'a']--;
            curr.push_back(ch);

            if(solv(ix+1,target,curr,ch>target[ix] || big)) return 1;

            frq[ch-'a']++;
            curr.pop_back();
        }
    return 0 ;
    }
    string lexGreaterPermutation(string s, string target) {
        frq.assign(26, 0);
        ans = "";
        for(char &ch : s ) frq[ch-'a']++ ;
        string curr = "";
        solv(0,target,curr,0);
        return ans;
    }
};