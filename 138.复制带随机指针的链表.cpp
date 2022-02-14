/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* n = head;
        while (n != NULL) {
            Node* tmp = new Node(n->val);
            tmp->next = n->next;
            n->next = tmp;
            n = tmp->next;
        }
        n = head;
        while (n != NULL) {
            Node* newNode = n->next;
            Node* tmp = newNode->next;
            if (n->random != NULL) {
                newNode->random = n->random->next;
            }
            n = tmp;
        }
        Node* newHead = head->next;
        n = head;
        while (n != NULL) {
            Node* newNode = n->next;
            Node* oldNextNode = newNode->next;
            if (oldNextNode != NULL) {
                newNode->next = oldNextNode->next;
            }
            n->next = oldNextNode;
            n = n->next;
        }
        return newHead;
    }
};
// @lc code=end

