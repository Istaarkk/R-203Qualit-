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
