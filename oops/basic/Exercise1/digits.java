package Exercise1;
public class digits {

  public static void main(String[] args) {
    int n = 100;
    int r;
    for (int i = 1; i <= n;) {
      r = n % 10;
      n = n / 10;
      System.out.println(r);
    }
  }
}
