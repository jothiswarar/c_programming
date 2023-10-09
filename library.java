import java.util.*;
abstract class Library_Management{
    static String[] a=new String[100];
    static int i=0;
    abstract void getbookname();
    void add(String b){
        a[i]=b;
        
        i++;
    }
    void displaybook(){
        for(int j=0;j<i;j++){
            System.out.println(a[j]);
        }
    }
    
    void Search(String b){
        for(int j=0;j<i;j++){
            if(a[j]==b){
                System.out.println(b+" is found at "+(j+1)+" position");
            }
        }
    }
}
class Issue extends Library_Management{
    void getbookname(){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter book to be Issued:");
        Decrement(sc.nextLine());
        System.out.println("Book is issued");
    }
    void Decrement(String b){
        for(int j=0;j<i;j++){
            if(a[j]==b){
                
                for(int k=j+1;k<i;k++){
                    a[j]=a[k];
                    j++;
                }
                i--;
                break;
            }
        }
        
        
    }
}
class Return extends Library_Management{
    void getbookname(){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter book to be Returned:");
        Increment(sc.nextLine());
        System.out.println("Book is Returned");
    }
    void Increment(String b){
        a[i]=b;
        
        i++;

    }
}
public class library {
    public static void main(String [] args){
        Issue i=new Issue();
        Return r=new Return();
        i.add("book 1");
        i.add("book 2");
        r.add("book 3");
        i.displaybook();
        i.getbookname();
        i.displaybook();
        i.getbookname();
        r.getbookname();
        r.displaybook();
        i.Search("book 2");
    }
}
