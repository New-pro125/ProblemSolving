function minSubarray(nums: number[], p: number): number {
    let sum = 0;
    for (const num of nums) sum += num;
    
    let target = sum % p;
    if (target === 0) return 0;
    
    let modMap = new Map<number, number>();
    modMap.set(0, -1);
    
    let currSum = 0, minLen = nums.length;
    
    for (let i = 0; i < nums.length; i++) {
        currSum = (currSum + nums[i]) % p;
        const needed = (currSum - target + p) % p;
        
        if (modMap.has(needed)) {
            minLen = Math.min(minLen, i - modMap.get(needed)!);
        }
        
        modMap.set(currSum, i);
    }
    
    return minLen === nums.length ? -1 : minLen;
}
