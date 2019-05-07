#include<fstream>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int search(int);
void update(char[]);
void del(int);
int i = 6;
class busdet
{
public:
	int BusNo;
	char DName[20];
	char Area[20];
	int Cap;
	long int DPhNo;
	int srno;
	int total;
	void getd()
	{
		clrscr();
		textcolor(CYAN);
		cprintf("\n Enter the Bus No..");
		cin >> BusNo;
		cprintf("\n Enter the Drivers name", CYAN);
		gets(DName);
		cprintf("\n Enter the Drivers Contact Number", CYAN);
		cin >> DPhNo;
		cprintf("\n Enter the Area for the bus", CYAN);
		gets(Area);
		cprintf("\n Enter the Capacity of the bus", CYAN);
		cin >> Cap;
		textcolor(WHITE);

		getch();
	}
	void putd()
	{
		cout << "\n ";
		gotoxy(5, i);
		cout << BusNo;
		gotoxy(18, i);
		cout << DName;
		gotoxy(37, i);
		cout << DPhNo;
		gotoxy(55, i);
		cout << Area;
		gotoxy(69, i);
		cout << Cap;
		i++;
	}

}s1;

class mains
{
public:
	int drBusNo;
	char drName[20];
	char stuname[20];
	long int stuphno;
	char stutime[10];
	float stufee;
	char Area[20];
	int Cap;
	long int drPhNo;
	void putd()
	{
		name\tStudent Ph.No.\tCapacity";
			cout << "\nEnter the BusNo :" << drBusNo;
		cout << "\nEnter the Driver Name : " << drName;

		cout << "\nEnter the Area : " << Area;
		cout << "\nEnter the Driver PhNo :" << drPhNo;
		cout << "\nEnter the Student Name : " << stuname;
		cout << "\nEnter the Student PhNo : " << stuphno;
		cout << "\nEnter the Capcity : " << Cap;
		cout << "\nEnter the Student fees : " << stufee;
		cout << "\nEnter the Pick up Time : " << stutime;
	}

}m1;

