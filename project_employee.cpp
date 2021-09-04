#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct em{
    string fast_name;
	string last_name;
	float salary;
	string designation;
	string address;
	string phone;
	string id;
	string blood;
	string date_of_birth;
	string date_of_join;
	string gender;
	string email;
	string govt;
};
class employee
{
private:
	em  ptr[50];
	string fast_name;
	string last_name;
	float salary;
	string designation;
	string address;
	string phone;
	string id;
	string blood;
	string date_of_birth;
	string date_of_join;
	string gender;
	string email;
	string govt;

public:
	employee()
	{


		salary = 0;

	}


	void add_new_employee()
	{


	    cout << "============ Add New Employee ============\n\n\n" << endl;
		cout << " Employee ID : " << endl;
		cin >> id;


		cout << " First Name : " << endl;
		cin >> fast_name;
		cout << " Last Name : " << endl;
		cin >> last_name;
		cout << " Designation : " << endl;
		cin >> designation;
        cout << " Phone Number : " << endl;
		cin >> phone;
        cout << " Email : " << endl;
		cin >> email;
		cout << " Present Address" << endl;
		cin >> address;
        cout << " Gender : " << endl;
		cin >> gender;
        cout << " Blood Group : " << endl;
		cin >> blood;
		cout << " Date of Birth(dd-mm-yyyy) : " << endl;
		cin >> date_of_birth;
        cout << " Date of Join (dd-mm-yyyy) : " << endl;
		cin >> date_of_join;
		cout << " Govt. ID Number : " << endl;
		cin >> govt;

		ofstream fout;
		fout.open("data.txt", ios::app);

		float temp = 0;
		string tempdes;

		if (fout)
		{
			fout <<id<<" " <<fast_name << " " << last_name << " " << gender << " " << date_of_birth << " " << date_of_join << " " << blood << " " <<
				address << " " << phone <<" "<<email<<" "<<govt<<" "<<designation<<endl;

		}
		else
			cout << "file not open" << endl;
	fout.close();
cout<<"Successfully Registered New Employee!" << endl;

	}
	int readfile()
	{
		int counter = 0;
		ifstream fin;
		fin.open("data.txt");
		if (fin)
		{

			while(!fin.eof())
			{

				fin >> ptr[counter].id;
			    fin >> ptr[counter].fast_name;
				fin >> ptr[counter].last_name;
				fin >> ptr[counter].gender;
				fin >> ptr[counter].date_of_birth;
				fin >> ptr[counter].date_of_join;
				fin >> ptr[counter].blood;
				fin >> ptr[counter].address;
				fin >> ptr[counter].phone;
				fin >> ptr[counter].email;
				fin >> ptr[counter].govt;
				fin >> ptr[counter].designation;
				counter++;

			}


		}
		fin.close();
		return counter;
	}
	void view_all_employees()
	{
	    cout<<endl<<endl<<endl<<"\t\t\t ====================== List of All Employee  ======================"<<endl<<endl;
		cout<<endl<<endl << "\t\tID : \t"<<"NAME : \t"<< "DESIGNATION : \t" <<"JOIN DATE : \t\t " << "PHONE NUMBER : \t\t" << "EMAIL : \t" << endl<<endl<<endl;
		int temp = readfile();
		temp--;
		for (int i = 0;i < temp;i++)
		{
			cout<<"\n\t\t|"<< ptr[i].id << "\t"<< ptr[i].fast_name<<"\t" << ptr[i].designation << "\t\t" << ptr[i].date_of_join << "\t\t " << ptr[i].phone << "\t\t" << ptr[i].email <<endl;

		}

cout << "\n\n\n\t\t\t\t *******Press 0 to continue*******" << endl;
       // kbhit();//clear
       int dami;
       cin>>dami;

        system("cls");
	}

