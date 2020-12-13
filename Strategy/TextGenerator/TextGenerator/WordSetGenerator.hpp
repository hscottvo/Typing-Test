#pragma once
#include "TextGenerator.hpp"
#include <cstdlib>
using namespace std;


class WordSetGenerator : public TextGenerator {

public:

// ----- [ WordSetGenerator constructor ]
// -------------------------------------------------------------------------
// ----- [ convert DataBase ( text version ) to DataBase( vector Version ) ]
// ----- [ we use Data Base Vector Version from now ]
	WordSetGenerator(Language* L) {
		_dataBase_Vector = _dataBase_Text.get_dataBase( "Strategy/TextGenerator/DataBase/TextGenerator_WordSet_" +  L->get_language() + ".txt" );
	}

// ----- [ generate() ]
// -------------------------------------------------------------------------
// ----- [ only use dataBase Vector version ]
// ----- [ 1st, take the index from user. 2nd, take that index from dataBase ]
// ----- [ 3rd, parse that index into the word, 4th return all the word as a vector ]
	vector<string> generate() {
		int wordCount = 30;
		try
		{
			if(wordCount <= 0) {throw 1;}

			vector<string> sub_vector;

			for( int i =0; i < wordCount; i++)
			{
				string data = _dataBase_Vector[rand() % this->size()];
				stringstream dataBase_stream(data);
				sub_vector.push_back(data);
			}

			return sub_vector;
		}
		catch(int err)
		{
			cout << "\n[ the index is out of range ]\n";
            		exit(err);
		}
	}
	vector<string> generate(int wordCount) {
		try
		{
			if(wordCount <= 0) {throw 1;}

			vector<string> sub_vector;

			for( int i =0; i < wordCount; i++)
			{
				string data = _dataBase_Vector[rand() % this->size()];
				stringstream dataBase_stream(data);
				sub_vector.push_back(data);
			}

			return sub_vector;
		}
		catch(int err)
		{
			cout << "\n[ the index is out of range ]\n";
            		exit(err);
		}
	}
};
