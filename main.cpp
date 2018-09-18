// main.cpp ≤‚ ‘À˘”–LeetCode

#include <iostream>
using namespace std;

#include "./15/15.h"
#include <vector>
namespace zl15 {
    void test() {
        vector<int> v = { 1,-1,-1,0,2,3,4,5,-1,-3 };

        leetcode15::Solution s;
        vector<vector<int>> res;
        res = s.threeSum(v);

        for (auto vec : res) {
            for (int i = 0; i < vec.size(); i++) {
                std::cout << vec[i] << " ";
            }
            std::cout << std::endl;
        }
    }
}

#include "23\23.h"
#include <ctime>
#include <cstdlib>
#include <vector>
using leetcode23::ListNode;

namespace zl23 {
    ListNode* trans_to_list(vector<int>& v) {
        if (v.empty())
            return nullptr;

        ListNode* head = new ListNode(0);
        for (auto val : v) {
            ListNode* tmp = new ListNode(val);
            tmp->next = head->next;
            head->next = tmp;
        }
        return head->next;
    }

    void display(ListNode* l) {
        if (l == nullptr)
            return;

        while (l) {
            cout << l->val << ",";
            l = l->next;
        }
        cout << endl;
    }

    void test() {
        vector<int> v1 = { 9,4 };
        vector<int> v2 = { 2,1 };
        vector<int> v3 = { 3,1 };
        vector<int> v4;

        for (int i = 0; i < 500000; i++) {
            v4.push_back(rand() % 50000);
        }

        ListNode* l1 = trans_to_list(v1);
        ListNode* l2 = trans_to_list(v2);
        ListNode* l3 = trans_to_list(v3);
        ListNode* l4 = trans_to_list(v4);

        vector<ListNode*> v = { l1,l2,l3,l4 };
        leetcode23::Solution s;

        clock_t start_time = clock();
        ListNode* head = s.mergeKLists(v);
        cout << float(clock() - start_time) / CLOCKS_PER_SEC << endl;
        //display(head);

        leetcode23::Solution2 s2;

        start_time = clock();
        ListNode* head2 = s2.mergeKLists(v);
        cout << float(clock() - start_time) / CLOCKS_PER_SEC << endl;
        //display(head2);
    }
}

#include "08\8.h"
#include <string>
namespace zl08 {
    void test() {
        leetcode8::Solution s;
        std::string str = "42";
        int res = s.myAtoi(str);
        cout << res << endl;

        str = "   -42";
        cout << s.myAtoi(str) << endl;

        str = "4193 with words";
        cout << s.myAtoi(str) << endl;

        str = "words and 987";
        cout << s.myAtoi(str) << endl;

        str = "-91283472332";
        cout << s.myAtoi(str) << endl;

        str = "9223372036854775808";
        cout << s.myAtoi(str) << endl;
    }
    
}

#include "146\146.h"
namespace zl146 {
    void test() {
        leetcode146::LRUCache lru(2);
        lru.put(2, 1);
        lru.put(1, 1);
        lru.put(2, 3);
        lru.put(4, 1);
        cout << "lru.get(1)=" << lru.get(1) << endl;
        cout << "lru.get(2)=" << lru.get(2) << endl;
    }
}

#include "217\217.h"
namespace zl217 {
    void test() {
        vector<int> nums = {1,2,3,4};
        leetcode217::Solution s;
        cout << s.containsDuplicate(nums) << endl;
    }
}

#include "219\219.h"
namespace zl219 {
    void test() {
        leetcode219::Solution s;
        vector<int> nums = { 1,2,1 };
        cout << s.containsNearbyDuplicate(nums, 0) << endl;
    }
}

int main() {
    //zl08::test();
    //zl15::test();
    //zl23::test();
    //zl146::test();
    //zl217::test();
    zl219::test();
}