/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */
#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  private:
    // 获得向下取整的中间节点
    ListNode *middleNode(ListNode *head) {
        int cnt = 0;
        auto ptr = head;
        while (ptr) {
            cnt++;
            ptr = ptr->next;
        }
        ptr = head;
        int mid = cnt / 2;
        // 进行mid-1次操作，找到前半部分最后一个节点
        mid -= 1;
        while (mid--) {
            ptr = ptr->next;
        }
        return ptr;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *result = nullptr;
        while (head) {
            auto p = head;
            head = head->next;

            p->next = result;
            result = p;
        }
        return result;
    }
    void show(ListNode *head, std::string prompt = "list:") {
        std::cout << prompt;
        while (head) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << "\n";
    }

  public:
    /*
    1 2 3 4
    4 1 3 2

    1 2 3
    3 1 2
    */
    void reorderList(ListNode *head) {
        // 0 个 或 1 个时不用操作。
        if (head->next == nullptr || head->next->next == nullptr) {
            return;
        }
        auto midNode = middleNode(head->next);
        // std::cout << midNode->val << "\n";
        auto front = head->next;
        auto back = midNode->next;
        midNode->next = nullptr;
        // show(front);
        // show(back);

        back = reverseList(back);

        auto ptr = head;
        int cnt = 0;
        while (front != nullptr && back != nullptr) {
            if (cnt % 2 == 0) {
                ptr->next = back;
                back = back->next;
            } else {
                ptr->next = front;
                front = front->next;
            }
            cnt++;
            ptr = ptr->next;
        }
        ptr->next = front == nullptr ? back : front;
    }
};
// @lc code=end
