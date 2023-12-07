package ex8;

public class Main {

  static void s() throws ArrayIndexOutOfBoundsException {
    int a[] = { 1, 2, 3, 4, 5, 6 };
    try {
      System.out.println(a[10]);
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Catch inside s");
      throw e;
    } finally {
      System.out.println("Finally block in s");
    }
  }

  static void r() throws ArrayIndexOutOfBoundsException {
    try {
      s();
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Catch inside r");
      throw e;
    } finally {
      System.out.println("Finally bock in r");
    }
  }

  static void q() throws ArrayIndexOutOfBoundsException {
    try {
      r();
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Catch inside q");
      throw e;
    } finally {
      System.out.println("Finally bock in q");
    }
  }

  static void p() throws ArrayIndexOutOfBoundsException {
    try {
      q();
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Catch inside p");
      throw e;
    } finally {
      System.out.println("Finally bock in p");
    }
  }

  public static void main(String[] args) {
    try {
      p();
    } catch (Exception e) {
      System.out.println("Catch inside main");
      System.out.println(e);
    } finally {
      System.out.println("Finally bock in main");
    }
  }
}
