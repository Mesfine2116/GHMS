/*

			GUEST HOUSE MANAGEMENT SYSTEM !!
			Username : guesthouse
			Password : 1234


*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <time.h>
#include <ctime>

using namespace std;

struct Room
{
	int roomNumber;
	string roomType;
	string roomStatus;
	string guestName;
	bool reserved;
	bool checkedIn;
	double charge;
	Room *next;
};
bool reserved = true, checkedIn = true;
Room *head = NULL;

struct messages
{
	char roomQuality[200];
	char overall_service[200];
} msg;

void aboutSystem()
{
	do
	{
		cout << endl;
		cout << "************************************************************" << endl
			 << endl;
		cout << "             GUEST HOUSE MANAGEMENT SYSTEM" << endl;
		cout << "  -> The System Enables Our Customer To : " << endl;
		cout << "            * Reserve A Room Based On Their Interest." << endl;
		cout << "              They Can Reserve Different Types Of Rooms." << endl;
		cout << "              Such as : Luxury ,Family , Double Or Single" << endl;
		cout << "            * Pay The Rent In This System." << endl;
		cout << "            * To Reserve A Room Firstly ,The Room Must have Be" << endl;
		cout << "              Added. Then After Reserving A Room The Customer Should" << endl;
		cout << "              Checked In While They Are Getting The Room. When Customers" << endl;
		cout << "              Finish Their Renting Time , They Will Pay Their Charge With" << endl;
		cout << "              This System. Most Of This System Content Is Available " << endl;
		cout << "              For The Receptionist. By They Help Of Those Receptionist" << endl;
		cout << "              Our Guests Will Be Given A Safe Service!!" << endl
			 << endl;
		cout << "************************************************************" << endl
			 << endl;
		cout << "       __________________________________________" << endl
			 << endl;
		cout << "        THANK YOU FOR CHOOSING OUR GUEST HOUSE" << endl;
		cout << "            Press any key to continue!!" << endl
			 << endl;
		cout << "            By Mesfine" << endl;
		cout << "            ____________________________" << endl;
	} while (!getch());
	system("cls");
}
void addRoom(int roomNumber, string roomType, string roomStatus)
{
	Room *newRoom = new Room;
	newRoom->roomNumber = roomNumber;
	newRoom->roomType = roomType;
	newRoom->roomStatus = roomStatus;
	newRoom->guestName = "";
	newRoom->reserved = false;
	newRoom->checkedIn = false;
	newRoom->charge = 0.0;
	newRoom->next = NULL;
	if (head == NULL)
	{
		head = newRoom;
	}
	else
	{
		Room *current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newRoom;
	}

	if (roomNumber >= 100 && roomNumber <= 200)
	{
		system("cls");
		cout << endl
			 << endl;
		cout << "   ----------------------------------------------" << endl;
		cout << "   Room " << roomNumber << " Is Successfully Added " << endl;
		cout << "   Now You Can Reserve A Room !!" << endl;
		cout << "   ----------------------------------------------" << endl;
	}
	cout << endl
		 << endl;
	cout << "    Press any key to continue ..." << endl;
	getch();
	system("cls");
}

void editRoom(int roomNumber)
{
	Room *current = head;
	while (current != NULL)
	{
		if (current->roomNumber == roomNumber)
		{
		Label_1:
			cout << "------------------------" << endl;
			cout << "Enter new room type: ";
			if (current->roomNumber < 100 || current->roomNumber > 200)
			{
				system("cls");
				cout << "    ---------------------------------" << endl;
				cout << "    Available Rooms Are # 1 - 100" << endl;
				cout << "    Please insert the available room !!" << endl;
				cout << "    ---------------------------------" << endl
					 << endl;
				cout << "    Press any key to continue !!" << endl;
				goto Label_1;
				getch();
				system("cls");
			}
			cin >> current->roomType;
			cout << "Enter new room status: ";
			cin >> current->roomStatus;
			cout << "Enter new guest name: ";
			cin >> current->guestName;
			cout << "-------------------------" << endl;
			cout << "=> Room " << roomNumber << " has been edited." << endl;
			cout << "   ." << endl
				 << "   ." << endl;
			cout << "Press any key to continue ..." << endl;
			getch();
			system("cls");
			return;
		}
		current = current->next;
	}
	cout << "----------------------------------" << endl;
	cout << "Room " << roomNumber << " does not exist" << endl;
	cout << "----------------------------------" << endl;

	cout << endl
		 << endl;
	cout << "Press any key to continue ..." << endl;
	getch();
	system("cls");
}

void deleteRoom(int roomNumber)
{
	Room *current = head;
	Room *previous = NULL;

	while (current != NULL)
	{
		if (current->roomNumber == roomNumber)
		{
			if (current == head)
			{
				head = current->next;
			}
			else
			{
				previous->next = current->next;
			}
			delete current;
			cout << endl;
			cout << " *****************************************" << endl;
			cout << " Room " << roomNumber << " has been deleted" << endl;
			cout << " *****************************************" << endl;
			cout << endl
				 << endl;
			cout << " Press any key to continue ..." << endl;
			getch();
			system("cls");
			return;
		}
		previous = current;
		current = current->next;
	}
	cout << " --------------------------------------" << endl;
	cout << " Room " << roomNumber << " does not exist" << endl;
	cout << " --------------------------------------" << endl;

	cout << endl
		 << endl;
	cout << " Press any key to continue ..." << endl;
	getch();
	system("cls");
}
void roomDetail()
{
	Room *current = head;
	while (current != NULL)
	{
		cout << "     ******** Room Details ********" << endl
			 << endl;
		cout << " Room Number: " << current->roomNumber << endl;
		cout << " Room Type  : " << current->roomType << endl;
		cout << " Room Status: " << current->roomStatus << endl;
		cout << " Guest Name : " << current->guestName << endl;
		cout << " Charge     : Birr " << current->charge << endl;
		cout << endl;
		current = current->next;
		cout << endl;
		cout << " Press Enter To The See Next Detail !!" << endl;
		getch();
		system("cls");
	}
	if (current == NULL)
	{
		cout << endl
			 << endl;
		cout << "    There Is No More Room Detail Information " << endl;
		cout << "      Already you have reached at the end    " << endl;
		cout << "        Press any key to continue !!" << endl;
		getch();
		system("cls");
	}
	else
	{
		cout << endl
			 << endl;
		cout << "             The List Is Over !!" << endl;
		cout << "         Press any key to continue ..." << endl;
		getch();
		system("cls");
	}
}

void displayRoomDetails(int roomNumber)
{
	system("cls");
	cout << "	   **** Room Details ****" << endl;
	Room *current = head;
	while (current != NULL)
	{
		if (current->roomNumber == roomNumber)
		{
			cout << endl;
			cout << " Room Number: " << current->roomNumber << endl;
			cout << " Room Type  : " << current->roomType << endl;
			cout << " Room Status: " << current->roomStatus << endl;
			cout << " Guest Name : " << current->guestName << endl;
			cout << " Charge     : " << current->charge << " Birr" << endl;
			cout << endl;
			return;
		}
		current = current->next;
	}
	cout << " **************************************" << endl;
	cout << " Room " << roomNumber << " does not exist" << endl;
	cout << " **************************************" << endl;
}

void reserveRoom(int roomNumber, string guestName)
{
	Room *current = head;
	while (current != NULL)
	{
		if (current->roomNumber == roomNumber)
		{
			if (!current->reserved)
			{
				current->guestName = guestName;
				current->reserved = true;
				cout << " -----------------------------------------------------------" << endl;
				cout << " Room " << roomNumber << " has been reserved for " << guestName << endl;
				cout << " -----------------------------------------------------------" << endl
					 << endl;
				cout << " Press any key to continue ..." << endl;
				getch();
				system("cls");
			}
			else
			{
				cout << " ---------------------------------------------" << endl;
				cout << " Room " << roomNumber << " is already reserved" << endl;
				cout << " ---------------------------------------------" << endl
					 << endl;
				cout << " Press any key to continue ..." << endl
					 << endl;
				getch();
				system("cls");
			}
			return;
		}
		current = current->next;
	}
	cout << " --------------------------------------" << endl;
	cout << " Room " << roomNumber << " does not exist" << endl;
	cout << " --------------------------------------" << endl;
	cout << endl
		 << endl;
	cout << " Press any key to continue ..." << endl;
	getch();
	system("cls");
}

void checkIn(int roomNumber)
{
	Room *current = head;
	while (current != NULL)
	{
		if (current->roomNumber == roomNumber)
		{
			if (current->reserved && !current->checkedIn)
			{
				current->checkedIn = true;
				cout << " ---------------------------------------------------------" << endl;
				cout << " Guest " << current->guestName << " has checked in to room " << roomNumber << endl;
				cout << " ---------------------------------------------------------" << endl
					 << endl;
				cout << " Press any key to continue ..." << endl;
				getch();
				system("cls");
			}
			else if (!current->reserved)
			{
				cout << " ----------------------------------------------" << endl;
				cout << " Room " << roomNumber << " has not been reserved" << endl;
				cout << " ----------------------------------------------" << endl
					 << endl;
				cout << " Press any key to continue ..." << endl;
				getch();
				system("cls");
			}
			else
			{
				cout << " ---------------------------------------------------" << endl;
				cout << "  Room " << roomNumber << " has already been checked in" << endl;
				cout << " ---------------------------------------------------" << endl
					 << endl;
				cout << "  Press any key to continue ..." << endl;
				getch();
				system("cls");
			}
			return;
		}
		current = current->next;
	}
	cout << " -------------------------------------" << endl;
	cout << " Room " << roomNumber << " does not exist" << endl;
	cout << " -------------------------------------" << endl;
	cout << endl
		 << endl;
	cout << " Press any key to continue ..." << endl;
	getch();
	system("cls");
}

void charge(int roomNumber, double amount)
{
	Room *current = head;
	while (current != NULL)
	{
		if (current->roomNumber == roomNumber)
		{
			if (current->checkedIn)
			{
				current->charge += amount;
				cout << " ---------------------------------------------------" << endl;
				cout << " Room " << roomNumber << " has been charged Birr " << amount << endl;
				cout << " ---------------------------------------------------" << endl
					 << endl;
				cout << " Press any key to continue ..." << endl;
				getch();
				system("cls");
			}
			else if (!current->reserved)
			{
				cout << " ---------------------------------------------------" << endl;
				cout << " Room " << roomNumber << " has not been reserved" << endl;
				cout << " ---------------------------------------------------" << endl
					 << endl;
				cout << " Press any key to continue ..." << endl;
				getch();
				system("cls");
			}
			else
			{
				cout << " ---------------------------------------------------" << endl;
				cout << " Room " << roomNumber << " has not been checked in" << endl;
				cout << " ---------------------------------------------------" << endl
					 << endl;
				cout << " Press any key to continue ..." << endl;
				getch();
				system("cls");
			}
			return;
		}
		current = current->next;
	}
	cout << " ---------------------------------------" << endl;
	cout << "Room " << roomNumber << " does not exist" << endl;
	cout << " ---------------------------------------" << endl;

	cout << endl
		 << endl;
	cout << "Press any key to continue ..." << endl;
	getch();
	system("cls");
}

void checkOut(int roomNumber)
{
	Room *current = head;
	while (current != NULL)
	{
		if (current->roomNumber == roomNumber)
		{
			if (current->checkedIn)
			{
				cout << " -----------------------------------------------------------------" << endl;
				cout << " Guest " << current->guestName << " has checked out of room " << roomNumber << endl;
				cout << " -----------------------------------------------------------------" << endl;
				current->guestName = "";
				current->reserved = false;
				current->checkedIn = false;
				current->charge = 0.0;
			}
			else if (!current->reserved)
			{
				cout << " -----------------------------------------" << endl;
				cout << " Room " << roomNumber << " has not been reserved" << endl;
				cout << " -----------------------------------------" << endl;
			}
			else
			{
				cout << " -----------------------------------------" << endl;
				cout << " Room " << roomNumber << " has not been checked in" << endl;
				cout << " -----------------------------------------" << endl;
			}
			return;
		}
		current = current->next;
	}
	cout << " ---------------------------------------" << endl;
	cout << " Room " << roomNumber << " does not exist" << endl;
	cout << " ---------------------------------------" << endl;

	cout << endl
		 << endl;
	cout << " Press any key to continue ..." << endl;
	getch();
	system("cls");
}

void displayReservationList()
{
	cout << "    *** Reservation List ***" << endl;
	Room *current = head;
	while (current != NULL)
	{
		if (current->reserved && !current->checkedIn)
		{
			cout << "  **************************" << endl;
			cout << "  Room " << current->roomNumber << " - " << current->guestName << endl;
			cout << "  **************************" << endl;
		}
		current = current->next;
	}

	cout << endl
		 << endl;
	cout << " Press any key to continue ..." << endl;
	getch();
	system("cls");
}

void displayCheckInList()
{
	cout << "	 **** Check-In List ****" << endl
		 << endl;

	Room *current = head;
	while (current != NULL)
	{
		if (current->checkedIn)
		{
			cout << "  **************************" << endl;
			cout << "  Room " << current->roomNumber << " - " << current->guestName << endl;
			cout << "  **************************" << endl;
		}
		current = current->next;
	}

	cout << endl
		 << endl;
	cout << "	Press any key to continue ..." << endl;
	getch();
	system("cls");
}

void displayCheckOutList()
{
	cout << "	**** Check-Out List ****" << endl
		 << endl;
	Room *current = head;
	while (current != NULL)
	{
		if (!current->reserved && !current->checkedIn)
		{
			cout << "  ************" << endl;
			cout << "  Room : " << current->roomNumber << endl;
			cout << "  ************" << endl;
		}
		current = current->next;
	}

	cout << endl
		 << endl;
	cout << "	Press any key to continue ..." << endl;
	getch();
	system("cls");
}

void displayMenu()
{
	cout << "          ===============================  " << endl;
	cout << "            WELLCOME TO OUR GUEST HOUSE   " << endl;
	cout << "            =========================== " << endl
		 << endl;
	cout << "            MENU Press... " << endl;
	cout << "	Add Room    ....................1" << endl;
	cout << "	Edit Room   ....................2" << endl;
	cout << "	Delete Room ....................3" << endl;
	cout << "	Display Room Details ...........4" << endl;
	cout << "	Reserve Room ...................5" << endl;
	cout << "	Check In .......................6" << endl;
	cout << "	Charge .........................7" << endl;
	cout << "	Check Out ......................8" << endl;
	cout << "	Reservation List ...............9" << endl;
	cout << "	Check-In List ..................10" << endl;
	cout << "	Check-Out List..................11" << endl;
	cout << "	Comment Us  ....................12" << endl;
	cout << "	Exit ...........................13" << endl
		 << endl;
}

void commentArea()
{
	int choice;
	cout << endl
		 << endl;
	cout << "   ---------- COMMENT AREA FOR OUR GUEST --------------- " << endl
		 << endl;
	cout << "    => You Can Put Here Any Comment On Our Service ." << endl;
	cout << "    => Comment Based On The Following Choice . " << endl
		 << endl;

	cout << "                COMMENT :                             Options  " << endl;
	cout << "             => About The Room Based Issues             : 1    " << endl;
	cout << "             => About The Overall Service Delivery      : 2    " << endl
		 << endl;

	ofstream service_File("room_issued_comment.txt", ios::app);
	ofstream management_File("overall_service_comment.txt", ios::app);
	cout << " ********************** " << endl;
	cout << " Enter Your Choice : ";
	cin >> choice;
	cout << " ********************** " << endl;
	cout << endl
		 << endl;
	system("cls");

	switch (choice)
	{
	case 1:
		cout << " Enter Your Comment About Room And Room Issues : " << endl;
		cout << "              ---------------------------------------------------- " << endl;
		cout << "              => ";
		cin.ignore();
		cin.getline(msg.roomQuality, 200);
		cout << "              ---------------------------------------------------- " << endl;
		if (service_File.is_open())
		{
			service_File << " => " << msg.roomQuality << "\n"
						 << endl;
		}
		break;
	case 2:
		cout << " Enter Your Comment About Our Guest House Management Staff : " << endl;
		cout << "               --------------------------------------------------------- " << endl;
		cout << "               =>  ";
		cin.ignore();
		cin.getline(msg.overall_service, 200);
		cout << "               --------------------------------------------------------- " << endl
			 << endl;
		if (management_File.is_open())
		{
			management_File << " => " << msg.overall_service << "\n"
							<< endl;
		}
		break;
	default:
		cout << endl
			 << endl;
		cout << "           Invalid choice !! " << endl;
		cout << "                . " << endl;
		cout << "                . " << endl;
		cout << "                . " << endl;
		cout << "        Press any key to continue !!" << endl;
		getch();
	}
	if (choice == 1 || choice == 2)
	{
		cout << "                      * Succefully Sent your comment !! *" << endl;
		cout << "                           Press any key to continue " << endl;
	}
	getch();
	system("cls");
	if (choice == 1 || choice == 2)
	{
		cout << "     _________________________________________" << endl
			 << endl;
		cout << "          THANK YOU FOR YOUR FEED BACK !!	  " << endl;
		cout << "     _________________________________________" << endl
			 << endl;
		cout << "            Press any key to continue " << endl;
		getch();
		system("cls");
	}
}

int main()
{
	int choice, search, roomNumber, password;
	string username, guestName, roomType, roomStatus;
	double amount;
	do
	{
	Login:
		cout << endl
			 << endl;
		cout << "     ____________________________" << endl;
		cout << "              MENU" << endl;
		cout << "  	GUEST LOGIN PAGE  .... 1       " << endl;
		cout << "  	ABOUT THE SYSTEM  .... 2       " << endl;
		cout << "  	EXIT              .... 3       " << endl;
		cout << "     ____________________________" << endl;
		cout << "     => ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << endl
				 << endl;
			cout << "   ----------------------" << endl;
			cout << "        GUEST LOGIN PAGE " << endl
				 << endl;
			cout << "   Username : ";
			cin >> username;
			cout << "   Password : ";
			cin >> password;
			cout << "   ----------------------" << endl
				 << endl;
			if (username == "algorithm" && password == 1234)
			{
				cout << "  Successfully Logged in !!" << endl;
				cout << "  Press any key to dive in the program... " << endl
					 << endl;
				getch();
				system("cls");
				goto Menu;
			}
			else
			{
				cout << "   Incorret password !!" << endl;
				cout << "   Please enter the correct password!!" << endl;
				getch();
				system("cls");
			}

			break;
		case 2:
			system("cls");
			aboutSystem();
			goto Login;
			break;
		case 3:
			system("cls");
			cout << " -------------------------------------------" << endl;
			cout << "                THANK YOU                   " << endl;
			cout << "        FOR USING OUR GUEST HOUSE           " << endl;
			cout << " -------------------------------------------" << endl;
			cout << "                    -" << endl
				 << "                    -" << endl
				 << "                    -" << endl
				 << "                    -" << endl;
			getch();
			goto END;
			break;
		default:
			system("cls");
			cout << endl
				 << endl;
			cout << "            Invalid Entry!!  " << endl
				 << endl;
			cout << "                   ." << endl
				 << "                   ." << endl
				 << "                   ." << endl
				 << "                   ." << endl;
			cout << "       Press any key to continue" << endl;
			getch();
			system("cls");
			break;
		}
	} while (choice != 3);

	do
	{
	Menu:
		// Show the current date and time function
		cout << "    ____________________________________________ " << endl;
		cout << "   | Current Date : ";
		time_t now;
		time(&now);
		cout << (ctime(&now));
		cout << "   |____________________________________________ " << endl
			 << endl
			 << endl;
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			system("cls");
		Label_2:
			cout << "\n     Enter Room Detalis";
			cout << "\n   ----------------------" << endl;
			cout << "  Room range  : 100 - 200 " << endl;
			cout << "  Total Rooms :  100" << endl;
			cout << "  Room Type   :  - Luxury     - Single " << endl;
			cout << "                 - Family     - Double " << endl;
			cout << "  Room Status :  - Vaccant or - Occupied" << endl
				 << endl;
			cout << "  Enter room number: ";
			cin >> roomNumber;
			if (roomNumber < 100 || roomNumber > 200)
			{
				system("cls");
				cout << "    ---------------------------------" << endl;
				cout << "    Available Rooms Are # 100 - 200  " << endl;
				cout << "    Please insert the available room !!" << endl;
				cout << "    ---------------------------------" << endl
					 << endl;
				cout << "    Press any key to continue !!" << endl;
				getch();
				system("cls");
				goto Label_2;
			}
			cout << "  Enter room type  : ";
			cin >> roomType;
			cout << "  Enter room status: ";
			cin >> roomStatus;
			cout << endl
				 << endl;
			addRoom(roomNumber, roomType, roomStatus);
			break;
		case 2:
			system("cls");
			cout << "Enter room number: ";
			cin >> roomNumber;
			editRoom(roomNumber);
			break;
		case 3:
			system("cls");
			cout << "Enter room number: ";
			cin >> roomNumber;
			deleteRoom(roomNumber);
			break;
		case 4:
			system("cls");
		Room:
			cout << endl;
			cout << "          *** Room Details ***" << endl
				 << endl;
			cout << "  Options..." << endl;
			cout << "  Search Particular Room Detail   : ... 1" << endl;
			cout << "  See All Room Details            : ... 2" << endl;
			cout << "  Back                            : ... 3" << endl
				 << endl;
			cout << "Enter Your Choice : ";
			cin >> search;
			switch (search)
			{
			case 1:
				system("cls");
				cout << endl;
				cout << " Enter room number: ";
				cin >> roomNumber;
				displayRoomDetails(roomNumber);
				cout << endl;
				cout << " Press any key to continue .. " << endl;
				getch();
				system("cls");
				break;
			case 2:
				system("cls");
				roomDetail();
				break;
			case 3:
				system("cls");
				goto Menu;
				break;
			default:
				system("cls");
				cout << endl
					 << endl;
				cout << "            Invalid Entry!!  " << endl
					 << endl;
				cout << "                   ." << endl
					 << "                   ." << endl
					 << "                   ." << endl
					 << "                   ." << endl;
				cout << "       Press any key to continue" << endl;
				getch();
				system("cls");
				goto Room;
			}
			break;
		case 5:
			system("cls");
			cout << "Enter room number: ";
			cin >> roomNumber;
			cout << "Enter guest name : ";
			cin >> guestName;
			reserveRoom(roomNumber, guestName);
			break;
		case 6:
			system("cls");
			cout << "Enter room number: ";
			cin >> roomNumber;
			checkIn(roomNumber);
			break;
		case 7:
			system("cls");
			cout << "Enter room number: ";
			cin >> roomNumber;
			cout << "Enter amount     : ";
			cin >> amount;
			charge(roomNumber, amount);
			break;
		case 8:
			system("cls");
			cout << " Enter room number: ";
			cin >> roomNumber;
			checkOut(roomNumber);
			break;
		case 9:
			system("cls");
			displayReservationList();
			break;
		case 10:
			system("cls");
			displayCheckInList();
			break;
		case 11:
			system("cls");
			displayCheckOutList();
			break;
		case 12:
			system("cls");
			commentArea();
			break;
		case 13:
			system("cls");
			cout << " -------------------------------------------" << endl;
			cout << "                THANK YOU                   " << endl;
			cout << "        FOR USING OUR GUEST HOUSE           " << endl;
			cout << " -------------------------------------------" << endl;
			cout << "                    -" << endl
				 << "                    -" << endl
				 << "                    -" << endl
				 << "                    -" << endl;
			getch();
			break;
		default:
			system("cls");
			cout << endl
				 << endl;
			cout << "            Invalid Entry!!  " << endl
				 << endl;
			cout << "                   ." << endl
				 << "                   ." << endl
				 << "                   ." << endl
				 << "                   ." << endl;
			cout << "       Press any key to continue" << endl;
			getch();
			system("cls");
			goto Menu;
			break;
		}
	} while (choice != 13);
	do
	{
	END:
		cout << "                   BYE" << endl;
		getch();
		choice = 3;
	} while (choice != 3);
}
