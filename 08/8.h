#ifndef _8_H_
#define _8_H_
#include "../general.h"
#include <string>
using std::string;

_LEETCODE8_BEGIN
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;

        const int max_int = (int)((unsigned)~0 >> 1);
        const int min_int = -(int)((unsigned)~0 >> 1) - 1;
        int sign = 1;
        long long n = 0;
        int i = 0;
        while (i < str.size() && str[i] == ' ')
        { //跳过开始的空格字符
            i++;
        }

        //设置符号
        if (i < str.size() && str[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < str.size() && str[i] == '+')
            i++;

        for (; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9' && n <= max_int) {
                n = n * 10 + (str[i] - '0');
            }
            else {
                break;
            }
        }
        n = sign*n;
        if (n > max_int)
            n = max_int;
        else if (n < min_int)
            n = min_int;

        return n;
    }
};
_LEETCODE8_END
#endif // !_8_H_

