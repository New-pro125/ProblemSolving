let res:string[][] ;
function isPalindrome(s:string){
    for(let i=0;i<=Math.floor(s.length/2);i++){
        if(s[i]!=s[s.length-i-1])
            return false;
    }
    return true
}
function recPartition(s:string,idx:number,partition:string[]){
    if(idx==s.length){
        res.push([...partition])
        return
    }
    for(let i=idx;i<s.length;i++){
        const str = s.substring(idx,i+1)
        if(isPalindrome(str)){
            partition.push(str)
            recPartition(s,i+1,partition)
            partition.pop()
        }
    }
}

function partition(s: string): string[][] {
    res = []
    recPartition(s,0,[]);
    return res  
};