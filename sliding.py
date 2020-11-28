x= [1,2,3,5,2]
target = 8
start, end = 0, 0
sm = x[0]
while start < len(x):
    if start > end:
        end = start
        sm = x[start]
    if sm < target:
        if end == len(x) - 1:
            break
        end += 1
        sm += x[end]
    elif sm > target:
        sm -= x[start]
        start += 1
    else:
        print(start, end)
        break
