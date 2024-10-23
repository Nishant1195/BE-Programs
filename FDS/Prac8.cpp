#include <iostream>
using namespace std;

// Structure to represent a seat in the doubly circular linked list
struct Seat {
    int seatNumber;
    bool isBooked;
    Seat* prev;
    Seat* next;
};

// Class to represent a row of seats
class Row {
public:
    Seat* head;  // Head pointer for the doubly circular linked list of seats

    Row() {
        head = nullptr;
    }

    // Function to create a circular doubly linked list of 7 seats in each row
    void createSeats(int rowNumber) {
        Seat* newSeat, *temp;
        for (int i = 1; i <= 7; i++) {
            newSeat = new Seat;
            newSeat->seatNumber = i;
            newSeat->isBooked = false;

            if (head == nullptr) {
                head = newSeat;
                newSeat->next = newSeat;
                newSeat->prev = newSeat;
            } else {
                temp = head->prev;
                temp->next = newSeat;
                newSeat->prev = temp;
                newSeat->next = head;
                head->prev = newSeat;
            }
        }
    }

    // Function to display available seats
    void displaySeats() {
        Seat* temp = head;
        if (head == nullptr) {
            cout << "No seats available in this row." << endl;
            return;
        }
        do {
            if (!temp->isBooked)
                cout << "Seat " << temp->seatNumber << " [Available]" << " ";
            else
                cout << "Seat " << temp->seatNumber << " [Booked]" << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Function to book a seat
    void bookSeat(int seatNumber) {
        Seat* temp = head;
        do {
            if (temp->seatNumber == seatNumber) {
                if (temp->isBooked) {
                    cout << "Seat " << seatNumber << " is already booked." << endl;
                } else {
                    temp->isBooked = true;
                    cout << "Seat " << seatNumber << " has been successfully booked." << endl;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat " << seatNumber << " not found!" << endl;
    }

    // Function to cancel a booking
    void cancelSeat(int seatNumber) {
        Seat* temp = head;
        do {
            if (temp->seatNumber == seatNumber) {
                if (!temp->isBooked) {
                    cout << "Seat " << seatNumber << " is already available (not booked)." << endl;
                } else {
                    temp->isBooked = false;
                    cout << "Seat " << seatNumber << " booking has been successfully cancelled." << endl;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat " << seatNumber << " not found!" << endl;
    }
};

// Class to represent the theater with 10 rows
class CinemaxTheater {
public:
    Row rows[10];

    CinemaxTheater() {
        for (int i = 0; i < 10; i++) {
            rows[i].createSeats(i + 1);
        }
    }

    // Display all available seats in the theater
    void displayAvailableSeats() {
        for (int i = 0; i < 10; i++) {
            cout << "Row " << i + 1 << ": ";
            rows[i].displaySeats();
        }
    }

    // Book a seat by row and seat number
    void bookSeat(int rowNumber, int seatNumber) {
        if (rowNumber < 1 || rowNumber > 10 || seatNumber < 1 || seatNumber > 7) {
            cout << "Invalid row or seat number!" << endl;
            return;
        }
        rows[rowNumber - 1].bookSeat(seatNumber);
    }

    // Cancel a booking by row and seat number
    void cancelSeat(int rowNumber, int seatNumber) {
        if (rowNumber < 1 || rowNumber > 10 || seatNumber < 1 || seatNumber > 7) {
            cout << "Invalid row or seat number!" << endl;
            return;
        }
        rows[rowNumber - 1].cancelSeat(seatNumber);
    }
};

int main() {
    CinemaxTheater theater;

    int choice, rowNumber, seatNumber;

    do {
        cout << "\n--- Cinemax Theater Ticket Booking System ---" << endl;
        cout << "1. Display Available Seats" << endl;
        cout << "2. Book a Seat" << endl;
        cout << "3. Cancel Booking" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            theater.displayAvailableSeats();
            break;
        case 2:
            cout << "Enter row number (1-10): ";
            cin >> rowNumber;
            cout << "Enter seat number (1-7): ";
            cin >> seatNumber;
            theater.bookSeat(rowNumber, seatNumber);
            break;
        case 3:
            cout << "Enter row number (1-10): ";
            cin >> rowNumber;
            cout << "Enter seat number (1-7): ";
            cin >> seatNumber;
            theater.cancelSeat(rowNumber, seatNumber);
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
