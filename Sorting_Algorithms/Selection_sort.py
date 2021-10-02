
def selectionAscending(array): #sorts the array in Increasing order
    l=len(array)
    for i in range(l):
        min_element=array[i]
        min_index=i
        for j in range(i+1,l):
            if array[j]<min_element:
                min_element=array[j]
                min_index=j
        array[i],array[min_index]=array[min_index],array[i]
    return array

def selectionDescending(array): #sorts the array in Decreasing order
    l=len(array)
    for i in range(l):
        max_element=array[i]
        max_index=i
        for j in range(i+1,l):
            if array[j]>max_element:
                max_element=array[j]
                max_index=j
        array[i],array[max_index]=array[max_index],array[i]
    return array

def display(array):
    for i in array:
        print(i,end=" ")
    print()
    return 

if __name__=="__main__":
    array=list(map(int,input("Array: ").split()))
    display(selectionAscending(array))
    display(selectionDescending(array))
    


