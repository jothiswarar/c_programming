public class Substring {
    public static void main(String[] args) {
        String input = "Hello, World!";
        int start = 7;
        int end = 12;

        printSubstring(input, start, end);
    }

    static void printSubstring(String str, int start, int end) {
        if (start < 0 || end > str.length() || start > end) {
            System.out.println("Invalid indices.");
            return;
        }

        String substring = str.substring(start, end);
        System.out.println("Substring: " + substring);
    }
}
