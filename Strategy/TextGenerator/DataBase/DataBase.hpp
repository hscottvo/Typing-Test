#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "../Language/Language.hpp"
using namespace std;



class DataBase
{

private:

	ifstream			dataBase_Text;
	vector<string>		dataBase_Vector;

public:

// ----- [ get_dataBase() ]
// -------------------------------------------------------------------------
// ----- [ it open the dataBase(Text Version) and convert it to (Vector Version) ]
// ----- [ first it makes sure that dataBase can be open, if not exit(2) ]
// ----- [ else return the vector ]
	vector<string>  get_dataBase(string address) {

		try
		{
			dataBase_Text.open(address);

			if(dataBase_Text.is_open())
			{
				string				data;

				while (!dataBase_Text.eof())
				{
					getline(dataBase_Text, data);
					dataBase_Vector.push_back(data);
				}

				dataBase_Text.close();

				return dataBase_Vector;

			} 
			else 
			{
				throw(2);
			}

		} 
		catch (int err)
		{
		
			cout << "\n[ Error: unable to open the dataBase ]\n";
			exit(err);
		}

	}
};

