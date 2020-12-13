#pragma once
#include <string>
using namespace std;



class Language {

public:
	virtual string get_language() = 0;
};

class Language_English : public Language {

public:
	string get_language() {

		return "English";
	}
};

class Language_Spanish : public Language {

public:
	string get_language() {

		return "Spanish";
	}
};