/***** Fourth Visit *****/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        for (int len=1; len<n; len*=2) {
            for (int i=0; i+len<n; i+=2*len) {
                lists[i]=mergeTwoLists(lists[i],lists[i+len]);
            }
        }
        return n==0?0:lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *header=new ListNode(), *tail=header;
        while (l1&&l2) {
            if (l1->val<l2->val) {tail->next=l1; l1=l1->next; }
            else {tail->next=l2; l2=l2->next;}
            tail=tail->next;
        }
        if (l1) tail->next=l1;
        if (l2) tail->next=l2;
        tail=header; header=header->next;
        delete tail;
        return header;
    }
};

/***** Third Visit *****/
/*
    0 1 2 3 4 5 6 7 8
    1 2 3 4 5 6 7 8 9
    ___ ___ ___ ___    len=1
    _______ _______    len=2
    _______________    len=4
    _________________  len=8
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int n=lists.size(), len=1;
        if (n==0) return 0;
        while (len<n) {
            for (int i=0; i+len<n; i+=2*len) {
                ListNode *t=merge(lists[i],lists[i+len]);
                lists[i]=t;
            }
            len*=2;
        }
        return lists[0];
    }

    ListNode* merge(ListNode *l1, ListNode *l2)
    {
        ListNode *header=new ListNode(), *tail=header;
        ListNode *p1=l1,*p2=l2;
        while (p1&&p2) {
            if (p1->val<p2->val) {tail->next=p1; p1=p1->next;}
            else {tail->next=p2; p2=p2->next;}
            tail=tail->next;
        }
        if (p1) tail->next=p1;
        else tail->next=p2;
        return header->next;
    }
};

/***** Second Visit *****/
 /*
     DIVIDE & CONQUER
     for each iteration, sort list[i],list[i+1]
     T: k+k/2+k/4+...k/k=O(klogk*m)/S:O(1)
     1 2 3 4 5 6 7 8 9
     ___ ___ ___ ___ _
       ___     ___   _
         _______     _
               _______
 */
 class Solution {
 public:
     ListNode* mergeKLists(vector<ListNode*>& lists)
     {
         int k=lists.size();
         if(k==0) return 0;
         for (int i=1; i<k; i*=2){
             for (int j=0; j+i<k; j+=2*i) {
                 lists[j]=merge2Lists(lists[j],lists[j+i]);
             }
         }
         return lists[0];
     }

     ListNode* merge2Lists(ListNode* l1, ListNode* l2)
     {
         ListNode *header=new ListNode(0);
         ListNode *p1=l1,*p2=l2, *cur=header;
         while(p1&&p2) {
             if (p1->val<=p2->val) {cur->next=p1; p1=p1->next;}
             else {cur->next=p2; p2=p2->next;}
             cur=cur->next;
         }
         if (p1) cur->next=p1;
         else cur->next=p2;
         cur=header->next; delete header;
         return cur;
     }
 };

/***** First Visit *****/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // divide & conquer
        // T: O(nlogk), S:O(1) in place.
        if (lists.size()==0) return 0;
        int skip = 1;
        while(skip < lists.size()) {
            for (int i=0; i<lists.size()-skip; i+=skip*2) {
                lists[i] = merge2Lists(lists[i], lists[i+skip]);
            }
            skip *= 2;
        }

        return lists[0];
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* header = new ListNode(0);
        ListNode* tail=header;
        while (l1&&l2) {
            if (l1->val < l2->val){
                tail->next = l1;
                l1=l1->next;
            }
            else{
                tail->next = l2;
                l2=l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        tail = header;
        header=header->next;
        delete tail;
        return header;

    }
};

/**********************************************/

// Another iterating  approach for divide & conquer
// Each iteration, we take first 2 entries to merge.
// T: O(nlogk), S: O(1)
ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}
