/**
 * Cracking the Coding Interview Problem 5.2
 *
 * Given a real number between 0 and 1 that is passed in as a double, 
 * print the binary representation. If it cannot be represented
 * accurately in binary with at most 32 characters, print ERROR.
 *
 * @param {Double} input The number we'd like to represent in binary.
 * @return {String} The binary representation of the input number.
 */
 public static String returnBinary(double input) {
     // Check if input is out of bounds.
     if (input >= 1 || input <= 0) {
         return "ERROR";
     }

     StringBuilder binaryString = new StringBuilder();
     binary.append(".");
     while (input > 0) {
         // Limit the binary string to 32 characters long
         if(binaryString.length() > 32) {
             return "ERROR";
         }
        /**
         * We know that in binary representation, if input * 2 is greater
         * than 1, we add a 1 digit right after the decimal point. We do
         * this continuously to check every digit.
         */
         double check = input * 2;
         if (check >= 1) {
             binaryString.append(1);
             input = check - 1;
         } else {
             binaryString.append(0);
             input = check;
         }
     }
     return binaryString.toString();
 }