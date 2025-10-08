// Name: Min Hein
// Class: CECS 325-02
// Project Name: Prog 4 - Threads
// Due Date: March 25, 2025

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

const int NUM_THREADS = 16;
const int ARRAY_SIZE = 1000000;
const int TEST_SIZE = 10000;
long long global_swaps = 0;  // Global swap count
mutex swap_mutex;  // Mutex to protect swap count

int myMin(int a, int b) 
{
    return (a < b) ? a : b;
}

// Bubble Sort Function with Swap Count
void bubbleSort(int arr[], int left, int right, int threadID) 
{
    long long local_swaps = 0;
    for (int i = left; i < right - 1; i++) 
    {
        for (int j = left; j < right - (i - left) - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                local_swaps++;
            }
        }
    }

    // Safely update global swap count
    lock_guard<mutex> lock(swap_mutex);
    global_swaps += local_swaps;

    // Print swaps for this thread
    cout << "Thread " << threadID << " swaps: " << local_swaps << endl;
}

// Merge two sorted sections
void merge(int arr[], int left, int mid, int right) 
{
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp.push_back(arr[i++]);
        } 
        
        else 
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) 
    {
        arr[k] = temp[k - left];
    }
}

// Parallel Merge Sort using threads
void parallelSort(int arr[], int size) 
{
    int numThreads = myMin(NUM_THREADS, size);
    int chunkSize = size / numThreads;
    thread threads[NUM_THREADS];

    // Sort each section in parallel
    for (int i = 0; i < numThreads; i++) 
    {
        int start = i * chunkSize;
        int end = myMin((i + 1) * chunkSize, size);
        threads[i] = thread(bubbleSort, arr, start, end, i);
    }

    // Join all threads
    for (int i = 0; i < numThreads; i++) 
    {
        threads[i].join();
    }

    // Merge sorted sections in pairs
    for (int step = chunkSize; step < size; step *= 2) 
    {
        for (int i = 0; i < size; i += 2 * step) 
        {
            int left = i;
            int mid = myMin(i + step - 1, size - 1);
            int right = myMin(i + 2 * step - 1, size - 1);
            merge(arr, left, mid, right);
        }
    }
}

int main(int argc, char *argv[]) 
{
    if (argc < 3 || argc > 4) 
    {
        cerr << "Usage: " << argv[0] << " input_file output_file [-test]" << endl;
        return 1;
    }

    bool testMode = (argc == 4 && string(argv[3]) == "-test");
    int expectedSize = testMode ? TEST_SIZE : ARRAY_SIZE;

    ifstream infile(argv[1]);
    if (!infile) 
    {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Read numbers from file
    vector<int> numbers;
    int num;
    while (infile >> num) 
    {
        numbers.push_back(num);
    }
    infile.close();

    if (numbers.size() != expectedSize) 
    {
        cerr << "Error: Input file does not contain " << expectedSize << " numbers." << endl;
        return 1;
    }

    // Convert vector to dynamic array
    int *arr = new int[expectedSize];
    for (int i = 0; i < expectedSize; i++)
    {
        arr[i] = numbers[i];
    }

    // Run parallel sort
    parallelSort(arr, expectedSize);

    // Write sorted numbers to output file
    ofstream outfile(argv[2]);
    if (!outfile) 
    {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    for (int i = 0; i < expectedSize; i++) 
    {
        outfile << arr[i] << endl;
    }

    outfile.close();
    delete[] arr;

    // Print total swaps
    cout << "Total swaps: " << global_swaps << endl;
    return 0;
}
