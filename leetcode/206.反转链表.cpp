/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// 迭代：
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode * res = nullptr;

//         while(head!=nullptr){
//             auto curr = new ListNode(head->val);
//             curr->next = res;
//             res = curr;
//             head = head->next;
//         }

//         return res;
//     }
// };
// O(1) 空间：
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = head;
        ListNode * curr = nullptr;

        while(prev!=nullptr){
            auto t = prev->next;
            prev->next = curr;
            curr = prev;
            prev = t;
        }

        return curr;
    }
};
// @lc code=end

