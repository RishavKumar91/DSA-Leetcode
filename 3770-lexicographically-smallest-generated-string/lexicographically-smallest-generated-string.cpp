class Solution {
public:
    string generateString(string str1, string str2) {
        int m = str1.size(),n = str2.size();
        string ans(m+n-1,'&');
        vector<int> canchang(m+n+1,0);


        for(int i = 0;i<str1.size();i++){
            if(str1[i]=='T'){
                for(int j = 0,k=i;j<n;j++,k++){
                    if(ans[k]!='&' && ans[k]!=str2[j]) return "";
                    ans[k] = str2[j] ;
                }
            }
        }


        for(int i =0;i<m+n-1;i++){
            if(ans[i]=='&'){
                canchang[i] = 1;
                ans[i] = 'a';
            }
        }

        for(int i = 0;i<m;i++){
            if(str1[i]=='F' && ans.substr(i,n)==str2){
                bool flag = 0;
                for(int k = i+n-1;k>=i;k--){
                    if(canchang[k]==1){
                        ans[k] ='b';
                        flag = 1;
                        break;
                    }
                }
            if(flag==0) return "";
            }
        }
    return  ans;
    }
};