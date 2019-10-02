def merge(L, R, arr):
    '''Merge two sorted lists L and R into properly sized list arr'''
    i=j=0
    while i+j < len(arr):
        if j == len(R) or (i < len(L) and L[i] < R[j]):
                arr[i+j] = L[i]     # copy ith element of L as next item of arr
                i += 1
        else:
            arr[i+j] = R[j]         # copy jth element of R as next item of arr
            j += 1

def merge_sort(arr):
    ''' Sor the elements of list arr'''
    n = len(arr)
    if n < 2:
        return
    mid = n//2
    L = arr[0:mid]  #first half of list - Left side
    R = arr[mid:n]  #second half of list - Right side
    merge_sort(L)   #sort first half
    merge_sort(R)   #sort second half
    merge(L, R, arr)#merge halfs back together

