#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode dummy(0, head);
    ListNode *prev = &dummy;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        if (temp->val == val)
        {
            prev->next = temp->next;
            temp = temp->next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    return dummy.next;
}

int main()
{
    ListNode *head = new ListNode(2);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);

    ListNode *result = removeElements(head, 3);

    while (result != nullptr)
    {
        cout << result->val << endl;
        result = result->next;
    }
}

/*
1 -> 2 -> 3
val = 2
*/