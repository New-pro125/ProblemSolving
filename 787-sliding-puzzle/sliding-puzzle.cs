public class Solution {
    // direction map for zero's possible moves in a flatten 1D array
    private readonly int [][] directions = {
        new int[] {1,3},
        new int[] {0,2,4},
        new int[] {1,5},
        new int[] {0,4},
        new int[] {3,5,1},
        new int[] {4,2}
    };
    public int SlidingPuzzle(int[][] board) {
        StringBuilder startState = new StringBuilder();
        for(int i =0 ;i<2;i++){
            for(int j = 0;j<3;j++){
                startState.Append(board[i][j]);
            }
        }
        Dictionary<string,int> visited = new Dictionary<string,int>();
        Dfs(startState.ToString(),visited,startState.ToString().IndexOf('0'),0);
        return visited.ContainsKey("123450") ? visited["123450"] : -1 ; 
    }
    private void Dfs(string state,Dictionary<string,int>visited,int zeroPos,int moves){
        if(visited.ContainsKey(state) && visited[state]<=moves){
            return;
        }
        visited[state] = moves;
        foreach(int nextPos in directions[zeroPos]){
            string newState = Swap(state,zeroPos,nextPos);
            Dfs(newState,visited,nextPos,moves+1);
        }
    }
    // C# string is immutable
    private string Swap(string str,int i ,int j){
        char [] arr = str.ToCharArray();
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        return new string(arr);
    }
}