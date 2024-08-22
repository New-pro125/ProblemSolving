const findFirstOne = (num:number):number => Math.floor(Math.log2(num))-1 
function findComplement(num: number): number {
    let complementNumber = 0;
    console.log(findFirstOne(num))
    for(let i =findFirstOne(num);i>=0;i--){
        if(((1<<i)&num)==0)
        complementNumber +=(1)<< i
    }
    return complementNumber
};