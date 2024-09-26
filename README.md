# C-RingBuffer
This project implements a ring buffer (circular buffer) in C. A ring buffer is a fixed-size data structure that uses a single, fixed-size buffer as if it were connected end-to-end.

## Features
- Dynamic resizing of the buffer when capacity is reached.
- Operations to add and remove elements from both ends of the buffer.
- Basic error handling for empty buffer conditions.

## Structure

### Ring Data Structure
The ring buffer is represented by a `Ring` struct which contains:
- `int* head`: Pointer to the start of the buffer.
- `int* start`: Pointer to the current start index of the buffer.
- `int* end`: Pointer to the current end index of the buffer.
- `int length`: The current number of elements in the buffer.
- `int capacity`: The maximum number of elements the buffer can hold.

### Functions
- `Ring* ring_create(void)`: Initializes a new ring buffer.
- `void addLast(Ring *ring, int value)`: Adds an element to the end of the buffer.
- `void addFirst(Ring *ring, int value)`: Adds an element to the start of the buffer.
- `int removeLast(Ring *ring)`: Removes an element from the end of the buffer.
- `int removeFirst(Ring *ring)`: Removes an element from the start of the buffer.
- `void ringFree(Ring *ring)`: Frees the allocated memory for the ring buffer.
- `void printRing(Ring *ring)`: Prints the elements in the ring buffer.
