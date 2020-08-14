#ifndef STRING_H
#define STRING_H
#include <iostream>

class strings
{
private:
  char *str;
  int len;
  static int num_char;
  static int num_strings;
  static const int CLINLIM=80;
public:
   strings();//default struct function
   strings(const char *);//transform function
   strings(const strings &);//copy struct function
   ~strings();
   int length() const {return len;}
   strings & operator=(const strings &);
   void stringlow();
   void string();
   int stringcount(char);
   //strings operator+(const strings&);
   bool operator==(const strings &);

   friend std::ostream& operator<<(std::ostream &os,const strings &);
   friend strings operator+(strings &,const strings&);
   friend std::istream& operator>>(std::istream&,strings &);
   friend strings operator+(const char *,const strings &);
};

#endif