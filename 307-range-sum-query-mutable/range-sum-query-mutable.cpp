class NumArray {
public:
vector<int> nums;
int siz ;
int ssiz ;
vector<int> summ;
    NumArray(vector<int>& nums) {
        this->nums = nums ;
        siz = nums.size();
        ssiz = ceil(sqrt(siz));
        summ.resize(ssiz,0);
        for(int i = 0;i<siz;i++) summ[i/ssiz] += nums[i];
    }
    
    void update(int index, int val) {
        summ[index/ssiz] += (val-nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int lblock = left/ssiz; int rblock = right/ssiz;
        int ans = 0;
        if(lblock == rblock) {
            for(int i = left ; i<=right;i++) ans +=nums[i];
        return ans;
        }
        int lastoflftblock = (lblock+1)*ssiz -1;
        int firstofrghtblock = rblock * ssiz;

        for(int i = left ; i <= lastoflftblock;i++) ans += nums[i];
        for(int i =1+ lblock ; i<rblock ; i++) ans += summ[i];
        for(int i = firstofrghtblock ; i <= right;i++) ans += nums[i];
    return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */