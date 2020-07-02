
/*


https://leetcode-cn.com/problems/dinner-plate-stacks/solution/wei-hu-liang-ge-zhi-zhen-by-comiee/

left 维护的是 从左往右第一个 没有满的栈的位置 // 通过min来体现 // 如果left指向的栈满了, 则移动left ; 负责push
right 维护的是 从右往左第一个 栈的位置 //（栈可以为空）所以 需要特判 // 通过max来体现 ; 负责pop




*/


class DinnerPlates {
public:
    DinnerPlates(int capacity) {

    }
    
    void push(int val) {

    }
    
    int pop() {

    }
    
    int popAtStack(int index) {

    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */