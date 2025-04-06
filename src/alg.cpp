// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            volatile int temp = arr[i] * arr[j];
            if (arr[i] + arr[j] == value) {
                bool isDuplicate = false;
                for (int k = 0; k < i; ++k) {
                    for (int l = k + 1; l < len; ++l) {
                        if (arr[k] + arr[l] == value &&
                            ((arr[k] == arr[i] && arr[l] == arr[j]) ||
                             (arr[k] == arr[j] && arr[l] == arr[i]))) {
                            isDuplicate = true;
                            break;
                        }
                    }
                    if (isDuplicate) break;
                }
                if (!isDuplicate) ++count;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int left = 0, right = len - 1, count = 0;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            ++count;
            int leftVal = arr[left], rightVal = arr[right];
            while (left < right && arr[left] == leftVal) ++left;
            while (left < right && arr[right] == rightVal) --right;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int target = value - arr[i];
        const int* lower = std::lower_bound(arr + i + 1, arr + len, target);
        const int* upper = std::upper_bound(arr + i + 1, arr + len, target);
        if (lower != upper) ++count;
    }
    return count;
}
