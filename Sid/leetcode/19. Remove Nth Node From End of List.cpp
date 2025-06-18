
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int ll_len = 0;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            ll_len += 1;
            temp = temp->next;
        }

        temp = head;
        if (ll_len - n == 0)
        {
            return head->next;
        }
        else if (n == 1)
        {
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
        }
        else
        {
            int count = ll_len - n;
            while (--count)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }

        return head;
    }
};