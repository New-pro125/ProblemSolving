function isGood(piles:number[],h:number,k:number):boolean{
    let sum = piles.reduce((accumlator,pile)=>{ return accumlator+=Math.ceil(pile/k)},0)
    return sum<=h
}
function minEatingSpeed(piles: number[], h: number): number {
    let s=0 , e = 1e18;
    let ans = -1
    while(s<=e){
        let k = Math.floor(s+(e-s)/2)
        if(isGood(piles,h,k)){
            e = k-1
            ans = k;
        }
        else {
            s = k+1
        }
    }
    return ans;
};