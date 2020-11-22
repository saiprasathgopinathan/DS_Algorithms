# BINARY SEARCH TREE

# class Node:
#     def __init__(self, key):
#         self.left = None
#         self.right = None
#         self.val = key
    
# def insert(root, node):
#     if root is None:
#         root = node
#     else:
#         if root.val < node.val:
#             if root.right is None:
#                 root.right = node
#             else:
#                 insert(root.right, node)
#         else:
#             if root.left is None:
#                 root.left = node
#             else:
#                 insert(root.left, node)

# def inorder(root):
#     if root:
#         inorder(root.left)
#         print(root.val)
#         inorder(root.right)



# r = Node(3)    
# insert(r, Node(10))
# insert(r, Node(100))
# insert(r, Node(1))
# insert(r, Node(2))

# inorder(r)


##########################################################################################################

# BST MIN MAX FASHION AND SUM OF LEVELS
# class Node:
#     def __init__(self, key):
#         self.left = None
#         self.right = None
#         self.val = key

# def insert(root, node):
#     if node is None:
#         root = node
#     if root.val < node.val:
#         if root.right is None:
#             root.right = node
#         else:
#             insert(root.right, node)
#     else:
#         if root.left is None:
#             root.left = node
#         else:
#             insert(root.left, node)

# def get_ht(root):
#     if (root.left and root.right) == None:
#         return 0
    
#     left = 0
#     if root.left != None:
#         left = get_ht(root.left)
    
#     right = 0
#     if root.right != None:
#         right = get_ht(root.right)
#     return(max(right, left) + 1)

# sum = []
# def calc_sum(root, level):
#     global sum
#     if root == None:
#         return 0
    
#     sum[level] += root.val
#     calc_sum(root.left, level + 1)
#     calc_sum(root.right, level + 1)

# def print_tree(arr, n):
#     for i in range(n):
#         print(arr[i], end = ' ')

# # def sizeoftree(root):
# #     if root is None:
# #         return 0 
# #     left = sizeoftree(root.left)
# #     right = sizeoftree(root.right)
# #     return (1+left+right)

# # def min_max_utils(root, inorder, index):
# #     if root is None:
# #         return
# #     min_max_utils(root.left, inorder, index)
# #     inorder[index[0]] = root.val
# #     index[0] += 1
# #     min_max_utils(root.right, inorder, index)

# # def min_max(root):
# #     numnode = sizeoftree(root)
# #     inorder = [0] * (numnode +1)
# #     index = 0
# #     ref = [index]
# #     min_max_utils(root, inorder, ref)
# #     index = ref[0]
# #     index -= 1
# #     i =0
# #     while(i<index):
# #         print(inorder[i], inorder[index])
# #         i+=1
# #         index-=1
# #     if(i == index):
# #         print(inorder[i])


# root = Node(50)  
# insert(root, Node(30))  
# insert(root, Node(20)) 
# insert(root, Node(40))  
# insert(root, Node(70))  
# insert(root, Node(60))  
# insert(root, Node(80)) 

# levels = get_ht(root)
# print("LEVELS= ", levels)
# sums = [0] * levels
# calc_sum(sums, 0)
# print_tree(sums, levels)
# min_max(root)

#############################################################################################

#  LINEAR SEARCH
# def linear(arr, val):
#     n = len(arr)
#     for i in range(n):
#         if(arr[i] == val):
#             return "found"
            
#     return("not found")

# x = [2,4,3,1,5]            
# print(linear(x, 12))

# BINARY SEARCH
# def binary(arr, l , r, x):
#     if(r>=l):
#         mid = l + (r-1)//2
#         if(arr[mid] == x):
#             return mid
#         elif(arr[mid] < x):
#             return binary(arr, mid+1, r, x)
#         else:
#             return binary(arr, l, mid-1, x)
#     return -1

# x = [1,2,3,4]
# print(binary(x, 0 ,3, 2))


# JUMP SEARCH
# import math

# def jump(arr, x, n):
#     prev = 0
#     steps = math.sqrt(n)
#     while(arr[int(min(n, steps) -1)] < x):
#         prev = steps
#         steps += math.sqrt(n)
#         while(int(prev) >= n):
#             return -1
#     while(arr[int(prev)] < x):
#         prev += 1
#         if(min(n ,prev) == n):
#             return -1
#     if(x == arr[int(prev)]):
#         return int(prev)
        
# x = [5,6,7,8,9]
# print(jump(x, 9, 5))


# BUBBLE SORT
# def bubble(arr, n):
#     for i in range(0,n):
#         for j in range(0, n-i-1):
#             if(arr[j+1] < arr[j]):
#                 arr[j], arr[j+1] = arr[j+1], arr[j]

# arr = [64, 34, 25, 12, 22, 11, 90] 
# bubble(arr, len(arr))
# for i in range(len(arr)):
#     print(arr[i])


# SELECTION SORT
# def selection(arr, n):
#     for i in range(n):
#         min_idx = i
#         for j in range(i+1, n):
#             if(arr[min_idx] > arr[j]):
#                 min_idx = j
            
#         arr[i], arr[min_idx] = arr[min_idx], arr[i]

# arr = [64, 34, 25, 12, 22, 11, 90] 
# selection(arr, len(arr))
# for i in range(len(arr)):
#     print(arr[i])


