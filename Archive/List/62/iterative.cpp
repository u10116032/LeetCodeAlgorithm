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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len=1;
        ListNode* tail=head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next=head;
        int index=k%len;
        tail=head; ListNode* newTail;
        for (int i=0; i< len-index; ++i) {
            newTail=tail;
            tail=tail->next;
        }
        newTail->next=0;
        return tail;
    }
};
