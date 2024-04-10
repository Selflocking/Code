/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;

        ListNode * ans = nullptr;
        
        if(list1->val<list2->val){
            ans = list1;
            list1 = list1->next;
        }else{
            ans = list2;
            list2 = list2->next;
        }
        auto ptr = ans;
        while(list1!=nullptr&&list2!=nullptr){
            if(list1->val<list2->val){
                ptr->next = list1;
                ptr = list1;
                list1 = list1->next;
            }else{
                ptr->next = list2;
                ptr = list2;
                list2 = list2->next;
            }
        }
        // 用这个可以代替下面的操作
        ptr->next = list1==nullptr?list2:list1;
        
        // while(list1!=nullptr){
        //     ptr->next = list1;
        //     ptr = list1;
        //     list1 = list1->next;
        // }

        // while(list2!=nullptr){
        //     ptr->next = list2;
        //     ptr = list2;
        //     list2 = list2->next;
        // }

        return ans;
    }
};
// @lc code=end

