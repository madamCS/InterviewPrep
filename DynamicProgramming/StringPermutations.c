/**
 * Cracking the Coding Interview: Problem 9.5
 * Function which finds all permutations of a String.
 * @param {String} input The String for which we will find all permutations.
 * @return {ArrayList<String>} permutations An ArrayList containing all
 * the possible permutation Strings.
 */
ArrayList<String> allPermutations(String input) {
    ArrayList<String> permutations = new ArrayList<String>();

    // Base case, if the input string has length of 0.
    if (input.length() == 0) {
        permutations.add("");
        return permutations;
    }

    // All other cases: input has a length of at least 1.
    // We want to remove the first character, and insert it into every
    // other possible index.
    char firstLetter = input.charAt(0);
    String remainingWord = input.substring(1);
    // Call recursion on remainder to get rest of permutations.
    ArrayList<String> words = allPermutations(remainingWord);
    // Go through all permutations and add the first letter at every index.
    for (String word : words) {
        // Go through all indexes.
        for (int i = 0; i < word.length(); i++) {
            String permutation = insertCharAt(word, firstLetter, i);
            permutations.add(permutation);
        }
    }
    // At this point, we have taken every letter and inserted it into
    // every possible index of every possible permutation.
    return permutations;
}

/**
 * Function which inserts a letter into a word at a specified index.
 *
 * @param {String} word The word into which we'd like to insert a letter.
 * @param {Char} letter The letter we'd like to insert.
 * @param {Integer} i The index at which we'd like to insert our letter.
 * @return {String} The newly created String.
 */
String insertCharAt(String word, char letter, int i) {
    // Split up the word into two substrings, and insert letter between
    // these substrings.
    String firstHalf = word.substring(0, i);
    String secondHalf = word.substring(i);
    return firstHalf + firstLetter + secondHalf;
}