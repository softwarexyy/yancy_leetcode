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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){  // merge 2 sorted lists
        ListNode* res = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* r = res;      // res的游标
        while (p!=NULL && q!=NULL){
            if (p->val <= q->val){
                ListNode* tmp = new ListNode(p->val);
                r->next = tmp;  // 加入res中
                p = p->next;    // p往后移
            }
            else{
                ListNode* tmp = new ListNode(q->val);
                r->next = tmp;
                q = q->next;
            }
            r = r->next;
        }
        if (p==NULL)        //剩下的l1为空
            r->next = q;
        else                //剩下的l2为空
            r->next = p;
        return res->next;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //两两合并，归并
        if (lists.size()==0)
            return NULL;
        if (lists.size()==1)
            return lists[0];
        if (lists.size() == 2)
            return merge2Lists(lists[0], lists[1]);
        
        else {
            vector<ListNode*> tmpLists1;    //前半段
            vector<ListNode*> tmpLists2;    //后半段
            for (int i=0; i<lists.size()/2; i++)
                tmpLists1.push_back(lists[i]);
            for (int i=lists.size()/2; i<lists.size(); i++)
                tmpLists2.push_back(lists[i]);
                
                
            ListNode* l1 = mergeKLists(tmpLists1);
            ListNode* l2 = mergeKLists(tmpLists2);
            return merge2Lists(l1, l2);
        }
    }
};

/***************************方法：******************************
  两两合并，归并排序思想
  ****************************************************************/
