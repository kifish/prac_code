class Solution
{
    int parent[1005];
    int n;
    map<char,int> ch2id;
    int id = 0;
    vector<vector<int>> constraints;
public:
    int find_parent(int x){
        if(parent[x] == x) return x;
        int root = find_parent(parent[x]);
        parent[x] = root;
        return root;
    }
    void init(){
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    bool equationsPossible(vector<string> &equations)
    {   
        n = 2 * equations.size();
        init();
        for(auto equation:equations){
            char ch1 = equation[0];
            char ch2 = equation[3];
            char op = equation[1];
            if(ch2id.find(ch1) == ch2id.end()){
                ch2id[ch1] = id;
                id++;
            }
            if (ch2id.find(ch2) == ch2id.end()){
                ch2id[ch2] = id;
                id++;
            }
            int a = ch2id[ch1];
            int b = ch2id[ch2];
            if(op == '!'){
                vector<int> buf;
                buf.push_back(a);
                buf.push_back(b);
                constraints.push_back(buf);
            }
            int roota = find_parent(a);
            int rootb = find_parent(b);
            if(op == '='){
                if(roota != rootb) parent[roota] = rootb;
            }
            else{
                if(roota == rootb) return false;
            }
        }
        for(auto cons:constraints){
            int a = cons[0];
            int b = cons[1];
            if(find_parent(a) == find_parent(b)){
                return false;
            }
        }
        return true;
    }
};