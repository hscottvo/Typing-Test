#pragma once
#include "TextGenerator.hpp"
using namespace std;


class QuoteGenerator : public TextGenerator {

public:

// ----- [ QuoteGenerator constructor ]
// -------------------------------------------------------------------------
// ----- [ convert DataBase ( text version ) to DataBase( vector Version ) ]
// ----- [ we use Data Base Vector Version from now ]
	QuoteGenerator(Language* L) {
		_dataBase_Vector = _dataBase_Text.get_dataBase( "Strategy/TextGenerator/DataBase/TextGenerator_Quote_" +  L->get_language() + ".txt" );
	}

// ----- [ generate() ]
// -------------------------------------------------------------------------
// ----- [ only use dataBase Vector version ]
// ----- [ 1st, take the index from user. 2nd, take that index from dataBase ]
// ----- [ 3rd, parse that index into the word, 4th return all the word as a vector ]
	vector<string> generate() {
                int index = rand() % _dataBase_Vector.size();
		 try
                {
                        if( index >= _dataBase_Vector.size() ) { throw 1;}

                        vector<string> sub_vector;

                        string data = _dataBase_Vector[index];
                        stringstream dataBase_stream(data);

                        while (getline(dataBase_stream, data, ' '))
                        {
                                sub_vector.push_back(data);
                        }

                        return sub_vector;
                }
                catch(int err){

			cout << "\n[ the index is out of range ]\n";
                        exit(err);
                }

	}

        vector<string> generate(int index) {
		 try
                {
                        if( index >= _dataBase_Vector.size() ) { throw 1;}

                        vector<string> sub_vector;

                        string data = _dataBase_Vector[index];
                        stringstream dataBase_stream(data);

                        while (getline(dataBase_stream, data, ' '))
                        {
                                sub_vector.push_back(data);
                        }

                        return sub_vector;
                }
                catch(int err){

			cout << "\n[ the index is out of range ]\n";
                        exit(err);
                }

	}
};

