class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        // for(int i = 0;i<n;i++){
        //     v.push_back(i);
        // }
        // while(v.size()!=1){
        //     if(v.size()-1  ) 
        // }
        // return 0;
        int i =0;
        while(i<n && s[i] == '1') i++;
        while(i<n && s[i] == '0') i++;
        if(i==n) return 1;
        // while(i<n && s[i] == '1') i++; return 0;
        return 0;
    }
};