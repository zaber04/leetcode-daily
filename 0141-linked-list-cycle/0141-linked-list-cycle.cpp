/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// floyd's circle finder hare-tortoise algo
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (slow != nullptr && fast != nullptr) {
            slow = slow->next;

            if (fast->next == nullptr) {
                return false;
            }

            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        

        return false;
    }
};