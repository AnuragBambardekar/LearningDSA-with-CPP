#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        // Calculate the prefix sums of 'nums'
        vector<long long> sum(n+1, 0); //use long long instead of int to avoid integer overflow
        //vector -> sum is initialized with zeros
        // For each element nums[i], we add it to the sum of all previous elements sum[i], and store the result in sum[i+1]
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }
        return countWhileMergeSort(sum, 0, n+1, lower, upper);
    }
    
    int countWhileMergeSort(vector<long long>& sum, int start, int end, int lower, int upper) {
        if (end - start <= 1) // subarray with one or zero elements
        { return 0;}

        // divide-and-conquer approach
        int mid = (start + end) / 2;
        int count = countWhileMergeSort(sum, start, mid, lower, upper) 
                  + countWhileMergeSort(sum, mid, end, lower, upper);
        
        // indices to iterate over the prefix sums of the left and right halves of the subarray, and temp array (stores sorted prefix sums)
        int j = mid, k = mid, t = mid;
        vector<long long> temp(end - start, 0); // to keep track of the prefix sums in sorted order
        for (int i = start, r = 0; i < mid; i++, r++) { // r is to keep track of index in temp
            while (k < end && sum[k] - sum[i] < lower) k++;
            while (j < end && sum[j] - sum[i] <= upper) j++;
            while (t < end && sum[t] < sum[i]) temp[r++] = sum[t++];
            temp[r] = sum[i];
            count += j - k;
        }
        copy(temp.begin(), temp.begin() + t - start, sum.begin() + start); // Copies the range [first,last) into result
        return count;
    }
};

int main() {
    // vector<int> nums = {-2, 5, -1};
    // int lower = -2;
    // int upper = 2;
    
    // vector<int> nums = {0};
    // int lower = 0;
    // int upper = 0;

    // vector<int> nums = {-1, -1, -1, 1, 1, 1};
    // int lower = -1;
    // int upper = 1;

    vector<int> nums = {0,0,0};
    int lower = 0;
    int upper = 0;
    Solution solution;
    int count = solution.countRangeSum(nums, lower, upper);
    cout << count << endl; // Output: 3
    return 0;
}