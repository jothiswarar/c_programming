import java.util.Scanner;
class hello{
    public static void main(String[] args){
        
        int n;
        Scanner sc= new Scanner(System.in);
        n=sc.nextInt();
        int a=0;
        int b=1;
        System.out.println("\n"+a+"\n"+b);
        for(int i=2;i<n;i++){
            int temp=a+b;
            a=b;
            b=temp;
            System.out.println(b);
        }
        sc.close();
    }
}