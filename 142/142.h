#ifndef _142_H_
#define _142_H_
#include "../142/142.h"
#include <ctime>

_LEETCODE142_BEGIN
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    ListNode *detectCycle(ListNode *head, ostream& os) {
//        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
//            return nullptr;
//
//        //判断是否为环
//        ListNode* first = head;
//        ListNode* second = head->next->next;
//        int count = 0;
//        while (first != nullptr && second != nullptr && first != second) {
//            if (second->next == nullptr || second->next->next == nullptr)
//                break;
//            second = second->next->next;
//            first = first->next;
//            count++;
//        }
//        if (first != second)
//            return nullptr;
//
//        if (0 == count)
//            return head;
//
//        clock_t start_time = clock();
//        // 经过count次移动，first肯定在环内。因此入环位置在[0,count]之间的某个节点处
//        first = head;
//        while (true) {
//            second = first->next;
//            for (int i = 0; i <= 2 * (count+1)-count; i++) { //second走了count+1步
//                if (first == second)
//                    break;
//                second = second->next;
//            }
//            if (first == second) {
//                break;
//            }
//            first = first->next;
//        }
//        os << float(clock() - start_time) / CLOCKS_PER_SEC << endl;
//        return first; 
//    }
//};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        // 注意这里慢指针移动一步，快指针移动两步。要从头开始一起移动，不然后面计算距离会出错。
        ListNode* first = head->next;
        ListNode* second = head->next->next;
        while (first != second) {
            if (second == nullptr || second->next == nullptr)
                break;
            second = second->next->next;
            first = first->next;
        }
        if (first != second)
            return nullptr;

        // 经过count次移动，first肯定在环内。因此入环位置在[0,count]之间的某个节点处
        // 画图可以计算first到入环节点的距离正好等于两节点遇见处到入环节点的距离
        first = head;
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};
_LEETCODE142_END
#endif // !_142_H_

