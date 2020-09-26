
/*

https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/

逆波兰式 即后缀表达式

a b + 这种形式

遇到数字则压入栈

遇到 op 则弹出数字计算并把结果压入栈


逆波兰表达式：

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
逆波兰表达式主要有以下两个优点：

去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for(int i = 0;i<tokens.size();i++){
            string op = tokens[i];
            if(op.size() == 1){
                if(op[0] == '+'){
                    int b = S.top();
                    S.pop();
                    int a = S.top();
                    S.pop();
                    S.push(a+b);
                }
                else if(op[0] == '-'){
                    int b = S.top();
                    S.pop();
                    int a = S.top();
                    S.pop();
                    S.push(a-b);
                }
                else if(op[0] == '/'){
                    int b = S.top();
                    S.pop();
                    int a = S.top();
                    S.pop();
                    S.push(a/b);
                }
                else if(op[0] == '*'){
                    int b = S.top();
                    S.pop();
                    int a = S.top();
                    S.pop();
                    S.push(a*b);
                }
                else{
                    int num = atoi(op.c_str());
                    S.push(num);
                }
            }
            else{
                int num = atoi(op.c_str());
                S.push(num);
            }
        }
        return S.top();
    }
};