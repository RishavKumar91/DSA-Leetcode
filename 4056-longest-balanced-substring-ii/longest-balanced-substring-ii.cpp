class Solution {
public:
    int hlpr(char c1,char c2,string &s){
        int n = s.size();
        int maxln =0;
        int count1 =0, count2=0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i =0;i<n;i++){
            if(s[i]!= c1 && s[i]!=c2){
                mp.clear();
                count1=0; count2=0;
            }
            if(s[i]==c1) count1++;
            if(s[i]==c2) count2++;
            int diff = count1 - count2;
            if(mp.count(diff)) maxln = max(maxln,i-mp[diff]);
            else mp[diff] = i;
        }
    return maxln;
    }
    int longestBalanced(string s) {
        int maxln=0;
        int  n = s.size();
        map<pair<int,int>,int> mp;
        mp[{0,0}] = -1;
        int a=0,b=0,c=0;


        for(int i=0;i<n;i++){          // counting where  xyz r present
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;
            pair<int,int> diff = {a-b,a-c};
            if(mp.count(diff)) maxln = max(maxln,i-mp[diff]);
            else mp[diff] = i;
        }


        int count = 1;                // longest xxx type counting
        for(int i =1;i<n;i++){
            if(s[i]==s[i-1]) count++;
            else {
                maxln = max(maxln,count);
                count = 1;
            }
        }
        maxln = max(maxln,count);


        maxln = max(maxln,hlpr('a','b',s));
        maxln = max(maxln,hlpr('b','c',s));
        maxln = max(maxln,hlpr('a','c',s));
    return maxln;
    }
};