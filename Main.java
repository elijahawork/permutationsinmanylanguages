import java.util.*;
import java.lang.*;

class Main {
    // utility function to print an arraylist without addresses being printed
    static <T> void printArrayList(ArrayList<T> list) {
        for (T e : list)
            System.out.println(e);
    }
    // actual permutation function
    static ArrayList<String> permute(String s) {
        ArrayList<String> permutations = new ArrayList<>();
        // if someone enters 1 letter then just return the letter
        // there is a choice to make the base case 2, and that would decrease the stack size
        // during recursion but would also be more to type as there would be both a case for 1
        // in the case that someone only passes one char, and one for two
        // so the second one would be redunant
        if (s.length() == 1) {
            permutations.add(s);
        } else {
            // this goes through every possible character and creates a series of permutations
            // around that character and then appends it
            for (int i = 0; i < s.length(); i++) {
                // gets pivot char
                char pivotChar = s.charAt(i);
                // gets everything but the pivot char
                String sansPivot = s.substring(0, i) + s.substring(i + 1);

                // gets all the permutations of everything but the pivot
                ArrayList<String> sansPermutations = permute(sansPivot);

                    // adds the pivot onto the permutations sans pivot
                for (String permutation : sansPermutations) {
                    permutations.add(pivotChar + permutation);
                }
            }
        }

        return permutations;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String strToPermute = sc.nextLine();
        sc.close();

        ArrayList<String> permutations = permute(strToPermute);

        printArrayList(permutations);
    }
}
