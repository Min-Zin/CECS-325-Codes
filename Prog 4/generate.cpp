// Name:            Min Hein
// Class:           CECS 325-02
// Project Name:    Prog 4 - Threads
// Due Date:        March / 25 / 2025

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Usage: " << argv[0] << " COUNT MIN MAX" << endl;
        return 1;
    }

    int count = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    if (min > max)
    {
        cerr << "Error: MIN should be less than or equal to Max" << endl;
        return 1;
    }

    ofstream outfile("numbers.dat");
    if (!outfile)
    {
        cerr << "Error: Unable to create number.dat" << endl;
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < count; ++i)
    {
        outfile << (rand() % (max - min + 1)) + min << endl;
    }

    outfile.close();
    return 0;
}