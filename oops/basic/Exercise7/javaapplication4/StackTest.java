package Exercise7.javaapplication4;
interface Stack{
    void push(int b);
    int pop();
}
public class StackTest implements Stack{
    int n=10,i=-1;
    int[] arr = new int[n];
    private void newArray(){
        int[] narr=new int[2*n];
        System.arraycopy(arr, 0, narr, 0, n);
        n*=2;
        arr=narr;
    }
    @Override
    public void push(int b){
        if(isFull()){
            newArray();
        }
        arr[++i]=b;
    }
    boolean isFull(){
        return i==n-1;
    }
    @Override
    public int pop(){
        if(i==-1){
            System.out.println("Stack is Empty.");
            return -1;
        }
        else{
            return arr[i--];
        }
    }
}
