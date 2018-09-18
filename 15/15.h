#ifndef _15_H_
#define _15_H_
#include "../general.h"
#include <vector>
#include <algorithm>
using std::vector;

_LEETCODE15_BEGIN
class Solution { //“—≈≈–Ú ˝¡–
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty())
            return res;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int tmp = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == (-1)*tmp) {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    res.push_back(v);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1] && nums[right] == nums[right + 1])
                    {
                        left++;
                        right--;
                    }
                }
                else if (nums[left] + nums[right] < (-1)*tmp) {
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
                else
                {
                    right--;
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }

        }
        return res;
    }
};

_LEETCODE15_END
#endif // !_15_H_

