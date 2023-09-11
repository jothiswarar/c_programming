import java.util.*;
class sort{
    //int a[];
    
    int[] bubble(int[] a){
        int c;
        for(int i=0;i<a.length;i++){
            for(int j=i+1;j<a.length;j++){
                if(a[i]>a[j]){
                    c=a[i];
                    a[i]=a[j];
                    a[j]=c;
                }
            }
        }
        return a;
    }
}
public class sorting{
    public static void main(String[] args){
        int[] a;
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        a=new int[n];
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        sort c=new sort();
        a=c.bubble(a);
        System.out.println();
        for(int i=0;i<a.length;i++){
            System.out.println(a[i]);
        }
        sc.close();
    }
}