#ifndef HotDogStandsClass_H
#define HotDogStandsClass_H

#include <string>
using namespace std;
// Defines the HotDogStandsClass
class HotDogStandsClass
{
    private:
        string IDString;
        string address;
        float costPerHD;
        int inventory;
        int sold;
        int numberOfStores;
        static int totalSold;

    public:
        string getIDString();
        string getAddress();
        float getCostPerHD();
        int getTotalSold();
        int getInventory();
        int getSold();

        void setIDString(string);
        void setAddress(string);
        void setCostPerHD(float);
        void setTotalSold(int);
        void setInventory(int);
        void setSold(int);
        void setNumberOfStores(int);

        void hotDogsBuy(int);
        void stockInventory(int);

        HotDogStandsClass();

};

#endif