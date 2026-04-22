class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string &q : queries){
            for(string &dict : dictionary){
                if(q.size() != dict.size()) continue;
                int count = 0;
                for(int i = 0;i<dict.size();i++){
                    if(q[i] != dict[i]) count++;
                    if(count > 2) break;
                }
            if(count<=2)  {ans.push_back(q);break;}

            }
        }
    return ans;
    }
};