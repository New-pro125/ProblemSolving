public class Solution {
    private const char EMPTY  = '.';
    private const char STONE = '#';
    private const char OBSTACLE = '*';
    private void RearrangeBox(char[][]box){
        // int[] firstEmptyColIdx = new int[box[0].Length];
            for(int j = 0;j<box[0].Length;j++){
                int emptyIdx = box.Length - 1;
                for(int i = box.Length-1;i>=0;i--){
                    if(box[i][j]==STONE){
                        emptyIdx = emptyIdx < i ? i: emptyIdx;
                        box[emptyIdx][j] = STONE;
                        if(emptyIdx!=i)
                            box[i][j] = EMPTY;
                    }
                    else if(box[i][j]==OBSTACLE){
                        emptyIdx = i;
                    }
                    while(emptyIdx > 0 && box[emptyIdx][j]!=EMPTY)
                        emptyIdx--;
                }
            }
            // for(int j = 0 ;j<box[0].Length;j++){
            //     Console.Write("{0} ",firstEmptyColIdx[j]);
            // }
            // Console.WriteLine();
        }
    public char[][] RotateTheBox(char[][] box) {
        if(box.Length==0){
            return [[]];
        }
        char[][] rotatedBox = new char[box[0].Length][];
        for(int i = 0;i<rotatedBox.Length;i++){
            rotatedBox[i] = new char[box.Length];
        }
        for(int i = 0;i<box.Length;i++){
            for(int j = 0;j<box[0].Length;j++){
                rotatedBox[j][box.Length - i-1] = box[i][j];
            }
        }
        RearrangeBox(rotatedBox);
        return rotatedBox;
    }
}