class LRUCache {
private:
    int size;
    unordered_map<int,list<pair<int,int>>::iterator> map;       //数据结构为 哈希链表
    list<pair<int,int>> cache;
public:
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        auto it=map.find(key);                    //在map中寻找 key对应的链表记录
        if(it==map.end()) return -1;               //如果没有找到就返回-1
        pair<int,int> tmp=*map[key];                //找到了，暂存pair(key,value) 用于后续更新链表
        cache.erase(map[key]);                      //将key,value重新放到链表表头，并返回value；
        cache.push_front(tmp);
        map[key]=cache.begin();
        return tmp.second;
    }
    
    void put(int key, int value) {
        if(map.find(key)==map.end()){                    //如果map中没有该key
            if(map.size()<size){                         //如果map的大小小于size
                cache.push_front(make_pair(key,value));  //直接在链表头部插入该(key,value)并在Map中更新
                map[key]=cache.begin();
            }else{
                auto tmp=cache.back();                        //否则在链表中删除最后的节点，并在map中删除该记录，再完成插入操作
                map.erase(tmp.first);
                cache.pop_back();
                cache.push_front(make_pair(key,value));
                map.insert(make_pair(key,cache.begin()));                
            }
        }else{                                             //在链表中删除该记录，然后再插入
            cache.erase(map[key]);
            cache.push_front(make_pair(key,value));
            map[key]=cache.begin();
        }
    }
};
