// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }

    if (count)
        return count;
    else
        return 0;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len;
    int middle;
    while (left < right - 1) {
        middle = (left + right) / 2;
        if (arr[middle] <= value)
            left = middle;
        else
            right = middle;
    }
    for (int i = 0; i < right - 1; i++) {
        for (int j = right; j > i; j--) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    if (count)
        return count;
    else
        return 0;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right - 1) {
        int middle = (left + right) / 2;
        if (arr[middle] <= value)
            left = middle;
        else
            right = middle;
    }
    len = right - 1;
    for (int i = 0; i <len; i++) {
        left = i+1;
        right = len-1;
        int c = 0;
        while (left < right) {
            int m = (left + right) / 2;
            if (arr[m] < (value-arr[i]))
                left = m + 1;
            else
                right = m;
        }
        while (arr[left] == (value - arr[i])) {
            c++;
            left++;
        }
    count += c;
    }

    if (count)
        return count;
    else
        return 0;
}
