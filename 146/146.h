#ifndef _146_H_
#define _146_H_
#include "../general.h"
#include <map>
#include <list>
#include <algorithm>

_LEETCODE146_BEGIN
class LRUCache {
public:
    LRUCache(int capacity):cap(capacity) {

    }

    int get(int key) {
        auto item = m.find(key);
        if (item == m.end())
            return -1;

        auto key_item = std::find(l.begin(), l.end(), key);
        l.erase(key_item);
        l.push_back(key);

        return item->second;
    }

    void put(int key, int value) {
        if (m.size() < cap) { //����δ��
            if(m.find(key) == m.end()) //key����������
                l.push_back(key);
            else { //key��������
                auto item_key = std::find(l.begin(), l.end(), key);
                int old_key = *item_key;
                l.erase(item_key);
                l.push_back(old_key);
            }
            m[key] = value;
        }   
        else if (m.size() == cap && m.find(key) == m.end()) { //��������key����������
            int old_key = l.front();
            l.pop_front();
            l.push_back(key);
            m.erase(m.find(old_key));
            m[key] = value;
        }
        else if (m.size() == cap && m.find(key) != m.end()) {//��������key��������
            auto item_key = std::find(l.begin(), l.end(), key);
            int old_key = *item_key;
            l.erase(item_key);
            l.push_back(old_key);
            m[key] = value;
        }
    }
private:
    std::map<int, int> m;
    std::list<int> l;
    int cap;
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/
_LEETCODE146_END
#endif // !_146_H_

