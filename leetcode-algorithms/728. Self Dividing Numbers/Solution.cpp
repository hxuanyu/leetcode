// A self-dividing number is a number that is divisible by every digit it contains.

// For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

// Also, a self-dividing number is not allowed to contain the digit zero.

// Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

// Example 1:
// Input: 
// left = 1, right = 22
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
// Note:

// The boundaries of each input argument are 1 <= left <= right <= 10000.
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> rslt;
        for (int i = left; i <= right; i++) {
            if (bself(i)) rslt.push_back(i);
        }
        
        return rslt;
    }
    
    bool bself(int val) {
        int remain = 0;
        int c = val;
        do {
            remain = val % 10;
            if (remain == 0) return false;
            if (c % remain != 0) return false;
            val /= 10;
        } while (val != 0);
        
        return true;
    }
};