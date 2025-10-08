// vector notes:

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> v;
    vector<int>::iterator it;
    vector<int>::reverse_iterator rit;

    for (int i=0; i<10; i++)
    {
        v.push_back(rand()%100);
    }
    
    cout << "Vector size:"<<v.size()<<endl;
    
    cout << "Original Vector:(enhanced for loop)\n";
    for (int i:v)
        cout << i<<endl;

    sort(v.begin(), v.end());
    
    cout<<"Sorted Vector:\n";
    for (int i:v)
        cout << i<<endl;
    
    cout<< "Iterator:\n";
    for(it = v.begin(); it != v.end(); it++)
        cout << *it<<endl;
    
    cout<< "Reverse Iterator:\n";
    for(rit = v.rbegin(); rit != v.rend(); rit++)
        cout << *rit<<endl;

    cout << "Array Index:\n";
    for (int i=0; i<v.size(); i++)
        cout << v[i] << endl;

    cout<< "count_if:\n";
    // use a lambda expression to count elements divisible by 4.
    int count_div4 = count_if(v.begin(), v.end(), [](int i) { return i
    % 4 == 0; });

    cout << "numbers divisible by four: " << count_div4 << '\n';
    // use a lambda expression to count elements divisible by 3.
    int count_div3 = count_if(v.begin(), v.end(), [](int i) { return i
    % 3 == 0; });

    cout << "numbers divisible by three: " << count_div3 << '\n';
    
    cout<< "count:\n";
    int target = v[3];
    int num_items = count(v.cbegin(), v.cend(), target);
    cout << "number: " << target << ", count: " << num_items << '\n';
    
    return 0;
}