#ifndef _217_H_
#define _217_H_
#include "../general.h"
#include <set>
#include <vector>
using std::vector;

_LEETCODE217_BEGIN
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())
            return false;

        std::set<int> s(nums.begin(), nums.end());
        return (s.size() < nums.size());
    }
};
_LEETCODE217_END
#endif // !_217_H_
