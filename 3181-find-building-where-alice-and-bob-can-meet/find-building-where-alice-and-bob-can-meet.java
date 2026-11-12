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
    int qury(int start , int threshold , int ix , int l , int  r , int heights[] ){
        if(r < start ) return -1 ;
        if(heights[sgmt[ix]] <= threshold ) return -1 ;
        if(l == r) return l ; 

        int mid = l + (r - l) / 2 ;
        int lft = qury(start,threshold,ix*2+1,l,mid,heights);
        if(lft != -1) return lft ;
        return qury(start,threshold,ix*2+2,mid+1,r,heights);
    }
    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        n = heights.length ;
        sgmt = new int[4*n] ;
        build(heights,0,0,n-1);
        int ans[] = new int[queries.length]; int i = 0 ;
        for(int q[] : queries){
            int lft = Math.min(q[0],q[1]) , rgt = Math.max(q[0],q[1]) ; 
            int ansnow = qury(rgt , heights[lft] ,0,0,n-1,heights );
            if(lft == rgt) ans[i++] = lft ; 
            else ans[i++] = ansnow ; 
        }
    return ans ;
    }
}