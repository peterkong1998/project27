#include <iostream>
#include "string.h"
#include <cstdlib>
#include <ctime>
#include <cctype>

 const int ArSize=10;
 const int MaxLen=81;

int main()
{
  using std::cout;
  using std::cin;
  using std::endl;
  
#if(0)
  strings str("i");
  strings str1("love");
  strings str3;
      
  str3=str+str1;

  cout<<str3<<endl;

  cout<<"change to big write:\n";
  str1.string();
  cout<<"change to small write:\n";
  str1.stringlow();
  cout<<"show the char o numbers in string str:\n";
  char a='o';
  str1.stringcount(a);
#endif

strings s1("and I am a C++ student.");
strings s2="Please enteryour name:";
strings s3;
cout<<s2;
cin>>s3;
s2="My name is "+s3;
cout<<s2<<".\n";
s2=s2+s1;
s2.string();
cout<<"the string\n"<<s2<<"\ncontains"<<s2.stringcount('A')
    <<" 'A' characters in it.\n";
s1="red";

strings rgb[3]={strings(s1),strings("green"),strings("blue")};
cout<<"Enter the name of a primary color for mixing light:";
strings ans;
bool success=false;

while(cin >> ans)
{
  ans.stringlow();
  for(int i=0;i<3;i++)
  {
    if(ans==rgb[i])
    {
      cout<<"that is right!\n";
      success=true;
      break;
    }
  }
  if(success)
  break;
}

 cout<<"Bye,fxxk you bitch!\n";

  return 0;
}