package Exercise1;
import java.util.Scanner;

public class prime {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt(), k = 0;
    int i;
    for (i = 2; i < a - 1; i++) {
      if (a % i == 0) k = 1;
    }
    if (k == 0) System.out.println("prime"); else System.out.println(
      "Not prime"
    );
  }
}
