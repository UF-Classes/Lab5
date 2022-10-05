#include "StringData.h"
#include <vector>
#include <iostream>

using namespace std;


int binarySearch(vector<string> container, string element){
    int l = 0, r = container.size() - 1;
    int mid;
    while (l < r) {
        mid = l + (r - l) / 2;

        if (container[mid] > element) {
            r = mid - 1;
        }
        else if (container[mid] < element) {
            l = mid + 1;
        }
        else {
            return mid;
        }

    }
}


int linearSearch(vector<string> container, string element) {
    for (int i = 0; i < container.size(); i++)
        if (container[i] == element)
            return i;
    return -1;
}


int main()
{
    vector<string> words = {"not_here", "mzzzz", "aaaaa"};
    vector<string> wordList = getStringData();

    for (string element: {"not_here", "mzzzz", "aaaaa"})
    {
        cout << "Timing linear search for " << element << endl;
        long long startTime = systemTimeNanoseconds();
        int index = linearSearch(wordList, element);
        long long endTime = systemTimeNanoseconds();
        cout << "Found " << element << " at " << index << " in " << (endTime - startTime) << endl;
    }
    cout << endl << endl;
    for (string word: words)
    {
        cout << "Timing binary search for " << word << " element" << endl;
        long long startTime = systemTimeNanoseconds();
        int index = binarySearch(wordList, word);
        long long endTime = systemTimeNanoseconds();
        cout << "Found " << word << " at " << index << " in " << (endTime - startTime) << "s" << endl;
    }
}