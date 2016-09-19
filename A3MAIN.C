#include "A3_University.h"//Only need to include University header file.
using namespace std;

int main()
{
  string fileName;
  University csusm;//Make an object of type University.
  fileName = "A3TRANSACTIONTEST.txt";//Hardcoded transaction file.
  csusm.ProcessTransactionFile(fileName);//Call this function and have a blast.

}

