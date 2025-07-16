public class Solution {
    public bool Find132pattern(int[] nums) {
    Stack<int> stack = new();
int second = int.MinValue; // acts as nums[k]

for (int i = nums.Length - 1; i >= 0; i--)
{
    if (nums[i] < second)
        return true;

    while (stack.Count > 0 && nums[i] > stack.Peek())
        second = stack.Pop();

    stack.Push(nums[i]);
}

return false;
    }
}