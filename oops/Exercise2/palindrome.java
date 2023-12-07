package Exercise2;

import java.util.*;

class palin {

  int a;

  palin(int c) {
    a = c;
  }

  int reverse(int a) {
    int c = 0;
    //int r=0;
    while (a != 0) {
      c *= 10;
      c += (a % 10);
      a = a / 10;
    }
    return c;
  }

  boolean palindrome() {
    if (a == reverse(a)) {
      return true;
    } else {
      return false;
    }
  }
}

public class palindrome {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter a number;");
    int a = sc.nextInt();
    palin c = new palin(a);
    if (c.palindrome()) {
      System.out.println(a + " is palindrome");
    } else {
      System.out.println(a + " is not a palindrome");
    }
  }
}
