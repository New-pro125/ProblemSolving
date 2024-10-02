function wordBreak(s: string, wordDict: string[]): boolean {
    const memo = new Map<string, boolean>();  
    
    const trial = (composed: string): boolean => {
        if (composed.length === s.length) return composed === s;  
        if (memo.has(composed)) return memo.get(composed);  

        let ans = false;
        for (const word of wordDict) {
            if (s.startsWith(composed.concat(word))) {
                
                ans ||= trial(composed.concat(word));
                if (ans) break;  
            }
        }
        
        memo.set(composed, ans);  
        return ans;
    };

    return trial("");
}
