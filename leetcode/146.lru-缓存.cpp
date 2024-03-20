/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Node {
  public:
    Node *prv;
    Node *next;
    int key;
    int value;
    Node() : prv(nullptr), next(nullptr), key(0), value(0) {}
    Node(Node *prv, Node *next) : prv(prv), next(next) {}
    Node(int key, int value) : key(key), value(value) {}
    Node(Node *prv, Node *next, int key, int value)
        : prv(prv), next(next), key(key), value(value) {}
};

class LRUCache {
    unordered_map<int, Node *> hash;
    int cap = 0;
    Node *head{nullptr};
    Node *back{nullptr};

  public:
    LRUCache(int capacity) {
        this->cap = capacity;

        this->head = new Node;
        this->back = new Node;
        this->head->prv = this->back;
        this->back->next = this->head;
    }

    int get(int key) {
        log();

        if (hash.count(key) == 0) return -1;

        auto ptr = hash[key];
        moveToHead(ptr);
        return ptr->value;
    }

    void put(int key, int value) {
        log();
        if (hash.count(key) == 0) {
            if (hash.size() >= cap) {
                Node *b = this->back->next;
                removeNode(b);

                hash.erase(b->key);
                delete b;
            }

            Node *new_node = new Node{this->head->prv, this->head, key, value};
            addToHead(new_node);
            hash[key] = new_node;

        } else {
            auto ptr = hash[key];
            // 修改 value
            ptr->value = value;
            moveToHead(ptr);
        }
    }
    void removeNode(Node *ptr) {
        ptr->prv->next = ptr->next;
        ptr->next->prv = ptr->prv;
    }
    void addToHead(Node *ptr) {
        // 修改前面
        ptr->prv = head->prv;
        head->prv->next = ptr;
        // 修改 Head
        ptr->next = head;
        head->prv = ptr;
    }

    void moveToHead(Node *ptr) {
        removeNode(ptr);
        addToHead(ptr);
    }

    void log() {
        return;
        Node *ptr = head->prv;
        printf("{");
        while (ptr != back) {
            printf(" %d=%d ", ptr->key, ptr->value);
            ptr = ptr->prv;
        }
        printf("}\n");
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    auto lruc = LRUCache(2);
    lruc.put(1, 1);
    lruc.put(2, 2);
    cout << lruc.get(1) << "\n";
    lruc.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lruc.get(2) << "\n"; // 返回 -1 (未找到)
    lruc.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lruc.get(1) << "\n"; // 返回 -1 (未找到)
    cout << lruc.get(3) << "\n"; // 返回 3
    cout << lruc.get(4) << "\n"; // 返回 4
    return 0;
}