class studet
{
public:
	char Name[20];
	char Area[20];
	int RNo;
	long int PhNo;
	char Time[10];
	float Fee;
}stu1;
void createbus()
{
	fstream f1, f2, f3;
	f1.open("bus.dat", ios::in);
	f2.open("stud.dat", ios::in);
	f3.open("route.dat", ios::out);
	studet s2[20];
	busdet b2[20];
	int i = 1;
	while (f2.read((char*)&stu1, sizeof(stu1)))
	{
		s2[i] = stu1;
		i++;
	}
	f2.close();
	int j = 1;

	while (f1.read((char*)&s1, sizeof(s1)))
	{
		b2[j] = s1;
		j++;
	}
	for (int x = 1; x <= i - 1; x++)
	{
		for (int y = 1; y <= j - 1; y++)
		{
			if (strcmp(b2[x].Area, s2[y].Area) == 0)
			{
				m1.drBusNo = b2[x].BusNo;
				strcpy(m1.drName, b2[x].DName);
				strcpy(m1.stuname, s2[y].Name);
				strcpy(m1.Area, b2[x].Area);
				m1.Cap = b2[x].Cap;
				m1.drPhNo = b2[x].DPhNo;
				m1.stuphno = s2[y].PhNo;
				m1.stufee = s2[y].Fee;
				strcpy(m1.stutime, s2[y].Time);
				f3.write((char*)&m1, sizeof(m1));
			}
		}
	}
	f1.close();
	f3.close();
}
void findroute()   //TO CREATE THE ROUTE FOR A FOLDER
{
	int z = 0;
	char rou[20];
	cout << "\n Enter the route ";
	cin >> rou;
	fstream f9;
	f9.open("route.dat", ios::in);
	cout << "\n \t\t\t DETAILS OF BUS ROUTE :- " << strupr(rou);
	cout << "\n\tNAME\t     PHONE\t     PICK TIME\t";

	cout << "\n\n--------------------------------------------------------";
	mains m2;
	while (f9.read((char*)&m1, sizeof(m1)))
	{
		if (strcmpi(m1.Area, rou) == 0)
		{
			m2 = m1;
			cout << "\n\t  " << m1.stuname << "\t       " << m1.stuphno << "\t      " << m1.stutime;
			z++;
		}
	}
	cout << "\n\n----------------------------------------------------------";
	cout << "\n\tBUSNO :" << m2.drBusNo << "\tDRIVER NAME : " << strupr(m2.drName) << "\tDRIVER PH : " << m2.drPhNo;
	cout << "\n\tSTRENGTH : " << z << "\tCAPACITY : " << m2.Cap;
	f9.close();
}
void main()
{
	gotoxy(20, 2);
	cout << "T & G BUS TRANSPORT SERVICE";
	gotoxy(25, 3);
	textcolor(GREEN);
	cprintf(" 1. THE BUS DETAILS");
	gotoxy(25, 4);
	textcolor(BLUE);
	cprintf(" 2. THE ROUTE DETAILS");
	int copt;
	cout << "Please enter your choice";
	cin >> copt;
	if (copt == 2)
	{
		int opt;
		gotoxy(28, 4);
		textcolor(MAGENTA);
		cprintf(" 1. TO CREATE A BUS FILE");
		gotoxy(28, 5);

		textcolor(LIGHTCYAN);
		cprintf(" 2. TO FIND THE ROUTE OF THE BUS");
		cout << "Enter your choice";
		cin >> opt;
		clrscr()
			if (opt == 1)
			{
				createbus();
			}
			else if (opt == 2)
			{
				findroute();
			}
	}
	else if (copt == 1)
	{
		char answer = 'y';
		while (answer == 'y')
		{
			clrscr();
			int ch;
			gotoxy(30, 5); textcolor(LIGHTRED);
			cprintf(" 1. Add Records");
			gotoxy(30, 6);
			textcolor(LIGHTCYAN);
			cprintf(" 2. Show Records");
			gotoxy(30, 7);
			textcolor(LIGHTBLUE);
			cprintf(" 3. Search Records");
			gotoxy(30, 8);
			textcolor(LIGHTGREEN);
			cprintf(" 4. Update Records");
			gotoxy(30, 9);
			textcolor(LIGHTMAGENTA);
			cprintf(" 5. Delete Records");
			gotoxy(30, 10);
			textcolor(LIGHTGRAY);

			gotoxy(30, 10);
			cprintf(" 6. Exit");
			textcolor(WHITE);
			gotoxy(30, 15);
			cprintf(" Enter your choice(1-6) : ");
			cin >> ch;
			textcolor(WHITE);
			clrscr();
			if (ch == 1)
			{
				fstream f1;
				f1.open("bus.dat", ios::app);
				char ans = 'y';
				while (ans == 'y')
				{
					s1.getd();
					f1.write((char*)&s1, sizeof(s1));
					cout << "\n\t\t\t";
					textcolor(YELLOW + BLINK);
					cprintf("S A V I N G.........W A I T");
					delay(1000);
					cout << "\n\t\t\t";
					textcolor(LIGHTGREEN);
					cprintf("S A V E D    S U C C E S S F U L L Y");
					cout << "\n";
					textcolor(LIGHTRED);
					cprintf("Do you wish to add more records(y/n)");
					cin >> ans;
				}
				textcolor(WHITE);
				f1.close();
			}
			else if (ch == 2)
			{
				fstream f2;
				fstream f10;
				f10.open("buscopy.dat", ios::out);

				f2.open("bus.dat", ios::in);
				cout << "--------------------------------------------------------------------------------";
				textbackground(BLACK);
				textcolor(LIGHTGREEN);
				gotoxy(3, 2);
				cprintf("BusNo");
				gotoxy(14, 2);
				cprintf("Driver Name");
				gotoxy(32, 2);
				cprintf("Drivers Ph.No.");
				gotoxy(54, 2);
				cprintf("Area");
				gotoxy(66, 2);
				cprintf("Capacity");
				cout << "\n--------------------------------------------------------------------------------";
				while (f2.read((char*)&s1, sizeof(s1)))
				{
					s1.putd();
				}
				cout << "\n--------------------------------------------------------------------------------";
				i = 6;
				f2.close();
			}
			else if (ch == 3)
			{
				int b;
				textcolor(LIGHTMAGENTA);
				cout << "\n\t\t\t";
				cprintf("Enter the Bus No. to be searched : ");
				cin >> b;
				int x = search(b);
				if (x == 0)
				{
					cout << "\n\t\t\t";
					textcolor(RED + BLINK);
					delay(500);
					cprintf("The Bus No. does not exist");

				}
				textcolor(WHITE);
			}
			else if (ch == 4)
			{
				char name1[20];
				textcolor(LIGHTMAGENTA);
				cout << "\n\t\t\t";
				cprintf("Enter the name to be searched : ");
				cin >> name1;
				update(name1);
				textcolor(WHITE);
			}
			else if (ch == 5)
			{
				int b;
				textcolor(LIGHTMAGENTA);
				cout << "\n\t\t\t";
				cprintf("Enter the Bus no. to be removed : ");
				cin >> b;
				del(b);
				textcolor(WHITE);
			}
			else if (ch == 6)
			{
				cout << "\n\t\t\tPress any key to Exit...";
				getch();
				exit(0);
			}
			else
			{
				cout << "\n\t\t\t Invalid Choice";
			}
			textcolor(LIGHTGRAY);
			cout << "\n\n\n\t\t\t";
			cprintf("Wish to go back to the main menu : ");
			cout << endl;

			cin >> answer;
		}
	}
	getch();
}
int search(int b)   //TO SEARCH THE DATA IN THE FILE
{
	fstream f1;
	int h = 0;
	f1.open("bus.dat", ios::in);
	textcolor(YELLOW + BLINK);
	cprintf("S C A N N I N G..........W A I T");
	delay(1000);
	while (f1.read((char*)&s1, sizeof(s1)))
	{
		if (s1.BusNo == b)
		{
			cout << "\n\t\t\t";
			textcolor(GREEN + BLINK);
			cprintf("Record Found.....");
			cout << "\n\t\t\tThe Details are : \n";
			s1.putd();
			return 1;
		}
	}
	f1.close();
	return 0;
}
void update(char name1[20])    // TO UPDATE THE DATA IN THE FILE
{
	int p = 0;
	fstream f5, f4;
	f5.open("bus.dat", ios::in);
	if (!f5)
		cout << "\n\t\t\t file cannot be opened";
	textcolor(YELLOW + BLINK);
	cprintf("S C A N N I N G..........W A I T");

	delay(1000);
	f4.open("temp.dat", ios::out);
	while (f5.read((char*)&s1, sizeof(s1)))
	{
		cout << s1.DName << "\nSTRLEN = " << strlen(s1.DName);
		if (strcmpi(s1.DName, name1) == 0)
		{
			p = 1;
			cout << "\n\t\t\t";
			textcolor(GREEN);
			cprintf("Record Found...");
			cout << "\n\t\t\t What do you wish to update : ";
			cout << "\n\t\t\t 1. Bus No.:\n\t\t\t 2. Capacity: \n\t\t\t 3. Area" << endl;
			int upch;
			cin >> upch;
			if (upch == 1)
			{
				cout << "\n\t\t\tEnter the new Bus No. for :  " << s1.DName;
				cin >> s1.BusNo;
			}
			else if (upch == 2)
			{
				cout << "\n\t\t\t Enter the new Capacity : ";
				cin >> s1.Cap;
			}
			else if (upch == 3)
			{
				cout << "\n\t\t\t Enter the new Area : ";
				gets(s1.Area);
			}
			f4.write((char*)&s1, sizeof(s1));
		}
		else
		{
			f4.write((char*)&s1, sizeof(s1));
		}
	}
	if (p == 0)

	{
		cout << "\n\t\t\t";
		textcolor(RED + BLINK);
		cprintf("The Record does not Exist ");
	}
	else
	{
		textcolor(YELLOW);
		cprintf("U P D A T E D   S U C C E S S F U L L Y");
		delay(1000);
	}
	f5.close();
	f4.close();
	remove("bus.dat");
	rename("temp.dat", "bus.dat");
}
void del(int b)    // TO DELETE THE DATA FROM THE FILE
{
	fstream f6, f7;
	f6.open("bus.dat", ios::in);
	f7.open("temp.dat", ios::out);
	int h = 0;
	textcolor(YELLOW + BLINK);
	cprintf("S C A N N I N G..........W A I T");
	delay(1000);
	while (f6.read((char*)&s1, sizeof(s1)))
	{
		if (s1.BusNo != b)
		{
			f7.write((char*)&s1, sizeof(s1));
		}
		else
		{
			h = 1;
		}
	}
	if (h == 0)

	{
		cout << "\n\t\t\t";
		textcolor(RED + BLINK);
		cprintf("The Record does not Exist ");
	}
	else
	{
		cout << "\n\t\t\t";
		textcolor(GREEN);
		cprintf("Record deleted successfully....");
	}
	f6.close();
	f7.close();
	remove("bus.dat");
	rename("temp.dat", "bus.dat");
}