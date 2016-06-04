#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using std::cin;             // <iostream>
using std::cout;            // <iostream>
using std::endl;            // <iostream>
using std::sort;            // <algorithm>
using std::string;          // <string>
using std::vector;          // <string>
 
int main()
{
    // display header message
    cout << "***************************************************************\n"
            "*** This program computes number of unique words            ***\n"
            "***************************************************************\n";
    cout << endl;
 
    // ask for a list of numbers and store the list as a vector
    cout << "Enter a list of words one by one: ";
    vector<string> v;
    string x;
    while (cin >> x)
        v.push_back(x);    // append new input to the vector
 
    cout << endl;
 
    // define and compute core vector variables
    typedef vector<string>::size_type vecSize;   // define a type for vector size related variables
    vecSize N = v.size();            // number of elements in the vector
    vecSize numLoops = N - 1;        // number of (comparison) operators required
    vecSize ND;                      // number of distinct words
 
    // Check vector size, action accordingly
    if (N ==0 )
    {
        ND = 0;
        cout << "Number of distinct words = " << ND << endl;
        return 0;
    }
 
    else if (N ==1 )
    {
        ND = 1;
        cout << "Number of distinct words = " << ND << endl;
        return 0;
    }
 
    else
    {
        // sort the vector;
        sort(v.begin(),v.end());
 
        // display some results to console window
        cout << "Vector size (number of words entered): " << N << endl;
        cout << endl;
        cout << "Display the sorted (non-descending) distinct words below." << endl;
        cout << v[0] << endl;
 
        // declare new variables
        vecSize A = 0;     // vector index
        vecSize B = 1;     // vector index
        ND = 1;            // number of distinct words
 
        // Loop through the vector, compute ND, and identify the distinct words
        for (vecSize i = 0; i != numLoops; ++i)
        {
            if (v[B] != v[A])
            {
                ++ND;
                cout << v[B] << endl;  // display any newly discovered distinct words
            }
            ++A;
            ++B;
        }
        // Display final distinct word count
        cout << endl;
        cout << "Number of distinct elements (words): " << ND << endl;
    }
    return 0;
 
}