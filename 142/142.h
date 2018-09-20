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
//        //�ж��Ƿ�Ϊ��
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
//        // ����count���ƶ���first�϶��ڻ��ڡ�����뻷λ����[0,count]֮���ĳ���ڵ㴦
//        first = head;
//        while (true) {
//            second = first->next;
//            for (int i = 0; i <= 2 * (count+1)-count; i++) { //second����count+1��
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

        // ע��������ָ���ƶ�һ������ָ���ƶ�������Ҫ��ͷ��ʼһ���ƶ�����Ȼ��������������
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

        // ����count���ƶ���first�϶��ڻ��ڡ�����뻷λ����[0,count]֮���ĳ���ڵ㴦
        // ��ͼ���Լ���first���뻷�ڵ�ľ������õ������ڵ����������뻷�ڵ�ľ���
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

