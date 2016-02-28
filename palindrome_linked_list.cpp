/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head){
        if (head == NULL)
            return NULL;
        if (head -> next == NULL)
            return head;
        
        ListNode* p = head->next;
        ListNode* prev1 = p;
        ListNode* prev2 = head;
        while (p!=NULL){
            p = p->next;
            prev1->next = prev2;
            prev2 = prev1;
            prev1 = p;
        }
        head->next = NULL;
        delete prev1;
        delete p;
        return prev2;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL)           //empty
            return true;    
        if (head->next == NULL)     //only a head
            return true;

        ListNode* fast = head;      // slow and fast make slow point to the mid
        ListNode* slow = head;
        ListNode* slowPrev = NULL;      // slowPrev is the element before slow  
        while (fast!=NULL && fast->next!=NULL){ // 'fast!=NULL' means the size of the list is odd,'fast->next' means even
            fast = fast->next->next;
            if (fast==NULL || fast->next==NULL){
                slowPrev = slow;      
            }
            slow = slow->next;
        }
        slowPrev->next = NULL;                  //  slowPrev->next points to NULL
        ListNode* tail = reverseList(slow); // reverse the list after the slow pointer(the mid of the list)
        while(head!=NULL && tail!=NULL){
            if (head->val != tail->val){
                delete tail;
                return false;
            }
            head = head->next;
            tail = tail->next;
        }
        delete fast,slow,slowPrev,tail;
        return true;
    }
};
