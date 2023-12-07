
public class Primeno {

  public static void main(String[] args) {
    int n = 23, i;
    for (i = 2; i < n; i++) {
      if (n % i == 0) {
        System.out.println(n + " is not a prime number");
        break;
      }
    }
    if (i == n) {
      System.out.println(n + "is a prime number");
    }
  }
}
