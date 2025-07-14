public class Solution {
    public int MaxArea(int[] height) {
        int left = 0, right = height.Length - 1, area = 0, high = 0;
        while(left < right){
            high = Math.Min(height[left],height[right]);
            area = Math.Max(area,high * (right - left));
            while(left < right && height[left] <=high) left++;
            while(left < right && height[right] <=high) right--;
        }
        return area;
    }
}