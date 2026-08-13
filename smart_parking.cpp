#include <iostream>
#include <string>
using namespace std;

class ParkingSlot
{
public:
    int slotNumber;
    string slotType;
    bool occupied;
    string vehicleNumber;

    ParkingSlot()
    {
        slotNumber = 0;
        slotType = "";
        occupied = false;
        vehicleNumber = "";
    }
};


class ParkingSystem
{
private:
    ParkingSlot slots[10];
    int totalSlots;

public:

    ParkingSystem()
    {
        totalSlots = 10;

        // Creating different types of slots

        for(int i = 0; i < totalSlots; i++)
        {
            slots[i].slotNumber = i + 1;
            slots[i].occupied = false;
        }

        // Slot types

        slots[0].slotType = "Car";
        slots[1].slotType = "Bike";
        slots[2].slotType = "Car";
        slots[3].slotType = "EV";
        slots[4].slotType = "Bike";
        slots[5].slotType = "Car";
        slots[6].slotType = "EV";
        slots[7].slotType = "Bike";
        slots[8].slotType = "Car";
        slots[9].slotType = "Bike";
    }


    void parkVehicle()
    {
        string vehicleNumber;
        string vehicleType;

        cout << "\nEnter vehicle number: ";
        cin >> vehicleNumber;

        cout << "Enter vehicle type (Car/Bike/EV): ";
        cin >> vehicleType;


        for(int i = 0; i < totalSlots; i++)
        {
            if(slots[i].occupied &&
               slots[i].vehicleNumber == vehicleNumber)
            {
                cout << "\nVehicle is already parked!\n";
                return;
            }
        }


        for(int i = 0; i < totalSlots; i++)
        {
            if(!slots[i].occupied &&
               slots[i].slotType == vehicleType)
            {
                slots[i].occupied = true;
                slots[i].vehicleNumber = vehicleNumber;

                cout << "\nVehicle parked successfully!\n";
                cout << "Assigned Slot: "
                     << slots[i].slotNumber << endl;

                return;
            }
        }


        cout << "\nNo suitable slot available!\n";
    }


    void displaySlots()
    {
        cout << "\n------ PARKING STATUS ------\n";

        for(int i = 0; i < totalSlots; i++)
        {
            cout << "Slot " << slots[i].slotNumber
                 << " | Type: " << slots[i].slotType;

            if(slots[i].occupied)
            {
                cout << " | Occupied"
                     << " | Vehicle: "
                     << slots[i].vehicleNumber;
            }
            else
            {
                cout << " | Empty";
            }

            cout << endl;
        }
    }


    void removeVehicle()
    {
        string vehicleNumber;

        cout << "\nEnter vehicle number: ";
        cin >> vehicleNumber;


        for(int i = 0; i < totalSlots; i++)
        {
            if(slots[i].occupied &&
               slots[i].vehicleNumber == vehicleNumber)
            {
                slots[i].occupied = false;
                slots[i].vehicleNumber = "";

                cout << "\nVehicle removed successfully!\n";
                cout << "Slot " << slots[i].slotNumber
                     << " is now available.\n";

                return;
            }
        }

        cout << "\nVehicle not found!\n";
    }


    void searchVehicle()
    {
        string vehicleNumber;

        cout << "\nEnter vehicle number: ";
        cin >> vehicleNumber;


        for(int i = 0; i < totalSlots; i++)
        {
            if(slots[i].occupied &&
               slots[i].vehicleNumber == vehicleNumber)
            {
                cout << "\nVehicle found!\n";
                cout << "Vehicle: "
                     << vehicleNumber << endl;

                cout << "Slot: "
                     << slots[i].slotNumber << endl;

                cout << "Type: "
                     << slots[i].slotType << endl;

                return;
            }
        }

        cout << "\nVehicle not found!\n";
    }


    void calculateFee()
    {
        string vehicleNumber;
        int hours;

        cout << "\nEnter vehicle number: ";
        cin >> vehicleNumber;

        cout << "Enter parking hours: ";
        cin >> hours;


        for(int i = 0; i < totalSlots; i++)
        {
            if(slots[i].occupied &&
               slots[i].vehicleNumber == vehicleNumber)
            {
                int rate;

                if(slots[i].slotType == "Bike")
                    rate = 20;
                else if(slots[i].slotType == "EV")
                    rate = 30;
                else
                    rate = 40;


                int fee = hours * rate;

                cout << "\nParking Fee = Rs. "
                     << fee << endl;

                return;
            }
        }

        cout << "\nVehicle not found!\n";
    }
};


int main()
{
    ParkingSystem parking;

    int choice;

    do
    {
        cout << "\n\n===== SMART PARKING SYSTEM =====";
        cout << "\n1. Park Vehicle";
        cout << "\n2. Display Parking Slots";
        cout << "\n3. Remove Vehicle";
        cout << "\n4. Search Vehicle";
        cout << "\n5. Calculate Parking Fee";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
                parking.parkVehicle();
                break;

            case 2:
                parking.displaySlots();
                break;

            case 3:
                parking.removeVehicle();
                break;

            case 4:
                parking.searchVehicle();
                break;

            case 5:
                parking.calculateFee();
                break;

            case 6:
                cout << "\nThank you!\n";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while(choice != 6);


    return 0;
}
