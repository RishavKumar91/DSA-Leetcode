class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n  = positions.size();
        
        vector<int> ix(n);
        for(int i = 0;i<n;i++) ix[i] = i;

        sort(ix.begin(), ix.end(), [&](int &a, int &b){
            return positions[a] < positions[b];
        });

        stack<int> fill;
        for(int i = 0;i<n;i++){
            int currix = ix[i];
            if(directions[currix]=='R') fill.push(currix);
            else{
                while(!fill.empty() && healths[currix] > 0){
                    int topix = fill.top();
                    fill.pop();

                    if(healths[topix]==healths[currix]){
                        healths[topix] = 0;
                        healths[currix] = 0;
                    }
                    else if(healths[topix] < healths[currix]){
                        healths[currix]--;
                        healths[topix] = 0;
                    }
                    else {
                        healths[topix]--;
                        fill.push(topix);
                        healths[currix] = 0;
                    }
                }
            }
        }


        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(healths[i] != 0) ans.push_back(healths[i]);
        }
        return ans;
    }
};