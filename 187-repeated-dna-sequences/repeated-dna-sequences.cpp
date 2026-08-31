class Solution {
public:
vector<string> ans ;
int base = 5 ;
int bpow ;
int m ;
unordered_map<char,int> mp; 
     
    vector<string> findRepeatedDnaSequences(string s) {
        m = s.size();  bpow = 9 ; 
        if(m < 10) return ans;
        mp['A'] = 1 ; mp['C'] = 2 ; mp['G'] = 3 ; mp['T'] = 4 ;

        
        int i = 0 ;
        int firsthash = 0 ,currpow = 9;
        for(i ; i < 10 ; i++){
            firsthash += mp[s[i]] * pow(5,currpow);
            currpow -= 1 ;
        }


        unordered_map<long long,int> frq;
        frq[firsthash]++;

        for( i ; i < m ; i++){
            
            firsthash -= mp[s[i-10]] * pow(base , bpow);
            firsthash *= base ;
            firsthash += mp[s[i]] ; 
            frq[firsthash]++;
            if(frq[firsthash] == 2) ans.push_back(s.substr(i-9,10));
        }
    return ans ;
    }
};