//https://www.jianshu.com/p/06df9064df56
class Solution
{
    struct Node{
        int num;
        int freq;
        friend bool operator < (const Node &a,const Node &b){
            return a.freq > b.freq;//freqÐ¡µÄÓÅÏÈ¼¶¸ß
        }
    };
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int,int> num2time;
        for(auto num:nums){
            num2time[num]++;
        }
        //multimap<int,int,greater<int>> pq;//Ð¡¸ù¶Ñ
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

class Solution {
    struct Node{
        int m_num;
        int m_cnt;

        Node(int num, int cnt){
            m_num = num;
            m_cnt = cnt;
        }

        friend bool operator < (const Node & node_a, const Node & node_b) {
            return node_a.m_cnt > node_b.m_cnt;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2cnt;
        priority_queue<Node> pq;
        for(auto num : nums){
            num2cnt[num]++;
        }
        for(auto iterator : num2cnt){
            int cnt = iterator.second;
            if(pq.size() < k){
                int num = iterator.first;
                Node tmp = Node(num, cnt);
                pq.push(tmp);
            }
            else{
                if(cnt < pq.top().m_cnt){
                    continue;
                }
                else{
                    pq.pop();
                    int num = iterator.first;
                    Node tmp = Node(num, cnt);
                    pq.push(tmp);
                }
            }
        }
        vector<int> ret;
        while(!pq.empty()){
            ret.push_back(pq.top().m_num);
            pq.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
