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
    bool hasCycle(ListNode *head) {
        //slow and fast pointer apporch 
        //take somewhere around O(n) time complexity we can not pricieslysay O(n);
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;//if they are  colliding then their is the loop
        }

        return false;
    }
};