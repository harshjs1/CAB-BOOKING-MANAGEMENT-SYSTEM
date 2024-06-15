#include <iostream>
#include <cmath>
#include <cstring>
#include <unistd.h>

#define FARE_PER_100M 10

using namespace std;

typedef struct {
    int station;
    float x;
    float y;
} Station;

class Queue {
public:
    int data[10];
    char name[20];
    char phn_no[12];
    int front;
    int rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % 3 == front;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % 3;
        data[rear] = element;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "No E-CAB available." << endl;
            return -1;
        }
        int element = data[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 3;
        }
        return element;
    }
};

float calculateDistance(Station* stations, int pickupStation, int dropStation) {
    float x1 = stations[pickupStation - 1].x;
    float y1 = stations[pickupStation - 1].y;
    float x2 = stations[dropStation - 1].x;
    float y2 = stations[dropStation - 1].y;

    float distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distance / 10;
}

int calculateFare(float distance) {
    return static_cast<int>(distance * FARE_PER_100M + 10);
}

int main() {
    char pay[][50] = {"CASH", "UPI/GPAY"};
    char name[50];

    char phno[12];
    int passenger;

    Station stations[8];
    stations[0].station = 1;
    stations[0].x = 0.0;
    stations[0].y = 0.0;
    stations[1].station = 2;
    stations[1].x = 0.0;
    stations[1].y = 10.0;
    stations[2].station = 3;
    stations[2].x = 10.0;
    stations[2].y = 10.0;
    stations[3].station = 4;
    stations[3].x = 15.0;
    stations[3].y = 10.0;
    stations[4].station = 5;
    stations[4].x = 20.0;
    stations[4].y = 15.0;
    stations[5].station = 6;
    stations[5].x = 25.0;
    stations[5].y = 20.0;
    stations[6].station = 7;
    stations[6].x = 25.0;
    stations[6].y = 25.0;
    stations[7].station = 8;
    stations[7].x = 30.0;
    stations[7].y = 20.0;

    Queue station1, station2, station3, station4, station5, station6, station7, station8;

    station1.enqueue(101);
    station1.enqueue(102);
    station1.enqueue(103);

    station2.enqueue(201);
    station2.enqueue(202);
    station2.enqueue(203);

    station3.enqueue(301);
    station3.enqueue(302);
    station3.enqueue(303);

    station4.enqueue(401);
    station4.enqueue(402);
    station4.enqueue(403);

    station5.enqueue(501);
    station5.enqueue(502);
    station5.enqueue(503);

    station6.enqueue(601);
    station6.enqueue(602);
    station6.enqueue(603);

    station7.enqueue(701);
    station7.enqueue(702);
    station7.enqueue(703);

    station8.enqueue(801);
    station8.enqueue(802);
    station8.enqueue(803);

    int pickupStation;
    int dropStation;
    char choice;
    char checker;
    do {
        cout << "WELCOME TO IITP E-CAB SERVICES" << endl;
        cout << "Please Wait......" << endl;
        sleep(2);

        cout << "ENTER YOUR NAME:" << endl;
       /* cin.ignore();*/
        cin.getline(name, 50);

        cout << "ENTER YOUR PHONE NUMBER:" << endl;
        cin >> phno;

        cout << "ENTER THE NUMBER OF PASSENGER:" << endl;
        cin >> passenger;
        if (passenger <= 5) {
            cout << "The pickup and drop locations:";
            cout << "\n1. Gate no.1" << endl;
            cout << "2. Admin block" << endl;
            cout << "3. Tutorial Block" << endl;
            cout << "4. Asima Hostel" << endl;
            cout << "5. Kalam Hostel" << endl;
            cout << "6. D. Quarters" << endl;
            cout << "7. Guest house" << endl;
            cout << "8. Health Center" << endl;

            cout << "ENTER THE PICKUP STATION (1-8): ";
            cin >> pickupStation;

            cout << "ENTER DROP STATION (1-8): ";
            cin >> dropStation;

            char loc[][20] = {"Gate no.1", "Admin block", "Tutorial Block", "Asima Hostel", "Kalam Hostel", "D. Quarters", "Guest house", "Health Center"};

            if (pickupStation < 1 || pickupStation > 8 || dropStation < 1 || dropStation > 8 || pickupStation == dropStation) {
                cout << "INVALID PICKUP AND DROP STATION." << endl;
            } else {
                Queue* pickupQueue;
                Queue* dropQueue;

                switch (pickupStation) {
                    case 1:
                        pickupQueue = &station1;
                        break;
                    case 2:
                        pickupQueue = &station2;
                        break;
                    case 3:
                        pickupQueue = &station3;
                        break;
                    case 4:
                        pickupQueue = &station4;
                        break;
                    case 5:
                        pickupQueue = &station5;
                        break;
                    case 6:
                        pickupQueue = &station6;
                        break;
                    case 7:
                        pickupQueue = &station7;
                        break;
                    case 8:
                        pickupQueue = &station8;
                        break;
                }

                switch (dropStation) {
                    case 1:
                        dropQueue = &station1;
                        break;
                    case 2:
                        dropQueue = &station2;
                        break;
                    case 3:
                        dropQueue = &station3;
                        break;
                    case 4:
                        dropQueue = &station4;
                        break;
                    case 5:
                        dropQueue = &station5;
                        break;
                    case 6:
                        dropQueue = &station6;
                        break;
                    case 7:
                        dropQueue = &station7;
                        break;
                    case 8:
                        dropQueue = &station8;
                        break;
                }

                int cabNumber = pickupQueue->dequeue();
                string person;
                long long int contact;
                cout << "Searching cabs in the area..." << endl;
                sleep(2);

                if (cabNumber != -1) {
                    if (cabNumber == 101) {
                        person = "Chandra";
                        contact = 9207654302;
                    } else if (cabNumber == 102) {
                        person = "Lokesh";
                        contact = 9207654124;
                    } else if (cabNumber == 103) {
                        person = "Yogi";
                        contact = 6207654231;
                    } else if (cabNumber == 201) {
                        person = "Chandrayan";
                        contact = 9207655322;
                    } else if (cabNumber == 202) {
                        person = "Keshav";
                        contact = 9207654162;
                    } else if (cabNumber == 203) {
                        person = "Bagha";
                        contact = 9207657200;
                    } else if (cabNumber == 301) {
                        person = "Yatendra";
                        contact = 9207651473;
                    } else if (cabNumber == 302) {
                        person = "Deepak";
                        contact = 9207654632;
                    } else if (cabNumber == 303) {
                        person = "Arsh";
                        contact = 9207654931;
                    } else if (cabNumber == 401) {
                        person = "Chandragol";
                        contact = 9207654305;
                    } else if (cabNumber == 402) {
                        person = "Brian";
                        contact = 9207654321;
                    } else if (cabNumber == 403) {
                        person = "Mani";
                        contact = 9207625432;
                    } else if (cabNumber == 501) {
                        person = "Rakesh";
                        contact = 9207650432;
                    } else if (cabNumber == 502) {
                        person = "Rohan";
                        contact = 9207651432;
                    } else if (cabNumber == 503) {
                        person = "Raj";
                        contact = 9207654132;
                    } else if (cabNumber == 601) {
                        person = "QUESH";
                        contact = 9207654312;
                    } else if (cabNumber == 602) {
                        person = "Hitesh";
                        contact = 9207654321;
                    } else if (cabNumber == 603) {
                        person = "Roop";
                        contact = 9207651432;
                    } else if (cabNumber == 701) {
                        person = "RITESH";
                        contact = 9207652432;
                    } else if (cabNumber == 702) {
                        person = "Azad";
                        contact = 9207653432;
                    } else if (cabNumber == 703) {
                        person = "Kuldeep";
                        contact = 9207655432;
                    } else if (cabNumber == 801) {
                        person = "Gagan";
                        contact = 9207675432;
                    } else if (cabNumber == 803) {
                        person = "Nitesh";
                        contact = 9207650432;
                    } else if (cabNumber == 802) {
                        person = "Pathak";
                        contact = 9207654232;
                    }

                    float distance = calculateDistance(stations, pickupStation, dropStation);
                    int fare = calculateFare(distance);

                    cout << "The total amount is: Rs. " << fare << endl;
                    cout << "Confirm ride(Y/N)? ";
                    cin >> checker;

                    if (checker == 'y' || checker == 'Y') {
                        int q = 0;
                        do {
                            cout << "Select mode of payment:\n1. Cash\n2. UPI/GPay\n";
                            cin >> q;
                            cout << "\n\n\n\n\n\n\n\t\t\tPlease Wait.";
                            sleep(1);
                            cout << "\n\n\n\n\n\n\n\t\t\tPlease Wait..";
                            sleep(1);
                            cout << "\n\n\n\n\n\n\n\t\t\tPlease Wait...";
                            sleep(1);
                            cout << "\n\n\n\n\n\n\n\t\t\tPlease Wait....";
                            sleep(1);
                            cout << "\n";
                            if (q > 2 || q < 1)
                                cout << "Error. Invalid payment mode. " << endl;
                        } while (q > 2 || q < 1);
                        cout << "==============HERE IS YOUR RECEIPT================\n\n";
                        cout << "==============YOUR E-CAB IS BOOKED=================\n";
                        cout << "NAME                             :  " << name << endl;
                        cout << "PHONE NO.                        :  " << phno << endl;
                        cout << "Name of your driver              :  " << person << endl;
                        cout << "Contact number for any query     :  " << contact << endl;
                        cout << "CAB NUMBER                       :  " << cabNumber << endl;
                        cout << "PICKUP STATION                   :  " << loc[pickupStation - 1] << endl;
                        cout << "DROP STATION                     :  " << loc[dropStation - 1] << endl;
                        cout << "DISTANCE                         :  " << distance << " km" << endl;
                        cout << "FARE CHARGE                      :  " << fare << " Rupees Only" << endl;
                        cout << "PAYMENT MODE                     :  " << pay[q - 1] << endl;
                    }
                } else {
                    cout << "NO E-CAB AVAILABLE AT PICKUP STATION " << pickupStation << "." << endl;
                }

                int pickupCabs = pickupQueue->rear != -1 ? (pickupQueue->rear - pickupQueue->front + 1) % 3 : 0;

                int dropCabs = dropQueue->rear != -1 ? (dropQueue->rear - dropQueue->front + 3) % 3 : 0;
                dropCabs = dropCabs + (4 - pickupCabs);

                cout << "\nAVAILABLE E-CAB AT PICKUP STATION " << pickupStation << ":  " << pickupCabs << endl;
                cout << "AVAILABLE E-CAB AT DROP STATION " << dropStation << ":    " << dropCabs << endl;
                cout << "THANK YOU.\nHOPE YOU ENJOYED OUR SERVICE !" << endl;
                cout << "\nANOTHER BOOKING (Y/N) : ";
                cin >> choice;
                if (choice == 'n' || choice == 'N')
                    break;
                cout << "\n";
            }
        } else {
            cout << "SORRY! BUT AN E-CAB CAN ACCOMMODATE A MAXIMUM OF 5 PASSENGERS." << endl;
            break;
        }

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
