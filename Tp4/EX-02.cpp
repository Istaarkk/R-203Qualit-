#include <iostream>
#include <cmath>
#include <vector>
/*
Copyright 2024, Université Paris-Saclay

Permission is hereby granted, free of charge, to any
person obtaining a copy of this software and associated
documentation files (the “Software”), to deal in the
Software without restriction, including without
limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice
shall be included in all copies or substantial portions
of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY
KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
*/


using namespace std;

class PrimeGenerator {
public:
    /*
    Generate the prime up to the given parameter.

    generatePrimes uses the sieve of Eratosthenes whose
    general idea is to remove the multiples of each integer
    successively and the remaining ones must be the primes.

    Parameters:
        - maxValue: the upper limit of integers that will be checked

    Returns:
        Primes between 2 and maxValue.
    */
    vector<int> generatePrimes(int maxValue) {
        if (maxValue < 2)
            return vector<int>();
        else {
            initialization(maxValue);
            crossOutMultiples();
            return result();
        }
    }

private:
    vector<bool> crossedOut;
    vector<int> primes; // Renamed from result

    void initialization(int maxValue) {
        crossedOut = vector<bool>(maxValue + 1, false);
    }

    void crossOutMultiples() {
        int limit = determineIterationLimit();
        for (int i = 2; i <= limit; i++)
            if (!crossedOut[i])
                crossOutMultiplesOf(i);
    }

    int determineIterationLimit() {
        double iterationLimit = sqrt(crossedOut.size());
        return static_cast<int>(iterationLimit);
    }

    void crossOutMultiplesOf(int i) {
        for (int multiple = 2 * i; multiple < static_cast<int>(crossedOut.size()); multiple += i)
            crossedOut[multiple] = true;
    }

    vector<int> result() {
        primes.clear();
        for (int i = 2; i < crossedOut.size(); i++)
            if (!crossedOut[i])
                primes.push_back(i);
        return primes;
    }
};

int main() {
    PrimeGenerator generator;
    vector<int> primes = generator.generatePrimes(100);
    for (int prime : primes)
        cout << prime << " ";
    cout << endl;
    return 0;
}
