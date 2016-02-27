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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        if (p == NULL)                // 空链表
            return NULL;
        if (p->next == NULL)        // 单元素链表
            return head;
        
        p = head->next;
        ListNode* prev1 = head->next;
        ListNode* prev2 = head;
        while(p != NULL){
            p = p->next;
            prev1 -> next = prev2;
            prev2 = prev1;
            prev1 = p;
        }
        head->next = NULL;          // 原先的head变为tail,next指向NULL
        delete prev1;
        delete p;
        return prev2;
    }
};
