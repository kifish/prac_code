
/*


https://leetcode-cn.com/problems/min-stack/

https://leetcode-cn.com/explore/interview/card/bytedance/245/data-structure/1049/


https://leetcode-cn.com/problems/min-stack/solution/zui-xiao-zhan-by-leetcode-solution/



*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        S.push(x);
        if(Q.empty() || Q.top() >= x){
            Q.push(x);
        }
        else
            Q.push(Q.top());
    }
    
    void pop() {
        S.pop();
        Q.pop();
        
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return Q.top();
    }
private:
    stack<int> S;
    stack<int> Q;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */