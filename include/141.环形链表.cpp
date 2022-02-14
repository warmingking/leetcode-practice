/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        ListNode* i = head;
        ListNode* j = head->next;
        while (i != NULL && j != NULL && j->next != NULL) {
            if (i == j) {
                return true;
            }
            i = i->next;
            j = j->next->next;
        }
        return false;
    }
};
// @lc code=end

