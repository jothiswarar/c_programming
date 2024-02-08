package Exercise5;



import java.util.*;

class Invoice {

  String number;
  String description;
  int quantity;
  double price;

  Invoice(String a, String b, int c, double d) {
    number = a;
    description = b;
    quantity = c;
    price = d;
    if (c < 0) {
      quantity = 0;
    }
    if (d < 0) {
      price = 0;
    }
  }

  void setnumber(String a) {
    number = a;
  }

  String getnumber() {
    return number;
  }

  void setdescription(String a) {
    description = a;
  }

  String getdescription() {
    return description;
  }

  void setquantity(int a) {
    quantity = a;
    if (a < 0) {
      quantity = 0;
    }
  }

  int getquantity() {
    return quantity;
  }

  void setprice(int a) {
    price = a;
    if (a < 0) {
      price = 0;
    }
  }

  double getprice() {
    return price;
  }

  double getInvoiceAmount() {
    return quantity * price;
  }
}

public class InvoiceTest {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String a, b;
    int c;
    double d;
    a = sc.nextLine();
    b = sc.nextLine();
    c = sc.nextInt();
    d = sc.nextDouble();
    Invoice i = new Invoice(a, b, c, d);
    System.out.println("Part Number:" + i.getnumber());
    System.out.println("Part Descrption:" + i.getdescription());
    System.out.println("Quantity:" + i.getquantity());
    System.out.println("Price per item:" + i.getprice());
    System.out.println("Total Amount:" + i.getInvoiceAmount());
    System.out.print(
      "If there is a change enter 0(No Changes),1(part number),2(part description),3(Quatity),4(price per item)"
    );
    System.out.println(" and Enter the changes");
    int p = sc.nextInt();
    switch (p) {
      case 1:
        {
          i.setnumber(sc.nextLine());
          break;
        }
      case 2:
        {
          i.setdescription(sc.nextLine());
          break;
        }
      case 3:
        {
          i.setquantity(sc.nextInt());
          break;
        }
      case 4:
        {
          i.setprice(sc.nextInt());
          break;
        }
      default:
        {
          break;
        }
    }
    System.out.println("Part Number:" + i.getnumber());
    System.out.println("Part Descrption:" + i.getdescription());
    System.out.println("Quantity:" + i.getquantity());
    System.out.println("Price per item:" + i.getprice());
    System.out.println("Total Amount:" + i.getInvoiceAmount());
    sc.close();
  }
}
