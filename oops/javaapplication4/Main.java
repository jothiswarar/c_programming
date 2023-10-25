package javaapplication4;
import java.util.*;
public class Main {

   
    public static void main(String[] args) {
       
        Scanner sc=new Scanner(System.in);
        StackTest a= new StackTest();
        int z,b;
       
        do {
            System.out.println("Enter Choice\n1.Push\n2.Pop\n3.Exit");
            z=sc.nextInt();
            switch (z) {
                case 1:
                    System.out.println("Enter the Element:");
                    b=sc.nextInt();
                    a.push(b);
                    System.out.println("Pushed Sucessfully.");
                    break;
                case 2:
                    b=a.pop();
                    if(b!=-1){
                        System.out.println("Popped Element: "+b);
                    }   break;
                case 3:
                    return;
                default:
                    System.out.println("Invalid Arguments");
                    break;
            }
        } while (true);
    }
   
}
