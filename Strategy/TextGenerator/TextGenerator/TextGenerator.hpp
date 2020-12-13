#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "../DataBase/DataBase.hpp"
using namespace std;

class TextGenerator {

protected:

	DataBase			_dataBase_Text;
	vector<string>		_dataBase_Vector;
	vector<string>		_vector;


public:

	virtual vector<string>	generate() = 0;
	virtual vector<string> generate(int) = 0;

public:	
	int 	size(){ return _dataBase_Vector.size(); }
};
