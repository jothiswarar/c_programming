import java.util.Arrays;

public class StringHandling {
    public static void main(String[] args) {

        String str1 = "Hello";
        String str2 = "World";
        String resultConcatenation = str1.concat(str2);
        System.out.println(resultConcatenation + "\n");

        String strDataType = "The value of x is: ";
        int x = 10;
        String resultConcatDataType = strDataType + x;
        System.out.println(resultConcatDataType + "\n");

        int num = 42;
        String resultToString = Integer.toString(num);
        System.out.println(resultToString + "\n");

        String s1 = "PSG CSE";
        char resultCharAt = s1.charAt(0);
        System.out.println(resultCharAt + "\n");

        String sGetChars = "Hello";
        char[] charArray = new char[3];
        sGetChars.getChars(0, 3, charArray, 0);
        System.out.println(Arrays.toString(charArray) + "\n");

        String sGetBytes = "Hello";
        byte[] byteArray = sGetBytes.getBytes();
        System.out.println(Arrays.toString(byteArray) + "\n");

        String sToCharArray = "Hello";
        char[] charArrayToChar = sToCharArray.toCharArray();
        System.out.println(Arrays.toString(charArrayToChar) + "\n");

        String sEquals1 = "hello";
        String sEquals2 = "Hello";
        System.out.println(sEquals1.equals(sEquals2));               // false
        System.out.println(sEquals1.equalsIgnoreCase(sEquals2) + "\n");  // true

        String sRegionMatches1 = "Hello World";
        String sRegionMatches2 = "World";
        System.out.println(sRegionMatches1.regionMatches(6, sRegionMatches2, 0, 5) + "\n");  // true

        String sStartEndWith = "Hello World";
        System.out.println(sStartEndWith.startsWith("Hello"));  // true
        System.out.println(sStartEndWith.endsWith("World") + "\n");      // true

        String sEquals3 = new String("hello");
        String sEquals4 = new String("hello");
        System.out.println(sEquals3.equals(sEquals4));  // true
        System.out.println(sEquals3 == sEquals4 + "\n");           // false

        String sCompareTo1 = "apple";
        String sCompareTo2 = "banana";
        System.out.println(sCompareTo1.compareTo(sCompareTo2) + "\n");  // A negative value

        String sSubstring = "Hello World";
        String resultSubstring = sSubstring.substring(6, 11);
        System.out.println(resultSubstring + "\n");

        String sConcat1 = "Hello";
        String sConcat2 = " World";
        String resultConcat = sConcat1.concat(sConcat2);
        System.out.println(resultConcat + "\n");

        String sReplace = "Hello World";
        String resultReplace = sReplace.replace("World", "Java");
        System.out.println(resultReplace + "\n");

        String sTrim = "   Hello   ";
        String resultTrim = sTrim.trim();
        System.out.println(resultTrim + "\n");

        int numValueOf = 42;
        String resultValueOf = String.valueOf(numValueOf);
        System.out.println(resultValueOf + "\n");

        String sChangeCase = "Hello World";
        String resultUpperCase = sChangeCase.toUpperCase();
        String resultLowerCase = sChangeCase.toLowerCase();
        System.out.println(resultUpperCase + "\n");
        System.out.println(resultLowerCase + "\n");
    }
}
