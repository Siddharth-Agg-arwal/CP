/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        string bin = "";
        while (head)
        {
            bin += to_string(head->val);
            head = head->next;
        }

        long long val = 0;
        long long it = 0;
        for (int i = bin.size() - 1; i >= 0; i--)
        {
            val = val + pow(2, it) * (bin[i] - '0');
            it += 1;
        }

        return val;
    }
};