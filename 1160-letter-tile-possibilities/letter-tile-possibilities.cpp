class Solution {
public:
int n;
vector<int> frq;
int ans = 0 ;
    void hlpr(){
        for(int i = 0 ; i < 26 ; i++){
            if(frq[i] == 0) continue ;
            ans++ ;
            frq[i]--;
            hlpr();
            frq[i]++;
        }
    }
    int numTilePossibilities(string t) {
        n = t.size();
        frq.assign(26,0);
        for(int i = 0 ; i < n ; i++){
            frq[t[i] - 'A']++;
        }
        hlpr();
    return ans;
    }
};