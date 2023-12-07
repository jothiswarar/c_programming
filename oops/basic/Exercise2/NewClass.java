package Exercise2;
import java.util.*; 
class hi{ 
void digit(int n,int k) 
{ 
int c=0; 
for(int i=0;i<k;i++) 
{ 
c=n%10; 
n/=10; 
} 
System.out.println(c); 
} 
} 
public class NewClass 
{ 
public static void main(String[] args) 
{ 
Scanner sc = new Scanner(System.in); 
int n=sc.nextInt(); 
int k=sc.nextInt(); 
hi a=new hi(); 
a.digit(n,k); 
} 
} 
