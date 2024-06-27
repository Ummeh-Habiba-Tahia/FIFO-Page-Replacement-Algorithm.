#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm> // for random_shuffle
#include <ctime> // for time seeding

using namespace std;

// Function to implement FIFO page replacement algorithm
int fifo(vector<int>& pages, int capacity) {
    queue<int> q; // Queue to store page numbers
    unordered_set<int> s; // Set to check if a page is in memory or not
    int pageFaults = 0; // Counter to track page faults

    // Traverse through each page
    for (int page : pages) {
        // If page is not in memory
        if (s.find(page) == s.end()) {
            // If memory is full, remove the first page (FIFO)
            if (q.size() == capacity) {
                int oldestPage = q.front();
                q.pop();
                s.erase(oldestPage);
            }
            // Add the new page to memory
            q.push(page);
            s.insert(page);
            pageFaults++;
        }
    }
    return pageFaults;
}

int main() {
    // Example usage
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 3, 2, 1, 2, 0,1, 7, 0, 1 };
    int capacity = 3; // Number of frames

    int pageFaults = fifo(pages, capacity);

    cout << "Total page faults using FIFO: " << pageFaults << endl;

    return 0;
}
//int main() {
//    // Example usage
//    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 3, 2, 1, 2, 0,1, 7, 0, 1 };
//
//    // Shuffle the page requests to introduce randomness
//    srand(time(0)); // Seed the random number generator with current time
//    random_shuffle(pages.begin(), pages.end());
//
//    for (int capacity = 1; capacity <= 10; ++capacity) {
//        int pageFaults = fifo(pages, capacity);
//        cout << "Total page faults using FIFO with " << capacity << " frames: " << pageFaults << endl;
//    }
//
//    return 0;
//}
