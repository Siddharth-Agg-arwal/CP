#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }

        ListNode *temp = head;
        ListNode *fast_temp = head->next->next;

        while (temp != nullptr && fast_temp != nullptr && fast_temp->next != nullptr)
        {
            if (temp == fast_temp)
            {
                return true;
            }
            temp = temp->next;
            fast_temp = fast_temp->next->next;
        }

        return false;
    }
};