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
    // Approach 1:
    // ListNode* middleNode(ListNode* head) {
    //     int n= getLength(head);
    //     int position=(n/2)+1;
    //     ListNode* temp=head;
    //     while(position!=1){
    //         temp=temp->next;
    //         position--;
    //     }
    //     return temp;
    // }
    // int getLength(ListNode* &head){
    //     int length=0;
    //     ListNode* temp=head;
    //     while(temp!=NULL){
    //         length++;
    //         temp=temp->next;
    //     }
    //     return length;
    // }
    // Approach 2: Tortoise algorithm or Fast & Slow Pointer
    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            //Take 1 step first
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
};