class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m = a.size() , n = b.size();
        int k = n%m == 0 ? n/m : (n/m)+1 ;
        string s ;
        int t  =  k ;
        while(t--) s += a ;
        if(s.find(b) != string::npos) return k ; 
        s += a ;
        if(s.find(b) != string::npos) return k+1 ;
    return -1; 
    }
};