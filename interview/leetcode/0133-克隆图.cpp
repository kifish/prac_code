/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution
{
public:
    map<Node*,Node*> M;
    Node *cloneGraph(Node *node)
    {
        //深拷贝，需要都new出来
        if(node == nullptr) return nullptr;
        if(M.count(node)) return M[node];
        Node* new_node = new Node();
        new_node->val = node->val;
        M[node] = new_node;//一定要写在for循环之前，否则网络中的同一个实体可能进行了多次new,并且陷入死循环，相当于递归没有终止条件
        for(int i =0;i<node->neighbors.size();i++){
            if(node->neighbors[i]){
                new_node->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }
        return new_node;
    }
};