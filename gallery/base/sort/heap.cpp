#include<bits/stdc++.h>
using namespace std;

// vscode的代码补全就是这么好用........
// 实现一个大顶堆

class Heap
{
private:
    /* data */
    vector<int> nums;
    int n = 0;
    // 上浮
    // void swim(int idx){}
    // 可以不需要使用swim操作

    // sink
    void sink(int idx){
        while(2*idx <= n){
            int max_child_idx = 2 * idx;
            if(max_child_idx < n && nums[max_child_idx + 1] > nums[max_child_idx]){
                max_child_idx++;
            }

            if(nums[idx] < nums[max_child_idx]){
                swap(nums[idx], nums[max_child_idx]);
                idx = max_child_idx;
            }
            else{
                break;
            }
        }
    }

    // 让nums有序
    void sort(){
        assert(n >= 1);
        int cnt = n - 1; // cnt为执行次数
        while (cnt--){
         // cnt+2 是堆中当前最大元素的最终位置; 由于cnt已经预先减1因此不是cnt+1而是cnt+2
            swap(nums[1], nums[cnt+2]);
            n--; // 当前最大元素离开堆
            sink(1);
        }
    }

    // TODO
    vector<int> get_sorted_nums(){
        sort();
        return nums; // 注意这里面包含了padding 0
    }

    // a.cpp:154:14: error: 'print_sorted_nums' is a private member of 'Heap'
    // void print_sorted_nums(){
    //     sort();
    //     for(auto num : nums){
    //         cout<<num<<" ";
    //     }
    //     cout<<endl;
    // }
    
    int get_max_val(){
        assert(n >= 1);
        return nums[1];
    }

    int pop_max_val(){
        assert(n >= 1);
        int ret = nums[1];
        swap(nums[1],nums[n]);
        nums.pop_back();
        n--;
        sink(1);
        return ret;
    }

    void del_max_val(){
        assert(n >= 1);
        swap(nums[1],nums[n]);
        nums.pop_back();
        n--;
        sink(1);
    }

    void swim(int idx){
        while (idx >= 2) // idx/2 >= 1 可优化成idx >= 2
        {
            int parent_idx = idx / 2;
            if(nums[parent_idx] < nums[idx]){
                swap(nums[parent_idx], nums[idx]);
                idx = parent_idx;
            }
            else{
                break;
            }
        }
    }

    void insert(int num){
        /*
        如果实现动态插入
        如果直接插在数组末尾做上浮操作是可以的
        如果直接做下沉操作呢?不能保证正确性, 经过调整后大顶堆的性质会被破坏
        如果先和nums[1]交换呢? 然后调整nums[1]?
        也不行, nums[n]这里的性质可能也被破坏了
        */
       nums.push_back(num);
       n++;
       swim(n);
    }

    void print_cur_state(){
        cout<<"n: "<<n<<endl;

        for(auto num:nums){
            cout<<num<<" ";
        }
        cout<<endl;
    }

public:
    Heap(/* args */);
    // or
    // heap(){}

    // 这种建堆方法是O(n)的
    Heap(vector<int> nums_): nums(nums_){
        // 建堆操作
        nums.insert(nums.begin(),0); // http://www.cplusplus.com/reference/vector/vector/insert/
        // 这样插入是有点低效的
        n = (int)nums.size() - 1;
        // cout<<"n: "<<n<<endl;
        for(int i = n / 2; i>=1; i--){ // 从倒数第二层开始调整;也就是说从最后一个节点的父节点开始调整; 然后从右往左, 从下往上遍历。
            // 下沉即可
            sink(i);
        }
        // print_cur_state();
    }
    
    // 想在类的外部调用函数得写在public里面
    // 从小到大排序
    void print_sorted_nums(){
        sort();
        for(int i = 1;i < nums.size();i++){ // 由于n被破坏了, 只能用nums.size()
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }

    ~Heap();
};


Heap::Heap(/* args */)
{
}

Heap::~Heap()
{
}


// 您的代码已保存
// 答案正确:恭喜！您提交的程序通过了所有的测试用例


int main(){

    // test
    // https://www.nowcoder.com/questionTerminal/508f66c6c93d4191ab25151066cb50ef

    int n;
    vector<int> nums;
    int tmp;
    while (cin>>n)
    {
        while(n--){
            cin>>tmp;
            nums.push_back(tmp);
        }

        // wrong:
        // Heap heap = Heap(nums);
        // heap.print_sorted_nums();
        // delete heap; // 需要是指针
        // https://docs.microsoft.com/en-us/cpp/cpp/delete-operator-cpp?view=vs-2019
        // https://stackoverflow.com/a/62221507

        Heap* heap_ptr = new Heap(nums);
        heap_ptr->print_sorted_nums();
        delete heap_ptr;
        nums.clear();
    }
    return 0;
}