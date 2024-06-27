import java.util.*;
public class Main{
  public static void main(String [] args){
    int n;
    Scanner s=new Scanner(System.in);
    n=s.nextInt();
    StringBuilder t=new StringBuilder();
    String ch="10";
    for(int i=0;i<n;i++) t.append(ch);
    t.append('1');
    System.out.println(t);
  }
}