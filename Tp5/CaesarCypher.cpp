#include <iostream>
#include <string>
#Ex01
using namespace std;

class cesarEncoding {
public:
    string encoder(string message) {
        string encodedMessage = "";
        for (auto letter : message) {
            encodedMessage += encodeLetter(letter);
        }
        return encodedMessage;
    }

private:
    int key = 3;

    char encodeLetter(char letter) {
        letter += key;
        return letter;
    }
};

int main() {
    string message = "A message to encode";
    cesarEncoding encoding;
    cout << encoding.encoder(message) << endl;
    return 0;
}
