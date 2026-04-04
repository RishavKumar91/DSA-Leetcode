class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int  l = encodedText.size();
        int colum = l/rows;
        string ans = "";
        for(int col = 0;col<colum ;col ++ ){
            for(int j = col ; j<l;j+=colum+1)
            ans.push_back(encodedText[j]);
        }
        while( ans.size()!=0  && ans[ans.size()-1]==' ')
            ans.pop_back();
    return ans;
    }
};