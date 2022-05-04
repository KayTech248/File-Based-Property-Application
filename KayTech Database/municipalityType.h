#pragma once
#include "entityType.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct type
{

	string name;
	string ID;
	int hoodNo;
	string province;

};
class municipalityType : public entityType
{
public:
	municipalityType();
	~municipalityType();
	string getName(int p);
	string getProvince(int p);
	string getID(int p);
	int getNeighbourhood(int p);
	void setRecords();
	void Delete(string pk);
	void SelectAll(string pk);
	void Insert(string pk);

private:
	type * list;

};


municipalityType::municipalityType()
{
	size = 6;
	tname = "municipalityType_Table";
	list = new type[size];

	ofstream outData;

	outData.open("munData.txt");
	if (outData.is_open() == false)
		cout << "File not found";
	else
	{
		outData << "MT001" << " " << "Kinshasa" << " " << "Kinshasa" << " " << 25 << endl;
		outData << "MT002" << " " << "Lubumbashi" << " " << "Katanga" << " " << 30 << endl;
		outData << "MT003" << " " << "Manita" << " " << "Lualaba" << " " << 45 << endl;
		outData << "MT004" << " " << "Joburg" << " " << "Gauteng" << " " << 50 << endl;
		outData << "MT005" << " " << "Likasi" << " " << "Katanga" << " " << 30 << endl;
		outData << "MT006" << " " << "Kipushi" << " " << "Tanganyika" << " " << 13 << endl;
		outData.close();
	}
	
	

}
municipalityType::~municipalityType()
{
	delete [] list;
}


void municipalityType::setRecords()
{
	ifstream in;
	in.open("munData.txt");
	for (int i = 0; i < size; i++)
	{

		in >> list[i].ID;
		in >> list[i].name;
		in >> list[i].province;
		in >> list[i].hoodNo;



	}
	in.close();

}
string municipalityType::getName(int no)
{
	return list[no].name;

}
string municipalityType::getProvince(int no)
{
	return list[no].province;
}
string municipalityType::getID(int no)
{
	return list[no].ID;
}
int municipalityType::getNeighbourhood(int no)
{
	return list[no].hoodNo;
}

void municipalityType::Delete(string pk)
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

void municipalityType::SelectAll(string pk)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (pk == list[i].ID)
		{
			found = true;
			cout << list[i].ID << " ";
			cout << list[i].name << " ";
			cout << list[i].province << " ";
			cout << list[i].hoodNo << " ";
			cout << endl;

		}

	}
	if (found == false)
		cout << "No results" << endl;

	cout << endl;
}

void municipalityType::Insert(string pk)
{
	ofstream addData;
	string n;
	int no;
	string p;
	cout << "Enter new municipalityType name(eg Kinshasa): ";
	cin >> n;
	cout << "Enter The number of Neighbourhoods: ";
	cin >> no;
	cout << "Enter The province: ";
	cin >> p;
	addData.open("NewmunicipalityType.txt", ios::app);													

	addData << p << " " << n << " " << no << endl;
	addData.close();
}