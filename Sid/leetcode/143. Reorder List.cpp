#include <iostream>
#include <vector>
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
    void reorderList(ListNode *head)
    {
        vector<ListNode *> reordered;

        if (head == nullptr)
        {
            return;
        }

        ListNode *temp = head;
        while (temp != nullptr)
        {
            reordered.push_back(temp);
            temp = temp->next;
        }

        int ptr1 = 1;
        int ptr2 = reordered.size() - 1;

        if (ptr2 == 1)
        {
            return;
        }

        temp = head;
        bool t1 = true;
        while (ptr1 <= ptr2)
        {
            if (t1)
            {
                temp->next = reordered[ptr2];
                ptr2--;
                t1 = false;
            }
            else
            {
                temp->next = reordered[ptr1];
                ptr1++;
                t1 = true;
            }

            temp = temp->next;
        }
        temp->next = nullptr;
    }
};