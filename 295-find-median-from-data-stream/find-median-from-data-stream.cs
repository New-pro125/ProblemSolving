public class MedianFinder {
   PriorityQueue<int, int> maxHeap = new (Comparer<int>.Create((x,y) => y.CompareTo(x)));
   PriorityQueue<int, int> minHeap = new ();
   public MedianFinder() { 
   }
   public void AddNum(int value)
   {
       if(maxHeap.Count == 0 || value <= maxHeap.Peek())
       {
           maxHeap.Enqueue(value,value);
       }
       else
       {
           minHeap.Enqueue(value,value);
       }
       // balance the heaps
       if (minHeap.Count + 1 < maxHeap.Count)
       {
           int element = maxHeap.Dequeue();
           minHeap.Enqueue(element, element);
       }
       else if (maxHeap.Count < minHeap.Count) 
       {
           int element = minHeap.Dequeue();
           maxHeap.Enqueue(element, element);
       }
   }
   public double FindMedian()
   {
       int size = maxHeap.Count + minHeap.Count; 
       if(size % 2 != 0)
       {
           return (double) maxHeap.Peek();
       }
       return (maxHeap.Peek() + minHeap.Peek())/2.0;
   }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.AddNum(num);
 * double param_2 = obj.FindMedian();
 */