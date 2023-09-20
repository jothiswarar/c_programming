import java.util.*;

class sort {
    int[] bubble(int[] a) {
        int c;
        for (int i = 0; i < a.length; i++) {
            for (int j = i + 1; j < a.length; j++) {
                if (a[i] > a[j]) {
                    c = a[i];
                    a[i] = a[j];
                    a[j] = c;
                }
            }
        }
        return a;
    }

    int[] insertion(int[] a) {
        int n = a.length;
        for (int i = 1; i < n; i++) {
            int key = a[i];
            int j = i - 1;

            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
        return a;
    }
}

public class sorting {
    public static void main(String[] args) {
        int[] a;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        a = new int[n];
        
        sort c = new sort();

        System.out.println("Bubble Sort:");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] bubbleSorted = c.bubble(a);
        for (int i = 0; i < bubbleSorted.length; i++) {
            System.out.print(bubbleSorted[i]+"\t");
        }

        System.out.println("\nInsertion Sort:");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] insertionSorted = c.insertion(a);
        for (int i = 0; i < insertionSorted.length; i++) {
            System.out.print(insertionSorted[i]+"\t");
        }

        sc.close();
    }
}
