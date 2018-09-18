#ifndef _219_H_
#define _219_H_
#include "..\general.h"

#include <map>
#include <queue>
#include <functional>
#include <vector>
using std::vector;

_LEETCODE219_BEGIN
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty() || 0 == k)
            return false;

        std::multimap<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m.insert(std::pair<int, int>(nums[i], i));
        }
        for (auto item = m.begin(); item != std::prev(m.end()); ++item) {
            if (item->first != std::next(item)->first)
                continue;

            auto last = std::next(item);
            while (last != m.end() && item->first == last->first) {
                std::advance(last, 1);
            }
            //[item, last)之间是相等区域
            std::priority_queue<int, vector<int>, std::greater<int>> pq;
            while (item != last) {
                pq.push(item->second);
                ++item;
            }
            int index1 = pq.top();
            pq.pop();
            while (!pq.empty()) {    
                int index2 = pq.top();
                pq.pop();
                if (std::abs(index1 - index2) <= k)
                    return true;
                index1 = index2;
            }
            item = last;
            if (item == m.end())
                break;
        }
        return false;
    }
};
_LEETCODE219_END
#endif // !_219_H_
