#ifndef BRASS_H
#define BRASS_H

#include <iostream>

class BrassAccount
{
private:
    char *cust_name;
    int account_num;
    double cur_cash;
public:
     BrassAccount();
     BrassAccount(char *name,int account_num,double cur_cash);
     double recash(){return cur_cash;}
     //char* rename(){return cust_name;}
     //int reaccount(){return account_num;}
     void showbasicinfo() const;//show account information
     void savemoney(double input_cash);
     void setcash(double cash);
     virtual void getmoney(double get_money);
     virtual void showinfo() const;
     virtual ~BrassAccount();
};

class BrassPlus:public BrassAccount
{
private:
    double overdraft_MAX;
    double overdraft_rate;
    double cur_overdraft_total;
public:
     BrassPlus();
     BrassPlus(double overdraft_MAX,double overdraft_rate,double cur_overdraft_total,char *name,int account_num,double cur_cash);
     void getmoney(double get_money);
     void showinfo() const;
     ~BrassPlus();
};






#endif