/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
 */

// @lc code=start
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
class Solution {
  public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *res = new ListNode(0);
        ListNode *ptr = res;
        head = head->next;
        while (!(head->val == 0 && head->next == nullptr)) {
            if (head->val == 0) {
                auto tmp = new ListNode(0);
                ptr->next = tmp;
                ptr = tmp;
            }
            ptr->val += head->val;
            head = head->next;
        }
        return res;
    }
};
// @lc code=end
