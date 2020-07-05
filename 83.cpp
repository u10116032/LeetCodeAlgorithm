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
    ListNode* deleteDuplicates(ListNode* head)
    {
        /*
        Note that our list is SORTED.
        we can always include first one node, and traverse entire list
        in each step, compare the current node's val with distinct ptr.
        */
        if (!head) return head;
        ListNode *header=head, *tail=head, *cur=head->next;
        while(cur) {
            if (cur->val!=tail->val) {
                tail->next=cur;
                tail=tail->next;
            }
            cur=cur->next;
        }
        tail->next=0;
        return header;
    }
};