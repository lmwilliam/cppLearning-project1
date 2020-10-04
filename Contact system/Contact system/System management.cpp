#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

struct Person
{
	string m_Name;
	int m_Gender;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks
{
	// Use a array to save the contacts.
	struct Person personArray[MAX];
	// The number of current contacts.
	int m_Size;
};

void addPerson(Addressbooks* abs)
{
	// Determine whether the contact list is full.
	if (abs->m_Size == MAX)
	{
		cout << "The contact list is full." << endl;
		return;
	}
	else
	{
		// Add a person to contact list
		// Name
		string name;
		cout << "Please input a name: " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		// Gender
		int gender = 0;
		cout << "Please enter the gender: " << endl;
		cout << "1 for Male " << endl;
		cout << "2 for Female " << endl;
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->personArray[abs->m_Size].m_Gender = gender;
				break;
			}
			cout << "The system is only accept number 1 or 2, please enter again." << endl;
		}

		// Age
		cout << "Please enter the ages:" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 130)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "The system is only accept number 1 - 129, please enter again." << endl;
		}

		// Phone number
		cout << "Please enter the phone number: " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		// Address
		cout << "Please enter the address: " << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		// Renew contact list
		abs->m_Size++;

		cout << "Successful!" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs)
{
	// Determine whether the contact list is empty.
	if (abs->m_Size == 0)
	{
		cout << "The contact list is empty, please add a contact!" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "Name: " << abs->personArray[i].m_Name << "\t";
			cout << "Gender: " << (abs->personArray[i].m_Gender == 1 ? "Male" : "Female") << "\t";
			cout << "Ages: " << abs->personArray[i].m_Age << "\t";
			cout << "Phone number: " << abs->personArray[i].m_Phone << "\t";
			cout << "Address: " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

// Search contacts to comfirm is exist or not.
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0;i < abs->m_Size;i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs)
{
	cout << "Please input the one you want to delete:" << endl;
	string name;
	cin >> name;
	//If ret == -1 ¡ú Not found
	//If ret != -1 ¡ú Found
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//Renew contact list.
		abs->m_Size--;
		cout << "Deleted." << endl;
	}
	else
	{
		cout << "The Person Is Not Found." << endl;
	}
}

void findPerson(Addressbooks* abs)
{
	cout << "Please input the person you are searching for:" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "Name:" << abs->personArray[ret].m_Name << "\t";
		cout << "Gender:" << abs->personArray[ret].m_Gender << "\t";
		cout << "Ages:" << abs->personArray[ret].m_Age << "\t";
		cout << "Phone number:" << abs->personArray[ret].m_Phone << "\t";
		cout << "Addresss:" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "The person is not found." << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)
{
	cout << "Please input the one you want to modify." << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		// Name
		string name;
		cout << "Please input a name: " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		// Gender
		int gender = 0;
		cout << "Please enter the gender: " << endl;
		cout << "1 for Male " << endl;
		cout << "2 for Female " << endl;
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->personArray[ret].m_Gender = gender;
				break;
			}
			cout << "The system is only accept number 1 or 2, please enter again." << endl;
		}

		// Age
		cout << "Please enter the ages:" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 130)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "The system is only accept number 1 - 129, please enter again." << endl;
		}

		// Phone number
		cout << "Please enter the phone number: " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		// Address
		cout << "Please enter the address: " << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		cout << "Successful!" << endl;
	}
	else
	{
		cout << "The Person Is Not Found." << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "Contact list is empty now." << endl;
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "*******************************" << endl;
	cout << "**** 1. Add a contact      ****" << endl;
	cout << "**** 2. Show contact list  ****" << endl;
	cout << "**** 3. Delete the contact ****" << endl;
	cout << "**** 4. Search contacts    ****" << endl;
	cout << "**** 5. Modify contacts    ****" << endl;
	cout << "**** 6. Clean all contacts ****" << endl;
	cout << "**** 0. Exit               ****" << endl;
	cout << "*******************************" << endl;
}

int main()
{
	// Create a contact sturcture variable
	Addressbooks abs;

	// Initialize the number of people in the current address book.
	abs.m_Size = 0;

	int select = 0;

	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs); // Use address to modified actual parameters.
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
		{
			/*
			cout << "Please enter a name:" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "The Person Is Not Found." << endl;
			}
			else
			{
				cout << "Found" << endl;
			}
			*/
		}
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
;			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "Welcome to use our contact system next time." << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}