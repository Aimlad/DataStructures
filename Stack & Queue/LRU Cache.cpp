//LRU Cache
//Leet Code


class LRUCache {
public:
    map <int,list<pair< int,int>>::iterator > hash;
    list <pair< int,int>> q;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }

    int get(int key) {
        if(hash.find(key)==hash.end())
            return -1;
        int val=hash[key]->second;
        put(key,val);
        return val;

    }

    void put(int key, int value) {
        if(hash.find(key)!=hash.end()){
            q.erase(hash[key]);
            q.push_front(make_pair(key,value));
            hash[key]=q.begin();
            return;
        }
        else{
            q.push_front(make_pair(key,value));
            hash[key]=q.begin();
        }

        if(q.size()>capacity){
            pair<int,int> p=q.back();
            hash.erase(p.first);
            q.pop_back();

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
