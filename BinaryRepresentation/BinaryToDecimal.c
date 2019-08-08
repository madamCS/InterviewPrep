/**
 * Write a program that turns a given binary number into its decimal
 * representation.
 * Sample input: 1011
 * Sample output: 10
 */

int output = 0;
 int toDecimal(String binary, int i = 0) {
     int length = binary.length();

     // Return when reach the end
     if (length == 0) {return output;}

     if (input[length - 1] == 1) {
         // add value
         output += Math.pow(2, i);
     }
     toDecimal(binary.substring(0, length -2), i+1);
 }