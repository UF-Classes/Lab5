#include <vector>
#include <iostream>
#include "StringData.h"


using namespace std;

int linearSearch(vector<string> container, string element) {
    for (int i = 0; i < container.size(); i++)
        if (container[i] == element)
            return i;
    return -1;
}

int main() {
    cout << "Starting program" << endl;
    vector<string> words = getStringData();
    for (string element : {"not_here", "mzzzz", "aaaaa"}) {
        cout << "Timing linear search for " << element << endl;
        long long startTime = systemTimeNanoseconds();
        int index = linearSearch(words, element);
        long long endTime = systemTimeNanoseconds();
        cout << "Found " << element << " at " << index << " in " << endTime - startTime << endl;
    }
    return 0;
}
