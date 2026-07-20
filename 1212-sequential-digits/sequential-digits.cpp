class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q; vector<int> ans;
        for(int i = 1 ;i < 9 ; i++){
            q.push(i);
        }
        while(!q.empty()){
            int now = q.front();
            q.pop();
            if(now > high) continue;
            if(now >= low) ans.push_back(now);
            if(now % 10 == 9) continue;
            q.push(now*10 + (now%10)+1);
        }
    return ans;
    }
};