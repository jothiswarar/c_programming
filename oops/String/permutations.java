import java.util.ArrayList;
import java.util.List;

public class permutations {
    public static void main(String[] args) {
        String input = "abc";
        List<String> permutations = generatePermutations(input);
        System.out.println("Permutations: " + permutations);
    }

    static List<String> generatePermutations(String str) {
        List<String> result = new ArrayList<>();
        permute("", str, result);
        return result;
    }

    static void permute(String prefix, String suffix, List<String> result) {
        if (suffix.length() == 0) {
            result.add(prefix);
        } else {
            for (int i = 0; i < suffix.length(); i++) {
                String newPrefix = prefix + suffix.charAt(i);
                String newSuffix = suffix.substring(0, i) + suffix.substring(i + 1);
                permute(newPrefix, newSuffix, result);
            }
        }
    }
}
