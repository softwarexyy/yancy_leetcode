class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int end = lists.size();
        return doMerge(lists, 0, end);
    }

    ListNode* doMerge(vector<ListNode*>& lists, int start, int end) {   
        if (start == end) {
            return nullptr;
        }
        if (end == start + 1) {
            return lists[start];
        }
        int mid = (start + end) >> 1;
        cout << mid << endl;
        ListNode *l1 = doMerge(lists, start, mid);
        ListNode *l2 = doMerge(lists, mid, end);
        
        // 前半段 + 后半段
        return merge2Lists(l1, l2);
    }

    // 合并两个有序链表
    ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
        ListNode *dummy_head = new ListNode();
        ListNode *p = dummy_head;
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
        return dummy_head->next;
    }
};

// ---------------------- 方法二 ----------------------------
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret = nullptr;
        for (int i = 0; i < lists.size(); i++) {
            ret = merge2Lists(ret, lists[i]);
        }
        return ret;
    }

    // 合并两个有序链表
    ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
        // print(l1, "l1");
        // print(l2, "l2");
        ListNode *dummy_head = new ListNode();
        ListNode *p = dummy_head;
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
        // print(dummy_head->next, "ret");
        return dummy_head->next;
    }
};
