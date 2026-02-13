class RecentCounter {
public:
int count;
vector<int> v;
deque<int> p;
    RecentCounter() {
        count = 0;
    }
    
    int ping(int t) {
        p.push_back(t);
        while(p.front() < p.back()-3000)
        p.pop_front();
        int count = p.size();
        return count;


        // v.push_back(t);
        // int n = v.size();
        // int mx = v[n-1];
        // int i =n-1;
        // while( i>=0 && v[i] > v[n-1]-3000){
        //     count++;
        //     i--;
        // }
        // return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */