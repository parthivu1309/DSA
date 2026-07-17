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
    // Function to reverse a linked list using the recursive approach
ListNode* reverseLinkedList(ListNode* head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;  // No change is needed; return the current head
    }

    // Recursive step: Reverse the remaining part of the list and get the new head
    ListNode* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front' to reverse the link
    ListNode* front = head->next;

    // Update the 'next' pointer of 'front' to point to the current head
    front->next = head;

    // Set the 'next' pointer of the current head to null to break the original link
    head->next = NULL;

    // Return the new head obtained from the recursion
    return newHead;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(ListNode* head) {
    // Check if the linked list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return true;  // It's a palindrome by definition
    }

    // Initialize two pointers, slow and fast, to find the middle of the linked list
    ListNode* slow = head;
    ListNode* fast = head;

    // Traverse the linked list to find the middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;       // Move slow pointer one step at a time
        fast = fast->next->next; // Move fast pointer two steps at a time
    }

    // Reverse the second half of the linked list starting from the middle
    ListNode* newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    ListNode* first = head;

    // Pointer to the reversed second half
    ListNode* second = newHead;

    // Compare data values of nodes from both halves
    while (second != NULL) {
        if (first->val != second->val) {
            // If values do not match, the list is not a palindrome
            reverseLinkedList(newHead);  // Reverse the second half back to its original state
            return false;
        }

        first = first->next;  // Move the first pointer
        second = second->next; // Move the second pointer
    }

    // Reverse the second half back to its original state
    reverseLinkedList(newHead);

    // The linked list is a palindrome
    return true;
}
};