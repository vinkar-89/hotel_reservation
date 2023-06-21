/*
    Hotel rooms division -
    Presidential suite
            Penthouse suite
                Executive suite
                    honeymoon /
        couple room double
            single

                Assistant -
    Virtual interaction

    Book room =

*/

#include <iostream>
#include <queue>
#include <math.h>
#include <string>
#include <map>
using namespace std;

class HotelBooking
{
private:
    map<string, int> typeHash;
    int id;
    // vector<queue<roomInfo>> roomData;
    priority_queue<int, vector<int>, greater<int>> roomData[6];
    vector<int> capacity;
    vector<int> prices;
    // Constructor
public:
    HotelBooking()
    {
        typeHash["Penthouse"] = 0;
        typeHash["Presidential"] = 1;
        typeHash["Executive"] = 2;
        typeHash["Couple"] = 3;
        typeHash["Double"] = 4;
        typeHash["Single"] = 5;
        capacity.push_back(10);
        capacity.push_back(1);
        capacity.push_back(100);
        capacity.push_back(100);
        capacity.push_back(200);
        capacity.push_back(300);
        prices.push_back(500000);
        prices.push_back(10000000);
        prices.push_back(5000);
        prices.push_back(1000);
        prices.push_back(500);
        prices.push_back(300);
        // for (int i = 0; i < 5; i++)
        // {
        //     (roomData + i) = new int;
        // }
        id = 0;
    }

    bool isAvailable(int bookDate, string hotelType)
    {
        if (capacity[typeHash[hotelType]] > roomData[typeHash[hotelType]].size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int Bill(int bookDate, int nOfDays, string newHotelType)
    {
        return nOfDays * prices[typeHash[newHotelType]];
    }
    int waitingDays(int bookDate, string hotelType)
    {
        return roomData[typeHash[hotelType]].top();
    }
    void listAvailable(int bookDate, int nOfDays)
    {
        for (auto it = typeHash.begin(); it != typeHash.end(); it++)
        {
            if (capacity[it->second] > roomData[it->second].size())
            {
                cout << "\n"
                     << it->first;
            }
        }
    }
    void Book(int nOfDays, string hotelType)
    {
        roomData[typeHash[hotelType]].push(nOfDays);
    }
    void assistant()
    {
        string decision;
        cout << "Hello sir/ma'am! Welcome to Hotel Cecil. How may I assist you? Would you like to book a room?" << endl;
        cout << "[Yes/No]" << endl;
        cin >> decision;
        if (decision == "Yes")
        {
            // cout << "For which date shall I book?\n";
            // cout << "[Enter a number n where 0 <= n <= 30, n=0 implies today]\n";
            int bookDate = 1;
            // cin >> bookDate;
            cout << "What kind of room would you like to book?\n";
            cout << "We have a Penthouse suite, Presidential suite, Executive suite, Couple suite, Double, Single" << endl;
            cout << "[Enter the type of room as a string]" << endl;
            string hotelType;
            cin >> hotelType;
            cout << "How many days would you like to stay?" << endl;
            cout << "[Enter a number n where n >= 1]" << endl;
            int nOfDays;
            cin >> nOfDays;
            if (isAvailable(bookDate, hotelType))
            {
                cout << "We have a room available for you!! " << endl;
                Book(nOfDays, hotelType);

                cout << "Your estimated bill will be " << Bill(bookDate, nOfDays, hotelType) << " units and you can pay anytime during your stay :)" << endl;
                cout << "Thank you for booking with us. Here are the keys." << endl;
                // cout << "[Enter -1 to start a new booking]" << endl;
                cout << "[Enter 1 to start a new booking and 0 to terminate]" << endl;
                // int terminate;
                // cin>>terminate;
                // if(terminate == -1)
            }
            else
            {
                cout << "Sorry we do not have rooms at this time!" << endl;
                cout << "Would you like to book another kind of room or wait until the room becomes available?" << endl;
                cout << "[Enter 1 for booking another kind of room and 2 for waiting until the room becomes available]" << endl;
                int choice;
                cin >> choice;
                if (choice == 1)
                {
                    cout << "We have the following rooms available:";
                    listAvailable(bookDate, nOfDays);
                    cout << "\nWhich one would you like to book?\n";
                    cout << "[Enter the type of hotel as a string]" << endl;
                    string newHotelType;
                    cin >> newHotelType;
                    cout << "How many days would you like to stay?" << endl;
                    // cout << "[Enter a number n where n>=1]" << endl;
                    int nOfDays;
                    cin >> nOfDays;
                    Book(nOfDays, newHotelType);
                    cout << "Your estimated bill will be " << Bill(bookDate, nOfDays, newHotelType) << " units and you can pay anytime during your stay :)" << endl;
                    cout << "Thank you for booking with us. Here are the keys." << endl;
                    // cout << "[Enter -1 to start a new booking]" << endl;
                    cout << "[Enter 1 to start a new booking and 0 to terminate]" << endl;
                }
                else
                {
                    cout << "Your room will be available after " << waitingDays(bookDate, hotelType) << " days.\n";
                    cout << "Your estimated bill will be " << Bill(bookDate, nOfDays, hotelType) << " units and you can pay anytime during your stay :)" << endl;
                    cout << "Thank you for booking with us. Here are the keys." << endl;
                    // cout << "[Enter -1 to start a new booking]" << endl;
                    cout << "[Enter 1 to start a new booking and 0 to terminate]" << endl;
                }
            }
        }
        else
        {
            cout << "Well, sorry but we can't help you with anything else." << endl;
        }
    }
};

int main()
{

    HotelBooking Cecil;
    Cecil.assistant();
    int session;
    cin >> session;
    while (session == 1)
    {
        Cecil.assistant();
        cin >> session;
    }
}