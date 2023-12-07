
public class fibb {

  public static void main(String[] args) {
    int a = 0;
    int b = 1;
    System.out.println(a);
    System.out.println(b);
    int n = 5;
    int i, f;
    for (i = 2; i < n; i++) {
      f = a + b;
      System.out.println(f);
      a = b;
      b = f;
    }
  }
}
