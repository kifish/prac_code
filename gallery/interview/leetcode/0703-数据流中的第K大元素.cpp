class KthLargest {
public:
    int size;
    priority_queue<int,vector<int>,greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
        //维护一个k大小的小顶堆
        size = k;
        for(int num:nums){
            pq.push(num);
            if(pq.size() > size){
                pq.pop();//把最小的t出去
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size){
            pq.pop();
        }
        return pq.top();//最小的
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */