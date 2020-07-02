// https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/shi-xian-trie-qian-zhui-shu-by-leetcode/

// https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/shi-xian-trie-qian-zhui-shu-by-leetcode/417275


// https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/shi-xian-trie-qian-zhui-shu-by-leetcode/151430



// 执行用时：
// 108 ms
// , 在所有 C++ 提交中击败了
// 77.77%
// 的用户
// 内存消耗：
// 43.6 MB
// , 在所有 C++ 提交中击败了
// 54.55%
// 的用户


// 可以只使用Trie; 既当node又当tree

class Trie {
    bool m_is_end = false;
public:
    char c;
    Trie* children[26] = {nullptr}; //一共26个小写字母


    /** Initialize your data structure here. */
    Trie() {}

    // Trie():{} // 不能这么写

    Trie(char c): c(c) {} // 实际上字典树连c都可以不用存, 该node信息其实存在了他的父节点的children数组里, 这点很神奇

    // Trie(bool m_is_end):m_is_end(m_is_end){} // char bool 可能可以互转? 这里这么写可能有点问题

    Trie(char c, bool m_is_end): c(c), m_is_end(m_is_end){}

    bool is_end(){
        return m_is_end;
    }

    void set_end(bool m_is_end_){
        m_is_end = m_is_end_;
    }
    

    /** Inserts a word into the trie. */
    void insert(string word) { // 这是种迭代的写法
        Trie* cur_root = this;
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            if(cur_root->children[ch - 'a'] != nullptr){
                // 不用插入
                if(i == (int)word.size() - 1){
                    cur_root->children[ch - 'a']->set_end(true); // 实际上这行可以和下面的分支合并起来放到for循环之后即可
                }
                else
                {
                    cur_root = cur_root->children[ch - 'a']; 
                }    
            }
            else{
                cur_root->children[ch - 'a'] = new Trie(ch);
                if(i == (int)word.size() - 1){
                    cur_root->children[ch - 'a']->set_end(true);
                }
                else{
                    cur_root = cur_root->children[ch - 'a'];
                }
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        bool is_end = false;
        return startsWith(word, is_end) && is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur_root = this;
        for(auto & ch : prefix){
            if(cur_root->children[ch - 'a'] == nullptr){
                return false;
            }
            else{
                cur_root = cur_root->children[ch - 'a'];
            }
        }
        return true;
    }

    bool startsWith(string prefix, bool & is_end) {
        Trie* cur_root = this;
        for(auto & ch : prefix){
            if(cur_root->children[ch - 'a'] == nullptr){
                return false;
            }
            else{
                cur_root = cur_root->children[ch - 'a'];
            }
        }
        if(cur_root->is_end()){ // 没有标记位的话, 需要遍历children数组, 如果都为nullptr说明is_end == true
            is_end = true;
        }
        return true;
    }


};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */