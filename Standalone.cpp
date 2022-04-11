#include "Standalone.h"

void checkFile()
{
  try
  {
    time_t now = time(0);
    char *date_time = ctime(&now);

    // If a file in the current minute has been created
    std::string present_name = "Stack " + std::string(date_time) + ".txt";
    // If a file in the minute prior has been created
    std::string past_name = "Stack " + std::string(date_time - 1) + ".txt";

    // Open the current minute file
    ifstream file_to_check_present(present_name);
    // Try to open the past minute file
    ifstream file_to_check_past(past_name);

    // Check if either file exists
    if (file_to_check_present.is_open() != true || file_to_check_past.is_open() != true)
    {
      throw string("ER01");
    }

    // Close files
    file_to_check_present.close();
    file_to_check_past.close();
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