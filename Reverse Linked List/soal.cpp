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

ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *nextNode = nullptr;

    while (curr != nullptr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
int main()
{
    ListNode *head = new ListNode(2);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);

    ListNode *result = reverseList(head);

    while (result != nullptr)
    {
        cout << result->val << endl;
        result = result->next;
    }
}

/*
dummyNode -> 1
1 -> 2 -> 3 -> 4


nextNode = 2
curr->next = null
prev = 1
curr = 2

nextNode = 3
curr->next = 1
prev = 2


*/