/**
 * Cracking the Coding Interview Problem 11.1
 * You are given two sorted arrays, A and B. A has a large enough buffer
 * at the end to hold the elements of B.
 * Insert the elements of B into A, to create one large sorted array of 
 * both A and B's elements.
 */

 public int[] sortedArray(int[] A, int[] B, int lengthA, int lengthB) {
     // Note: easier to insert elements into back of the array, so start from
     // there & work backwards towards the front.
     int indexA = lengthA - 1; // index of last element in A
     int indexB = lengthB - 1; // index of last element in B
     int mergedIndex = lengthA + lengthB - 1;

     // PART 1: MOVE THINGS TO BACK
     // Start merging from last element in each array.
     while (indexA >= 0 && indexB >=0) {
         // if the index @ end of A is greater than the end of B
         if(A[indexA] > B[indexB]) {
             A[mergedIndex] = A[indexA]; // Move to back of array
             mergedIndex--; // Set new back of array
             indexA--; // Look at next element in A
         } else {
             A[mergedIndex] = B[indexB];
             mergedIndex--;
             indexB--;
         }
     }
     // PART 2: FILL IN THE MIDDLE
     // Account for the rest of the elements in the B array (these would already
     // be in order since we have already accounted for the cases in which they
     // are not)
     while(indexB >= 0) {
         A[mergedIndex] = B[indexB];
         indexMerged--;
         indexB--;
     }
     // No more work to do: elements of A are already in place.
     // Return sorted array.
     return A;
 }