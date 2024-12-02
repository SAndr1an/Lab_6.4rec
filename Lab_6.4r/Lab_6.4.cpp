#include <iostream>
#include <vector>
using namespace std;

void PrintArray(const vector<int>& a, size_t i = 0) {
    if (i < a.size()) {
        cout << "a[" << i << "] = " << a[i] << "; ";
        PrintArray(a, i + 1);
    } else {
        cout << endl;
    }
}

int GetProductOfEvenIndex(const vector<int>& a, size_t i = 0) {
    if (i >= a.size()) return 1; 
    if (i % 2 == 0) {
        return a[i] * GetProductOfEvenIndex(a, i + 2);
    } else {
        return GetProductOfEvenIndex(a, i + 1); 
    }
}

int GetSumBetweenZeros(const vector<int>& a, size_t i = 0, int firstZero = -1, int lastZero = -1) {
    if (i >= a.size()) {
        if (firstZero == -1 || lastZero == -1 || firstZero == lastZero) {
            return 0; 
        }
        int sum = 0;
        for (int j = firstZero + 1; j < lastZero; ++j) {
            sum += a[j];
        }
        return sum;
    }

    if (a[i] == 0) {
        if (firstZero == -1) {
            firstZero = i; 
        }
        lastZero = i; 
    }

    return GetSumBetweenZeros(a, i + 1, firstZero, lastZero);
}

void TransformArray(vector<int>& a, vector<int>& positives, vector<int>& negatives, size_t i = 0) {
    if (i < a.size()) {
        if (a[i] >= 0) {
            positives.push_back(a[i]); 
        } else {
            negatives.push_back(a[i]); 
        }
        TransformArray(a, positives, negatives, i + 1); 
    } else {
        a = positives; 
        a.insert(a.end(), negatives.begin(), negatives.end()); 
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "\nOriginal array:" << endl;
    PrintArray(a);

    // 1.1
    int product = GetProductOfEvenIndex(a);
    cout << "\n1.1. Product of elements with even indices: " << product << endl;

    // 1.2
    int sum = GetSumBetweenZeros(a);
    cout << "1.2. Sum of elements between first and last zero: " << sum << endl;

    // 2
    vector<int> positives, negatives;
    TransformArray(a, positives, negatives);
    cout << "\n2. Transformed array:" << endl;
    PrintArray(a);

    return 0;
}

