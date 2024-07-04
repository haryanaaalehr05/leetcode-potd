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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0); // Dummy node to simplify edge cases
        ListNode* current = dummy; // Pointer to build the new list
        ListNode* iterator = head->next; // Skip the initial zero node
        int sum = 0;

        while (iterator != nullptr) {
            if (iterator->val == 0) {
                // When a zero is encountered, create a new node with the accumulated sum
                current->next = new ListNode(sum);
                current = current->next;
                sum = 0; // Reset the sum
            } else {
                // Accumulate the sum of values between zeros
                sum += iterator->val;
            }
            iterator = iterator->next;
        }
        return dummy->next; // Return the head of the new list
    }
};
