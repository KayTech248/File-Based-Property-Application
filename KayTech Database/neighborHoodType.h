#pragma once
#include "entityType.h"

#include <iostream>
#include <fstream>
#include <string>
#include "municipalityType.h"


using namespace std;



struct ntype
{
	string ID;
	string name;
	int streetNo;
	string munID;
};
class neighborHoodType : public entityType
{
public:
	neighborHoodType();
	~neighborHoodType();
	void setRecords();
	string getName(int p);
	string getID(int p);
	int getStreetNo(int p);
	string getmunID(int p);
	void SelectAll(string pk);
	void Insert(string pk);
	void Delete(string pk);
private:
	municipalityType object;
	ntype* list;


};

neighborHoodType::neighborHoodType()
{
	size = 8;
	list = new ntype[size];
	tname = "neighborHoodType_Table";
	object.setRecords();


	ofstream outData;

	outData.open("HoodData.txt");
	if (outData.is_open() == false)
		cout << "file not found" << endl;
	else
	{
		outData << "NH001" << " " << "Ndola" << " " << object.getID(0) << " " << 30 << endl;
		outData << "NH002" << " " << "Kitwe" << " " << object.getID(0) << " " << 35 << endl;
		outData << "NH003" << " " << "Lusaka" << " " << object.getID(0) << " " << 34 << endl;
		outData << "NH004" << " " << "Malvern" << " " << object.getID(1) << " " << 40 << endl;
		outData << "NH005" << " " << "Kempton_Park" << " " << object.getID(1) << " " << 42 << endl;
		outData << "NH006" << " " << "Mongu" << " " << object.getID(3) << " " << 51 << endl;
		outData << "NH007" << " " << "Solwezi" << " " << object.getID(4) << " " << 49 << endl;
		outData << "NH008" << " " << "luanshya" << " " << object.getID(4) << " " << 44 << endl;


	}

}


void neighborHoodType::setRecords()
{
	ifstream inData;
	inData.open("HoodData.txt");
	for (int i = 0; i < size; i++)
	{

		inData >> list[i].ID;
		inData >> list[i].name;
		inData >> list[i].munID;
		inData >> list[i].streetNo;


	}
	inData.close();
}

string neighborHoodType::getName(int no)
{
	return list[no].name;

}
string neighborHoodType::getmunID(int no)
{
	return list[no].munID;
}
string neighborHoodType::getID(int no)
{
	return list[no].ID;
}
int neighborHoodType::getStreetNo(int no)
{
	return list[no].streetNo;
}

neighborHoodType::~neighborHoodType()
{
	delete[] list;
}

void neighborHoodType::SelectAll(string pk)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (pk == list[i].ID)
		{
			found = true;
			cout << list[i].ID << " ";
			cout << list[i].name << " ";
			cout << list[i].munID << " ";
			cout << list[i].streetNo << " ";
			cout << endl;
		}

	}
	if (found == false)
		cout << "No results" << endl;

}


void neighborHoodType::Insert(string pk)
{
	ofstream addData;
	string n;
	int no;
	string p;
	cout << "Enter new Hood name(eg Ndola): ";
	cin >> n;
	cout << "Enter The number of streets: ";
	cin >> no;
	cout << "Enter The municipilaity id: ";
	cin >> p;
	addData.open("NewHood.txt", ios::app);													

	addData << pk << " " << n << " " << no << " " << p << endl;
	addData.close();
}

void neighborHoodType::Delete(string pk)
{
	bool found = false;
	for (int i = 0; i < size; i++)
		if (pk == list[i].ID)
		{
			found = true;
			if (i < size)
			{
				size = size - 1;
				for (int j = i; j < size; j++)
				{
					list[j] = list[j + 1];

				}

			}
		}

	if (found == false)
		cout << "No results" << endl;
}