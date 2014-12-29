class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head)
            return NULL;
        ListNode* ret = head;
        ListNode* last = head;
        ListNode* p = head;
        ListNode* p1 = p->next;
        ListNode* next_start = NULL;
        while(p)
        {
            if (!p1)
                return ret;
            next_start = p1->next;
            if (ret == head)
            {
                ret = p1;
                last = p;
                ret->next = last;
                last->next = next_start;
            }
            else
            {
                last->next = p1;
                p1->next = p;
                p->next = next_start;
                last = p;
            }
            p = next->start;
            if (p)
                p1 = p->next;
        }
        return ret;
    }
};