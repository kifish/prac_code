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
        //�������Ҫ��new����
        if(node == nullptr) return nullptr;
        if(M.count(node)) return M[node];
        Node* new_node = new Node();
        new_node->val = node->val;
        M[node] = new_node;//һ��Ҫд��forѭ��֮ǰ�����������е�ͬһ��ʵ����ܽ����˶��new,����������ѭ�����൱�ڵݹ�û����ֹ����
        for(int i =0;i<node->neighbors.size();i++){
            if(node->neighbors[i]){
                new_node->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }
        return new_node;
    }
};