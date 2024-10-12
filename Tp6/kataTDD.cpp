#include <unordered_map>
#include <stdexcept>
#include <string>
using namespace std;

string hello() {
    return "Hello World!";
}

string fizzBuzz(int number) {
    string result = "";
    if (number % 3 == 0) {
        result += "Fizz";
    }
    if (number % 5 == 0) {
        result += "Buzz";
    }
    if (result.empty()) {
        result = to_string(number);
    }
    return result;
}

class RomanToDecimal {
public:
    RomanToDecimal(string romanNumeral) : mRomanNumeral(romanNumeral) {}

    int getDecimal() {
        int decimal = 0;
        int prevValue = 0;
        for (char& c : mRomanNumeral) {
            int value = romanLetters[c];
            if (value > prevValue) {
                decimal += value - 2 * prevValue; // correction for previous addition
            } else {
                decimal += value;
            }
            prevValue = value;
        }
        return decimal;
    }

private:
    string mRomanNumeral;
    unordered_map<char, int> romanLetters = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
};
