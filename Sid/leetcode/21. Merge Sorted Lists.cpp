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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *prev = nullptr;
        ListNode *new_head = nullptr;

        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        if (list1->val <= list2->val)
        {
            prev = list1;
            new_head = list1;
            list1 = list1->next;
        }
        else
        {
            prev = list2;
            new_head = list2;
            list2 = list2->next;
        }

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                prev->next = list1;
                prev = prev->next;
                list1 = list1->next;
            }
            else
            {
                prev->next = list2;
                prev = prev->next;
                list2 = list2->next;
            }
        }

        // if(list1 != nullptr){
        while (list1 != nullptr)
        {
            prev->next = list1;
            prev = prev->next;
            list1 = list1->next;
        }

        // if(list2 != nullptr){
        while (list2 != nullptr)
        {
            prev->next = list2;
            prev = prev->next;
            list2 = list2->next;
        }

        return new_head;
    }
};