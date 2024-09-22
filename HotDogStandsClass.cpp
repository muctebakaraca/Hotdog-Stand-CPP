#include <string>
#include <iostream>
#include "HotDogStandsClass.h"
using namespace std;

// Implementation of the HotDogStandsClass
void HotDogStandsClass::setNumberOfStores(int n)
{
    numberOfStores = n;
}
void HotDogStandsClass::setIDString (string ID)
{
    IDString = ID;
}
void HotDogStandsClass::setAddress(string add) {
    address = add;
}

void HotDogStandsClass::setCostPerHD(float costPer) {
    costPerHD = costPer;
}

void HotDogStandsClass::setTotalSold(int total) {
    totalSold = total;
}

void HotDogStandsClass::setInventory(int inv) {
    inventory += inv;
}

void HotDogStandsClass::setSold(int s) {
    sold = s;
}

string HotDogStandsClass::getIDString() {
    return IDString;
}

string HotDogStandsClass::getAddress() {
    return address;
}

float HotDogStandsClass::getCostPerHD() {
    return costPerHD;
}

int HotDogStandsClass::getTotalSold() {
    return totalSold;
}

int HotDogStandsClass::getInventory() {
    return inventory;
}

int HotDogStandsClass::getSold() {
    return sold;
}

// Constructor
HotDogStandsClass::HotDogStandsClass()
{
    totalSold = 0;
}

// The hotDogsBuy method used to change the inventory and increment the sale numbers
void HotDogStandsClass::hotDogsBuy(int n)
{
    if (inventory == 0)
    {
        cout << "There are no more hot dogs left in our inventory. " << endl;
    }
    else
    {
        if (n > inventory)
        {
            cout << "There is not enough hot dogs in our inventory, try again later. The inventory is at: " << inventory << endl;
        }
        else
        {
            sold += n;
            totalSold += n;
            inventory -= n;
        }
    }
}

// Stocks the inventory
void HotDogStandsClass::stockInventory(int k)
{
    inventory += k;
}