
import java.util.*;

class calculator {

  int a, b;

  public calculator(int c, int d) {
    a = c;
    b = d;
  }

  int add() {
    return a + b;
  }

  int sub() {
    if (a > b) {
      return a - b;
    } else {
      return b - a;
    }
  }

  int mul() {
    return a * b;
  }

  double div() {
    return a / b;
  }
}

public class cal {

  public static void main(String[] args) {
    int a, b;
    Scanner sc = new Scanner(System.in);
    a = sc.nextInt();
    b = sc.nextInt();
    calculator c = new calculator(a, b);
    String s = sc.next();
    switch (s) {
      case "+":
        {
          System.out.println(c.add());
          break;
        }
      case "-":
        {
          System.out.println(c.sub());
          break;
        }
      case "*":
        {
          System.out.println(c.mul());
          break;
        }
      case "/":
        {
          System.out.println(c.div());
          break;
        }
      default:
        {
          System.out.println("Enter a valid Operand.");
        }
    }
  }
}
