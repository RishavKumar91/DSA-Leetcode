class LRUCache {
public:
int sz ;
unordered_map<int,int > KV , frq ;
queue<int> q;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(!KV.count(key)) return -1;
        q.push(key);
        frq[key]++;
        return KV[key];
    }
    
    void put(int key, int value) {
        KV[key] = value;
        q.push(key);
        frq[key]++;
        while(frq.size() > sz ){
                int fr = q.front();
                q.pop();
                frq[fr]--;
                if(frq[fr] == 0){ frq.erase(fr); KV.erase(fr); }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */