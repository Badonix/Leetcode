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
    int maxDepth(Node* root) {
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        int answ = 0;
        if(!root){
            return 0;
        }
        while (!q.empty()) {
            pair<Node*, int> p = q.front();
            q.pop();
            answ = max(answ, p.second);
            if(!p.first){
                continue;
            }
            for(Node* n : p.first->children){
                if(n){
                    q.push(make_pair(n, p.second + 1));
                }
            }
        }
        return answ + 1;
    }
};