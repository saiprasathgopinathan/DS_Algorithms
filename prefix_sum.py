"""
1) This problem of finding the target sum subarray using a) prefix sum b) sliding window
2) sliding window is possible only in sorted array and prefix is possible in unsorted array
because in sliding sum can be unpredictable if not sorted. The answer may be different
"""
x =  [2,4,-2,1,-3,5,-3]
target = 5
def prefix_sum(x):
    sm = 0
    hash_map = {}
    for i in range(len(x)):
        sm += x[i]
        if sm == target:
            return(x[0:i+1])
        if sm-target in hash_map.keys():
            hash_map[sm] += 1
        if sm not in hash_map.keys():     
            hash_map[sm] = 1        
    key_max_value = max(hash_map, key=hash_map.get)
    max_val = hash_map[key_max_value]
    ind = []
    for k, v in hash_map.items():
        if v == max_val:
            ind.append(k)
    
    s_ind, e_ind = ind[0]-1, ind[1]+1
    return(x[s_ind:e_ind])

def prefix(x):
    hash_map = {}
    sm = 0
    for i in range(len(x)):
        sm += x[i]
        if sm == target:
            print("ent")
            return x[0:i+1]
        if sm-target not in hash_map.keys():
            hash_map[sm] = 1
        if sm-target in hash_map.keys():
            hash_map[sm] += 1
    max_val_key = max(hash_map, key = hash_map.get)
    max_val = hash_map[max_val_key]
    ind = []
    for k, v in hash_map.items():
        if v == max_val:
            ind.append(k)
    print(x[ind[0]+1:ind[1]+1])


print(prefix(x))
print(prefix_sum(x))