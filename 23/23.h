#ifndef _23_H_
#define _23_H_
#include "../general.h"
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

_LEETCODE23_BEGIN
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution { //320ms
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // LeetCode中测试用例会传入nullptr到vector中
        auto iter = std::remove(lists.begin(), lists.end(), nullptr);
        lists.erase(iter, lists.end());
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (!lists.empty()) {
            std::vector<int> tmp;
            for (int i = 0; i < lists.size(); ++i) {   
                tmp.push_back(lists[i]->val);
            }
            if (tmp.empty())
                break;
            auto pos = std::min_element(tmp.begin(), tmp.end());
            int j = pos - tmp.begin();
            cur->next = lists[j];
            cur = cur->next;
            if (lists[j]->next == nullptr)
                lists.erase(lists.begin() + j);
            else
            {
                lists[j] = lists[j]->next;
            }
        }     
        return dummy->next;
    }
};

class Solution2 { //24ms
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        std::priority_queue<int> pq;
        if (lists.empty())
            return nullptr;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* tmp = lists[i];
            while (tmp) {
                pq.push(tmp->val);
                tmp = tmp->next;
            }
        }

        while (!pq.empty()) {
            ListNode* tmp = new ListNode(pq.top());
            tmp->next = head->next;
            head->next = tmp;
            pq.pop();
        }

        return head->next;
    }
};
_LEETCODE23_END

#endif // !_23_H_

