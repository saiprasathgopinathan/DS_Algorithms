x = [1,2,-1,2,-3,2,-5]
def kadane(x):
    tail = 0
    result = x[0]
    sm_tmp = x[0]
    for i in range(1, len(x)):
        sm_tmp = max(x[i], x[i]+sm_tmp)
        if result < sm_tmp:
            result = sm_tmp
            tail = i
    sm_tmp = 0
    head = 0
    for i in range(tail, -1, -1):
        sm_tmp = sm_tmp + x[i]
        head = i
        if sm_tmp == result:
            break
    return head, tail

s, e = kadane(x)
print(x[s:e+1])