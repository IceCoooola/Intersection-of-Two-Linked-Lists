/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *listA = headA;   
    struct ListNode *listB = headB;
    int countA = 0;
    int countB = 0;
    while(listA && listA->next)
    {
        listA = listA->next;
        countA++;
    }
    while(listB && listB->next)
    {
        listB = listB->next;
        countB++;
    }
    int steps = abs(countA - countB);
    if(listA == listB)
    {
        if(countA > countB)
        {
            while(steps--)
            {
                headA = headA->next;
            }
        }
        else
        {
            while(steps--)
            {
            headB = headB->next;
            }
        }
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    return NULL;
}
