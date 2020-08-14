
python---DFS---回溯法---n皇后

Backtracking is the technique of recursively exploring the tree that contains all the possible solutions to a problem. Choose a systematic way to explore all the possible cases. This approach should reflect a rooted tree, and the backtracking approach is a depth-first search of the rooted tree. Whenever the search has found a solution or determined that there are no further solutions on the branches below the current vertex, backtrack to the preceeding vertex.

A classic example of a problem that can be easily solved with this approach is the n queens problem. This problem is to determine all the possible ways to place n nonattacking queens on an n-by-n chess board.

 可以看看:

https://segmentfault.com/a/1190000003733325

#核心就是回溯的时候一定要恢复现场


```python
import numpy as np

def build_chessboard(N):
    chessboard = np.zeros((N,N))
    return chessboard

def print_chessboard(chessboard):
    N = len(chessboard)
    for r in range(N):
        for c in range(N):
            if chessboard[r,c] == 1:
                print('Q', end='')
            else:
                print('.', end='')
        print ()
    print ()

'''
# generate an empty 4x4 chessboard:
chessboard = build_chessboard(4)
print (chessboard)

# Place 4 non-attacking queens on this board
chessboard[1,0] = 1
chessboard[3,1] = 1
chessboard[0,2] = 1
chessboard[2,3] = 1

# Pretty print the resulting board
print_chessboard(chessboard)
'''

# check from the point we consider
def islegal(chessboard,row,cur_col):
    N = len(chessboard)
    for c in range(0,cur_col):
        if(chessboard[row,c]) == 1:
            return 0
    for r in range(0,N):
        for c in range(0,cur_col):
            if(chessboard[r,c] == 1):
                if(abs(r-row)==abs(c-cur_col)):
                    return 0
    return 1

#col:0 -> n-1
def n_queens(chessboard, col=0, count=[0]):
    """ given a partially filled <chessboard>, try to place a queen in column <col> and recursively fill the board.
    Finally return the number of solutions (added to <count>)"""
    N = len(chessboard)
    if col == N:  # 说明之前最后一列合法，达到递归边界
        if count[0] < 5:
            print_chessboard(chessboard)
        count[0] += 1
        #return即可。
        return 

    # Examine all available squares in column <col> (value is 0), place the queen, and
    # mark all squares under attack by that queen (use anything except 0 or 1).
    # Note: you can make a copy of a chessboard using chessboard.copy()
    #


    next_chessboard = chessboard.copy()
    for r in range(0,N):
        next_chessboard[r,col] = 1
        if islegal(next_chessboard,r,col):
            if col < N:
                #print(next_chessboard)
                n_queens(next_chessboard,col+1,count)
                next_chessboard[r,col] = 0   #这一步非常重要! the core of the backtracking
        else:
            next_chessboard[r,col]=0
            continue

    return count[0]

chessboard = build_chessboard(6)
count = n_queens(chessboard)
print("solutions: ", count)
```
