import java.util.Arrays;

public class anagram {
    public static void main(String[] args) {
        String str1 = "parliament";
        String str2 = "partial men";

        boolean result = areAnagrams(str1, str2);
        System.out.println("Are Anagrams: " + result);
    }

    static boolean areAnagrams(String str1, String str2) {
        str1 = str1.replaceAll("[\\s\\p{Punct}]", "").toLowerCase();
        str2 = str2.replaceAll("[\\s\\p{Punct}]", "").toLowerCase();

        char[] charArray1 = str1.toCharArray();
        char[] charArray2 = str2.toCharArray();

        Arrays.sort(charArray1);
        Arrays.sort(charArray2);

        return Arrays.equals(charArray1, charArray2);
    }
}
