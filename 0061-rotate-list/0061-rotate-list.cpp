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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }

        if (head->next == NULL) {
            return head;
        }

        ListNode* previousTail = head;
        int length;

        for (length = 1; previousTail->next != NULL; length++) {
            previousTail = previousTail->next;
        }

        previousTail->next = head;

        k %= length;

        ListNode* newTail = head;

        for (int i = 0; i < length-k-1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};