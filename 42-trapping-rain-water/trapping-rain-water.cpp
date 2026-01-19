class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(),wat=0;
        // vector<int > lftmax(n,0) , rgtmax(n,0);int lfttmax=0,rgttmax=0;
        // for(int i =1;i<n;i++){
        //     lfttmax = max(lfttmax,height[i-1]);
        //     lftmax[i] = lfttmax;
        // }
        // for(int i =n-2;i>=0;i--){
        //     rgttmax = max(rgttmax,height[i+1]);
        //     rgtmax[i] = rgttmax;
        // }
        // for(int i =0;i<n;i++){
        //     int minnn = min(rgtmax[i],lftmax[i]);
        //     if(minnn-height[i] >0 )
        //     wat = wat+minnn-height[i];
        // }
        int l = 0, r = n - 1,lmax = 0, rmax = 0, water = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] > lmax)
                    lmax = height[l];
                else
                    water += lmax - height[l];
                l++;
            } 
            else {
                if (height[r] > rmax)
                    rmax = height[r];
                else
                    water += rmax - height[r];
                r--;
            }
        }
    return water;
    }
};