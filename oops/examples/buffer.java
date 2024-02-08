package examples;

import java.io.*;

public class buffer {

  public static void main(String[] args) {
      try {
    BufferedReader a = new BufferedReader(new FileReader("D:\\jo_programs\\c_programming\\oops\\String\\anagram.java"));
      String line = a.readLine();
      while (line!=null){
        System.out.println(line);
        line = a.readLine();
      }
      a.close();
    } catch (Exception b) {
      System.out.println(b);
    }
  }
}
