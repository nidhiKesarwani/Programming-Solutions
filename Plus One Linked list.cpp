//                  Plus One Linked list Solution
//       https://leetcode.com/problems/plus-one-linked-list/

/*
Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example :

Input: [1,2,3]
Output: [1,2,4]

*/

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
    ListNode* reverse(ListNode* head) 
    {
        ListNode *prev,*curr;
        prev = NULL, curr = head;
        
        while(curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    
    ListNode* plusOne(ListNode* head) {
        
        // reverse it
        head = reverse(head);
        // dummy variable
        ListNode *tmp = head;
        int carry=1;
        int a = tmp->val;
        tmp=tmp->next;
        
        // ans node for propagation
        ListNode* ans= new ListNode((a+carry)%10);
        head = ans;
        
        carry = (a+carry)/10;
        
        while(tmp)
        {
          a = tmp->val;
          ListNode* v = new ListNode((a+carry)%10);
          ans->next = v;
          ans = v;
          tmp=tmp->next;
         carry = (a+carry)/10;
        }
        
        // if carry remains
        if(carry)
        {
          ListNode* v = new ListNode(carry);
          ans->next = v;
        }
        // reverse again
        head = reverse(head);
        return head;
    }
};
