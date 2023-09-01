import java.util.*;
class money{
    int a,c;
    money(int a){
        this.a=a;
    }
    void denominate(){
        if(a>=2000){
            c=a/2000;
            System.out.println(c+" * 2000 = "+c*2000);
            a%=2000;
        }
        if(a>=500){
            c=a/500;
            System.out.println(c+" * 500 = "+c*500);
            a%=500;
        }if(a>=200){
            c=a/200;
            System.out.println(c+" * 200 = "+c*200);
            a%=200;
        }
        if(a>=100){
            c=a/100;
            System.out.println(c+" * 100 = "+c*100);
            a%=100;
        }
        if(a>=50){
            c=a/50;
            System.out.println(c+" * 50 = "+c*50);
            a%=50;
        }
        if(a>=10){
            c=a/10;
            System.out.println(c+" * 10 = "+c*10);
            a%=10;
        }
        if(a>=5){
            c=a/5;
            System.out.println(c+" * 5 = "+c*5);
            a%=5;
        }
        if(a>=2){
            c=a/2;
            System.out.println(c+" * 2 = "+c*2);
            a%=2;
        }if(a>=1){
            c=a/1;
            System.out.println(c+" * 1 = "+c*1);
            a%=1;
        }
    }

}
public class denomination{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        money a=new money(n);
        a.denominate();
        sc.close();
    }
}