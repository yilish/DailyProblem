
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pHead = new ListNode;//引入哨兵结点
        ListNode* pCur = pHead;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                pCur->next = l1;
                pCur = l1;
                l1 = l1->next;
            }
            else
            {
                pCur->next = l2;
                pCur = l2;
                l2 = l2->next;
            }
        }
        pCur->next = l1 ? l1 : l2;
        return pHead->next;
    }
};