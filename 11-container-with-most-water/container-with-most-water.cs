public class Solution {
    public int MaxArea(int[] height) {
        int left = 0, right = height.Length - 1, area = 0, high = 0;
        while(left < right){
            area = Math.Max(area,(right-left) * Math.Min(height[left],height[right]));
            if(height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }

        }
        return area;
    }
}