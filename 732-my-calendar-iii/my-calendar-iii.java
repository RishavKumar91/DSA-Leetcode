class MyCalendarThree {
    TreeMap<Integer,Integer> event ; 
    public MyCalendarThree() {
        event = new TreeMap<>();
    }
    
    public int book(int startTime, int endTime) {
        event.put(startTime , event.getOrDefault(startTime,0) + 1 ) ;
        event.put(endTime , event.getOrDefault(endTime  ,0) - 1 ) ;
        int i = 0 , ans = 1 ;
        for(int delta:event.values()){
            i+=delta;
            ans=Math.max(ans,i);
        }
    return ans ;
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(startTime,endTime);
 */