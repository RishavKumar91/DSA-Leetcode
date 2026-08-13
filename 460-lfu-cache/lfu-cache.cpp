class LFUCache {
public:
    int cap , minfrq;
    unordered_map<int , pair<int,int>> valfrq;
    unordered_map<int , list<int> > listoffrq;
    unordered_map<int , list<int>::iterator > LLit;
    LFUCache(int capacity) {
        cap = capacity ;
        minfrq = 0 ;
    }
    
    int get(int key) {
        if(!valfrq.count(key)) return -1;
        int val = valfrq[key].first;
        int frq = valfrq[key].second;
        listoffrq[frq].erase(LLit[key]);
        listoffrq[frq+1].push_front(key);
        LLit[key] = listoffrq[frq+1].begin();
        valfrq[key].second++;
        
        if(minfrq == frq && listoffrq[frq].empty()){
            minfrq++;
        }
        return val;

    }
    
    void put(int key, int value) {
        if(valfrq.count(key)){
            valfrq[key].first = value;
            get(key);
            return ;
        }
        if(valfrq.size() == cap){
            int oldkey = listoffrq[minfrq].back();
            listoffrq[minfrq].pop_back();
            valfrq.erase(oldkey);
            LLit.erase(oldkey);
        }
        minfrq = 1;
        valfrq[key] = {value,1};
        listoffrq[1].push_front(key);
        LLit[key] = listoffrq[1].begin();

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */