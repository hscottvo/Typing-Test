#include "TextGenerator.hpp"
#include <cstdlib>

int main()
{
   vector<string> my_Vector;

   TextGenerator* sample = new WordSetGenerator( new Language_English() );

// ----- [ if you know the index ]
//   my_Vector = sample->generate(10);

// ----- [ if you want to generate random]

   for (int i =0; i < 20; i++){

      int index = rand() % sample->size();

      cout << "\n\nthe index is: " << index << endl;
      my_Vector = sample->generate(index);

      for (int j =0; j < my_Vector.size(); j++){ cout << "\'" << my_Vector[j] << "\' "; }
   }
   


    return 0;
}