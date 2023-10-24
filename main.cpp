#include <iostream>
#include "my_sort.h"

using namespace std;

int main() {
    int nums[] = {2,7,12,8,-1,9};
    mergeSort(nums, 6);

    for (int num : nums){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
