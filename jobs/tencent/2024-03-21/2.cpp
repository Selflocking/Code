#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// 分割后两边都必须是上升
// 同时有一段的最大值小于另一端的最小值

// 3 5 | 4
// 2 3 | 1
// 3 4 0 1
// 2 | 1 3
// 3 | 1 2
// 4 2 3 5
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
    bool solve(ListNode *ptr) {
        if (ptr->next->next == nullptr) {
            return true;
        }
        ListNode *curr = ptr;
        auto prev = curr;
        curr = curr->next;
        bool up = true;
        while (curr->next != nullptr) {
            if ((curr->val < prev->val && curr->val < curr->next->val)) {
                auto p = ptr;
                int prev_mi = p->val;
                int prev_mx = prev_mi - 1;
                while (p != curr) {
                    if (p->val <= prev_mx) return false;
                    prev_mx = p->val;
                    p = p->next;
                }
                int back_mi = curr->val;
                int back_mx = back_mi - 1;
                p = curr;
                while (p != nullptr) {
                    if (p->val <= back_mx) return false;
                    back_mx = p->val;
                    p = p->next;
                }
                if (prev_mi > back_mx || prev_mx < back_mi) return true;
            } else if ((curr->val > prev->val && curr->val > curr->next->val)) {
                auto p = ptr;
                int prev_mi = p->val;
                int prev_mx = prev_mi - 1;
                while (p != curr->next) {
                    if (p->val <= prev_mx) return false;
                    prev_mx = p->val;
                    p = p->next;
                }
                int back_mi = curr->next->val;
                int back_mx = back_mi - 1;
                p = curr->next;
                while (p != nullptr) {
                    if (p->val <= back_mx) return false;
                    back_mx = p->val;
                    p = p->next;
                }
                if (prev_mi > back_mx || prev_mx < back_mi) return true;
            }
            if (curr->val < prev->val) up = false;
            prev = curr;
            curr = curr->next;
        }
        if (up) return true;
        return false;
    }

  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return bool布尔型vector
     */
    vector<bool> canSorted(vector<ListNode *> &lists) {
        const int n = lists.size();
        vector<bool> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = solve(lists[i]);
        }
        return ans;
    }
};
