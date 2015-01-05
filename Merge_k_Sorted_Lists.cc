#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    private:
        ListNode *merge2Lists(ListNode* list1, ListNode* list2)
        {
            if (!list1)
                return list2;
            if (!list2)
                return list1;
            ListNode* p1 = list1;
            ListNode* p2 = list2;
            ListNode* head = NULL;
            ListNode* last = NULL;
            while(p1 && p2)
            {
                int val1 = p1->val;
                int val2 = p2->val;
                if (val1 > val2)
                {
                    if (!head)
                    {
                        head = p2;
                        last = p2;
                    }
                    else
                    {
                        last->next = p2;
                        last = last->next;
                    }
                    p2 = p2->next;
                }
                else
                {
                    if (!head)
                    {
                        head = p1;
                        last = p1;
                    }
                    else
                    {
                        last->next = p1;
                        last = last->next;
                    }
                    p1 = p1->next;
                }

            }
            if (p1)
                last->next = p1;
            if (p2)
                last->next = p2;
            return head;
        }
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists)
        {
            if (lists.size() == 0)
                return NULL;
            if (lists.size() == 1)
                return lists[0];
            int i = 0;
            while (i != lists.size())
            {
                if ( i + 1 == lists.size())
                    return lists[i];
                if ( i + 1 < lists.size())
                {
                    ListNode *merged = merge2Lists(lists[i], lists[i+1]);
                    lists.push_back(merged);
                }
                i = i + 2;

            }
        }
};



