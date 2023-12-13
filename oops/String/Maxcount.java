public class Maxcount {
    public static void main(String[] args) {
        String input = "programming";
        char result = findMaxOccurringCharacter(input);
        System.out.println("Maximum occurring character: " + result);
    }

    static char findMaxOccurringCharacter(String str) {
        int[] charCount = new int[256]; // Assuming ASCII characters

        for (char c : str.toCharArray()) {
            charCount[c]++;
        }

        char maxChar = ' ';
        int maxCount = 0;

        for (int i = 0; i < charCount.length; i++) {
            if (charCount[i] > maxCount) {
                maxCount = charCount[i];
                maxChar = (char) i;
            }
        }

        return maxChar;
    }
}
