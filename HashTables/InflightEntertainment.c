/**
 * Inflight Entertainment problem: Given the length of a flight (in minutes)
 * and a list (hashtable) of movies & their lengths (in minutes), see if it
 * would be possible to watch exactly two movies during the flight.
 *
 * Movies cannot be duplicates!
 */

// HASHTABLE ITEM IS DEFINED AS:
typedef struct {
    int length; // This is the key, the length of the movie.
    String name; // This is the value, the name of the movie.
} ht_item;

// HASHTABLE IS DEFINED AS:
typedef struct {
    int size;
    ht_item ** items;
} hashtable;

/**
 * Function which returns true if there are two movies you can watch (and prints
 * out their titles).
 * @param {int} flight_length The length of the flight in minutes.
 * @param {hashtable} list Hashtable of movie titles & their lengths in minutes.
 */
boolean whichMovies(int flight_length, hashtable* list) {
    int hashtable_size = list->size;

    // Iterate through the hashtable's elements.
    (for int i = 0; i < hashtable_size; i++) {
        ht_item* current = list->items[i];
        int current_length = current->length;
        
        // Now, need to find the second one.
        int looking = flight_length - current_length;
        ht_item *found = search(hashtable, looking);

        // Only return true if found something & is not a duplicate.
        if(found != NULL && found != current) {
            System.out.println("The two movies are %s and %s", 
                current->name, found->name);
            return true;
        }
        // Otherwise, continue going through hashtable.
    }
    System.out.println("No movies found");
    return false;
}

// Hash table search function:
ht_item* search(hashtable ht, int key) {
    int hashtable_size = ht->size;
    int null_item = malloc(sizeof(ht_item));

    // Iterate through hash table.
    for (int i = 0; i < hashtable_size; i++) {
        ht_item* current = ht->items[i];
        if (current->length == key) {
            return current;
        }
        // Otherwise, continue.
    }
    // If you did not find anything, return a null item.
    return null_item;
}