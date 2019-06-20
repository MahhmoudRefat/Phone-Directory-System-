
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct node {
	string f_name;
	string l_name;
	string number;
	string job;
	string email;
	node *next;
};
node * head = NULL;
node * current = NULL;
node *tail = NULL;

void add(string f_name, string l_name, string number, string job, string email);
void printinf();
void getdata();
void readfile();
void display();
void sort();
void update();
void deletee();
void search();
void quit();
void interface();

int main()
{
	system("Color A");
	cout << "\t\t\t\t\t ************************** \t\t\t\n";
	cout << "\t\t\t\t\t *                        * \t\t\t\n";
	cout << "\t\t\t\t\t * Phone Directory System * \t\t\t\n";
	cout << "\t\t\t\t\t *                        * \t\t\t\n";
	cout << "\t\t\t\t\t * welcome to our project * \t\t\t\n";
	cout << "\t\t\t\t\t *                        * \t\t\t\n";
	cout << "\t\t\t\t\t ************************** \t\t\t\n";
	cout << "\n\n";
	cout << "======================================================================================================================\n";
	readfile();
	interface();

    return 0;
}

void add(string f_name, string l_name, string number, string job, string email) {//add contacts in the linkedlist
	if (head == NULL)
	{
		current = new node;
		current->f_name = f_name;
		current->l_name = l_name;
		current->number = number;
		current->job = job;
		current->email = email;
		current->next = NULL;
		head = current;
		tail = current;
	}
	else
	{
		current = new node;
		current->f_name = f_name;
		current->l_name = l_name;
		current->number = number;
		current->job = job;
		current->email = email;
		tail->next = current;
		tail = tail->next;
		current->next = NULL;
	}
}
void getdata() { //get the data from the user
	string f_name;
	string l_name;
	string number;
	string job;
	string email;

	cout << "Enter The First Name \n";
	cin >> f_name;
	cout << "Enter The Last Name \n";
	cin >> l_name;
	cout << "enter phone number \n";
	cin >> number;
	cout << "Enter The job \n";
	cin >> job;
	cout << "Enter The Email \n";
	cin >> email;
	for (int i = email.find('@'), ii = email.find('.'); i < 0 || ii<0; i = email.find('@'), ii = email.find('.'))
	{
		cout << "\n";
		setw(20);
		cout << "email should be like that name@domain.com\n" << endl;
		setw(20); cout << "enter the email : ";
		cin >> email;
	}
	add(f_name, l_name, number, job, email);
}
void printinf() { //print in file

	ofstream of("contacts.txt");

	if (head != NULL)
	{
		current = head;
		while (current != NULL)
		{
			of << current->f_name << setw(20);
			of << current->l_name << setw(15);
			of << current->number << setw(20);
			of << current->job << setw(30);
			of << current->email;
			of << endl;
			current = current->next;
		}
		of.close();
	}
	else {
		of << "No Contacts \n";
	}
}
void readfile() {
	string f_name;
	string l_name;
	string number;
	string job;
	string email;

	ifstream file;
	file.open("contacts.txt");

	while (file >> f_name)
	{
		//file >> f_name;
		file >> l_name;
		file >> number;
		file >> job;
		file >> email;
		add(f_name, l_name, number, job, email);
	}
	file.close();
}
void display()
{
	int count = 1;
	int num;
	string s_number;
	cout << endl;
	cout << "1) Enter 1 To print All contacts           2) Enter 2 To print specific query contacts by phone number \n\n";
	cout << "write Your choice Here : ";cin >> num;
	switch (num)
	{
	case 1:
		cout << endl;
		cout << "---------------------------- Your Contacts ------------------------------\n";
		cout << endl;
		cout << "   ---------" << setw(15) << "--------" << setw(20) << "-----------" << setw(17) << "-------------" << setw(10) << "----" << setw(20) << "-----";cout << endl;
		cout << "   FirstName" << setw(15) << "LastName" << setw(20) << "phoneNumber" << setw(17) << "The Number is" << setw(10) << "job" << setw(20) << "email";cout << endl;
		cout << "   ---------" << setw(15) << "--------" << setw(20) << "-----------" << setw(17) << "-------------" << setw(10) << "----" << setw(20) << "-----";
		cout << endl;
		if (head != NULL)
		{
			current = head;
			while (current != NULL)
			{
				cout << count << "- ";
				cout << current->f_name << setw(24-(current->f_name).length());
				cout << current->l_name << setw(20);
				cout << current->number << setw(17);
				cout << current->number.size() << setw(15);
				cout << current->job << setw(30);
				cout << current->email << endl;
				count++;
				current = current->next;
			}
		}
		else { cout << "No Data Found" << endl; }
		cout << "----------------------------      End      ------------------------------\n";
		break;
	case 2:
		cout << "Enter The Number U want to search here : ";
		cin >> s_number;
		if (head != NULL)
		{
			current = head;
			while (current != NULL)
			{
				if (current->number == s_number)
				{
					cout << endl;
					cout << "The contacts Data Is :  ";
					cout << current->f_name << "  ";
					cout << current->l_name << "  ";
					cout << current->number << "  ";
					cout << current->job << "  ";
					cout << current->email;
					break;
				}
				else { current = current->next; }
			}
		}
		else { cout << "No Contacts" << endl; }
	default:
		break;
	}

}
void sort() {
	string temp;
	if (head != NULL)//to sort The first Name
	{
		current = head;
		node *current2 = head;
		cout << endl;
		cout << "----------------\n";
		cout << "| Sort Finshed |\n";
		cout << "----------------\n";

		while (current2->next != NULL)
		{
			current = head;
			while (current->next != NULL)
			{
				if (current->f_name > ((current->next)->f_name))
				{
					temp = (current->f_name);
					(current->f_name) = (current->next)->f_name;
					(current->next)->f_name = temp;
				}
				else
				{current = current->next;}
			}
			current2 = current2->next;
		}
	}
	else { cout << "No contacts \n"; }
}
void update() {//edit any node
	int count = 1;
	if (head != NULL)//to print the Name to edit
	{
		current = head;
		cout << "---------------------\n";
		cout << "Your contacts Name is\n";
		cout << "---------------------\n";
		while (current != NULL)
		{
			cout << count << " - " << current->f_name << " ";
			cout << current->l_name;
			cout << endl;
			count++;
			current = current->next;
		}
	}
	else { cout << "No Data Found" << endl; }
	string name;
	string lname;

	int x;
	cout << endl;
	cout << "Enter The First name To Get The name \n";
	cout << "Enter Here : ";cin >> name;
	cout << endl;
	cout << "Enter The Last name To Get The name \n";
	cout << "Enter Here : ";cin >> lname;
	if (head != NULL)
	{
		current = head;
		while (current != NULL)
		{
			if (current->f_name == name && current->l_name == lname)
			{
				cout << "1) Enter 1 to Edit first name  \n";
				cout << "2) Enter 2 to Edit last name \n";
				cout << "3) Enter 3 to Edit the phone \n";
				cout << "4) Enter 3 to Edit the job \n";
				cout << "5) Enter 3 to Edit the Email \n";
				cout << "Enter Your choice here : "; cin >> x;
				switch (x)
				{
				case 1:
					cout << "Enter Your Edit Here : ";
					cin >> current->f_name;
					break;
				case 2:
					cout << "Enter Your Edit Here : ";
					cin >> current->l_name;
					break;
				case 3:
					cout << "Enter Your Edit Here : ";
					cin >> current->number;
					break;
				case 4:
					cout << "Enter Your Edit Here : ";
					cin >> current->job;
					break;
				case 5:
					cout << "Enter Your Edit Here : ";
					cin >> current->email;
					break;

				default:
					cout << "Enter a valid number \n";
					break;
				}
				break;
			}
			else { current = current->next;; }

		}
	}
	else { cout << "No Contacts" << endl; }

}
void deletee() {
	int count = 1;
	if (head != NULL)//to print All contacts Name to delete Your special one
	{
		current = head;
		cout << "---------------------\n";
		cout << "Your contacts Name is\n";
		cout << "---------------------\n";
		while (current != NULL)
		{
			cout << count << " - " << current->f_name << " ";
			cout << current->l_name;
			cout << endl;
			count++;
			current = current->next;
		}
	}
	else { cout << "No Data Found" << endl; }
	//The delete code
	string name;
	string lname;
	int x;
	cout << endl;
	cout << "Enter The First name To Get The name \n";
	cout << "Enter Here : ";cin >> name;
	cout << endl;
	cout << "Enter The Last name To Get The name \n";
	cout << "Enter Here : ";cin >> lname;
	cout << endl;
	if (head != NULL)
	{//if the data is the first node
		current = head;
		if (current->f_name == name)
		{
			head = head->next;
			delete current;
		}
		else
		{//if the data not in the first node
			while (current->next != NULL)
			{
				if ((current->next)->f_name == name) {
					(current->next) = (current->next)->next;
					break;
				}
				else { current = current->next; }

			}
		}
	}
	else { cout << "No Contacts" << endl; }
}
void search() {
	string s_job;
	string s_email;
	string s_number;
	int x;
	cout << "Enter The way That You want to search by \n";

	cout << "1) Enter 1 to search by Job \n";
	cout << "2) Enter 2 to search by email \n";
	cout << "3) Enter 3 to search by Number \n";

	cout << "Enter Your choice here : "; cin >> x;
	switch (x)
	{
	case 1: //case 1 search by job

		cout << "Enter The job U want to search here : ";
		cin >> s_job;
		if (head != NULL)
		{
			current = head;
			while (current != NULL)
			{
				if (current->job == s_job)
				{
					cout << "The job is found \n\n";
					break;
				}
				else { current = current->next;; }
			}
			if(current == NULL)
				cout << "Sorry This Jobe is not found \n";
		}
		else { cout << "No Contacts" << endl; }
		break;
	case 2: //case to search by email


		cout << "Enter The email U want to search here : ";
		cin >> s_email;
		if (head != NULL)
		{
			current = head;
			while (current != NULL)
			{
				if (current->email == s_email)
				{
					cout << "The email is found \n";
					break;
				}
				else { current = current->next; }
			}
			if (current == NULL)
				cout << "Sorry This email is not found \n";
		}
		else { cout << "No Contacts" << endl; }
		break;
	case 3: //case 3 to search by number
		cout << "Enter The Number U want to search here : ";
		cin >> s_number;
		if (head != NULL)
		{
			current = head;
			while (current != NULL)
			{
				if (current->number == s_number)
				{
					cout << "The Number is found \n";
					break;
				}
				else { current = current->next; }
			}
			if (current == NULL)
				cout << "Sorry This Number is not found \n";
		}
		else { cout << "No Contacts" << endl; }
		break;
	default:
		cout << endl;
		cout << "Warning.....................! \n";
		cout << "Enter a valid Number \n";
		search();
		break;
	}

}
void quit()
{
	//it,s not return any thing
}
void interface()
{
	string com;char comm;
	cout << endl;
	cout << "1)Enter A for Add any new contact                ";
	cout << "2)Enter P for print the saved contact information \n";
	cout << endl;
	cout << "3)Enter U to  update the contact information     ";
	cout << "4)Enter D for delete any saved contact \n";
	cout << endl;
	cout << "5)Enter S for search any saved contact           ";
	cout << "6)Enter Q for quit the program \n";
	cout << endl;
	cout << "7)Enter O for Sort the program                   ";
	cout << "8)Enter H for help the program \n";
	cout << "\nPlease Enter you ordar here : ";cin >> com;
	comm = com.at(0);
	switch (comm)
	{
	case 'a':
	case 'A':
		getdata();
		interface();
		break;
	case 'p':
	case 'P':
		display();
		interface();
		break;
	case 'Q':
	case 'q':
		printinf();
		quit();
		break;
	case'D':
	case'd':
		deletee();
		interface();
		break;
	case'S':
	case's':
		search();
		interface();
		break;
	case 'o':
	case 'O':
			sort();
		interface();
		break;
	case 'U':
	case'u':
		update();
		interface();
		break;
	case 'H':
	case 'h':
		cout << "\n\n A ) to add contact    .  D ) to delete contact\n\n";
		cout << "\n\n P ) print the contact .  E ) to edit contact\n\n";
		cout << "\nPlease Enter you ordar here : ";cin >> com;
		break;
	default:
		cout << "use \"h\" to get help :)\n ";
		interface();
		break;
	}

}

