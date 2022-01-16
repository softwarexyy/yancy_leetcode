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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        // 链表总长度
        int length = 0;
        ListNode *p = head;
        while (p) {
            p = p->next;
            length++;
        }
 
        ListNode *dummyHead = new ListNode(0, head);
        // 根据子链表长度 两两merge
        for (int subListLength = 1; subListLength < length; subListLength <<= 1) {
            ListNode *cur = dummyHead->next; // 这里不能直接=head，因为一趟归并后，head就不一定在第一个了
            ListNode *prev = dummyHead;
            while (cur != nullptr) {
                ListNode *l1 = cur;         // l1头
                for (int i = 1; i < subListLength && cur->next != nullptr; i++) {
                    cur = cur->next;
                }   // 现在cur指向l1最后一个元素
                ListNode *l2 = cur->next;   // l2头
                cur->next = nullptr;        // l1尾：置为nullptr，方便merge操作
                cur = l2;   // 更新cur
                
                for (int i = 1; i < subListLength && cur != nullptr && cur->next != nullptr; i++) { 
                    // cur初始的时候可能就是nullptr，所以条件包含cur!=nullptr
                    cur = cur->next;
                }   // 现在cur指向l2最后一个元素(可能是nullptr)                
                if (cur != nullptr) {
                    ListNode *last = cur;   // 保存l2最后一个元素
                    cur = cur->next;        // 移动cur到后一个位置，准备下一轮循环
                    last->next = nullptr;   // l2尾：置为nullptr，方便merge操作
                }
                ListNode *merged = merge(l1, l2);
                prev->next = merged;    // 接上prev
                while (prev->next) {
                    prev = prev->next;
                }
            }
        }
        return dummyHead->next;

    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode();
        ListNode *p = ret;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return ret->next;
    }
};
