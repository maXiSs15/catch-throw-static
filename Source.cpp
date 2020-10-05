

#include "Clock.h"
#include "Account.h"

enum action
{
	stop,
	balance,
	deposit,
	withDraw,
	sumDeposit,
	sumWithDraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	cout << endl;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number: " << endl;
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i == size)
		throw "ERROR: no such account number!";
	cout << "please enter the code: " << endl;
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	else
		throw "ERROR: wrong code!";

}
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	;
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case withDraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithDraw:
		cout << "sum of all withdraws: " << Account::getSumWithDraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	try
	{
		int i = findAccount(bank, size);
		c += 20;
		printTransaction(bank[i], balance, c);
	}
	catch (const char* e)
	{
		cout << c << "\t" << e;
	}

}
void cashDeposit(Account* bank, int size, Clock& c)
{
	try
	{
		int i = findAccount(bank, size);
		int amount;
		cout << "enter the amount of the check: " << endl;
		cin >> amount;
		bank[i].deposit(amount);
		c += 30;
		printTransaction(bank[i], deposit, c);
	}
	catch (const char* e)
	{
		cout << c << "\t" << e;
	}

}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	try
	{
		int i = findAccount(bank, size);
		int amount;
		cout << "enter the amount of money to withdraw: " << endl;
		cin >> amount;
		bank[i].withDraw(amount);
		c += 50;
		printTransaction(bank[i], withDraw, c);
	}

	catch (const char* str)
	{
		cout << c << "\t" << str;
	}
}
int main()
{
	Clock c(8);
	Account bank[10];
	cout << "enter account number and code for 10 accounts:\n";
	for (int i = 0; i < 10; i++)
	{
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}
		catch (const char* str)
		{
			cout << c << '\t' << str;
			i--;
		}
	}
	cout << endl;
	action ac = menu();
	while (ac)
	{
		switch (ac)
		{
		case balance: getBalance(bank, 10, c);
			break;
		case withDraw:cashWithdraw(bank, 10, c);
			break;
		case deposit:cashDeposit(bank, 10, c);
			break;
		case sumDeposit:c += 60;
			printTransaction(bank[0], sumDeposit, c);
			break;
		case sumWithDraw:c += 60;
			printTransaction(bank[0], sumWithDraw, c);

		}
		ac = menu();
	}
	return 0;
}
