/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <deque>
#include <set>
using namespace std;
// @lc code=start
class MyQueue {
    deque<int> first, second;

  public:
    MyQueue() {}

    void push(int x) {
        int s = first.size();
        while (s--) {
            int f = this->peek();
            second.push_front(f);
            first.pop_front();
        }
        first.push_front(x);
        s = second.size();
        while (s--) {
            int f = second.front();
            first.push_front(f);
            second.pop_front();
        }
    }

    int pop() {
        int res = this->peek();
        first.pop_front();
        return res;
    }

    int peek() {
        return first.front();
    }

    bool empty() {
        return first.empty();
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
