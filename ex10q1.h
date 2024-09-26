typedef struct {
    int* head;    // Start of dynamic storage
    int* start;   // Index 0 of ring buffer
    int* end;     // One after the last element in the ring buffer
    int length;   // Number of elements currently stored in the ring buffer
    int capacity; // Maximum number of elements this ring buffer can hold
} Ring;
