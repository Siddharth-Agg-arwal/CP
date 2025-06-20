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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        ListNode *next_node = head->next;
        head->next = nullptr;

        while (next_node != NULL)
        {
            ListNode *temp = next_node->next;
            next_node->next = head;
            head = next_node;
            next_node = temp;
        }

        return head;
    }
};