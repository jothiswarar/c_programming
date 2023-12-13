import java.io.*;

public class file2 {

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
        FileOutputStream b=new FileOutputStream("hi2.txt");
    while(true){
      c =  a.read();
      if(c==-1){
        break;
      }
      b.write(c);
    } 
    System.out.println("Sucessful");
    }
    catch(Exception e){
        System.out.println(e);
    }
  }
}
