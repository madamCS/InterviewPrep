/** Given an input string, print out how many recurring characters
 * exist in that string.
 * Sample inputs:
 * ABCA should return 1
 * BCABA should return 2
 * ABC should return 0
 *
 * This problem was implemented using recursion, but it could also be 
 * implemented using a hash table.
 */

// FIRST: Implemented using recursion
 int numRecurring = 0;
 char look = '';

 int recurringChar(String input, char look) {
     int length = input.length();
     if (length == 0) {
         return;
     }
    
     char current = input[0]; // looking at first character

     for (int i = 1; i < length; i ++) {
        if (current == input[i]) {
            numRecurring++;
        } else {
         // Have found a new character
         recurringChar(input.substring(i+1), input[i]);
        }
     }
     // After have iterated through whole string
     return numRecurring;
 }

 // SECOND: Implemented using a hash table
 int findRecurring(String &input) {

     int length = input.length();
     unordered_set<char> hash;
     int numRecurring = 0;

     for (int i = 0; i < length; i++) {
         char current = input[i];

         if(hash != end && hash.find(current)) {
             numRecurring++;
         } else {
             // Insert the current element into th elist
             hash.insert(current);
         }
     }
     return numRecurring;
 }