class Solution {
public:
vector<int> sgmnt;
void build(int i, int start , int last,vector<int> &pairsum){
    if(start == last ) {
        sgmnt[i] =  pairsum[start];
        return;
    }
    int mi = start + (last-start)/2;
    build(i*2+1,start,mi,pairsum);
    build(i*2+2,mi+1,last,pairsum);
    sgmnt[i] = max(sgmnt[i*2+1] , sgmnt[i*2+2]);
    // return ;
}
int q(int i ,int ql , int qr , int l , int r ){
    if(ql>r || qr<l) return INT_MIN;
    if(ql <= l && r <= qr ) return sgmnt[i];
    int mi = l + (r-l)/2;
    return max(q(i*2+1,ql,qr,l,mi) , q(i*2+2 , ql,qr,mi+1,r) );
}
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int activestart = 0;
        int i  = 0 ;
        vector<int> startof0 , lastof0 ,sizeof0; 
        while(i<n){
            if(s[i] == '0'){
                int start = i;
                while(i<n && s[i] == '0') i++;
                startof0.push_back(start);
                lastof0.push_back(i-1);
                sizeof0.push_back(i-start);
            }
            else{
                i++;
                activestart++;
            }
        }
        if(sizeof0.size() <= 1) return vector<int> (queries.size() , activestart);
        vector<int> pairsum;
        for(int i = 0 ; i < sizeof0.size()-1 ; i++) pairsum.push_back(sizeof0[i] + sizeof0[i+1]);
        sgmnt.resize(pairsum.size()*4);
        build(0,0,pairsum.size()-1,pairsum);

        vector<int> ans;
        for(auto &qu : queries){
            int s = qu[0] , l = qu[1];
            int st = lower_bound(lastof0.begin(),lastof0.end(),s) -  lastof0.begin();
            int la = upper_bound(startof0.begin(),startof0.end(),l) - startof0.begin()-1;
            int maxpairsum = 0;
            if(st<la){
                int sta = lastof0[st] - max(startof0[st] , s) +1 ;
                int las = min(l,lastof0[la]) - startof0[la]+1;
                if(la-st == 1) maxpairsum = sta + las;
                else{
                    int pair1 = sta + sizeof0[st+1];
                    int pair2 = q(0,st+1 , la-2,0,pairsum.size()-1);
                    int pair3 = las + sizeof0[la-1];
                    maxpairsum = max({pair1,pair2,pair3});
                }
            }
            ans.push_back(activestart + maxpairsum);
        }
    return ans;
    }
};