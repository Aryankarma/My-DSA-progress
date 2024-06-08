// nothing just notes on why Quick Sort preferred for Arrays and Merge Sort for Linked Lists?

/*

    to know -
        - both have O(NlogN) time complexity if we take the avg case
        - am array stors all elements in continous blocks in the memory
        - as we have a next and prev pointer in a LL, it's elememts are stored randomizing (anuwhere) in the memory blocks


    Quick Sort -
        - an in place sort algorithm (mean it does not takes any extra space)


    Merge Sort -
        - it requires O(N) extra space to store elements
        - access is easy in LL alike array where we need to travel each element before ith to reach the i element
        - merge operations are pretty much efficient in terms of memory as we have the references to the next and prev pointer hence using merge sort won't hurt


*/