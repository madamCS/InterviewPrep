/**
 * Cracking the Coding Interview Problem 11.3
 *
 * Given a sorted array of n integers that has been rotated an unknown number of
 * times, write code to find an element in the array. You may assume that the array was
 * originally sorted in increasing order
 *
 * Example array: {4, 5, 6, 1, 2, 3}. Note that one half is ordered normally,
 * so find the normally-ordered half and go from there.
 *
 * Check leftmost element and midpoint. If leftmost > midpoint, know that the
 * RIGHT side is normally ordered, and vice versa.
 */

/**
 * Function which finds an element in an array.
 * 
 * @param {Array} array Input array of integers to search.
 * @param {Int} find The number we are supposed to find in our array.
 * @param {Int} leftmost The leftmost index of the array.
 * @param {Int} rightmost The rightmost index of the array.
 */
 public int findElement(int[] array, int find, int leftmost, int rightmost) {
     int midpoint = (leftmost + rightmost) / 2;

     // Found the element:
     if (array[midpoint] == find) {
         return midpoint;
     }

    // This means that the array WAS shifted.
     if (rightmost < leftmost) {
         return -1;
     }

     if (array[leftmost] > array[midpoint]) {
         // Right side is normally ordered
         if (find >= array[midpoint] && find <= array[rightmost]) {
             // Search the right side
             findElement(array, find, midpoint, rightmost);
         } else {
             // Search the left side
             findElement(array, find, leftmost, midpoint);
         }

     } else if (array[leftmost] < array[midpoint]) {
         // Left side is normally ordered
         if (find >= array[leftmost] && find <= array[midpoint]) {
             // Search the left side (ordered)
             findElement(array, find, leftmost, midpoint);
         } else {
             findElement(array, find, midpoint, rightmost);
         }
     }  else if (array[leftmost] == array[midpoint]) {
         // This means that the whole left half is the same int
         // First, check if the right half is different
         if (array[midpoint] != array[rightmost]) {
             // If right half is different, search it!
            findElement(array, find, midpoint, rightmost);
         } else { 
             // Have to search the whole array 
            // Search the left first:
            int result = findElement(array, find, leftmost, midpoint);
            if (result == -1) {
                // This means that rightmost < leftmost
                // So, now search the right half
                findElement(array, find, midpoint, rightmost);
            } else {
                // This means the array was completely in order.
                return result;
            }
         }
     }
 }

/**
 * A case where rightmost < leftmost
 * Simply, this means that the array order HAS been shifted.
 * array = {2, 2, 2, 3, 1}
 */