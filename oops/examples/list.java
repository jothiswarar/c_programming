package examples;
//import java.io.*;
import java.util.*;
public class list {
    /**
     * @param args
     */
    public static void main(String[] args){
        Queue <Integer> a=new PriorityQueue<>();
        a.add(45);
        a.add(65);
        a.add(25);
        System.out.println(a.peek()); 
    }
}
