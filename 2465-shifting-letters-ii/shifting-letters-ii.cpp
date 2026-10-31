class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        vector<int> shiftDAT(n + 1, 0);

        for(auto &tmp : shifts) {
            if(tmp[2] == 1) {
                shiftDAT[tmp[0]]++;
                shiftDAT[tmp[1] + 1]--;
            }
            else {
                shiftDAT[tmp[0]]--;
                shiftDAT[tmp[1] + 1]++;
            }
        }

        int shiftsum = 0;

        for(int i = 0; i < n; i++) {
            shiftsum += shiftDAT[i];

            int ch = s[i] - 'a';
            ch += shiftsum;
            ch = (ch % 26 + 26) % 26;

            s[i] = ch + 'a';
        }

        return s;
    }
};