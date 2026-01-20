class Solution {
public:
    long long cc(int mi,vector<int> piles){
        long long c = 0;
        for(int i =0;i<piles.size();i++){
            if(mi>=piles[i]) c++;
            else if(piles[i]%mi==0)  c+= (long long)piles[i]/mi;
            else {c = c+  (long long)piles[i]/mi; c++;}
        }
        return c;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n = piles.size(),minn ,first= 1,last =INT_MIN,ans =0;
        for(int i =0;i<n;i++){
            last = max(last,piles[i]);
        }
        while(first<=last){
            int mi = first+(last-first)/2;
            long long hour = cc(mi,piles);
            if(hour<= (long long)h) last = mi-1;
            else first = mi+1;
        }
        return first;;
    }
};