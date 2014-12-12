typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 } ListNode;

class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *head = NULL;
            ListNode *p = NULL;
            ListNode *q = NULL;
            int carry = 0;
            ListNode* i1 = l1;
            ListNode* i2 = l2;
            while(i1 || i2)
            {
                int sum = carry;
                if (i1)
                {
                    sum += i1->val;
                    i1 = i1->next;
                }
                if (i2)
                {
                    sum += i2->val;
                    i2 = i2->next;
                }
                int cur_digit = sum % 10;
                p = new ListNode(cur_digit);
                if (head == NULL)
                {
                    head = p;
                    q = head;
                }
                else
                {
                    q->next = p;
                    q = p;
                }
                p = p->next;
                carry = sum / 10;
            }
            if (carry)
            {
                p = new ListNode(carry);
                q->next = p;
            }
            return head;
        }

};
