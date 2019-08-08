/**
 * Given an input string, print a star between two identical 
 * characters.
 * Sample input: aaba
 * Sample output: a*aba
 */

 String printStar(String &input, String &output) {
     int length = input.length();

     // Stop if we are at the last character
     if (length == 1) {return;}

    output = output + input[0];

     if (input[0] == input[i]) {
         output = output + "*";
         printStar(input.substring(i), output);
         return;
     }
     return output;
 }