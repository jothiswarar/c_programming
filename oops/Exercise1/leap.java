package Exercise1;


import java.util.*;
public class leap {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int y = sc.nextInt();
    if (y % 4 == 0) System.out.println("leap year"); else System.out.println(
      "not a leap year"
    );
  }
}
