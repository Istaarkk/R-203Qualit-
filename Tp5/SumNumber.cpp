#include <iostream>
#include <stdexcept>
#EX02
using namespace std;

int sumOddNumbersUpTo(int oddValue) {
    if (oddValue <= 0 || oddValue % 2 == 0) {
        throw invalid_argument("L'entrée doit être un nombre impair positif.");
    }

    int sum = 0;
    for (int i = 1; i <= oddValue; i += 2) {
        sum += i;
    }
    return sum;
}

int main() {
    int oddValue;
    cout << "Entrez un nombre impair positif : ";
    cin >> oddValue;

    try {
        int result = sumOddNumbersUpTo(oddValue);
        cout << "La somme des entiers naturels impairs jusqu'à " << oddValue << " est : " << result << endl;
    } catch (const invalid_argument& e) {
        cerr << "Erreur : " << e.what() << endl;
    }

    return 0;
}
