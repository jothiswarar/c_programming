import java.io.*;
import java.util.*;
public class fle3 {

  public static void main(String args[]) throws IOException {
   Scanner sc= new Scanner(System.in);
   int n=sc.nextInt();
   String a="";
   for(int i=0;i<n;i++){
    a+=sc.nextLine()+"\n";
   }
   char c[]=a.toCharArray();
    try{
        FileOutputStream b=new FileOutputStream("hi2.txt");
        
    for(int i=0;i<c.length;i++){
        b.write((int)c[i]);
    }
    System.out.println("Sucessful");
    }
    catch(Exception e){
        System.out.println(e);
    }
  }
}
