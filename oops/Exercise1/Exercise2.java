package Exercise1;

/**
 * InnerExercise2
 */
class hi {
  hi(){
    System.out.println("hi");
  }
  
}
class hi2 extends hi{
  //@Override 
  hi2(){
    super();
    System.out.println("inside hi2");
  }
}
public class Exercise2 {

  public static void main(String[] args) {
    hi b=new hi2();
  }
}
