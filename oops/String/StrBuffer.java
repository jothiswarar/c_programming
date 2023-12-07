package String;

import java.util.Arrays;

public class StrBuffer {
    public static void main(String[] args) {
        StringBuffer buffer1 = new StringBuffer();
        StringBuffer buffer2 = new StringBuffer("Hello");
        System.out.println("Constructor 1: " + buffer1.toString());
        System.out.println("Constructor 2: " + buffer2.toString() + "\n");

        System.out.println("Length: " + buffer2.length() + "\n");
        System.out.println("Capacity: " + buffer2.capacity() + "\n");

        buffer2.ensureCapacity(20);
        System.out.println("After ensureCapacity: " + buffer2.capacity() + "\n");

        buffer2.setLength(3);
        System.out.println("After setLength: " + buffer2.toString() + "\n");

        char charAtIndex = buffer2.charAt(1);
        buffer2.setCharAt(1, 'a');
        System.out.println("charAt(1): " + charAtIndex + "\n");
        System.out.println("After setCharAt: " + buffer2.toString() + "\n");

        char[] charArrayGetChars = new char[3];
        buffer2.getChars(0, 3, charArrayGetChars, 0);
        System.out.println("getChars(): " + Arrays.toString(charArrayGetChars) + "\n");

        buffer2.append(" World");
        System.out.println("After append: " + buffer2.toString() + "\n");

        buffer2.insert(5, " Java");
        System.out.println("After insert: " + buffer2.toString() + "\n");

        buffer2.reverse();
        System.out.println("After reverse: " + buffer2.toString() + "\n");

        buffer2.delete(5, 10);
        System.out.println("After delete: " + buffer2.toString() + "\n");

        buffer2.replace(0, 5, "Hola");
        System.out.println("After replace: " + buffer2.toString() + "\n");

        String substringResult = buffer2.substring(2, 6);
        System.out.println("Substring: " + substringResult + "\n");
    }
}

