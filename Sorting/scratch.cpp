function heapSort(a, count) is
   input: an unordered array a of length count
 
   (first place a in max-heap order)
   heapify(a, count)
 
   end := count - 1
   while end > 0 do
      (swap the root(maximum value) of the heap with the
       last element of the heap)
      swap(a[end], a[0])
      (decrement the size of the heap so that the previous
       max value will stay in its proper place)
      end := end - 1
      (put the heap back in max-heap order)
      siftDown(a, 0, end)
	  
	  
	  function heapify(a,count) is
   (start is assigned the index in a of the last parent node)
   start := (count - 2) / 2
   
   while start = 0 do
      (sift down the node at index start to the proper place
       such that all nodes below the start index are in heap
       order)
      siftDown(a, start, count-1)
      start := start - 1
   (after sifting down the root all nodes/elements are in heap order)
 
function siftDown(a, start, end) is
   (end represents the limit of how far down the heap to sift)
   root := start

   while root * 2 + 1 = end do     
      child := root * 2 + 1        
     
	 if child + 1 = end and a[child] < a[child + 1] then
         child := child + 1        
      if a[root] < a[child] then   
         swap(a[root], a[child])
         root := child                (repeat to continue sifting down the child now)
      else
         return