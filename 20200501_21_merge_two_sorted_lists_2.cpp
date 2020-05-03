
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)    return l2;//若其中一者为空则自动继承另一个
        if (!l2)    return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);//保留较小的节点，让剩余的节点继续进入递归中
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);//保留较小的节点，让剩余的节点继续进入递归中
            return l2;
        }
    }
};