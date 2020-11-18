


# http://wjjc.openjudge.cn/2020jgcfall6/006/



# wrong: 初始化的时候引用导致的
# def mul(A, B):
#     m = len(A) # A: m*n 
#     p = len(B[0]) # B: n*p
#     C = [[0]* p] * m # m*p
#     n = len(A[0])
#     for i in range(m):
#         for j in range(p):
#             sum_val = 0
#             for k in range(n):
#                 sum_val += A[i][k] * B[k][j]
            
#             print('cur sum_val : {}'.format(sum_val))
            
#             C[i][j] = sum_val
            
#     print(C)
#     return C    



def mul(A, B):
    m = len(A) # A: m*n 
    p = len(B[0]) # B: n*p
    C = []
    
    for i in range(m):
        row = []
        for j in range(p):
            row.append(0)
            
        C.append(row)
        
    
    n = len(A[0])
    for i in range(m):
        for j in range(p):
            sum_val = 0
            for k in range(n):
                sum_val += A[i][k] * B[k][j]
            
            # print('cur sum_val : {}'.format(sum_val))
            
            C[i][j] = sum_val
            
    # print(C)
    return C   


def pretty_print(matrix):
    for i,row in enumerate(matrix):
        if i != 0:
            print()
        for idx, item in enumerate(row):
            if idx == len(row) - 1:
                print(item, end = '')
            else:
                print(item, end = ' ')
    

def parse_line():
    ret = []
    line = input().strip().split()
    for item in line:
        ret.append(int(item))
    return ret 


if __name__ == '__main__':
    # n, m, k = list(map(input().strip().split(), int))
    
    # DEBUG = False
    n, m, k = parse_line()
    # if DEBUG:
    #     print(f'\nn: {n}')
    #     print(f'm: {m}')
    #     print(f'k: {k}')
    
    # A = [[1,1]] * 3
    # B = [[1,1,1]] * 2 
    A = []
    for _ in range(n):
        # A.append(list(map(input().strip().split(), int)))
        A.append(parse_line())
    B = []
    for _ in range(m):
        # B.append(list(map(input().strip().split(), int)))
        B.append(parse_line())

    
    C = mul(A,B) 
    pretty_print(C)
    
    
