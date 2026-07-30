class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<vector<char>> g(numRows);
        int i = 0 ; 
        bool flag = 1;
        for(char &ch : s){
            g[i].push_back(ch);
            if(flag == 1) i++;
            else i--;
            if(i == numRows){ i = numRows-2 ; flag = !flag ;}
            if(i==-1) { i = 1 ; flag = !flag ;}
        }
        string ans = "";
        for(int i = 0 ; i < numRows ; i++){
            for(char &ch : g[i]){
                ans.push_back(ch);
            }
        }
    return ans;
    }
};