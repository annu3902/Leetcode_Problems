class Solution {
    // Function to get all primne numbers less than 100
    void getPrimes(vector<int>& primes) {
        vector<bool> nums(1000, true);

        for (int i = 2; i < 1000; i++) {
            if (nums[i]) {
                // if this section is nums[i]==true than the value i is prime
                primes.push_back(i);

                int temp = i;
                while (temp + i < 1000) {
                    temp += i;
                    // marking all multiples of i as non-prime
                    nums[temp] = false;
                }
            }
        }
    }

    int perfectPrime(vector<int>& primes, int& num1, int& num2) {
        int i = 0, j = primes.size() - 1;

        while (i < j) {
            int mid = (i + j) / 2;

            // finding the most perfect prime for the number;
            if (num1 - primes[mid] <= num2)
                j = mid - 1;
            else
                i = mid + 1;
        }

        return i;
    }

public:
    bool primeSubOperation(vector<int>& nums) {

        // Setting the primes into the vector along with 0 which means no change
        vector<int> primes;
        primes.push_back(0);
        getPrimes(primes);

        // find the lowest positive non-zero value for first element
        int hh = 0;
        int ind = perfectPrime(primes, nums[0], hh);

        while (ind >= 0) {
            if (nums[0] - primes[ind] < 1)
                ind--;
            else
                break;
        }

        // checking if it is possible or not
        if (ind == -1)
            return false;
        else
            nums[0] -= primes[ind];

        // finding the most perfect value for each element else returning false
        for (int i = 1; i < nums.size(); i++) {
            ind = perfectPrime(primes, nums[i], nums[i - 1]);

            while (ind >= 0) {
                cout << nums[i] << " " << primes[ind] << endl;
                if (nums[i] - primes[ind] <= nums[i - 1])
                    ind--;
                else
                    break;
            }
            if (ind == -1)
                return false;
            else
                nums[i] -= primes[ind];
        }
        return true;
    }
};