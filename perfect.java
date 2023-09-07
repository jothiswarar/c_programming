
class number{
    boolean isPerfect(int s){
        int a=1;
        for(int i=2;i<s;i++){
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
                System.out.println(i);
            }
        }
    }
}