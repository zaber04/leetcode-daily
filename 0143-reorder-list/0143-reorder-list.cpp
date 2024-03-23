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
    void reorderList(ListNode* head) {
        if (head == NULL) {
            return;
        }

        // find the middle of linked list [Problem 876]
        // in 1->2->3->4->5->6 find 4 
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast ->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second part of the list [Problem 206]
        // convert 1->2->3->4->5->6 into 1->2->3->4 and 6->5->4
        // reverse the second half in-place
        ListNode* previous = NULL;
        ListNode* current = slow;
        ListNode* temp = NULL;

        while (current != NULL) {
            temp = current->next;

            current->next = previous;
            previous = current;
            current = temp;
        }

        // merge two sorted linked lists [Problem 21]
        // merge 1->2->3->4 and 6->5->4 into 1->6->2->5->3->4
        ListNode *first = head;
        ListNode *second = previous;

        while (second->next != NULL) {
            temp = first->next;
            first->next = second;
            first = temp;

            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};