/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = head;
        while (ans != nullptr && ans->val == val) {
            ans = ans->next;
        }
        if (ans == nullptr) {
            return ans;
        }
        ListNode* preNode = ans;
        ListNode* curNode = ans->next;
        while (curNode != nullptr) {
            if (curNode->val == val) {
                preNode->next = curNode->next;
            } else {
                preNode = preNode->next;
            }
            curNode = curNode->next;
        }
        return ans;
    }
};
// @lc code=end