	void update_employee_info()
	{

		cout << "Enter Old Employee ID to Update Information" << endl;
		string id;
		 cin>> id;
		int temp=readfile();
		temp--;
		int counter = 0;
		int count = 0;
		while (count<temp&&ptr[counter].id != id)
		{
			count++;
			counter++;
		}
		cout << "\t\t=========== Present Employee Data are: ===========" << endl;
		cout << "\t\t| Full name:" << ptr[counter].fast_name << endl;
		cout << "\t\t| Designation:" << ptr[counter].designation << endl;
		cout << "\t\t| Gender:" << ptr[counter].gender << endl;
		cout << "\t\t| Date of Birth:" << ptr[counter].date_of_birth << endl;
		cout << "\t\t| Date of Join:" << ptr[counter].date_of_join << endl;
		cout << "\t\t***** Are you sure you want to edit employee info? *****" << endl;
		cout << "\n\n\t\t| Press 'Y' for Yes or 'N' for No " << endl;
		string check;
		cin >> check;
		if (check == "Y")
		{
			cout << "Enter id of the employee" << endl;
			cin >> ptr[counter].id;

			cout << "Enter first name of the employee" << endl;
			cin >> ptr[counter].fast_name;
			cout << "Enter last name of the employee" << endl;
			cin >> ptr[counter].last_name;
			cout << "Enter designation of the employee" << endl;
			cin >> ptr[counter].designation;
			cout << "Enter Phone Number of the Employee :" << endl;
			cin >> ptr[counter].phone;
			cout << "Enter Address of the Employee : " << endl;
			cin >> ptr[counter].address;
			cout << "Enter Blood group  of the Employee : " << endl;
			cin >> ptr[counter].blood;
			cout << "Enter Date of birth of the Employee : " << endl;
			cin >> ptr[counter].date_of_birth;
			cout << "Enter Date of join  of the Employee : " << endl;
			cin >> ptr[counter].date_of_join;
			cout << "Enter Gender  of the Employee : " << endl;
			cin >> ptr[counter].gender;
			cout << "Enter Govt id  of the Employee : " << endl;
			cin >> ptr[counter].govt;
			cout << "Enter Email  of the Employee : " << endl;
			cin >> ptr[counter].email;
			ofstream fout;
			fout.open("data.txt");
			if(fout){
			for (int i = 0;i < temp;i++)
			{
				fout << ptr[i].id << " " << ptr[i].fast_name << " " << ptr[i].last_name << " " << ptr[i].gender << " " << ptr[i].date_of_birth << " " << ptr[i].date_of_join << " " << ptr[i].blood << " " <<
					ptr[i].address << " " << ptr[i].phone << " " << ptr[i].email << " " << ptr[i].govt<<" "<<ptr[i].designation << endl;

			}
			}

			cout << "Edited successfully! Press 0 to continue...." << endl;

                int dami;
             cin>>dami;

           system("cls");
		}


	}
	void delete_info()
	{
		cout << "============= Enter Employee ID to delete ============= \n\n \nOLD Employee ID : "<< endl;
		string id;
		cin >> id;
		int temp = readfile();
		temp--;
		int counter = 0;

			int count = 0;
		while (count<temp&&ptr[counter].id != id)
		{
			count++;
			counter++;
		}
		cout << "========== Present Employee Data : ========== " << endl;
		cout << "Name:" << ptr[counter].fast_name << endl;
		cout << "Designation:" << ptr[counter].designation << endl;
		cout << "Gender:" << ptr[counter].gender << endl;
		cout << "Date of birth:" << ptr[counter].date_of_birth << endl;
		cout << "Date of join:" << ptr[counter].date_of_join << endl;
		cout << "Are you sure you want to delete employee info?" << endl;
		cout << "Press Y for Yes or N for No" << endl;
		string check;
		cin >> check;
		if (check =="Y")
		{
			for (int i = counter;i < temp-1;i++)
			{
				ptr[i].id = ptr[i + 1].id;
				ptr[i].fast_name = ptr[i + 1].fast_name;
				ptr[i].last_name = ptr[i + 1].last_name;
				ptr[i].designation = ptr[i + 1].designation;
				ptr[i].date_of_birth = ptr[i + 1].date_of_birth;
				ptr[i].date_of_join = ptr[i + 1].date_of_join;
				ptr[i].blood = ptr[i + 1].blood;
				ptr[i].address = ptr[i + 1].address;
				ptr[i].gender = ptr[i + 1].gender;
				ptr[i].email = ptr[i + 1].email;
				ptr[i].govt = ptr[i + 1].govt;
				ptr[i].phone = ptr[i + 1].phone;


			}
			ofstream fout;
			fout.open("data.txt");
			for (int i = 0;i < temp-1;i++)
			{
				fout << ptr[i].id << " " << ptr[i].fast_name << " " << ptr[i].last_name << " " << ptr[i].gender << " " << ptr[i].date_of_birth << " " << ptr[i].date_of_join << " " << ptr[i].blood << " " <<
					ptr[i].address << " " << ptr[i].phone << " " << ptr[i].email << " " << ptr[i].govt << " "<<ptr[i].designation<< endl;

			}
fout.close();

cout << " \t\t****Successfully Deleted Employee Data****" << endl;
		}



	}

	void search_employee()
	{
		cout << "Enter the ID of the employee to search : " << endl;
		string id;
		cin >> id;
		int temp = readfile();
		int counter = 0;

		int count = 0;

		while (count<temp&&ptr[counter].id != id)
		{
			count++;
			counter++;
		}

		cout << "Name          : " << ptr[counter].fast_name<<" "<< ptr[counter].last_name<<endl;
		cout << "Designation   : " << ptr[counter].designation << endl;
		cout << "Gender        : " << ptr[counter].gender << endl;
		cout << "Date of Birth : " << ptr[counter].date_of_birth << endl;
		cout << "Date of Join  : " << ptr[counter].date_of_join << endl;
		cout << "Salary        : " << ptr[counter].salary <<endl;
		cout << "Blood group   : " << ptr[counter].blood << endl;
		cout << "Phone Number  : " << ptr[counter].phone <<endl;
		cout << "Email         : " << ptr[counter].email << endl;
		cout << "Address       : " << ptr[counter].address<<endl;
		cout << "Govt ID       : " << ptr[counter].govt << endl<<endl<<endl;
		cout << " Press 0 to continue" << endl;


	}

};

void menu()
{   cout <<"\t==============Main Menu=============="<<endl<<endl<<endl;
	cout <<"press 1 to View of All Employee." << endl;
	cout <<"press 2 to Add Employee." << endl;
	cout <<"press 3 to Update Employee Info."<< endl;
	cout <<"press 4 to Delete Employee Info."<<endl;
	cout <<"press 5 to Search Employee."<<endl;
	cout <<"press 6 to Exit."<<endl;

}
int main()
{
	employee e1;
	int option = 0;

	menu();

	cin >> option;
	while(option!=6)
	{
	switch (option)
	{
	case 1:
		e1.view_all_employees();
		break;
	case 2:
		e1.add_new_employee();
		break;
	case 3:
		e1.update_employee_info();
		break;
	case 4:
		e1.delete_info();
		break;
	case 5:
		e1.search_employee();
		break;
	case 6:
        break;
    default:
        cout<<"invalid choice"<<endl;
        break;
	}
	menu();

	cin >> option;

}
        cout<<"Thank You For Using My Application."<<endl;


return 0;
}

