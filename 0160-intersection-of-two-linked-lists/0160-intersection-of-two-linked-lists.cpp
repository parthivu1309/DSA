class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int n1 = 0, n2 = 0;

        ListNode* t1 = head1;
        ListNode* t2 = head2;

        // count length
        while(t1){
            n1++;
            t1 = t1->next;
        }
        while(t2){
            n2++;
            t2 = t2->next;
        }

        t1 = head1;
        t2 = head2;

        int diff = abs(n1 - n2);

        // move longer list
        if(n1 > n2){
            while(diff--) t1 = t1->next;
        } else {
            while(diff--) t2 = t2->next;
        }

        // move together
        while(t1 && t2){
            if(t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }

        return nullptr;
    }
};