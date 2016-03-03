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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL)
            return NULL;
        int listSize = 0;           //链表长度
        ListNode* p = head;
        ListNode* q = head;
        int Nth;                    //待删元素是顺序第几个
        for (p; p!=NULL; p=p->next)
            listSize++;
        
        Nth = listSize-n+1;
        if (Nth == 1)
            return head->next;      //如果要删除顺序第一个元素
        
        p = head;
        for (int i=1; i<Nth-1; i++){
            p = p->next;
            q = q->next;
        }
        q = p->next;        //q指向待删元素
        p->next = q->next;
        free(q);
        
        return head;
    }
};
