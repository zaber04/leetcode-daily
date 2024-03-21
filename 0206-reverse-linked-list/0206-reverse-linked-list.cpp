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
// https://leetcode.com/problems/reverse-linked-list/description/comments/1716755
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* reverseListTail  = nullptr;
        ListNode* originalListHead = head;

        while (originalListHead != nullptr) {
            ListNode* temp = originalListHead->next;
            originalListHead->next = reverseListTail;
            reverseListTail = originalListHead;
            originalListHead = temp;
        }

        return reverseListTail;
    }
};