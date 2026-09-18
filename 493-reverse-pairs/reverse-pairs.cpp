class Solution {
public:
    int inversion(vector<int> &a,vector<int> &b){
    long long count=0,i=0,j=0;
    while(i<a.size()&& j<b.size()){
        if(a[i] > 1LL * 2 *  b[j]) {count+=a.size()-i; j++;}
        else i++;

    }
    return count;
}
void mergee(vector<int>a1,vector<int> a2,vector<int> &r){
    int i =0,j=0,k=0;
    while(i<a1.size() && j<a2.size()){
        if(a1[i]<=a2[j]) r[k++] = a1[i++];
        else r[k++]  = a2[j++];
    }
    while(i<a1.size()) r[k++] = a1[i++];
    while(j<a2.size()) r[k++] = a2[j++];
}
int mergesort(vector<int> &v){
    int count =0;
    int n = v.size();
    if(n==1 ) return 0;
    int n1= n/2 , n2=n-n1;
    vector<int> v1(n1), v2(n2);
    for(int i = 0;i<n1;i++ ) v1[i] = v[i];
    for(int i =0 ;i<n2;i++) v2[i] = v[i+n1]; 
    count+=mergesort(v1) ;   count+=mergesort(v2);
    count+=inversion(v1,v2);
    mergee(v1,v2,v); 
    v1.clear(); v2.clear();
    return count;
}
    // void mrgsort(vector<int> &arr,int first , int mi , int last){
    //     if()
    // }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums);
    }
};