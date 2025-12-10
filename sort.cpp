#include <vector>
#include <cmath>
#include "sort.h"

using namespace std;

// сортировка расческой
int combSort(vector<double>& arr) {
    int comparisons = 0;
    int swaps = 0;
    int n = arr.size();
    int step = n;
    bool swapped = true;

    while (step > 1 || swapped) {
        step = (step > 1) ? (int)(step / 1.247) : 1;
        if (step < 1) step = 1;

        swapped = false;

        for (int i = 0; i + step < n; i++) {
            comparisons++;
            if (arr[i] > arr[i + step]) {
                double temp = arr[i];
                arr[i] = arr[i + step];
                arr[i + step] = temp;
                swapped = true;
                swaps++; 
            }
        }
    }

    return comparisons + swaps;
}