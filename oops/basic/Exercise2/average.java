package Exercise2;

import java.util.*;

public class average {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    double s = 0;
    for (int i = 0; i < n; i++) {
      s += sc.nextInt();
    }
    System.out.println("the average is " + s / n);
  }
}
