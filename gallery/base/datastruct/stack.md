





```python

class Stack(object):
    def __init__(self,size = 8):
        self.stack = []
        self.size = size
        self.top = -1

    def set_size(self,size):
        if self.top > size -1:
            raise Exception("StackWillOverflow")
        self.size = size

    def isFull(self):
        return True if self.size -1 == self.top else False
    def isEmpty(self):
        return True if self.top == -1 else False

    def push(self,data):
        if self.isFull():
            raise Exception("StackOverflow")
        self.stack.append(data)
        self.top += 1

    def pop(self):
        if self.isEmpty():
            raise Exception("StackUnderflow")
        self.top -= 1
        return self.stack.pop()

    def top(self):
        if self.isEmpty():
            raise Exception("StackUnderflow")
        return self.stack[self.top]

    def show(self):
        if self.isEmpty():
            return
        print(self.stack)

if __name__ == "__main__":
    s = Stack()
    for i in range(8):
        s.push(i)

    print(s.pop())
    print(s.pop())
    s.top()
    #TypeError: 'int' object is not callable
    #python解释器误认为是s.top即self.top的那个值
    s.show()


```





```python
class Stack(object):
    def __init__(self,size = 8):
        self.stack = []
        self.size = size
        self.top = -1

    def set_size(self,size):
        if self.top > size -1:
            raise Exception("StackWillOverflow")
        self.size = size

    def isFull(self):
        return True if self.size -1 == self.top else False
    def isEmpty(self):
        return True if self.top == -1 else False

    def push(self,data):
        if self.isFull():
            raise Exception("StackOverflow")
        self.stack.append(data)
        self.top += 1

    def pop(self):
        if self.isEmpty():
            raise Exception("StackUnderflow")
        self.top -= 1
        return self.stack.pop()

    def get_top(self):
        if self.isEmpty():
            raise Exception("StackUnderflow")
        return self.stack[self.top]

    def show(self):
        if self.isEmpty():
            return
        print(self.stack)

if __name__ == "__main__":
    s = Stack()
    for i in range(8):
        s.push(i)

    print(s.pop())
    print(s.pop())
    print(s.get_top())
    s.show()
"""
7
6
5
[0, 1, 2, 3, 4, 5]

"""
```






```python
class Stack:
    def __init__(self):
        self.items = []
    def peek(self):
        return self.items[-1]
    def pop(self):
        if len(self.items) >0:
            return self.items.pop()
        return None 

    def isEmpty(self):
        return len(self.items) == 0
    def push(self,val):
        self.items.append(val)
    def size(self):
        return len(self.items)

def parChecker(input):
    s = Stack()
    res = None
    for ch in input:
        if ch == '(':
            s.push(ch)
        elif ch == ')':
            if s.size():
                s.pop()
            else:
                res = False
                break
    if res != False:
        if s.size():
            res = False
        elif s.size() == 0:
            res = True 
    return res




symbols = "()[]{}"
def get_symbols(text):
    i, text_len = 0, len(text)
    while True:
        while i < text_len and text[i] not in symbols:
            i += 1
        if i >= text_len:
            return
        yield text[i], i
        i += 1

def check_symbols(text):
    left_symbols = "([{"
    right2left = {')': '(', ']': '[', '}': '{'} # 表示配对关系的字典
    s = Stack()
    for symbol, i in get_symbols(text): #get_symbols(text)直接生成了generator,第一次循环symbol == '(',i == 0
        if symbol in left_symbols:  # 开括号，压进栈并继续
            s.push(symbol)
        elif s.pop() != right2left[symbol]:  
            print('Unmatching is found at', i, 'for', symbol)
            return False
        # else 是一次括号配对成功，什么也不做，继续
    if s.isEmpty():
        print("All paretheses are correctly matched.")
        return True
    else:
        print("left symbols aren't matched.")
        return False


if __name__ == '__main__':
    print(parChecker('(()()()())'))
    print(parChecker('(((())))'))
    print(parChecker('(()((())()))'))

    print(parChecker('((((((())'))
    print(parChecker('()))'))
    print(parChecker('(()()(()'))
    
    print(check_symbols('([]{}]'))
    print(check_symbols('([]{})'))



    


```
