//https://www.jianshu.com/p/06df9064df56
class Solution
{
    struct Node{
        int num;
        int freq;
        friend bool operator < (const Node &a,const Node &b){
            return a.freq > b.freq;//freq小的优先级高
        }
    };
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int,int> num2time;
        for(auto num:nums){
            num2time[num]++;
        }
        //multimap<int,int,greater<int>> pq;//小根堆
        priority_queue<Node> pq;
        for(auto kv:num2time){
            if(pq.size() == k){
                if(pq.top().freq < kv.second){
                    pq.pop();
                    Node* tmp = new Node();
                    tmp->num = kv.first;
                    tmp->freq = kv.second;
                    pq.push(*tmp);
                }
            }
            else{
                Node* tmp = new Node();
                tmp->num = kv.first;
                tmp->freq = kv.second;
                pq.push(*tmp);
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().num);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};