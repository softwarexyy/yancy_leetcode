/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* reverse_n_nodes(ListNode* p, int n)            //从p开始，翻转n个元素,返回head指针
    {
        if (n==1)
            return p;
        if (n==2)
        {
            ListNode* q = p->next;
            p->next = q->next;
            q->next = p;
            return q;
        }
        ListNode* prev1 = p;
        ListNode* prev2 = p->next;
        ListNode* cur = p->next->next;
        int count = 1;
        while (count < n-1)
        {
            prev2->next = prev1;    //翻转
            prev1 = prev2;          //移位
            prev2 = cur;
            cur = cur->next;
            count ++;
        }
        prev2->next = prev1;
        p->next = cur;
        return prev2;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k==1)
            return head;

        int count = 0;      //元素个数
        ListNode* p = head;
        ListNode* newhead = head;
        while (p != NULL)
        {
            count ++;
            p = p->next;
        }
        if (count < k)
            return head;
        else
        {
            p = newhead;
            newhead = reverse_n_nodes(p, k);    //翻转第一组k个元素,返回头指针head,尾指针设为tailTmp
        }
        ListNode* tailTmp = newhead;
        count = k;
        while(count != 1)
        {
            tailTmp = tailTmp->next;
            count --;
        }

        bool moreThanK = false;  //剩余元素个数是否大于k
        while (true)
        {
            moreThanK = false;  // 测试剩余元素个数是否大于k个(从p开始有多少个元素)
            ListNode* tmpp = tailTmp;
            count = 0;
            while (tmpp->next != NULL)
            {
                count ++;
                if (count>=k)
                {
                    moreThanK = true;
                    break;
                }
                tmpp = tmpp->next;
            }
            if (moreThanK == false) //剩余元素不到k个
                break;

            ListNode* tmphead = reverse_n_nodes(tailTmp->next, k);      // 翻转k个元素
            cout << tmphead->val << endl;
            tailTmp->next = tmphead;
            //  将p移到p后第k个元素
            count = k;
            while(count != 1)
            {
                tmphead = tmphead->next;
                count --;
            }
            tailTmp = tmphead;
        }
        return newhead;
    }
};
