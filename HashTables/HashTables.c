// Initializing a hash table item.
typedef struct {
    int value;
    int key;
} ht_item;

// Initializing a hash table.
typedef struct {
    int size; 
    int count; 
    ht_item** items;
} hashtable;

// Deleting an item in a hash table.
void deleteItem(ht_item* item) {
    // Free up its memory!
    free(item->value);
    free(item->key);
    free(item);
}

// Create a new hashtable item.
static ht_item* addItem(int value, int key) {
    ht_item *new = malloc(sizeof(ht_item));
    new->value = value;
    new->key = key;
    return new;
}

// Create a new hashtable.
hashtable* newHashtable(int size, int count) {
    // Allocate space for new hash table.
    hashtable *new = malloc(sizeof(hashtable));
    new->size = size;
    new->cound = count;
    // Calloc means that you are filling this memory w empty bytes.
    new->items = calloc((size_t)new->size, sizeof(ht_item*))
    return new;
}

// Deleting a hashtable. Remember this means you have to delete all of its items!
void deleteHashtable(hashtable* myht) {
    for (int i = 0; i < myht->size; i++) {
        if(myht->items[i] != NULL) {
            deleteItem(myht->items[i]);
        }
    }
    // Now that we have deleted every item, free up that memory:
    free(myht->items);
    free(myht);
}