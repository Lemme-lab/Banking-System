#include <iostream>
#include <fstream>
#include <string>

bool loop = true;
int interface_switch;

bool security_1 = false;
bool security_2 = false;
bool security_3 = false;

void interface() 
{
	std::cout << " \n 1. Add Record \n 2. Show Record\n 3. Search Record\n 4. Show All Records\n 5. Edit Record\n 6. Delete Record\n 7. Quit \n";
}
void Add_Record() 
{
	std::string Acc_Number;
	std::string Acc_First_Name;
	std::string Acc_Last_Name;
	std::string Acc_Balance;

	std::fstream file;
	file.open("DataBase.txt", std::ios::app);

	std::cout << "Enter Account Number: ";
	std::cin >> Acc_Number;
	std::cout << "Enter First Name: ";
	std::cin >> Acc_First_Name;
	std::cout << "Enter Last Name: ";
	std::cin >> Acc_Last_Name;
	std::cout << "Enter Balance: ";
	std::cin >> Acc_Balance;

	file << "Enter Account Number: " + Acc_Number + "\n" + "Enter First Name: " + Acc_First_Name + "\n" + "Enter Last Name: " + Acc_Last_Name + "\n" + "Enter Balance: " + Acc_Balance + "\n";
}
void Show_Record() 
{
	std::string Acc_Number;
	std::string Acc_First_Name;
	std::string Acc_Last_Name;

	std::string line;
	int limit = 0;
	int counter = 0;
	int counter_save;

	std::cout << "Enter Account Number: ";
	std::cin >> Acc_Number;
	std::cout << "Enter First Name: ";
	std::cin >> Acc_First_Name;
	std::cout << "Enter Last Name: ";
	std::cin >> Acc_Last_Name;

	std::fstream file;
	file.open("DataBase.txt", std::ios::in);

	while (getline(file, line) && limit != 1000) 
	{
		limit++; counter++;
		if ("Enter Account Number: " + Acc_Number == line) { std::cout << Acc_Number + "\n"; security_1 = true; counter_save = counter; }
		if ("Enter First Name: " + Acc_First_Name == line) { std::cout << Acc_First_Name + "\n"; security_2 = true; }
		if ("Enter Last Name: " + Acc_Last_Name == line) { std::cout << Acc_Last_Name + "\n"; security_3 = true; }

		if (security_1 == true & security_2 == true & security_3 == true && counter - 3 == counter_save)
		{
			std::cout << "Balance: " + line.substr(15,line.length());
		}
	}
}
void Search_Record()
{
	std::fstream file;
	std::string line;
	file.open("DataBase.txt", std::ios::in);
	
	int counter = 0;
	int limit = -1;
	std::string search;

	std::cout << "\nEnter an ID you want to Search: ";
	std::cin >> search;
	
	while (getline(file, line) && counter != limit) 
	{
		if (line == "Enter Account Number: " + search)
		{
			limit = counter + 4;
		}
		if (limit >= 0)
		{
			counter++;
			std::cout << line << std::endl;
		}
	}
}
void Show_All()
{
	std::fstream file;
	std::string line;
	file.open("DataBase.txt", std::ios::in);
	int counter = 0;

	while (getline(file, line))
	{
		std::cout << line + "\n";
		counter++;
		if (counter == 4)
		{
			std::cout << "  " << std::endl;
			counter = 0;
		}
	}
}
void Edit_Record()
{
	std::fstream file; file.open("DataBase.txt", std::ios::in);
	std::string line;
	std::string save = "";
	std::string input;
	std::string change;
	
	while (getline(file, line))
	{
		save = save + line + "\n";
	}

	int edit_case;
	std::cout << " 1. Edit Account Number \n 2. Edit First Name\n 3. Edit Last Name\n 4. Edit Balance \n 5. Quit to Main Menue \n";
	std::cin >> edit_case;

	if (edit_case == 1)
	{
		std::cout << "Enter Account Number you want to edit: ";
		std::cin >> input;
		std::cout << "Enter new Account Number: ";
		std::cin >> change;

		size_t found = save.find("Enter Account Number: " + input);
		if (found != std::string::npos)
		{
			save.replace(found+22, input.length(),change);
		}
		file.close();
		file.open("DataBase.txt", std::ios::out);
		file << save;
	}
	if(edit_case == 2)
	{ 
		std::cout << "Enter First Name you want to edit: ";
		std::cin >> input;
		std::cout << "Enter new First Name: ";
		std::cin >> change;

		size_t found = save.find("Enter First Name: " + input);
		if (found != std::string::npos)
		{
			save.replace(found + 18, input.length(), change);
		}
		file.close();
		file.open("DataBase.txt", std::ios::out);
		file << save;
	}
	if (edit_case == 3)
	{
		std::cout << "Enter Last Name you want to edit: ";
		std::cin >> input;
		std::cout << "Enter new Last Name: ";
		std::cin >> change;

		size_t found = save.find("Enter Last Name: " + input);
		if (found != std::string::npos)
		{
			save.replace(found + 17, input.length(), change);
		}
		file.close();
		file.open("DataBase.txt", std::ios::out);
		file << save;
	}
	if (edit_case == 4)
	{
		std::string bait;
		std::cout << "Enter ID to change Balance: ";
	    std::cin >> bait;
		std::cout << "Enter Balance on the Account: ";
		std::cin >> input;
		std::cout << "Enter new Balance: ";
		std::cin >> change;

		size_t found = save.find("Enter Balance: " + input);
		if (found != std::string::npos)
		{
			save.replace(found + 15, input.length(), change);
		}
		file.close();
		file.open("DataBase.txt", std::ios::out);
		file << save;
	}
	if(edit_case == 5){ }
}
void Delete_Record()
{
	std::fstream file;
	std::string line;
	file.open("DataBase.txt", std::ios::in);
	std::string save = "";

	while (getline(file, line))
	{
		save = save + line + "\n";
	}

	std::string Search_ID;
	std::string Search_Balance;
	int save_position_1;

	std::cout << " Enter an ID: ";
	std::cin >> Search_ID;

	std::cout << " Enter your Balance: ";
	std::cin >> Search_Balance;

	size_t found = save.find("Enter Account Number: " + Search_ID);
	if (found != std::string::npos)
	{
		save_position_1 = found;
	}
	size_t found_2 = save.find("Enter Balance: " + Search_Balance);
	if (found_2 != std::string::npos)
	{
		save.replace(save_position_1, found_2+15+Search_Balance.length(), " ");
	}
	file.close();
	file.open("DataBase.txt", std::ios::out);
	file << save;	
}
int main() {

	while (loop == true) 
	{
		interface();
	    std::cin >> interface_switch;

		switch (interface_switch) 
		{
		case 1:Add_Record(); break;
		case 2:Show_Record(); break;
		case 3:Search_Record(); break;
		case 4:Show_All(); break;
		case 5:Edit_Record(); break;
		case 6:Delete_Record(); break;
		case 7:loop = false; break;
		default: std::cout << "ERROR"; break;
		}
	}
}
