class Solution {
    public int[] resultArray(int[] nums) {
       ArrayList<Integer> arr1 = new ArrayList<>();
       ArrayList<Integer> arr2 = new ArrayList<>();
       arr1.add(nums[0]);
       arr2.add(nums[1]);
       int i = 2; int n = nums.length;
       while(i<n){
        if(arr1.getLast() > arr2.getLast()) {
            arr1.add(nums[i]);
        }
        else 
            arr2.add(nums[i]);
        i++;
       }
       arr1.addAll(arr2);
       return arr1.stream().mapToInt(Integer::intValue).toArray();
    }
}