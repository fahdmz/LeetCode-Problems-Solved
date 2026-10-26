#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *test1 = headA;
    ListNode *test2 = headB;
    while (test1 != test2)
    {
        if (test1 == nullptr)
        {
            test1 = headB;
        }
        else
        {
            test1 = test1->next;
        }

        if (test2 == nullptr)
        {
            test2 = headA;
        }
        else
        {
            test2 = test2->next;
        }
    }

    return test1;
}

int main()
{
}