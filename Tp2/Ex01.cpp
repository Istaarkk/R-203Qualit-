Questions 6 :
Le compte avec le plus d'argent est le deuxième compte.
Question 7 :
Renommage des membres de la classe :
balance devient mBalance pour respecter la convention des membres privés de classe.
float b dans le constructeur devient float initialBalance pour rendre son intention plus claire.
Renommage des méthodes :
ba_deposit devient deposit pour suivre la convention des noms de méthodes.
ba_withdraw devient withdraw pour la même raison.
ba_get devient getBalance pour indiquer clairement qu'il s'agit d'une méthode pour obtenir le solde.
#include <iostream>
using namespace std;
class BankAccount {
public:
    BankAccount(float initialBalance) : mBalance(initialBalance) {}
    void deposit(float amount) {

        mBalance += amount;
    }
    void withdraw(float amount) {
        if (amount <= mBalance) {
            mBalance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
    float getBalance() {
        return mBalance;
    }
private:
    float mBalance;
};
int main() {
    BankAccount firstAccount(0.0);
    BankAccount secondAccount(100.0);
    BankAccount thirdAccount(50.0); // Ajout du troisième compte
    firstAccount.deposit(100.0);
    firstAccount.withdraw(50.0);
    secondAccount.deposit(100.0);
    secondAccount.withdraw(50.0);
    thirdAccount.deposit(200.0); // Opération spécifique au troisième compte
    cout << "First Account Balance: " << firstAccount.getBalance() << endl;
    cout << "Second Account Balance: " << secondAccount.getBalance() << endl;
    cout << "Third Account Balance: " << thirdAccount.getBalance() << endl; // Affichage du solde du troisième compte
    return 0;
}
Questions 8 :
Le troisième compte a été initialisé avec un solde de 50.0, puis une opération de dépôt de 200.0 a été effectuée. Par conséquent, le montant total d'argent dans le troisième compte est de 250.0.
#include <iostream>
#include <string>
using namespace std;
class GrammaticallyCorrectMessage {
private:
    string number;
    string verb;
    string pluralModifier;
    void thereAreNoCandidates() {
        number = "no";
        verb = "are";
        pluralModifier = "s";
    }
    void thereIsOneCandidate() {
        number = "1";
        verb = "is";
        pluralModifier = "";
    }
    void thereAreMultipleCandidates(int count) {
        number = to_string(count);
        verb = "are";
        pluralModifier = "s";
    }
    void assignValuesToMessageParts(int count) {
        if (count == 0) {
            thereAreNoCandidates();

        } else if (count == 1) {
            thereIsOneCandidate();
        } else {
            thereAreMultipleCandidates(count);
        }
    }
public:
    string createMessage(string candidate, int count) {
        assignValuesToMessageParts(count);
        string message = "There " + verb + " " + number + " " + candidate + pluralModifier + ".";
        return message;
    }
};
int main() {
    GrammaticallyCorrectMessage message;
    cout << message.createMessage("bicycle", 0) << endl;
    cout << message.createMessage("house", 1) << endl;
    cout << message.createMessage("computer", 2) << endl;
    return 0;
}
