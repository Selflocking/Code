/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        // 注意空指针
        if(root==nullptr) return res;

        res.push_back(root->val);
        for(auto &child:root->children){
            auto r = preorder(child);
            res.insert(res.end(),r.begin(),r.end());
        }
        return res;
    }
};