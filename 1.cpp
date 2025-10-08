#include <iostream>

using namespace std;

int main() 
{
    // Using UTF-8 encoding explicitly
    cout << u8"Spade: \u2660" << endl;
    cout << u8"Heart: \u2665" << endl;
    cout << u8"Diamond: \u2666" << endl;
    cout << u8"Club: \u2663" << endl;

    return 0;
}
