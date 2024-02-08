import java.util.*;

public class alpha{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String a=sc.nextLine();
        char b[]=a.toCharArray();
        for(int i=0;i<b.length-1;i++){
            for(int j=0;j<b.length-i-1;j++){
                if(b[j]>b[j+1]){
                    char temp =b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
        }
        System.out.println(b);
    }
}