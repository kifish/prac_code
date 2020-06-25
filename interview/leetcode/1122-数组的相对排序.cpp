class Solution {
public:
    struct Node
    {
        int num;
        int val;
    };
    
    static bool cmp(Node a,Node b){
        return a.val < b.val;
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> num2val;
        int offset = -1;
        for(int i = 0;i<arr2.size();++i){
            num2val[arr2[i]] = i;
            offset = max(offset,arr2[i]);
        }
        vector<Node> nodes;
        Node tmp;
        for(auto num : arr1){
            tmp.num = num;
            if(num2val.count(num)){
                tmp.val = num2val[num];
            }
            else tmp.val = num + offset;
            nodes.push_back(tmp);
        }
        sort(nodes.begin(),nodes.end(),cmp);
        vector<int> ret;
        for(auto node : nodes){
            ret.push_back(node.num);
        }
        return ret;
    }
};