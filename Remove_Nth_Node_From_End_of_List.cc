typedef struct ListNode_t {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
    public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first;
        ListNode *second;
        first = head;
        second = head;
        ListNode* before_second = head;
        for(int i = 1; i < n; ++i)
        {
            first = first->next;
        }
        while(first->next)
        {
            first = first->next;
            second = second->next;
            if (second != head->next)
                before_second = before_second->next;
        }
        if (second == head)
            head = head->next;
        else
            before_second->next = second->next;
        return head;
    }

};
