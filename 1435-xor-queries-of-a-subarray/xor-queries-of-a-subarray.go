func xorQueries(arr []int, queries [][]int) []int {
    pref := make([]int,len(arr))
    res := make([]int,0,len(queries))
    pref[0]= arr[0]
    for i:=range pref {
        if i>0{
            pref[i] = pref[i-1]^arr[i]
        }
    }
    for _,query:=range queries {
        xored_res := pref[query[1]]
        if query[0]>0{
            xored_res ^=pref[query[0]-1]
        }
        res = append(res,xored_res)
    }
    return res
}