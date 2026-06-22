class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(char &ch : text) mp[ch]++;
        return min({mp['a'] , mp['b'] , mp['n'] , mp['l']/2 , mp['o']/2});
    }
};