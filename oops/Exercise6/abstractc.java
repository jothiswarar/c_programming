
import java.util.*;
abstract class Accounts{
    double balance;
    String acct_no;
    String name;
    String address;
    abstract void withdrawal(int a);
    abstract void deposit(int a);
    void display(){
        System.out.println("Balance is "+balance);
    }
}
class SavingsAccount extends Accounts{
    int rateofinterest;
    SavingsAccount(double a,String b,String c,String d){
        balance=a;
        acct_no=b;
        name=c;
        address=d;
    }
    void withdrawal(int a){
        if(a>=0&&balance>=a){
            balance=balance-a;
            System.out.println("Withdrawed");
            display();
        }
        else{
            System.out.println("Not a valid input");
        }
    }
    void deposit(int a){
        if(a>0){
            balance+=a;
            System.out.println("Deposited");
            display();
        }
        else{
            System.out.println("Not a valid input");
        }
    }
    void calculateAmount(){
        System.out.println(balance+(balance*rateofinterest/100));
    }
}
class abstractc{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        double a=sc.nextDouble();
        String b=sc.nextLine();
        String c=sc.nextLine();
        String d=sc.nextLine();
        SavingsAccount n=new SavingsAccount(a,b,c,d);
        n.display();
        System.out.print("Enter Rate of Interest:");
        n.rateofinterest=sc.nextInt();
        n.calculateAmount();
        System.out.print("Enter Amount to be deposited:");
        n.deposit(sc.nextInt());
        System.out.print("Enter Amount to be withdrawed:");
        n.withdrawal(sc.nextInt());
        n.calculateAmount();
        sc.close();
    }
}