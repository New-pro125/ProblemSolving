public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
         Array.Sort(nums);
 if(nums.Length <3) return [];
 if (nums[0] > 0)
 {
     return [];
 }
 Dictionary<int, int> hashMap = new();
 for(int i = 0;i< nums.Length; i++)
 {
     hashMap[nums[i]] = i;
 }
 List<List<int>> answer = new();
 for(int i = 0; i < nums.Length - 2; i++)
 {
     if (nums[i] > 0)
     {
         break;
     }
     for(int j = i + 1; j < nums.Length - 1; j++)
     {
         int target = -(nums[i] + nums[j]);
         hashMap.TryGetValue(target,out int targetIndex);
         if (targetIndex > j)
         {
             answer.Add(new List<int> { nums[i], nums[j],target });
         }
         hashMap.TryGetValue(nums[j], out int value);
         j = value;
     }
         hashMap.TryGetValue(nums[i], out int value2);
         i = value2;
 }
        List<IList<int>> result = answer.Select(sub => (IList<int>)sub).ToList();
        return result;
    }
}