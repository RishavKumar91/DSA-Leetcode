class Solution {
    int sgmt[] ;
    int n ;
    void build(int[] heights,int i , int l , int r ){
        if(l == r){
            sgmt[i] = l ; 
            return ;
        }
        int mi = l + (r-l)/2 ;
        build(heights , i * 2 + 1 , l  , mi);
        build(heights , i * 2 + 2 , mi+1 ,r);
        sgmt[i] = heights[sgmt[2*i+1]] >= heights[sgmt[2*i+2]] ? sgmt[2*i+1] : sgmt[2*i+2]; 
    }
    int qury(int start , int last , int ix , int l , int  r , int heights[] ){
        if(start > r || last < l) return -1;
        if(start <=l && last >= r){
            return sgmt[ix];
        }
        int mid = l + (r - l) / 2 ;
        int lft = qury(start,last,ix*2+1,l,mid,heights);
        int rgt = qury(start,last,ix*2+2,mid+1,r,heights);
        if(lft == -1) return rgt ;
        if(rgt == -1) return lft ;
        return heights[lft] >= heights[rgt] ? lft : rgt ; 
    }
    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        n = heights.length ;
        sgmt = new int[4*n] ;
        build(heights,0,0,n-1);
        int ans[] = new int[queries.length]; int i = 0 ;
        for(int q[] : queries){
           int lft = Math.min(q[0], q[1]);
            int rgt = Math.max(q[0], q[1]);

            int start = rgt;
            int last = n-1;
            int ansnow = -1;

            while(start <= last) {
                int mid = start + (last-start)/2;

                int currans = qury(start, mid, 0, 0, n-1, heights);

                if(currans != -1 &&
                   (currans == lft || heights[currans] > heights[lft])) {

                    ansnow = mid;
                    last = mid-1;
                }
                else {
                    start = mid+1;
                }
            }
            ans[i++] = ansnow ; 
        }
    return ans ;
    }
}