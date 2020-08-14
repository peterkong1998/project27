#include "string.h"
#include <cstring>

using std::cin;
using std::cout;

int strings::num_strings=0;
int strings::num_char=0;

strings::strings()
{
    num_char=0;
    len=4;
    str=new char[1];
    str[0]='\0';
    num_strings++;
}

strings::strings(const char*a)
{
    len=strlen(a);
    str=new char[len+1];
    strcpy(str,a);
    num_strings++;
}

strings::strings(const strings &st)
{
  num_strings++;
  len=strlen(st.str);
  str=new char[len+1];
  strcpy(str,st.str);
}

strings::~strings()
{
    num_strings--;
    delete []str;
}

strings& strings::operator=(const strings &a)
{
    if(this==&a)
    return *this;
    delete []str;
    len=strlen(a.str);
    str=new char[len+1];
    strcpy(str,a.str);
    return *this;
}

strings operator+(strings &str1,const strings &str2)
{   
    //const int len=str1.len+1;
    //char temp[20];
    //strcpy(temp,str1.str);
    //strcat(temp,str2.str);
    //return strings(temp);
    //return *this;
    strings s;
    s.len=str1.len+str2.len;
    s.str=new char[s.len+1];
    strcpy(s.str,str1.str);
    strcat(s.str,str2.str);
    return s;
}

#if(1)
strings operator+(const char *a,const strings &str2)
{
    strings s;
    s.len=strlen(a)+str2.len;
    s.str=new char[s.len+1];
    strcpy(s.str,a);
    strcat(s.str,str2.str);
    return s;
}
#endif

#if(0)
strings operator+(char a[20],const strings &str1)
{
    //a=new char[20];
    strings str2;
    str2.str=std::strcat(a,str1.str);
    //cout<<str2;
    //int len=strlen(a)+1;
    //int len1=strlen(str1.str)+1;
    //a=new char[30];
    //int i=0;
    //for(i=0;i<len1;i++)
    //*(a+len+i)=str1.str[i];
    //*(a+len+i)='\0';

    //int len2=strlen(a)+1;
    //for(i=0;i<len2;i++) 
    //str2.str[i]=*(a+i);
    //delete a;
    return str2;
}
#endif

std::istream& operator>>(std::istream &is,strings &st)
{
    char temp[strings::CLINLIM];
    is.get(temp,strings::CLINLIM);
    if(is)
       st=temp;
    while(is && is.get() !='\n')
       continue;
    return is;      
}

std::ostream& operator<<(std::ostream& os,const strings &st)
{
    os<<st.str;
    return os;
}

void strings::stringlow()
{
  int len=strlen(str)+1;
  //strings a;  
  for(int i=0;i<len;i++)
  str[i]=tolower(str[i]);
  cout<<str<<std::endl;
}

void strings::string()
{
  int len=strlen(str)+1;
  //strings a;  
  for(int i=0;i<len;i++)
  str[i]=toupper(str[i]);
  cout<<str<<std::endl;
}

int strings::stringcount(char a)
{
    int len=strlen(str)+1;
    //strings a;  
    for(int i=0;i<len;i++)
    {
        if(str[i]==a)
        num_char++;
    }
    return num_char;
}

bool strings::operator==(const strings &str1)
{

    return (strcmp(str,str1.str)==0);
}