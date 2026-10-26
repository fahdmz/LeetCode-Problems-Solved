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

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *test = head;
    while (test != nullptr && test->next != nullptr)
    {
        if (test->val == test->next->val)
        {
            test->next = test->next->next;
        }
        else
        {
            test = test->next;
        }
    }
    return head;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    head = deleteDuplicates(head);

    // Print the linked list
    ListNode *test = head;

    while (test != nullptr)
    {
        cout << test->val << " ";
        test = test->next;
    }

    cout << endl;
}