# INSERTION SORT
# def insertion(arr, n):
#     for i in range(n):
#         key = arr[i]
#         j = i -1
#         while(j>=0 and key < arr[j]):
#             arr[j+1] = arr[j]
#             j -= 1
#         arr[j+1] = key

# arr = [64, 34, 25, 12, 22, 11, 90] 
# insertion(arr, len(arr))
# for i in range(len(arr)):
#     print(arr[i])


# MERGE SORT
# def mergesort(arr):
#     if(len(arr) > 1):
#         mid = len(arr)//2
#         L = arr[:mid]
#         R = arr[mid:]
#         mergesort(L)
#         mergesort(R)
#         i=j=k=0
#         while(i<len(L) and j<len(R)):
#             if(L[i] > R[j]):
#                 arr[k] = L[i]
#                 i+=1
#                 k+=1
#             else:
#                 arr[k] = R[j]
#                 j += 1
#                 k += 1
        
#         while(i<len(L)):
#             arr[k] = L[i]
#             k+=1
#             i+=1
        
#         while(j<len(R)):
#             arr[k] = R[j]
#             k+=1
#             j+=1

# arr = [64, 34, 25, 12, 22, 11, 90] 
# mergesort(arr)
# for i in range(len(arr)):
#     print(arr[i])


# HEAP SORT
# def heapify(arr, n, i):
#      l = 2*i+1
#      r = 2*i+2
#      largest = i

#      if(l < n and arr[l] < arr[i]):
#          largest = l

#      if(r < n and arr[r] < arr[largest]):
#          largest = r
    
#      if( i != largest):
#         arr[i], arr[largest] = arr[largest], arr[i]
#         heapify(arr, n, largest)

# def heapsort(arr):
#     n = len(arr)

#     for i in range(n-1//2, -1, -1):  # Max heap forming
#         heapify(arr, n, i)

#     for i in range(n-1,0,-1):        # Heapify performed for 0 to n-1 last is the largest value
#         arr[0], arr[i] = arr[i], arr[0]
#         heapify(arr, i, 0)


# arr = [64, 34, 25, 12, 22, 11, 90] 
# heapsort(arr)
# for i in range(len(arr)):
#     print(arr[i])



# BFS / DFS

# from collections import defaultdict

# class graph:
#     def __init__(self):
#         self.graph = defaultdict(list)
#     def addEdge(self, u, v):
#         self.graph[u].append(v)
#     def BFS(self, s):
#         visited = [False] * len(self.graph)
#         queue = []
#         queue.append(s)
#         visited[s] = True
#         while queue:
#             s = queue.pop(0)
#             print(s)
#             for i in self.graph[s]:
#                 if visited[i] == False:
#                     queue.append(i)
#                     visited[i] = True
    
#     def DFS_utils(self, v, visited):
#         visited[v] = True
#         print(v)
#         for i in self.graph[v]:
#             if visited[i] == False:
#                 self.DFS_utils(i, visited)

#     def DFS(self, s):
#         visited = [False] *(max(self.graph)+1)
#         self.DFS_utils(s, visited)

# g = graph() 
# g.addEdge(0, 1) 
# g.addEdge(0, 2) 
# g.addEdge(1, 2) 
# g.addEdge(2, 0) 
# g.addEdge(2, 3) 
# g.addEdge(3, 3) 
# g.DFS(2)





# AVL TREES
# class Node:
#     def __init__(self, key):
#         self.val = key
#         self.left = None
#         self.right = None
#         self.height = 1

# class AVL_tree(object):
#     def insert(self ,root, key):
#         if not root:
#             return Node(key)
#         elif(key > root.val):
#             root.left = self.insert(root.left, key)
#         else:
#             root.right = self.insert(root.right, key)

#         self.height = 1 + max(self.getheight(root.left), self.getheight(root.right))


#     def getheight(self, root):
#         if not root:
#             return 0

#         return root.height


# LINKED LIST

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Linkedlist:
    def __init__(self):
        self.head = None
        self.size = 0

    def append(self, data):
        if(self.head == None):
            self.head = Node(data)
        else:
            current = self.head
            while(current.next != None):
                current = current.next
            current.next = Node(data)
            self.size = self.size + 1

    def insert(self, data, pos):
        if(pos == 0):
            newnode = Node(data)
            newnode.next = self.head
            self.head = newnode
        elif(pos == self.size):
            self.append(data)
        elif(pos > self.size):
            print("Pos > size")
        else:
            count = 0
            current = self.head
            while(current.next != None):
                if(pos-2 == count):
                    break
                else:
                    current = current.next
            
            newnode = Node(data)
            newnode.next = current.next
            current.next = newnode
        
    def printlist(self):
        current = self.head
        while(current.next != None):
            print(current.data)
            current = current.next

mylinklist=Linkedlist()
mylinklist.append(4)
mylinklist.append(5)
mylinklist.append(8)
mylinklist.append(10)
print("\n\nThe linked list before insertion:\n\n")
mylinklist.printlist()
mylinklist.insert(6,3)
print("\n\nThe linked list after insertion:\n\n")
mylinklist.printlist()
mylinklist.insert(10,4)
print("\n\nThe linked list after insertion:\n\n")
mylinklist.printlist()
mylinklist.insert(2,0)
print("\n\nThe linked list after insertion:\n\n")
mylinklist.printlist()
mylinklist.insert(12,8)
