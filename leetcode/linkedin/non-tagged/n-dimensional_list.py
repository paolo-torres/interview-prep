'''
You are given an N-Dimensional list with 2 methods:
i) getDim -> returns the dimensions .e.g [5,4,3].
ii) getElement([i,j,k]) -> return list[i][j][k] . You have to implement a method to sum all elements in the list.
'''

# Ex:- If we have 3D list of dimensions [2,2,3]
# We will have a total of 2*2*3 = 12 elements
# To get the correspoding indices for these elements
# 0 0 0
# 0 0 1
# 0 0 2
# 0 1 0
# ...
# ...
# 1 1 1
# 1 1 2
# The strategy is to increment the last index value and once
# we hit the dimension length of that particular index we mark it as zero
# and increment the prior index value and if reaches end as well, we continue
# to increment its prev index; the moment we reach a index which doesn't overflow
# we can break

def get_all_elems_sum(dims):
    n = len(dims) # no of dimensions
    elems_count = math.prod(dims) # get the total no. of elements that will be present
    dim_idxs = [0]*n # Start with indices of 0, 0, 0.. 0
    total = 0
    total += get_elem[tuple(dim_idxs)] # Get the element at the very first possible index
    for num in range(elems_count-1): # Loop to go over each element
        for dim in range(n-1, -1, -1): # Loop to run through dims from the end
            dim_idxs[dim] += 1
            if dim_idxs[dim] < dims[dim]:
                # If we are within the bounds of the current dimension after incrementing
                # we can stop right here and use the index to get element
                break
            # Otherwise we reached the end of current dimension, lets reset it to zero
            # and go to previous index and increment it.
            dim_idxs[dim] = 0

        total += get_elem[tuple(dim_idxs)]

    return total
    
print(get_all_elems_sum(dims))

'''
N - Total no. of elements, M - Total no. of dimensions
Time Complexity: O(N*M)
Space Complexity: O(M)
'''
