class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t) return 1;
        // else return 0;

        int n = s.size();
        if(n!=t.size()) return 0;
        unordered_map<char ,int> mp;
        for(int i =0;i<n;i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(int i =0;i<n;i++)
        if(mp[s[i]] !=0) return 0;
    return 1;
    }
};