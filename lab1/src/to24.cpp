#include "to24.h"
#include <cctype>
#include <string>


std::string to24(const std::string &input) {
  int hour = 0, minute = 0;
  char colon, m1, m2;

  if (sscanf(input.c_str(), "%d%c%d %c%c", &hour, &colon, &minute, &ap, &mm) != 5) { return ""; }

  if (colon != ':' || minute < 0 || minute > 59 || hour < 1 || hour > 12) { return ""; }

  ap = std::tolower(ap);
  mm = std::tolower(mm);

  bool is_pm;
  if (ap == 'a' && mm == 'm') {
  is_pm = false;
  } else if (ap == 'p' && mm == 'm') {
  is_pm = true;
  } else {
  return "";
  }


  if (is_pm && hour != 12) { hour += 12; } 
  if (!is_pm && hour == 12) { hour = 0; }


  char buffer[5];
  snprintf(buffer, sizeof(buffer), "%02d%02d", hour, minute);
  return std::string(buffer);
}
