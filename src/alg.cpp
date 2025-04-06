// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int *arr, int len, int value)
{
    int count = 0;
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[i] + arr[j] == value)
            {
                ++count;
            }
            else if (arr[i] + arr[j] > value)
            {
                break;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value)
{
    int left = 0;
    int right = len - 1;
    int count = 0;

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == value)
        {
            ++count;
            int leftVal = arr[left];
            int rightVal = arr[right];
            while (left < right && arr[left] == leftVal)
                ++left;
            while (left < right && arr[right] == rightVal)
                --right;
        }
        else if (sum < value)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value)
{
    int count = 0;
    for (int i = 0; i < len - 1; ++i)
    {
        int target = value - arr[i];
        int *lower = std::lower_bound(arr + i + 1, arr + len, target);
        int *upper = std::upper_bound(arr + i + 1, arr + len, target);
        if (lower != upper)
        {
            count += (upper - lower);
        }
        while (i + 1 < len && arr[i] == arr[i + 1])
            ++i;
    }
    return count;
}
