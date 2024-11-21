public class Solution {
    private const int Unguarded = 0;
    private const int Guarded = 1;
    private const int Guard = 2;
    private const int Wall = 3;
    private void MarkGuarded(int row ,int col , int[,] grid){
        int rows = grid.GetLength(0);
        int cols = grid.GetLength(1);
        for(int r =row - 1 ; r>=0;r--){
            if(grid[r,col] == Wall || grid[r,col] ==Guard) break;
            grid[r,col] = Guarded;
        }
        for(int r =row + 1 ; r<rows;r++){
            if(grid[r,col] == Wall || grid[r,col] ==Guard) break;
            grid[r,col] = Guarded;
        }
        for(int c =col - 1 ; c>=0;c--){
            if(grid[row,c] == Wall || grid[row,c] ==Guard) break;
            grid[row,c] = Guarded;
        }
        for(int c =col + 1 ; c<cols;c++){
            if(grid[row,c] == Wall || grid[row,c] ==Guard) break;
            grid[row,c] = Guarded;
        }
    }
    public int CountUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int [,] grid = new int[m,n];
        foreach (var guard in guards){
            grid[guard[0],guard[1]] = Guard;
        }
        foreach(var wall in walls){
            grid[wall[0],wall[1]] = Wall;
        }
        foreach(var guard in guards){
            MarkGuarded(guard[0],guard[1],grid);
        }
        int count = 0;
        foreach(int cell in grid){
            if(cell==Unguarded)
                count ++;
        }
        return count;
    }
}