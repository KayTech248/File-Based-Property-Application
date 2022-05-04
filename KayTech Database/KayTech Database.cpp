// KETSYA_DIOKA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "municipalityType.h"
//#include "neighborHoodType.h"
//#include "streetType.h"
//#include "clientType.h"
//#include "entityType.h"
#include <fstream>
#include <string>
#include "houseType.h"

using namespace std;

void displayMenu();
int _tmain(int argc, _TCHAR* argv[])
{
	system("color 02");
	string key;
	char choice = ' ';
	houseType Houses;
	Houses.setRecords();
	cout << "HouseID" << "	 " << "Address" << "	 " << "StreetID" << "	 " << "OwnerID" << endl;
	cout << endl;
	Houses.print();
	cout << endl;
	cout << endl;
	displayMenu();
	while (choice != 'x' && choice != 'X')
	{
		cout << "Please enter a choice: ";
		cin >> choice;

		switch (choice)
		{
		case '0':
		{
			cout << "HOUSE_ID	ADDRESS	STREET_ID	OWNER_ID" << endl;
			Houses.print();
			cout << endl;
			cout << endl;
		}
		break;
		case '1':
		{
			cout << "OWNER_ID	NAME	NO_PROPERTY" << endl;
			Houses.displayClients();
			cout << endl;
		}
		break;
		case '2':
		{
			cout << "Enter the ID of the client(eg CL004): ";
			cin >> key;
			Houses.locateClient(key);
			cout << endl;
		}
		break;
		case '3':
		{
			cout << "Enter ID of the House to change ownership: ";
			cin >> key;
			Houses.changeClient(key);
			Houses.print();
			cout << "--Query results added to the *ClientData*, *NewClientInfo* and *NewHouseInfo* file--" << endl;
			cout << endl;
			cout << endl;
		}
		break;
		case '4':
		{
			cout << "Enter ID of the House to delete: ";
			cin >> key;
			Houses.Delete(key);
			Houses.print();
			cout << endl;
			cout << endl;
		}
		break;
		case '5':
		{
			cout << "Enter the ID of the house to add: ";
			cin >> key;
			Houses.Insert(key);
			Houses.print();
			cout << "--Entries appended to the *clientData*, *HouseData*, and *newclientinfo*--" << endl;
			cout << endl;
			cout << endl;
		}
		break;
		case '6':
		{
			cout << "Enter the ID of the client to add: ";
			cin >> key;
			Houses.addClient(key);
			Houses.displayClients();
			cout << "--Entries appended to the *clientData* and *newclientinfo*--" << endl;
			cout << endl;
			cout << endl;
		}
		break;
		case '7':
		{
			cout << "Enter the ID of the client: ";
			cin >> key;
			Houses.displayProperty(key);
			cout << endl;
		}
		break;
		case 'm':
		case 'M':
		{
			displayMenu();
		}
		break;
		case 'x':
		case 'X':
		{
			choice = 'x';
		}
		break;
		default:
			cout << "Invalid option" << endl;
			break;
		}

		//if(choice != 'x' || choice != 'X')
		//{
		//	cout << "Please enter a choice: ";
		//	cin >> choice;
		//}
	}

	system("pause");
	return 0;
}

void displayMenu()
{
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "		***Menu***				 " << endl;
	cout << endl;
	cout << "0	 view House Table " << endl;
	cout << "1	 view the owners table" << endl;
	cout << "2	 view record of a client" << endl;
	cout << "3	 change ownership" << endl;
	cout << "4	 delete a house record" << endl;
	cout << "5	 add a house record" << endl;
	cout << "6	 add a client record" << endl;
	cout << "7	 view owners property" << endl;
	cout << "M	 view Menu" << endl;
	cout << "X	 To Quit" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
}