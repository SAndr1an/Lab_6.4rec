#include <iostream>

using namespace std;

void InputArray(int* a, int size, int i = 0) {
    if (i < size) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
        InputArray(a, size, i + 1);
    }
}

void PrintArray(const int* a, int size, int i = 0) {
    if (i < size) {
        cout << "a[" << i << "] = " << a[i] << "; ";
        PrintArray(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

int GetProductOfEvenIndex(const int* a, int size, int i = 0) {
    if (i >= size) return 1;
    return (i % 2 == 0 ? a[i] : 1) * GetProductOfEvenIndex(a, size, i + 1);
}

int SumBetweenIndices(const int* a, int firstZero, int lastZero, int i) {
    if (i >= lastZero) return 0;
    return a[i] + SumBetweenIndices(a, firstZero, lastZero, i + 1);
}

int GetSumBetweenZeros(const int* a, int size, int i = 0, int firstZero = -1, int lastZero = -1) {
    if (i >= size) {
        if (firstZero == -1 || lastZero == -1 || firstZero == lastZero) return 0;
        return SumBetweenIndices(a, firstZero, lastZero, firstZero + 1);
    }

    if (a[i] == 0) {
        if (firstZero == -1) firstZero = i;
        lastZero = i;
    }

    return GetSumBetweenZeros(a, size, i + 1, firstZero, lastZero);
}

void TransformArrayHelper(const int* a, int* positives, int* negatives, int size, int i, int& posCount, int& negCount) {
    if (i >= size) return;

    if (a[i] >= 0) {
        positives[posCount++] = a[i];
    }
    else {
        negatives[negCount++] = a[i];
    }

    TransformArrayHelper(a, positives, negatives, size, i + 1, posCount, negCount);
}

void TransformArray(int* a, int size, int*& positives, int& posCount, int*& negatives, int& negCount) {
    positives = new int[size];
    negatives = new int[size];
    posCount = negCount = 0;

    TransformArrayHelper(a, positives, negatives, size, 0, posCount, negCount);

    int index = 0;
    for (int i = 0; i < posCount; ++i) {
        a[index++] = positives[i];
    }
    for (int i = 0; i < negCount; ++i) {
        a[index++] = negatives[i];
    }
}

int main() {
    int n; 
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!" << endl; 
        return 1;
    }

    int* a = new int[n]; 
    cout << "Enter the elements of the array:" << endl;
    InputArray(a, n);

    cout << "\nOriginal array:" << endl;
    PrintArray(a, n);

    // 1.1
    int product = GetProductOfEvenIndex(a, n);
    cout << "\n1.1. Product of elements with even indices: " << product << endl;

    // 1.2
    int sum = GetSumBetweenZeros(a, n);
    cout << "1.2. Sum of elements between first and last zero: " << sum << endl;

    // 2
    int* positives, * negatives;
    int posCount, negCount;
    TransformArray(a, n, positives, posCount, negatives, negCount);
    cout << "\n2. Transformed array:" << endl;
    PrintArray(a, n);

    delete[] a;
    delete[] positives;
    delete[] negatives;

    return 0;
}

