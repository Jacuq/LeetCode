class Solution {
public:
    //solution using Sieve of Eratostenes
    int countPrimes(int n) {
        /*
        * init array of all numbers [0,n)
        * could be adjusted memory-wise - you only need numbers [2,n)
        */
        bool* numbers = new bool[n];
        memset(numbers, true, n);
        
        //Sieve 
        int primes = 0;
        int sqr = sqrt(n);
        for(int i=2; i<=sqr; ++i)
        {
            if(numbers[i])
            {
                for(int j=2; j*i<n; ++j)
                    numbers[i*j] = false;
            } 
        }
        //count primes left in array
        for(int i=2; i<n; ++i)
        {
            primes += static_cast<int>(numbers[i]);
        }
        delete[] numbers;
        return primes;
    }
};