package ex8.exception; 
import java.util.*; 
class InvalidRegNoException extends Exception { 
InvalidRegNoException(String e) { 
super(e); 
} 
} 
class MarksOutOfBoundsException extends Exception { 
MarksOutOfBoundsException(String e) { 
super(e); 
} 
}
public class Student { 
String name, reg; 
int m1, m2, m3; 
int total; 
double avg; 
Student(String a, String b, int c, int d, int e) { 
name = a; 
reg = b; 
m1 = c; 
m2 = d; 
m3 = e; 
check(); 
total=m1+m2+m3; 
avg=(double)total/3; 
} 
void check() { 
try { 
if (reg.length() > 6) { 
throw new InvalidRegNoException("Reg No Out of Bound"); } 
} catch (InvalidRegNoException f) { 
Scanner sc = new Scanner(System.in); 
System.err.println(f+"\nEnter valid Register No."); 
reg = sc.nextLine(); 
check(); 
} 
try { 
if (((m1 < 0 || m1 > 100) || (m2 < 0 || m2 > 100)) || (m3 < 0 || m3 > 100)) { 
throw new MarksOutOfBoundsException("Invalid mark Entry");
} 
} catch (MarksOutOfBoundsException f) { Scanner sc = new Scanner(System.in); 
System.err.println(f+"\nEnter valid Marks:"); System.out.println(); 
m1 = sc.nextInt(); 
m2 = sc.nextInt(); 
m3 = sc.nextInt(); 
check(); 
} 
} 
void display() { 
System.out.println("Nmae:" + name); 
System.out.println("Reg:" + reg); 
System.out.println("Total:" + total); 
System.out.println("Average:" + avg); 
} 
} 
