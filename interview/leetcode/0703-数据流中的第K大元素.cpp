class KthLargest {
public:
    int size;
    priority_queue<int,vector<int>,greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
        //ά��һ��k��С��С����
        size = k;
        for(int num:nums){
            pq.push(num);
            if(pq.size() > size){
                pq.pop();//����С��t��ȥ
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size){
            pq.pop();
        }
        return pq.top();//��С��
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */