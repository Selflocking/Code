/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
    deque<int> q;

  public:
    MyStack() {}

    void push(int x) {
        q.push_back(x);
    }

    int pop() {
        int t = q.size() - 1;
        while (t--) {
            q.push_back(q.front());
            q.pop_front();
        }
        int res = q.front();
        q.pop_front();
        return res;
    }

    int top() {
        int t = this->pop();
        this->push(t);
        return t;
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
