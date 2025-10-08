// Name:            Min Hein
// Class:           CECS 325-02
// Project Name:    Prog 3 - Sort Contest
// Due Date:        March / 6 / 2025

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void bubbleSort(int A[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < (size - 1) - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // Check if the correct number of command-line arguments are provided
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " input_file output_file" << endl;
        return 1;
    }

    // Open the input file for reading
    ifstream infile(argv[1]);
    if (!infile)
    {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Read numbers from the input file into a vector
    vector<int> numbers;
    int num;

    while (infile >> num)
    {
        numbers.push_back(num);
    }
    infile.close();

    // Convert vector to array for sorting
    int size = numbers.size();
    if (size == 0)
    {
        cerr << "Error: No numbers found in the input file." << endl;
        return 1;
    }

    int *arr = new int[size];
    for (int i = 0; i <size; i++)
    {
        arr[i] = numbers[i];
    }
    
    // Sort the number using bubble sort
    bubbleSort(arr, size);

    // Open the output file for writing
    ofstream outfile(argv[2]);
    if (!outfile)
    {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    // Write the sorted numbers to the output file
    for (int i = 0; i < size; i++)
    {
        outfile << arr[i] << endl;
    }

    outfile.close();
    return 0;
}