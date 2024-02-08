package Exercise5;



import java.util.*;

public class Reverse {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a[];
    int n = sc.nextInt();
    a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    for (int i = 0; i < n; i++) {
      System.out.print(a[i] + "\t");
    }
    for (int i = 0; i < n / 2; i++) {
      int temp = a[i];
      a[i] = a[n - i - 1];
      a[n - i - 1] = temp;
    }
    System.out.println("\nReversed Array:");
    for (int i = 0; i < n; i++) {
      System.out.print(a[i] + "\t");
    }
  }
}
