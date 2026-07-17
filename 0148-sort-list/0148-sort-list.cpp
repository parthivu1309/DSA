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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        if (head1 != nullptr) temp->next = head1;
        if (head2 != nullptr) temp->next = head2;

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head) {
        //base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;//you disconnect the links 

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(mid);

        return merge(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};