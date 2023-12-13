import java.io.*;

public class file {

  public static void main(String args[]) throws IOException {
    int c;
    FileInputStream a;
    try{
        a=new FileInputStream("hi.txt");
    }
    catch(IOException e){
        System.out.println(e);
       return;
    }
    try{
    while(true){
      c =  a.read();
      if(c==-1){
        break;
      }
      System.out.print((char)c);
    } 
    }
    catch(Exception e){
        System.out.println(e);
    }
  }
}
