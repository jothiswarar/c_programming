package Exercise5;
class number{
    boolean isPerfect(int s){
        int a=0;
        for(int i=1;i<s;i++){
            if(s%i==0){
                a+=i;
            }
        }
        return (a==s);
    }
}

public class perfect{
    public static void main(String[] args){
        number a=new number();
        for(int i=1;i<=1000;i++){
            if(a.isPerfect(i)){
                System.out.println(i+" is a perfect number and it's factors are");
                for(int j=1;j<i;j++){
                    if(i%j==0){
                        System.out.print(j+"\t");
                    }
                }
                System.out.println("\n");
            }
        }
    }
}