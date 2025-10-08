// Name: Min Hein
// Class: CECS 325-02
// Project Name: Prog 5 - goldRabbits
// Due Date: April 22, 2025

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>

// Allows the user to use any valid integer type: int, short, long long

#define integer int // Used for normal runs, Change as needed
//#define short     // Uncomment for short
//#define long long // Uncomment for large values


using namespace std;

integer goldRabbits(integer n)
{
    // Static Map, initialized with fib(0) = 1, and fib(1) = 1
    static map<integer, integer> fibo_map =
    {
        {0, 1},
        {1, 1}
    };

    if (n == -1)    // Print map when taken fib(-1)
    {
        cout << "\nFibo Map contents:" << endl;
        for (const auto& [key, val] : fibo_map)
        {
            cout << key << ":" << val << endl;
        }
        cout << "End of Fibo map\n";
        cout << "" << endl;
        return -1;
    }

    if (n == 0 || n == 1) return 1;

    if (fibo_map.count(n)) return fibo_map[n];

    integer val1 = goldRabbits(n-1);
    integer val2 = goldRabbits(n-2);

    if (numeric_limits<integer>::max() - val1 < val2) // If space from "val1" to max_values of "integer" < "val2"'s space required -> overflow
    {
        throw string("Overflow error at fib(" + to_string(n) + "): " + to_string(val1 + val2));
    }

    fibo_map[n] = val1 + val2; //Add the 2 prior values to map to current location.
    return fibo_map[n];
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        string arg = argv[i];
        try
        {
            size_t idx;
            int n = stoi(arg, &idx);

            if (idx != arg.length()) throw invalid_argument("Invalid");

            cout << "fibo(" << n << "):\t";
            try
            {
                integer result = goldRabbits(n);
                if (n != -1)
                {
                    cout << result << endl;
                }
            }

            catch (const string &e)
            {
                cout << e << endl;
            }
        }
        catch (...)
        {
            cout << arg << " is not an integer" << endl;
        }

    }
    return 0;
    
}


