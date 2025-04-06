// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int left = 0, right = len - 1, count = 0;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                count += (right - left) * (right - left + 1) / 2;
                break;
            }
            int left_val = arr[left];
            int right_val = arr[right];
            int left_count = 0, right_count = 0;
            
            while (arr[left] == left_val && left <= right) {
                left++;
                left_count++;
            }
            while (arr[right] == right_val && left <= right) {
                right--;
                right_count++;
            }
            count += left_count * right_count;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int target = value - arr[i];
        int left = i + 1, right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                int j = mid;
                while (j >= left && arr[j] == target) {
                    count++;
                    j--;
                }
                j = mid + 1;
                while (j <= right && arr[j] == target) {
                    count++;
                    j++;
                }
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
