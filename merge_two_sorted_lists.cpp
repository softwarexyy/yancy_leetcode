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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* res = new ListNode(0);   //存放结果
        ListNode* pres = res;   //结果链表里的游标
        while (p!=NULL && q!=NULL){
            if (p->val <= q->val){
                ListNode *tmp = new ListNode(p->val);
                pres->next = tmp;
                p = p->next;
            }
            else {
                ListNode *tmp = new ListNode(q->val);
                pres->next = tmp;
                q = q->next;
            }
            pres = pres->next;
        }
        if (p==NULL)
            pres->next = q;
        else
            pres->next = p;
            
        return res->next;
    }
};
