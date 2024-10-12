# TP - Utilisation du Debugger et gestion d'erreur en C++

## Exercice 1 : Analyse d'un programme Cesar Encoding

Recopier le code suivant.

```cpp
#include <iostream>
#include <string>

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

### Réponses aux questions sur le code :

- **Quelles sont ces variables ?**
  - Les variables dans la fonction `encoder` sont `message` et `encodedMessage`.
- **Quel est le type de letter ici ?**
  - Le type de `letter` est `char`.
- **Quelle est la valeur de encodedMessage (avec les guillemets) ?**
  - La valeur de `encodedMessage` est `"D#phvvrjh#wr#hqfubhg"`.
- **Quelle est la valeur de encodeLetter(letter) quand letter: 's' ?**
  - La valeur de `encodeLetter('s')` est `'v'`.
- **Quel est le nom de ce fichier (avec l’extension) ?**
  - Le nom du fichier est `string`.
- **Quel est le type de letter+key dans WATCH ?**
  - Le type de `letter+key` dans WATCH est `int`.
- **Quelle est la valeur de encodedMessage quand letter+key == 119 ?**
  - Quand `letter+key == 119`, la valeur de `encodedMessage` est `"D#phvvrjh#wr#hqfubhg"`.
- **Quelle est la valeur de letter+key dans WATCH quand le Hit Count est atteint ?**
  - Quand le Hit Count est atteint, la valeur de `letter+key` dans WATCH est `118`.
- **Grâce au Log Message {letter+key}, déterminer combien de fois 118 apparaît dans DEBUG CONSOLE ?**
  - Grâce au Log Message `{letter+key}`, le nombre de fois que `118` apparaît dans DEBUG CONSOLE est `3`.

## Exercices 2 : Try Throw Catch

Écrire un programme qui permet à l’utilisateur de rentrer une valeur impaire positive `oddValue` depuis son clavier et qui retourne la somme des entiers naturels impairs de 1 jusqu’à `oddValue` inclus. Ce programme doit être accompagné d’une gestion d’erreur comme dans le cours.

Voici une implémentation du programme :

```cpp
#include <iostream>
#include <stdexcept>

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


- **Combien d’erreurs doit-on gérer (au moins) ?**
  - On doit gérer au moins une erreur.
- **Quel type d’erreur (standard) devrait-on retourner ?**
  - On devrait retourner une erreur de type `std::invalid_argument`.
