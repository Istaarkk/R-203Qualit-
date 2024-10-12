# Exercice 1 : Shape area

```cpp
#include <iostream>
#include <cmath>

using namespace std;

class Shape {
protected:
    double width;
    double height;
    double radius;

public:
    // Constructeur
    Shape(double w = 0, double h = 0, double r = 0) : width(w), height(h), radius(r) {}

    // Méthode pour calculer l'aire
    virtual double calculateArea() const = 0; // Méthode virtuelle pure
};

class Circle : public Shape {
public:
    // Constructeur
    Circle(double r) : Shape(0, 0, r) {}

    // Méthode pour calculer l'aire du cercle
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

class Square : public Shape {
public:
    // Constructeur
    Square(double w) : Shape(w, 0, 0) {}

    // Méthode pour calculer l'aire du carré
    double calculateArea() const override {
        return width * width;
    }
};

class Rectangle : public Shape {
public:
    // Constructeur
    Rectangle(double w, double h) : Shape(w, h, 0) {}

    // Méthode pour calculer l'aire du rectangle
    double calculateArea() const override {
        return width * height;
    }
};

int main() {
    // Création des formes
    Circle circle(5);
    Square square(4);
    Rectangle rectangle(3, 5);

    // Calcul et affichage des aires
    cout << "Area of circle: " << circle.calculateArea() << endl;
    cout << "Area of square: " << square.calculateArea() << endl;
    cout << "Area of rectangle: " << rectangle.calculateArea() << endl;

    return 0;
}

# Réponses à l'exercice 1 : Shape area

## Problèmes du code initial :

1. **Manque d'encapsulation :** Les variables `width`, `height` et `radius` sont passées en paramètres de la fonction `getArea`, ce qui rend la fonction dépendante de ces variables externes, plutôt que d'avoir un comportement autonome en tant que méthode de l'objet. Cela viole le principe d'encapsulation et peut entraîner des problèmes de maintenance à mesure que le code évolue.

2. **Mauvaise gestion des erreurs :** Lorsqu'une forme invalide est passée à `getArea`, il affiche simplement un message d'erreur sur la sortie d'erreur standard et renvoie -1. Cela ne permet pas à l'appelant de savoir qu'une erreur s'est produite, et le choix d'une valeur de retour négative pour une surface n'est pas approprié car une surface ne peut pas être négative.

3. **Manque de modularité :** Les calculs d'aire sont gérés dans une fonction `getArea` qui accepte différents paramètres selon le type de forme. Cela rend le code difficile à comprendre et à maintenir, et pourrait être simplifié en utilisant une approche orientée objet avec une classe pour représenter chaque forme.

## Nombre d'attributs dans la classe Shape :

Dans une implémentation simple, une classe `Shape` pourrait avoir trois attributs privés : `width`, `height` et `radius`.

## Éviter les conflits de noms entre arguments et attributs :

Pour éviter l'ambiguïté entre les arguments de la méthode et les attributs de la classe, vous pouvez utiliser le mot-clé `this` pour faire référence aux attributs de la classe. Par exemple :
```cpp
void Shape::setWidth(double width) {
    this->width = width;
}
