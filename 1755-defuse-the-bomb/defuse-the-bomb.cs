public class Solution {
    public int[] Decrypt(int[] code, int k) {
        int[] decryptedMessage = new int[code.Length];
        for(int i=0;i<code.Length;i++){
            int res = 0;
            if(k>0){
                for(int j = 0;j<k;j++){
                    res += code[(i+1+j)%code.Length];
                }     
            }
            else if(k<0){
                for(int j = 0;j<-k;j++){
                    res += code[(i-1-j+code.Length)%code.Length];
                }     
            }
            decryptedMessage[i] = res;
        }
        return decryptedMessage;
    }
}