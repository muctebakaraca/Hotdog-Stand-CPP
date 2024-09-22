/*
    Program Name : HotDogStands
    Author       : Mucteba Karaca
    Date Written : 04/22/2026
    Program Purpose:
        The purpose of this program is to act as a demonstration of classes and their uses. It does this by simulating
        a point of service tool and tracking demonstrative hot dog stands and their information.
*/
// Includes any relavant libraries using the standard namespace.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
// Includes the specification and implementation files.
#include "HotDogStandsClass.h"
#include "HotDogStandsClass.cpp"
using namespace std;

int HotDogStandsClass::totalSold = 0;

// The main function
int main()
{
    // Initializes all variables
    string line, lines, identification;
    ifstream input;
    ofstream output;
    int lineCounter = 0, counter = 0, entryCounter = 0, linesInInfoFile = 0;
    float globalSales;
    
    input.open("infoHotDogStands.txt");

    // Counts the number of lines in the file
    while (getline(input, line))
    {
        lineCounter++;
        linesInInfoFile++;
    }
    input.close();

    // Makes the dynamic array of objects
    HotDogStandsClass * standsArray = new HotDogStandsClass[lineCounter];
    input.open("infoHotDogStands.txt");

    // Splits the input file into the IDString, address, costPerHOTDOG, inventory, and amount sold
    while(counter<lineCounter)
    {
        getline(input, lines, ',');
        standsArray[counter].setIDString(lines);

        getline(input, lines, ',');
        standsArray[counter].setAddress(lines);

        getline(input, lines, ',');
        standsArray[counter].setCostPerHD(stof(lines));

        getline(input, lines, ',');
        standsArray[counter].setInventory(stoi(lines));

        getline(input, lines);
        standsArray[counter].setSold(stoi(lines));

        counter++;
    }
    cout << fixed << setprecision(2);
    counter = 0;
    input.close();
    input.open("InfoGlobalSold.txt");
    lines = "";

    // Sets the total sold file
    while(counter<lineCounter)
    {
        input >> lines;
        standsArray[counter].setTotalSold(stoi(lines));
        counter++;
    }
    input.close();

    // Displays the initial stand stats.
    cout << "Initial states of stands: " << endl;
    cout << "========================= " << endl;
    cout << endl;
    for (int i = 0; i < lineCounter; i++)
    {
        cout << "Stand Id  : " << standsArray[i].getIDString() << endl;
        cout << "Address   : " << standsArray[i].getAddress() << endl;
        cout << "Price     : " << standsArray[i].getCostPerHD() << endl;
        cout << "Inventory : " << standsArray[i].getInventory() << endl;
        cout << "Store Sold: " << standsArray[i].getSold() << " at $" << standsArray[i].getCostPerHD() << " ea." << endl;
        cout << endl;
    }
    cout << "Global sold: " << standsArray[0].getTotalSold() << endl;
    cout << "Press the enter key once or twice to continue..." << endl;
    cout << "================================================" << endl; 
    cin.ignore(); cin.get();

    cout << "Processing Transactions: " << endl;
    cout << "======================== " << endl;


    input.open("InfoHotDogStandsTransactions.txt");
    lines = "";
    int linesCounter = 0;
    while(getline(input, lines))
    {
        linesCounter++;
    }
    counter = 0;
    input.close();
    input.open("InfoHotDogStandsTransactions.txt");
    int argument = 0;
    // For every input in the transactions file, displays the relevant information.
    while(counter < linesCounter)
    {
        getline(input, identification, ',');
        for (int i = 0; i < linesCounter; i++)
        {
            if (standsArray[i].getIDString() == identification)
            {
                cout << "HotDog Stand Current Status : " << endl;
                cout << "Stand Id  : " << standsArray[i].getIDString() << endl;
                cout << "Address   : " << standsArray[i].getAddress() << endl;
                cout << "Price     : " << standsArray[i].getCostPerHD() << endl;
                cout << "Inventory : " << standsArray[i].getInventory() << endl;
                cout << "Store Sold: " << standsArray[i].getSold() << " at $" << standsArray[i].getCostPerHD() << " ea." << endl;
                cout << endl;
                cout << "Transaction:" << endl;
                cout << "Transaction Stand Id  : " << standsArray[i].getIDString() << endl;
                getline(input, identification, ',');
                if (identification == "stock inventory")
                {
                    cout << "Transaction Id: stock inventory" << endl;
                    getline(input, line);
                    argument = stoi(line);
                    cout << "Transaction Argument: " << argument << endl;
                    standsArray[i].stockInventory(argument);
                    counter++;
                }
                else if (identification == "buy")
                {
                    cout << "Transaction Id: buy" << endl;
                    getline(input, line);
                    argument = stoi(line);
                    cout << "Transaction Argument: " << argument << endl;
                    standsArray[i].hotDogsBuy(argument);
                    counter++;
                }
                cout << endl;
                cout << "HotDog Stand Status After Transaction :" << endl;
                cout << endl;
                cout << "Stand Id  : " << standsArray[i].getIDString() << endl;
                cout << "Address   : " << standsArray[i].getAddress() << endl;
                cout << "Price     : " << standsArray[i].getCostPerHD() << endl;
                cout << "Inventory : " << standsArray[i].getInventory() << endl;
                cout << "Store Sold: " << standsArray[i].getSold() << " at $" << standsArray[i].getCostPerHD() << " ea." << endl;
                cout << endl;
                cout << "Global sold : " << standsArray[i].getTotalSold() << endl;
                cout << "Please press enter key once or twice to continue..." << endl;
                cout << "---------------------------------------------------" << endl;

                cin.ignore(); cin.get();
                break;
            }
        }

    }
    input.close();
    output.open("InfoHotDogStands.txt");

    // Updates the InfoHotDogStands File.
    for (int i = 0; i < linesInInfoFile; i++)
    {
        output << standsArray[i].getIDString() << "," << standsArray[i].getAddress() << "," << standsArray[i].getCostPerHD() << "," 
            << standsArray[i].getInventory() << "," << standsArray[i].getSold() << endl;
    }
    output.close();
    output.open("InfoGlobalSold.txt");
    output << standsArray[1].getTotalSold();

}
