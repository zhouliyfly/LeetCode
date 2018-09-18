#ifndef _220_H_
#define _220_H_
#include "../general.h"
#include <vector>
#include <set>
#include <algorithm>
using std::vector;

_LEETCODE220_BEGIN
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty() || k == 0)
            return false;

        int n = std::min((int)nums.size(), k + 1);
        std::multiset<int> s;
        for (int i = 0; i < n; i++) {
            if (s.size() < 1) {
                s.insert(nums[i]);
                continue;
            }
       
            auto item = s.lower_bound(nums[i]);
            if (item == s.end()) {
                if (std::abs(*(std::prev(item)) - (long long)nums[i]) <= t)
                    return true;
            }
            else {
                if (std::abs(*item - (long long)nums[i]) <= t)
                    return true;
                if (item != s.begin()) {
                    if (std::abs(*(std::prev(item)) - (long long)nums[i]) <= t)
                        return true;
                }
            } 
            s.insert(nums[i]);       
        }
        int start = 0;
        while (n < nums.size()) {
            s.erase(nums[start]);
            if (s.size() < 1) {
                s.insert(nums[n]);
                continue;
            }
            auto item = s.lower_bound(nums[n]);
            if (item == s.end()) {
                if (std::abs(*(std::prev(item)) - (long long)nums[n]) <= t)
                    return true;
            }
            else {
                if (std::abs(*item - (long long)nums[n]) <= t)
                    return true;
                if (item != s.begin()) {
                    if (std::abs(*(std::prev(item)) - (long long)nums[n]) <= t)
                        return true;
                }
            }
    
            s.insert(nums[n]);
            start++;
            n++;
        }
        return false;
    }
};
_LEETCODE220_END
#endif // !_220_H_
