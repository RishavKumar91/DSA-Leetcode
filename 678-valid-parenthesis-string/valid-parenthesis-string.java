class Solution {
    boolean hlpr(int ix , String s ,int opncount ){
        if(ix == s.length()) return opncount == 0 ;  
        if(s.charAt(ix) == '(') return hlpr(ix+1,s,opncount+1);
        else if(s.charAt(ix) == '*'){
            return hlpr(ix+1,s,opncount+1) || hlpr(ix+1,s,opncount) || hlpr(ix+1,s,opncount-1) ;
        }
        else if(opncount > 0 ) return hlpr(ix+1,s,opncount-1);
    return false ;  
    }
    public boolean checkValidString(String s) {
        // return hlpr(0,s,0);

        Stack<Integer> opnst = new Stack<>();
        Stack<Integer> starst = new Stack<>();
        for(int i = 0 ; i < s.length() ; i++){
            char ch = s.charAt(i);
            if(ch == '(') opnst.add(i);
            else if(ch == '*') starst.add(i);
            else {
                if( opnst.empty() && starst.empty() ) return false;
                else if( !opnst.empty()  ) opnst.pop();
                else if ( !starst.empty() )   starst.pop();
            }
        }
        System.out.println(opnst +"  " + starst);
        while(opnst.size() > 0  && starst.size() > 0 && opnst.peek() < starst.peek()) {
            starst.pop() ; opnst.pop();
        }
    return opnst.empty() ;
    }
}