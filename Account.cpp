#include "Account.h"

int Account::sumWithDraw = 0;
int Account::sumDeposit = 0;


istream & operator>>(istream & in, Account& x)
{
	int cod;
	in >> x.accountNumber >> cod;
	if (cod < 1000 && cod>9999)
		throw "ERROR: code must be of 4 digits!";
	x.code = cod;
	x.balance = 0;
	return in;
}

Account Account::withDraw(int nis)
{
	try
	{
		if ((balance -= nis) < -6000)
			throw "\n ERROR: cannot have less than - 6000 NIS!";
		if (nis > 2500)
			throw "\n ERROR: cannot withdraw more than 2500 NIS!";
		balance -= nis;
		sumWithDraw += nis;
	}
	catch (char *str)
	{
		cout << str << endl;
	}
	return *this;
}

Account Account::deposit(int nis)
{
	try
	{
		if (nis > 10000)
			throw "ERROR: cannot deposit more than 10000 NIS!";
		balance += nis;
		sumDeposit += nis;
	}
	catch (char *str)
	{
		cout << str << endl;
	}
	return *this;
}