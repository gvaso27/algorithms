#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

typedef long long LongInt;

struct SegmentInfo {
    int leftIndex;
    int rightIndex;

    LongInt totalSum;
    LongInt minElement;
};

class RangeQueryHandler {
private:
    vector<SegmentInfo> segmentInfoArray;
    vector<int> lazyUpdates;

    void constructSegmentInfo(vector<int>& inputArray, int lower, int higher, int position) {
        if (lower == higher) {
            segmentInfoArray[position].leftIndex = segmentInfoArray[position].rightIndex = lower;
            segmentInfoArray[position].totalSum = segmentInfoArray[position].minElement = inputArray[lower];
            return;
        }

        int middle = (lower + higher) / 2;
        constructSegmentInfo(inputArray, lower, middle, 2 * position + 1);
        constructSegmentInfo(inputArray, middle + 1, higher, 2 * position + 2);

        segmentInfoArray[position].leftIndex = lower;
        segmentInfoArray[position].rightIndex = higher;
        segmentInfoArray[position].totalSum = segmentInfoArray[2 * position + 1].totalSum + segmentInfoArray[2 * position + 2].totalSum;
        segmentInfoArray[position].minElement = min(segmentInfoArray[2 * position + 1].minElement, segmentInfoArray[2 * position + 2].minElement);
    }

    void applyLazyUpdates(int position, int start, int end, int value) {
        if (lazyUpdates[position] != 0) {
            segmentInfoArray[position].totalSum += (LongInt)(segmentInfoArray[position].rightIndex - segmentInfoArray[position].leftIndex + 1) * lazyUpdates[position];
            segmentInfoArray[position].minElement += lazyUpdates[position];
            if (segmentInfoArray[position].leftIndex != segmentInfoArray[position].rightIndex) {
                lazyUpdates[2 * position + 1] += lazyUpdates[position];
                lazyUpdates[2 * position + 2] += lazyUpdates[position];
            }
            lazyUpdates[position] = 0;
        }

        if (start > segmentInfoArray[position].rightIndex || end < segmentInfoArray[position].leftIndex || segmentInfoArray[position].leftIndex > segmentInfoArray[position].rightIndex)
            return;

        if (start <= segmentInfoArray[position].leftIndex && segmentInfoArray[position].rightIndex <= end) {
            segmentInfoArray[position].totalSum += (LongInt)(segmentInfoArray[position].rightIndex - segmentInfoArray[position].leftIndex + 1) * value;
            segmentInfoArray[position].minElement += value;
            if (segmentInfoArray[position].leftIndex != segmentInfoArray[position].rightIndex) {
                lazyUpdates[2 * position + 1] += value;
                lazyUpdates[2 * position + 2] += value;
            }
            return;
        }

        int middle = (segmentInfoArray[position].leftIndex + segmentInfoArray[position].rightIndex) / 2;
        applyLazyUpdates(2 * position + 1, start, end, value);
        applyLazyUpdates(2 * position + 2, start, end, value);
        segmentInfoArray[position].totalSum = segmentInfoArray[2 * position + 1].totalSum + segmentInfoArray[2 * position + 2].totalSum;
        segmentInfoArray[position].minElement = min(segmentInfoArray[2 * position + 1].minElement, segmentInfoArray[2 * position + 2].minElement);
    }

    LongInt calculateSum(int position, int start, int end) {
        if (lazyUpdates[position] != 0) {
            segmentInfoArray[position].totalSum += (LongInt)(segmentInfoArray[position].rightIndex - segmentInfoArray[position].leftIndex + 1) * lazyUpdates[position];
            segmentInfoArray[position].minElement += lazyUpdates[position];
            if (segmentInfoArray[position].leftIndex != segmentInfoArray[position].rightIndex) {
                lazyUpdates[2 * position + 1] += lazyUpdates[position];
                lazyUpdates[2 * position + 2] += lazyUpdates[position];
            }
            lazyUpdates[position] = 0;
        }

        if (start <= segmentInfoArray[position].leftIndex && end >= segmentInfoArray[position].rightIndex)
            return segmentInfoArray[position].totalSum;

        if (segmentInfoArray[position].rightIndex < start || segmentInfoArray[position].leftIndex > end)
            return 0;

        return calculateSum(2 * position + 1, start, end) + calculateSum(2 * position + 2, start, end);
    }

    LongInt findMinElement(int position, int start, int end) {
        if (lazyUpdates[position] != 0) {
            segmentInfoArray[position].totalSum += (LongInt)(segmentInfoArray[position].rightIndex - segmentInfoArray[position].leftIndex + 1) * lazyUpdates[position];
            segmentInfoArray[position].minElement += lazyUpdates[position];
            if (segmentInfoArray[position].leftIndex != segmentInfoArray[position].rightIndex) {
                lazyUpdates[2 * position + 1] += lazyUpdates[position];
                lazyUpdates[2 * position + 2] += lazyUpdates[position];
            }
            lazyUpdates[position] = 0;
        }

        if (start <= segmentInfoArray[position].leftIndex && end >= segmentInfoArray[position].rightIndex)
            return segmentInfoArray[position].minElement;

        if (segmentInfoArray[position].rightIndex < start || segmentInfoArray[position].leftIndex > end)
            return INT_MAX;

        return min(findMinElement(2 * position + 1, start, end), findMinElement(2 * position + 2, start, end));
    }

public:
    RangeQueryHandler(vector<int>& inputArray) {
        int size = inputArray.size();
        int height = (int)(ceil(log2(size)));
        int treeSize = 2 * (int)pow(2, height) - 1;

        segmentInfoArray.resize(treeSize);
        lazyUpdates.resize(treeSize, 0);
        constructSegmentInfo(inputArray, 0, size - 1, 0);
    }

    void applyUpdates(int index1, int index2, int value) {
        applyLazyUpdates(0, index1 - 1, index2 - 1, value);
    }

    LongInt calculateSumInRange(int index1, int index2) {
        return calculateSum(0, index1 - 1, index2 - 1);
    }

    LongInt findMinInRange(int index1, int index2) {
        return findMinElement(0, index1 - 1, index2 - 1);
    }
};

int main() {
    int dataSize;
    cin >> dataSize;

    int queryCount;
    cin >> queryCount;

    vector<int> dataValues(dataSize);
    for (int i = 0; i < dataSize; ++i) {
        cin >> dataValues[i];
    }

    RangeQueryHandler queryHandler(dataValues);

    for (int i = 0; i < queryCount; ++i) {
        char operationType;
        int operandA;
        int operandB;
        int operandC;
        cin >> operationType >> operandA >> operandB;

        if (operationType == 'M') {
            cout << queryHandler.findMinInRange(operandA, operandB) << "\n";

        } else if (operationType == 'S') {
            cout << queryHandler.calculateSumInRange(operandA, operandB) << "\n";

        } else if (operationType == 'P') {
            cin >> operandC;
            queryHandler.applyUpdates(operandA, operandB, operandC);
        }
    }

    return 0;
}
