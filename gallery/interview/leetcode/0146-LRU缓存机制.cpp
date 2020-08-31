/*


https://leetcode-cn.com/explore/interview/card/bytedance/245/data-structure/1032/

https://leetcode-cn.com/problems/lru-cache/


*/



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache
{
private:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
public:
    LRUCache(int capacity)
    {   
        cap = capacity;
    }

    int get(int key)
    {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator it = m.find(key);
        if(it == m.end()) return -1;
        l.splice(l.begin(),l,it->second);
        return it->second->second;
    }

    void put(int key, int value)
    {
        auto it = m.find(key);
        if(it != m.end()) l.erase(it->second);

        if(l.size() == cap){
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k); //map可以根据key值和迭代器值移除，查找
        }
        
        l.push_front(make_pair(key,value));
        m[key] = l.begin();
    }
};
