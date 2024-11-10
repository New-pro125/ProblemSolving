public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        int[] realNums1 = nums1.Take(m).ToArray();
        int nums1Idx = 0,nums2Idx =0;
        while(nums1Idx<m&&nums2Idx<n){
            if(realNums1[nums1Idx]<nums2[nums2Idx]){
                nums1[nums1Idx+nums2Idx] = realNums1[nums1Idx];
                nums1Idx++;
            }
            else {
                nums1[nums1Idx+nums2Idx] = nums2[nums2Idx];
                nums2Idx++;
            }
        }
        while(nums1Idx<m){
            nums1[nums1Idx+nums2Idx] = realNums1[nums1Idx];
            nums1Idx++;
        }
        while(nums2Idx<n){
            nums1[nums1Idx+nums2Idx] = nums2[nums2Idx];
            nums2Idx++;
        }
    }
}