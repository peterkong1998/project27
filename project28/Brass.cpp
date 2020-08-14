#include "Brass.h"

BrassAccount::BrassAccount()
{
    cust_name=new char[1];
    cust_name[0]='\0';
    account_num=0;
    cur_cash=0;
}

BrassAccount::BrassAccount(char *name,int account_num,double cur_cash)
{
    cust_name=new char[std::strlen(name)+1];
    strcpy(cust_name,name);
    this->account_num=account_num;
    this->cur_cash=cur_cash;
}

void BrassAccount::savemoney(double input_money)
{
  cur_cash+=input_money;
  std::cout<<"you have input "<<input_money<<" money!\n";
}

void BrassAccount::getmoney(double get_money)
{
  cur_cash-=get_money;
  std::cout<<"you have get "<<get_money<<" money!\n";
}

void BrassAccount::showinfo() const
{
    std::cout<<"customer name:"<<cust_name<<std::endl;
    std::cout<<"customer account number:"<<account_num<<std::endl;
    std::cout<<"customer current cash:"<<cur_cash<<std::endl;
}
#if(0)
void BrassAccount::showinfo() const
{
    std::cout<<"customer name:"<<cust_name<<std::endl;
    std::cout<<"customer account number:"<<account_num<<std::endl;
    std::cout<<"customer current cash:"<<cur_cash<<std::endl;
}
#endif

BrassPlus::BrassPlus()
{
    overdraft_MAX=0;
    overdraft_rate=0;
    cur_overdraft_total=0;
}

BrassPlus::BrassPlus(double overdraft_MAX,double overdraft_rate,double cur_overdraft_total,
               char *name,int account_num,double cur_cash):BrassAccount(name,account_num,cur_cash)
               {
                   this->overdraft_MAX=overdraft_MAX;
                   this->overdraft_rate=overdraft_rate;
                   this->cur_overdraft_total=cur_overdraft_total;
               }

void BrassAccount::setcash(double cash)
{
    cur_cash=cash;
}

void BrassPlus::getmoney(double get_money)
{
   double cur_cash=recash();
   if(get_money<cur_cash)
   {
       cur_cash-=get_money;
       setcash(cur_cash);
       std::cout<<"get money successful!\n";
   }
   else if (get_money<cur_cash+10000)
   {
        cur_overdraft_total=(get_money-cur_cash)*(1+overdraft_rate);
        cur_cash-=get_money;
        setcash(cur_cash);
        std::cout<<"get money successful!\n";
   }
   else
   {
       std::cout<<"you can not overdraft money more than 10000!\n";
   }
}

void BrassPlus::showinfo() const
{
    //showbasicinfo();
    BrassAccount::showinfo();
    std::cout<<"current the rate of overdraft is:"<<overdraft_rate<<std::endl;
    std::cout<<"now you have overdrafted "<<cur_overdraft_total<<" money!\n";
}

BrassAccount::~BrassAccount()
{
    delete []cust_name;
}

BrassPlus::~BrassPlus()
{}




