class LRUCache {
public:
    queue<int> q ;
    int sz ;
    unordered_map<int,int> mp , frq ;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(frq.count(key) == 0 ) return -1;
        q.push(key);
        frq[key]++;
        return mp[key];
    }
    
    void put(int key, int value) {
        q.push(key);
        mp[key] = value;
        frq[key]++;
        while(frq.size() > sz){
            int fr = q.front();
            q.pop();
            frq[fr]--;
            if(frq[fr] == 0) {frq.erase(fr); }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */