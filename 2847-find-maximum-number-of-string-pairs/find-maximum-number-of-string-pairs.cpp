class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s; int n = words.size(),count=0;
        for(int i=0;i<n;i++){
            s.insert(words[i]);
        }
        for(int i =0;i<n;i++){
            string rv = words[i];
            reverse(rv.begin(),rv.end());
            if(rv==words[i]) continue;
            else if(s.find(rv) !=s.end()) { count++; s.erase(words[i]); }
        }
        return count;
    }
};