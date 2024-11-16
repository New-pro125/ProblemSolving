using System;
using System.Collections.Generic;

public class Solution {
    public int[] ResultsArray(int[] nums, int k) {
        int length = nums.Length;
        int[] result = new int[length - k + 1];
        LinkedList<int> indexDeque = new LinkedList<int>();

        for (int currentIndex = 0; currentIndex < length; currentIndex++) {
            
            if (indexDeque.Count > 0 && indexDeque.First.Value < currentIndex - k + 1) {
                indexDeque.RemoveFirst();
            }

            
            if (indexDeque.Count > 0 && nums[currentIndex] != nums[currentIndex - 1] + 1) {
                indexDeque.Clear(); 
            }

            
            indexDeque.AddLast(currentIndex);

            
            if (currentIndex >= k - 1) {
                if (indexDeque.Count == k) { 
                    result[currentIndex - k + 1] = nums[indexDeque.Last.Value];
                } else {
                    result[currentIndex - k + 1] = -1; 
                }
            }
        }

        return result;
    }
}
