
import java.util.Scanner;

public class primeseries {

  public static void main(String a[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int c = 0;
    for (int i = 2; c < n; i++) {
      int prime = 1;
      for (int j = 2; j < i; j++) {
        if (i % j == 0) {
          prime = 0;
        }
      }
      if (prime == 1) {
        System.out.println(i);
        c++;
      }
    }
  }
}
