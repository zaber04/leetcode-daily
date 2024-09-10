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
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }

        return gcd(b, a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* left = head;
        ListNode* right = head->next;

        while (right != nullptr) {
            int val = gcd(left->val, right->val);

            ListNode* middle = new ListNode(val);

            left->next = middle;
            middle->next = right;

            left = right;
            right = right->next;
        }

        return head;
    }
};