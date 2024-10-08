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
    // Approach 1 : Very Basic Approach
    // bool hasCycle(ListNode *head) {
    //     unordered_map<ListNode*, bool> table;
    //     ListNode* temp=head;
    //     while(temp != NULL){
    //         if(table[temp]==false)
    //             table[temp]= true;
    //         else
    //             return true;
    //         temp=temp->next;
    //     }
    //     return false;
    // }
    // Approach 2: Tortoise & Hare A;gorithm
    bool hasCycle(ListNode *head){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast != NULL){
            fast=fast->next;
            if(fast != NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast==slow)
                return true;
        }
        return false;
    }
};