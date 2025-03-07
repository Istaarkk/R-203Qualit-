#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
private:
    string mName;
    int mExpiresIn;
    int mQuality;

public:
    Item(string name, int expiresIn, int quality) : mName(name), mExpiresIn(expiresIn), mQuality(quality) {}

    string getName() const {
        return mName;
    }

    int getExpiresIn() const {
        return mExpiresIn;
    }

    int getQuality() const {
        return mQuality;
    }

    void setQuality(int quality) {
        mQuality = quality;
    }

    void setExpiresIn(int expiresIn) {
        mExpiresIn = expiresIn;
    }
};

class Shop {
private:
    vector<Item> & items;

    // Méthodes auxiliaires pour la mise à jour des différents types d'items
    void updateNormalItem(Item & item);
    void updateCheese(Item & item);
    void updateConcertTicket(Item & item);
    void updateExcalibur(Item & item);
    void updateSpecialItem(Item & item);

    // Méthode pour réinitialiser la qualité d'un item dans les limites autorisées
    void resetQualityToWithinRange(Item & item);

public:
    Shop(vector<Item> & itemsInStock) : items(itemsInStock) {}

    vector<Item>& getItems() {
        return items;
    }

    void updateItems();
};

void Shop::updateItems() {
    for (Item & item : items) {
        if (item.getName() == "Normal Item") {
            updateNormalItem(item);
        } else if (item.getName() == "Cheese") {
            updateCheese(item);
        } else if (item.getName() == "Concert Ticket") {
            updateConcertTicket(item);
        } else if (item.getName() == "Excalibur") {
            updateExcalibur(item);
        } else if (item.getName() == "Special Item") {
            updateSpecialItem(item);
        }
        resetQualityToWithinRange(item);
    }
}

void Shop::updateNormalItem(Item & item) {
    int qualityChangeRate = 1;
    if (item.getExpiresIn() <= 0) {
        qualityChangeRate *= 2; // La qualité diminue deux fois plus vite après la date d'expiration
    }
    item.setQuality(item.getQuality() - qualityChangeRate);
    item.setExpiresIn(item.getExpiresIn() - 1);
}

void Shop::updateCheese(Item & item) {
    item.setQuality(item.getQuality() + 1);
    item.setExpiresIn(item.getExpiresIn() - 1);
}

void Shop::updateConcertTicket(Item & item) {
    if (item.getExpiresIn() > 10) {
        item.setQuality(item.getQuality() + 1);
    } else if (item.getExpiresIn() > 5) {
        item.setQuality(item.getQuality() + 2);
    } else if (item.getExpiresIn() > 0) {
        item.setQuality(item.getQuality() + 3);
    } else {
        item.setQuality(0);
    }
    item.setExpiresIn(item.getExpiresIn() - 1);
}

void Shop::updateExcalibur(Item & item) {
    // La qualité de Excalibur ne change pas avec le temps
    item.setExpiresIn(item.getExpiresIn() - 1);
}

void Shop::updateSpecialItem(Item & item) {
    if (item.getExpiresIn() <= 0) {
        item.setQuality(item.getQuality() + 4); // La qualité augmente de 4 par jour après la date d'expiration
    } else {
        item.setQuality(item.getQuality() - 2); // La qualité diminue deux fois plus vite avant la date d'expiration
    }
    item.setExpiresIn(item.getExpiresIn() - 1);
}

void Shop::resetQualityToWithinRange(Item & item) {
    // Remettre la qualité dans les limites autorisées
    if (item.getQuality() < 0) {
        item.setQuality(0);
    } else if (item.getQuality() > 50) {
        item.setQuality(50);
    }
}

int main() {
    Item normalItem("Normal Item", 4, 6);
    Item cheese("Cheese", 4, 10);
    Item concertTicket("Concert Ticket", 4, 14);
    Item excalibur("Excalibur", 4, 10);
    Item specialItem("Special Item", 3, 4); // Ajout de Special Item
    vector<Item> itemsInStock = {normalItem, cheese, concertTicket, excalibur, specialItem}; // Ajout de Special Item
    Shop qualityShop(itemsInStock);
    int workingDays = 6;

    for (int i = 0; i < workingDays; i++) {
        cout << "Day " << i + 1 << endl;
        qualityShop.updateItems();
        for (int j = 0; j < qualityShop.getItems().size(); j++) {
            cout << qualityShop.getItems()[j].getName() << ": Quality(" << qualityShop.getItems()[j].getQuality() << "), expires in " << qualityShop.getItems()[j].getExpiresIn() << " days." << endl;
        }
    }

    return 0;
}

