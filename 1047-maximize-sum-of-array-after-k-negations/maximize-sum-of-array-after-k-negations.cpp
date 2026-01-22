class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> hp;
        int sum=0; int n = nums.size();
        for(int i =0;i<n;i++){
            hp.push(nums[i]);
            sum+=nums[i];
        }
        while(k!=0){
            if(hp.top()==0) return sum;
            else if(hp.top()<0) sum+= 2*-hp.top();
            else  sum -= 2*hp.top();
            int o = hp.top();
            hp.pop();
            hp.push(-o);
            k--;
        }
    return sum;
    }
};