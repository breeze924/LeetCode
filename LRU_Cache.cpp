class LRUCache{
public:
    struct node {
        int key;
        int value;
        
        node(int key_,int value_): key(key_),value(value_) {
            
        }
    };
    
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->sz=0;
    }
    
    int get(int key) {
        auto it=help.find(key);
        if(it!=help.end()) {
            int value=(it->second)->value;
            splice(it->second);
            return value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto it=help.find(key);
        if(it!=help.end()) {
            it->second->value=value;
            splice(it->second);
        }
        else {
            help[key]=cache.emplace(cache.end(),key,value);
            ++sz;
            if(sz>capacity) {
                help.erase(cache.begin()->key);
                cache.erase(cache.begin());
                --sz;
            }
        }
    }
    
private:
    inline void splice(list<node>::iterator d_it) {
        cache.splice(cache.end(),cache,d_it);
    }
    
    unordered_map<int,list<node>::iterator> help;
    list<node> cache;
    int capacity;
    int sz;
};

