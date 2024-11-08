FIFO
#include <iostream>
using namespace std;
#define MAX_PAGES 20                          // Define a maximum limit for pages
void fifoPageReplacement(int frames, int pages[], int numPages) {
int frame[MAX_PAGES];  // Array to hold the pages in frames (initialized to empty)
    int pageFaults = 0;
    int front = 0;  // Pointer to the front of the queue
    // Initialize frames with -1 to indicate they are empty
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }
    cout << "Page Replacement using FIFO:" << endl;
    cout << "Frames: " << frames << endl;
    cout << "Pages: ";
    for (int i = 0; i < numPages; i++) {
        cout << pages[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < numPages; i++) {
        bool found = false;
        // Check if the page is already in a frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            // Page fault: Add new page to available frame or replace oldest one
            frame[front % frames] = pages[i];  // Circular replacement using modulo
            front++;
            pageFaults++;
        }

        // Print the current state of frames after each operation
        cout << "Page " << pages[i] << ": ";
        for (int j = 0; j < frames; j++) {
            if (frame[j] == -1)
                cout << "- ";
            else
                cout << frame[j] << " ";
        }
        cout << endl;
    }

    cout << "Total Page Faults: " << pageFaults << endl;
}


int main() {
    int frames = 3;  // Number of frames in main memory
    int pages[] = {1, 2, 3, 4, 2, 1, 5, 6};  // Pages to be loaded
    int numPages = sizeof(pages) / sizeof(pages[0]);  // Calculate the number of pages
    fifoPageReplacement(frames, pages, numPages);
    return 0;
}
//OUTPUT
Page Replacement using FIFO:
Frames: 3
Pages: 1 2 3 4 2 1 5 6 
Page 1: 1 - - 
Page 2: 1 2 - 
Page 3: 1 2 3 
Page 4: 4 2 3 
Page 2: 4 2 3 
Page 1: 4 1 3 
Page 5: 4 1 5 
Page 6: 6 1 5 
Total Page Faults: 7









LRU
#include <iostream>
using namespace std;

int findLRU(int time[], int capacity) {
    int minimum = time[0], pos = 0;
    for (int i = 1; i < capacity; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

void lruPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity];
    int time[capacity];
    int page_faults = 0;

    // Initialize frames and time arrays
    for (int i = 0; i < capacity; ++i) {
        frames[i] = -1;                                              // -1 indicates an empty frame
        time[i] = 0;    						// Initial time
    }

    for (int i = 0; i < n; ++i) {
        bool page_found = false;
        
        // Check if the page is already in one of the frames
        for (int j = 0; j < capacity; ++j) {
            if (frames[j] == pages[i]) {
                page_found = true;
                time[j] = i + 1; // Update the time for the page
                break;
            }
        }

        // If the page is not found in frames
        if (!page_found) {
            int pos = findLRU(time, capacity); // Find LRU position
            frames[pos] = pages[i];            // Replace LRU page
            time[pos] = i + 1;                  // Update time
            page_faults++;
        }

        // Print current frames
        cout << "Frames after page " << pages[i] << ": ";
        for (int j = 0; j < capacity; ++j) {
            if (frames[j] == -1) {
                cout << " - ";
            } else {
                cout << frames[j] << " ";
            }
        }
        cout << endl;
    }

    cout << "Total Page Faults: " << page_faults << endl;
}

int main() {
    int pages[] = {1, 2, 3, 4, 5, 3, 4, 1, 6, 7};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    cout << "LRU Page Replacement Algorithm Simulation" << endl;
    lruPageReplacement(pages, n, capacity);

    return 0;
}

//OUTPUT
LRU Page Replacement Algorithm Simulation
Frames after page 1: 1  -  - 
Frames after page 2: 1 2  - 
Frames after page 3: 1 2 3 
Frames after page 4: 4 2 3 
Frames after page 5: 4 5 3 
Frames after page 3: 4 5 3 
Frames after page 4: 4 5 3 
Frames after page 1: 4 1 3 
Frames after page 6: 4 1 6 
Frames after page 7: 7 1 6 
Total Page Faults: 8























OPTIMAL 
#include <iostream>
using namespace std;
// Function to find the optimal page to replace
int findOptimal(int pages[], int n, int frames[], int capacity, int currentIndex) {
    int farthest = currentIndex;
    int pos = -1;

    for (int i = 0; i < capacity; ++i) {
        // Check if the frame is empty
        if (frames[i] == -1) {
            return i; 			// Return the empty frame
        }

        // Find the index of the page in the future reference list
        int j;
        for (j = currentIndex; j < n; ++j) {
            if (frames[i] == pages[j]) {
                // Found the page in future references
                if (j > farthest) {
                    farthest = j;
                    pos = i; 		// Update position to replace
                }
                break;
            }
        }

        // If the page is not found in future references
        if (j == n) {
            return i; 				// Replace this frame
        }
    }
    return pos;			 // Return the position to replace
}

void optimalPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity];
    int page_faults = 0;

    // Initialize frames array
    for (int i = 0; i < capacity; ++i) {
        frames[i] = -1; 			// -1 indicates an empty frame
    }

    for (int i = 0; i < n; ++i) {
        bool page_found = false;

        // Check if the page is already in one of the frames
        for (int j = 0; j < capacity; ++j) {
            if (frames[j] == pages[i]) {
                page_found = true;
                break;
            }
        }

        // If the page is not found in frames
        if (!page_found) {
            int pos = findOptimal(pages, n, frames, capacity, i); // Find the optimal position to replace
            frames[pos] = pages[i];			 // Replace the page
            page_faults++;
        }

        // Print current frames
        cout << "Frames after page " << pages[i] << ": ";
        for (int j = 0; j < capacity; ++j) {
            if (frames[j] == -1) {
                cout << " - ";
            } else {
                cout << frames[j] << " ";
            }
        }
        cout << endl;
    }
    cout << "Total Page Faults: " << page_faults << endl;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    cout << "Optimal Page Replacement Algorithm Simulation" << endl;
    optimalPageReplacement(pages, n, capacity);

    return 0;
}

//OUTPUT
Optimal Page Replacement Algorithm Simulation
Frames after page 7: 7  -  - 
Frames after page 0: 0  -  - 
Frames after page 1: 0 1  - 
Frames after page 2: 0 2  - 
Frames after page 0: 0 2  - 
Frames after page 3: 0 2 3 
Frames after page 0: 0 2 3 
Frames after page 4: 4 2 3 
Frames after page 2: 4 2 3 
Frames after page 3: 4 2 3 
Frames after page 0: 0 2 3 
Frames after page 3: 0 2 3 
Frames after page 2: 0 2 3 
Total Page Faults: 7


