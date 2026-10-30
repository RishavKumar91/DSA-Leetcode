class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length(); 
        int shiftDAT[] = new int[n+1];
        for(int tmp[] : shifts){
            if(tmp[2] == 1){
                shiftDAT[tmp[0]]++;
                shiftDAT[tmp[1]+1]--;
            } else {
                shiftDAT[tmp[0]]--;
                shiftDAT[tmp[1]+1]++;
            }
        }
        StringBuilder ans = new StringBuilder("");
        int shiftsum = 0 ;
        for(int i = 0 ; i < n ; i++){
            shiftsum += shiftDAT[i];
            int ch = s.charAt(i) - 'a';
            ch += shiftsum;
            ch = ( ch%26 + 26 ) % 26 ;
            ans.append((char) (ch + 'a'));
        }
    return new String(ans);
    }
}