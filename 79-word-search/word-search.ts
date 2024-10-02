
function exist(board: string[][], word: string): boolean {
    if(board.length===0 || board[0].length===0) return false
    let found = false
    let start_x = []
    let start_y = []
    for(let i=0;i<board.length;i++){
        for(let j =0;j<board[0].length;j++){
            if(board[i][j]===word[0]){
                start_x.push(j)
                start_y.push(i)
            }
        }
    }
    let visited = Array.from({length:board.length},()=>Array(board[0].length).fill(false)) 
    const find = (x,y,indices_found) => {
        if(indices_found===word.length) {
            return true
        }
        visited[x][y] = true;
        let ans = false
        if(x-1>=0&&board[x-1][y]===word[indices_found]&&!visited[x-1][y]){
            ans||=find(x-1,y,indices_found+1)
        }
         if(x+1<board.length&&board[x+1][y]===word[indices_found]&&!visited[x+1][y]){
            ans||=find(x+1,y,indices_found+1)
        }
         if(y-1>=0&&board[x][y-1]===word[indices_found]&&!visited[x][y-1]){
            ans||=find(x,y-1,indices_found+1)
        }
         if(y+1<board[0].length&&board[x][y+1]===word[indices_found]&&!visited[x][y+1]){
            ans||=find(x,y+1,indices_found+1)
        }
        visited[x][y] = false
        return ans
    }
    let res = false
    for(let i = 0;i<start_x.length;i++){
        let indices_found = 1;
        
        let y  = start_x[i]
        let x  = start_y[i]
        // console.log(x,y)
        res||=find(x,y,indices_found)
    }
    
    return res
};