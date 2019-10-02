def quicksort(arr, first, last):
    '''sort the list from arr[first] to arr[last] using quicksort algorithm'''
    if first >= last:
        return
    pivot = arr[last]
    left = first
    right = last-1
    while left <= right:
        #scan until reaching value equal or larger than pivot (or right marker)
        while left <= right and arr[left] < pivot:
            left += 1
        #scan until reaching value equal or smaller than pivot (or left marker)
        while left <= right and pivot < arr[right]:
            right -= 1
        if left <= right:   # scans did not strictly cross
            arr[left], arr[right] = arr[right], arr[left]
            left, right = left+1, right-1

    # put pivot into its final place (currently marked by left index)
    arr[left], arr[last] = arr[last], arr[left]
    #mark recursive calls
    quicksort(arr, first, left-1)
    quicksort(arr, left+1, last)
