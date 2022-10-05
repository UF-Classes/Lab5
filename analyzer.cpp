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


int linearSearch(vector<string> container, string element){

}


int main(){
    vector<string> words = {"not_here", "mzzzz", "aaaaa"};
    vector<string> wordList = getStringData();

    for (string word : words) {
        cout << "Timing binary search for " << word << " element" << endl;
        long long startTime = systemTimeNanoseconds();
        int index = binarySearch(wordList, word);
        long long endTime = systemTimeNanoseconds();
        cout << "Found " << word << " at " << index << " in " << (endTime - startTime) / 1000000000.0L << "s" << endl;
    }


    return 0;
}
