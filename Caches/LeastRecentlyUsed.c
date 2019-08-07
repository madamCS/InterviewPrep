/** 
 * Implementing the Least Recently Used algorithm with queues.
 */

// Our queue will be implemented using a doulby linked list
 typedef struct QNode {
     struct QNode *previous, *next;
     unsigned number;
 } QNode;

// Instance of a Queue: FIFO collection of queue Nodes
typedef struct Queue {
    unsigned count; // Number of filled frames
    unsigned numberOfFrames; // Total number of frames
    QNode *front, *rear; // Signifying the front and rear of the queue
} Queue;

// Collection of pointers to queue nodes
typedef struct Hash {
    int capacity; // Number of pages there can be
    QNode **array; // An array of queue nodes
} Hash;

// Function which creates a new Queue Node and stores its given number
QNode* newQNode(unsigned number) {
    // Allocaate memory for number
    QNode *temp = (QNode*)malloc(sizeof(QNode));
    temp->number = number;

    temp->previous = temp->next = NULL;
    return temp;
}

// Creates an empty queue, with at most numberOfFrames nodes
Queue* createQueue(unsigned numberOfFrames) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->count = 0; // Initialized as empty
    queue->front = queue->rear = NULL;
    queue->numberOfFrames = numberOfFrames;

    return queue;
}

// Creates an empty hash of given capacity
Hash* createHash(int capacity) {
    Hash* hash = (Hash*)malloc(sizeof(Hash));
    hash->capacity = capacity;
    // Initialize an array of pointers where every pointer references
    // a queue node
    hash->array = (QNode**)malloc(hash->capacity * sizeof(QNode*));

    // Make sure all of the hash's entries are empty:
    for (int i = 0; i < hash->capacity; i++) {
        hash->array[i] = NULL;
    }
    return hash;
}

// Check if there is a slot available
int allFramesFull(Queue * queue) {
    return queue->cound == queue->numberOfFrames;
}

// Check if a queue is empty
int isQueueEmpty(Queue* queue) {
    return queue->rear == NULL;
}

// Delete a frame from a queue.
void deleteFrame(Queue* queue) {
    // Make sure queue is not empty.
    if(isQueueEmpty(queue)) {return;}

    // Base case: only one node in the list.
    if(queue->front == queue->rear) {
        queue->front = NULL;
    }

    QNode *temp = queue->rear; // Stores current rear
    queue->rear = queue->rear->previous; // Reset rear

    if(queue->rear)
        queue->rear->next = NULL; // Reset the new rear's next

    free(temp); 

    // Adjust the number of frames
    queue->count--;
}

// Add a page with given number to both the queue and hash
void addPage(Queue *queue, Hash* hash, unsigned number) {
    // If all the frames are full, remobe the page at the rear
    if(allFramesFull(queue)) {
        // Remove the page from Hash
        hash->array[queue->rear->number] = NULL;
        deleteFrame(queue);
    }

    // Create new node with given number and add to front of queue
    QNode *temp = newQNode(number);
    temp->next = queue->front;

    // Check if queue is empty and adjust pointers
    if (isQueueEmpty(queue)) {
        queue->rear = queue->front = temp;
    } else {
        queue->front->prev = temp;
        queue->front = temp;
    }

    // Add a page entry to the hash
    hash->array[number] = temp;
    queue->count++;
}

// Called when page with given number is referenced
// 1. If page is not there in memory, bring it in from memory and put into
// front of the queue.
// 2. If page is there in memory, bring it to front of queue.
void pageReferenced(Queue* queue, Hash* hash, unsigned number) {
    QNode* reqPage = hash->array[number];

    // If the page is not in hash
    if (reqPage == NULL) {
        addPage(queue, hash, number);
    }

    // Page exists but is not at the front.
    else if(reqPage != queue->front) {
        // Unlink from current place
        reqPage->prev->next = reqPage->next;
        if(reqPage->next) {
            reqPage->next->prev = reqPage->prev;
        }

        // If in rear, remove from rear
        if(reqPage == queue->rear) {
            queue->rear = reqPage->prev;
            queue->rear->next = NULL;
        }

        // Put page before current front
        reqPage->next = queue->front;
        reqPage->prev = NULL;
        reqPage->next->prev = reqPage;
        queue->front = reqPage;
    }
}

