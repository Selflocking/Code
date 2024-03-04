/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <deque>
#include <set>
#include <stack>
using namespace std;
// @lc code=start
class MyQueue {
    stack<int> in, out;
    void in2out() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }

  public:
    MyQueue() {}

    void push(int x) {
        in.push(x);
    }

    int pop() {
        // 注意：只有out empty时才需考虑in2out
        if (out.empty()) {
            in2out();
        }
        int res = out.top();
        out.pop();
        return res;
    }

    int peek() {
        if (out.empty()) {
            in2out();
        }
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
