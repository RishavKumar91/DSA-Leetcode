class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q ; 
        for(int i = 1; i <= 9 ; i++){
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(top >=low && top <=high) ans.push_back(top);
            int last = top%10 ; if(last == 9) continue;
            if(top*10 + last+1 <= high ) q.push(top*10 + last+1);
        }
    return ans;
    }
};