class Solution {
    public String reverseWords(String s) {
        int i = 0 , vwlcount = 0 , n = s.length(); 
        StringBuilder sb = new StringBuilder("") ; 
        while(i < n && s.charAt(i) != ' '){
            if(s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i)=='i' || s.charAt(i)=='o'
            || s.charAt(i) == 'u' ) vwlcount++;
        i++; 
        }
        int currvwl = 0 , start = i+1 ; i++;
        StringBuilder tmp = new StringBuilder();
        sb.append(s.substring(0,i-1));
        if(i >= n) return new String(sb) ;
        while(i < n ){
            if(s.charAt(i) == ' '){
                // StringBuilder tmp = new StringBuilder(s.substring(start,i));

                if(currvwl == vwlcount) tmp.reverse() ;
                sb.append(" " + tmp);
                i++;
                currvwl = 0 ;
                start = i ;
                tmp = new StringBuilder();
            } else {
                if(s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i)=='i' || s.charAt(i)=='o'
                || s.charAt(i) == 'u' ) currvwl++;
                tmp.append(s.charAt(i));
                i++;
            }
        }
        if(currvwl == vwlcount) tmp.reverse() ;
        sb.append(" " + tmp);
    return new String(sb) ; 
    }
}