class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points , (a,b)-> Integer.compare(a[1] , b[1] ));
        System.out.println(points[0][0]);
        int ans = 1 , last = points[0][1];
        for(int tmp[] : points){
            for(int x : tmp) {
                System.out.print(x+ " ");
            } System.out.println();
        }
        for(int i = 1 ; i < points.length ;  i++){
            if(points[i][0] > last){
                // System.out.print(points[i][0]);
                ans++;
                last =  points[i][1] ;
            } else {
                last = Math.min(last,points[i][1]) ; 
            }
        }
    return ans ;
    }
}