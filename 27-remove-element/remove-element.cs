public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int[] newArr =  nums.Where(n => n!=val).ToArray();
        Array.Copy(newArr,nums ,newArr.Length);
        return newArr.Length;
    }
}