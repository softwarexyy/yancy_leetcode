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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)       //空列表
            return NULL;
        if (head->next == NULL) //单元素列表
            return head;
            
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        
        ListNode* p = newhead;
        ListNode* q = head->next;
        while (true){
            p->next->next = q->next;
            q->next = p->next;
            p->next = q;
            
            if (q->next->next == NULL)
                break;
            if (q->next->next->next == NULL)
                break;

            p = q->next;
            q = q->next->next->next;   
        }
        return newhead->next;
    }
};
