class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(),ans=-1,min = INT_MAX;
        vector<int> pr(n+1) , po(n+1);
        pr[0] = 0 , po[n] = 0;int count =0;
        for(int i =0;i<n;i++){
            if(customers[i]=='N') count++;
            pr[i+1] = count;
        }
        count=0;
        for(int i =n-1;i>=0;i--){
            if( customers[i] == 'Y' ) count++;
            po[i] = count;
            pr[i]+=po[i];
        }
        // for(int i =0;i<=n;i++){
        //     pr[i]+=po[i];
        // }
        for(int i =0;i<=n;i++){
            if(pr[i]<min) {min = pr[i] ; ans = i;}
        }
        return ans;
    }
};
