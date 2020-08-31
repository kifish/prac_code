/*
这题比较有意思, 工程中可能会用到。

https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/er-cha-shu-de-xu-lie-hua-yu-fan-xu-lie-hua-by-le-2/



python解法:
https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/er-cha-shu-de-xu-lie-hua-yu-fan-xu-lie-hua-by-le-2/445928



图解 (BFS)
https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/shou-hui-tu-jie-gei-chu-dfshe-bfsliang-chong-jie-f/





https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/er-cha-shu-de-xu-lie-hua-yu-fan-xu-lie-hua-by-le-2/446053
把空节点表示成null在好多题都见过了，这样序列化的时候就能保证只用一种遍历就能复原原来的二叉树


原来是通过中序遍历和其他一种遍历重建树, 这题通过把空节点表示为null从而只需要一种遍历就能重建二叉树

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        // 先序遍历
        if(root == nullptr) return "null";

        string ret = "";
        ret += to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        return ret;
    }


    vector<string> split(const string & data){
        vector<string> ret;
        string tmp = "";
        for(auto & c : data){
            if(c == ','){
                if(tmp.size()){
                    ret.push_back(tmp);
                    tmp = "";
                }
            }
            else{
                tmp += c;
            }
        }
        if(tmp.size()){
            ret.push_back(tmp);
        }

        return ret;
    }

    TreeNode* build_tree(vector<string> & items, int & index){
        if(index == items.size()){
            return nullptr;
        }

        if(items[index] == "null"){
            index++;
            return nullptr;
        }
        else{
            TreeNode* cur_root = new TreeNode;
            cur_root->val = stoi(items[index]);
            index++;
            cur_root->left = build_tree(items, index);
            cur_root->right = build_tree(items, index);
            return cur_root;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> items = split(data);
        int index = 0;
        return build_tree(items, index); // 有引用, 被使用了地址, 那必须是左值
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// 执行用时：
// 128 ms
// , 在所有 C++ 提交中击败了
// 13.81%
// 的用户
// 内存消耗：
// 61.4 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户