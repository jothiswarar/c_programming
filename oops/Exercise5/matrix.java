

import java.util.*;

class array {

  int a[][];
  int b[][];
  Scanner sc = new Scanner(System.in);

  array(int n, int m) {
    a = new int[n][m];
    b = new int[n][m];
    System.out.println("Enter the elements of first matrix:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = sc.nextInt();
      }
    }
    System.out.println("Enter the elements of second matrix:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        b[i][j] = sc.nextInt();
      }
    }
  }

  array(int n, int m, int o) {
    a = new int[n][m];
    b = new int[m][o];
    System.out.println("Enter the elements of first matrix:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = sc.nextInt();
      }
    }
    System.out.println("Enter the elements of second matrix:");
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < o; j++) {
        b[i][j] = sc.nextInt();
      }
    }
  }

  array(int n, int m, int o, int p) {
    a = new int[n][m];
    b = new int[o][p];
    System.out.println("Enter the elements of first matrix:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = sc.nextInt();
      }
    }
    System.out.println("Enter the elements of second matrix:");
    for (int i = 0; i < o; i++) {
      for (int j = 0; j < p; j++) {
        b[i][j] = sc.nextInt();
      }
    }
  }

  array(int n) {
    a = new int[n][n];
    b = new int[n][n];
    System.out.println("Enter the elements of first matrix:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = sc.nextInt();
      }
    }
    System.out.println("Enter the elements of second matrix:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        b[i][j] = sc.nextInt();
      }
    }
  }

  void addition() {
    if (a.length == b.length && a[0].length == b[0].length) {
      int[][] c = new int[a.length][a[0].length];
      for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a[0].length; j++) {
          c[i][j] = a[i][j] + b[i][j];
        }
      }
      System.out.println("Matrix Addition:");
      for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a[0].length; j++) {
          System.out.print(c[i][j] + "\t");
        }
        System.out.println();
      }
    } else {
      System.out.println("Matix of different order can't be added");
    }
  }

  void subraction() {
    if (a.length == b.length && a[0].length == b[0].length) {
      int[][] c = new int[a.length][a[0].length];
      for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a[0].length; j++) {
          c[i][j] = a[i][j] - b[i][j];
        }
      }
      System.out.println("Matrix Subraction:");
      for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a[0].length; j++) {
          System.out.print(c[i][j] + "\t");
        }
        System.out.println();
      }
    } else {
      System.out.println("Matix of different order can't be subracted");
    }
  }

  void multiplication() {
    if (a[0].length == b.length) {
      int c[][] = new int[a.length][b[0].length];
      for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < b[0].length; j++) {
          c[i][j] = 0;
          for (int k = 0; k < b.length; k++) {
            c[i][j] += a[i][k] * b[k][j];
          }
        }
      }
      System.out.println("Matrix Multiplication:");
      for (int i = 0; i < c.length; i++) {
        for (int j = 0; j < c[0].length; j++) {
          System.out.print(c[i][j] + "\t");
        }
        System.out.println();
      }
    } else {
      System.out.println("Given matrices can't be Multiplied");
    }
  }
}

public class matrix {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a, b, c, d;
    System.out.println("Enter Row 1:");
    a = sc.nextInt();
    System.out.println("Enter column 1:");
    b = sc.nextInt();
    System.out.println("Enter Row 2:");
    c = sc.nextInt();
    System.out.println("Enter Column 2:");
    d = sc.nextInt();
    array o;
    if (b == c && a != d) {
      o = new array(a, b, d);
    } else if (a == c && b == d) {
      if (b == c) {
        o = new array(a);
      } else {
        o = new array(a, b);
      }
    } else {
      o = new array(a, b, c, d);
    }
    o.addition();
    o.subraction();
    o.multiplication();
    sc.close();
  }
}
