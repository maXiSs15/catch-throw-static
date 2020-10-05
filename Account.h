#pragma once
#include <iostream>
using namespace std;

class Account
{
private:
	int accountNumber;
	int code;
	int balance;

	static int sumWithDraw;
	static int sumDeposit;

	void setAcc(int x) { accountNumber = x; }
	void setCode(int x) { code = x; }
	void setBalance(int x) { balance = x; }

public:
	Account(int a=0, int c=0, int b=0) : accountNumber(a), code(c), balance(b) {}
	int getAccountNumber() { return accountNumber; }
	int getCode() { return code; }
	int getBalance() { return balance; }

	friend istream& operator >>(istream& in, Account &x);
	Account withDraw(int nis);
	Account deposit(int nis);

	static int getSumWithDraw() { return sumWithDraw; }
	static int getSumDeposit() { return sumDeposit; }
};
