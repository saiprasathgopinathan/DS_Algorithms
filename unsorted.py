def unsorted_array(x):
    result = []
    start, end = 0, len(x)-1
    while(start < end):
        if(x[start] > x[start+1]):
            break
        start += 1
    
    if start == end:
        print("Array is sorted")
    
    while(end > 0):
        if(x[end-1] > x[end]):
            break
        end -= 1

    min_tmp = x[-1]
    max_tmp = x[0]

    k = start
    while(k <= end):
        if(max_tmp < x[k]):
            max_tmp = x[k]
        if(min_tmp > x[k]):
            min_tmp = x[k]
        k+=1
    
    while start > 0 and x[start-1] > min_tmp:
        start -= 1

    while end > len(x)-1 and x[end+1] < max_tmp:
        end += 1
    
    for i in range(start, end+1):
        result.append(x[i])

    print(result)

x =  [1,3,5,2,6,4,7,8,9]
unsorted_array(x)
