/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* preDelete = new ListNode;
        ListNode* newHead = preDelete;
        preDelete->next = head;
        ListNode* cur = head;
        int idx = 1;
        while (idx < n) {
            cur = cur->next;
            idx++;
        }
        while (cur->next != nullptr) {
            preDelete = preDelete->next;
            cur = cur->next;
        }
        preDelete->next = preDelete->next->next;
        return newHead->next;
    }
};
// @lc code=end

