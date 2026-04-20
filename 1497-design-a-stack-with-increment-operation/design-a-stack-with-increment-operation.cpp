class CustomStack {
public:
vector<int> nums;
vector<int> inc;
int siz;
    CustomStack(int maxSize) {
        siz = maxSize;
    }
    
    void push(int x) {
        if(nums.size()<siz){
        nums.push_back(x);
        inc.push_back(0);
        }
    }
    
    int pop() {
        if(nums.size()==0) return -1;
        else {
            int lastix = nums.size()-1;
            int ans = nums[lastix] + inc[lastix];
            if(lastix >= 1) inc[lastix-1] += inc[lastix];              // LAZY PROPOGATION 
            nums.pop_back();
            inc.pop_back();
            return ans;
        }
    }
    
    void increment(int k, int val) {
        // for(int i = 0;i< min(k,(int)nums.size());i++) nums[i] += val;
        int idx = min(k, (int)nums.size()) - 1;
        if (idx >= 0) inc[idx] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */