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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* current;
        ListNode* tail;
        //check if both lists arent empty
        if(!l1 && !l2)
            return nullptr;
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        //find the lower first node to know where to start appending to
        if(l1->val < l2->val)
        {
            current = l1;
            l1 = l1->next;
        }
        else
        {
            current = l2;
            l2 = l2->next;
        }
        tail = current;

        //append node with lower value to list, move to on proper list
        while(l1 && l2)
        {
            ListNode* temp;
            if(l1->val < l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            else
            {
                temp = l2;
                l2 = l2->next;
            }
            tail->next = temp;
            tail = temp;
        }

        //append remaining nodes of list l1 or l2
        while (l1)
        {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        while (l2)
        {
            tail->next= l2;
            tail = l2;
            l2 = l2->next;
        }

        return current;
    }

};
