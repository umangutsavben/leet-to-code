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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* fst = l1;
        ListNode* sec = l2;
        ListNode* node = new ListNode(-1);
        ListNode* dum = node;
        if(l1 == NULL) return l2;
        if(l2==NULL) return l1;
        int carry = 0;
        while(fst!=nullptr && sec!=nullptr){
            int a = fst->val;
            int b = sec->val;
            int sum = a + b + carry;
            if(sum>9){
                carry = 1;
            }
            else carry = 0;
            int end = sum%10;
            node->next = new ListNode(end);
            node = node->next;
            fst = fst->next;
            sec = sec->next;
        }   
        while(fst!=NULL){
            int a = fst->val;
            int sum = carry + a;
            if(sum>9) carry = 1;
            else carry = 0;
            int end = sum%10;
            node->next = new ListNode(end);
            node = node->next;
            fst = fst->next;
        }
        while(sec!=NULL){   
            int a = sec->val;
            int sum = carry + a;
            if(sum>9) carry = 1;
            else carry = 0;
            int end = sum%10;
            node->next = new ListNode(end);
            node = node->next;
            sec = sec->next;
        }
        if(carry==1){
            node->next = new ListNode(1);
        }
        return dum->next;
    }
};