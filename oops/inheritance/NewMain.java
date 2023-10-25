package inheritance;
import java.util.*;
import addition.add;
class calc extends add {
    calc(int a,int b){
        super(a,b);
    }
    int []sub(){
        int c[]={sum(),a-b};
        return c;
    }
   
}
public class NewMain{
    public static void main(String [] args){
        Scanner sc=new Scanner(System.in);
        int a= sc.nextInt();
        int b= sc.nextInt();
        calc z= new calc(a,b);
        int c[]=z.sub();
        for(int i=0;i<c.length;i++){
            System.out.println(c[i]);
        }
    }
}
