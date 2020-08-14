#include "Brass.h"




int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    double input_money;
    double get_money;
    BrassAccount *brass=new BrassPlus(5000,0.36,0,"peter",01,0);
    cout<<"now show the basic infomation:\n";
    brass->showinfo();
    cout<<"now you can input your money:";
    cin>>input_money;
    brass->savemoney(input_money);
    cout<<"now you can get your money:";
    cin>>get_money;
    brass->getmoney(get_money);

    cout<<"now show the current infomation:\n";
    brass->showinfo();
    delete brass;
    brass=NULL;
    return 0;
}