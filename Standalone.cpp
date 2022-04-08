#include "Standalone.h"

void checkFile()
{
  try
  {
    time_t now = time(0);
    char *date_time = ctime(&now);

    std::string name = "Stack " + std::string(date_time) + ".txt";

    ifstream file_to_check(name);
    if (file_to_check.is_open() != true)
    {
      throw string("ER01");
    }

    file_to_check.close();
  }
  catch (string error)
  {
    if (error == "ER01")
    {
      cout << "Score file not created " << error << endl;
    }
    else
    {
      cout << "File could not open " << error << endl;
    }
  }
}