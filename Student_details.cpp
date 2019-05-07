#include<fstream.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int search(int);
void update(int);
void del(int);
int i = 6;
class studet
{
public:
	char Name[100];
	char Area[100];
	int RNo;
	long int PhNo;
	char Time[10];
	float Fee;
	void getd()
	{
		textcolor(LIGHTRED);
		cprintf("\n Enter the Students Roll No.:");
		cin >> RNo;
		cprintf("\n Enter the Students name :");
		gets(Name);
		cprintf("\n Enter the Area :");
		gets(Area);
		cprintf("\n Enter the Pick Up Time :");
		gets(Time);
		cprintf("\n Enter the Studens Contact Number");
		cin >> PhNo;
		cprintf("\n Enter the Students Fees");

		cin >> Fee;
		textcolor(WHITE);
	}
	void putd()
	{
		gotoxy(4, i);
		cout << RNo;
		gotoxy(14, i);
		cout << Name;
		gotoxy(38, i);
		cout << Area;
		gotoxy(55, i);
		cout << Time;
		gotoxy(64, i);
		cout << PhNo;
		gotoxy(76, i);
		cout << Fee;
		i++;
	}
}s1;
void main()
{
	char answer = 'y';
	while (answer == 'y')
	{
		clrscr();
		gotoxy(28, 2);
		cout << "T & G BUS TRANSPORT SERVICE";
		int ch;
		gotoxy(28, 5);
		textcolor(LIGHTRED);
		cprintf("1. Add Records");
		gotoxy(28, 6);
		textcolor(LIGHTCYAN);
		cprintf("2. Show Records");
		gotoxy(28, 7);
		textcolor(LIGHTBLUE);

		cprintf("3. Search Records");
		gotoxy(28, 8);
		textcolor(LIGHTGREEN);
		cprintf("4. Update Records");
		gotoxy(28, 9);
		textcolor(LIGHTMAGENTA);
		cprintf("5. Delete Records");
		gotoxy(28, 10);
		textcolor(LIGHTGRAY);
		cprintf("6. Exit");
		textcolor(WHITE);
		cout << "\n\t\t\t Enter your choice(1-6) : ";
		cin >> ch;
		clrscr();
		if (ch == 1)
		{
			gotoxy(28, 2);
			cout << "T & G BUS TRANSPORT SERVICE" << endl;
			fstream f1;
			f1.open("stud.dat", ios::app);
			char ans = 'y';
			while (ans == 'y')
			{
				s1.getd();
				f1.write((char*)&s1, sizeof(s1));
				textcolor(YELLOW);
				cout << "\n\t\t\t";
				cprintf("S A V I N G.........W A I T");
				delay(2000);

				cout << "\n\t\t\t";
				cprintf("S A V E D    S U C C E S S F U L L Y");
				cout << "\n\nDo you wish to add more records(y/n)" << endl;
				cin >> ans;
			}
			textcolor(WHITE);
			f1.close();

		}
		else if (ch == 2)
		{
			gotoxy(28, 2);
			cout << "T & G BUS TRANSPORT SERVICE" << endl;
			fstream f2;
			f2.open("stud.dat", ios::in);
			cout << "\--------------------------------------------------------------------------------";
			textcolor(CYAN);
			cout << "\n";
			gotoxy(1, 4);
			cprintf("Roll No.");
			gotoxy(14, 4);
			cprintf("Students Name");
			gotoxy(38, 4);
			cprintf("Area");
			gotoxy(56, 4);
			cprintf("Time");
			gotoxy(64, 4);
			cprintf("Ph.No.");
			gotoxy(75, 4);
			cprintf("Fees");
			textcolor(WHITE);
			cout << "\n--------------------------------------------------------------------------------" << endl;
			while (f2.read((char*)&s1, sizeof(s1)))
			{
				s1.putd();
			}
			cout << "\n--------------------------------------------------------------------------------";
			f2.close();
		}
		else if (ch == 3)
		{
			gotoxy(28, 2);
			cout << "T & G BUS TRANSPORT SERVICE";
			int b;
			gotoxy(2, 5);

			cout << " Enter the Roll No. to be searched : ";
			cin >> b;
			int x = search(b);
			if (x == 0)
			{
				gotoxy(25, 6);
				cprintf("The Roll No. does not exist");
			}
			textcolor(WHITE);
		}
		else if (ch == 4)
		{
			gotoxy(28, 2);
			cout << "T & G BUS TRANSPORT SERVICE";
			int c;
			cout << "\n\t\t\t Enter the Roll No to be searched : ";
			cin >> c;
			update(c);
			textcolor(WHITE);
		}

		else if (ch == 5)
		{
			gotoxy(28, 2);
			cout << "T & G BUS TRANSPORT SERVICE";
			int r;
			cout << "\n\t\t\t Enter the Roll No. to be removed : ";
			cin >> r;
			del(r);
			textcolor(WHITE);
		}
		else if (ch == 6)
		{
			gotoxy(28, 2);
			cout << "T & G BUS TRANSPORT SERVICE";
			cout << "\n\n\t\t\t";
			textcolor(LIGHTRED + BLINK);

			cprintf("Press any key to Exit...");
			getch();
			exit(0);
		}
		else
		{
			cout << "\n\t\t\t Invalid Choice";
		}
		cout << "\n\n\n\t\t\t Wish to go back to the main menu : " << endl;
		cin >> answer;
	}
	getch();
}

int search(int b)   //TO SEARCH IN THE FILE
{
	fstream f1;
	int h = 0;
	f1.open("stud.dat", ios::in);
	textcolor(YELLOW);
	cprintf("S C A N N I N G..........W A I T");
	cout << endl;
	delay(1000);
	while (f1.read((char*)&s1, sizeof(s1)))
	{
		if (s1.RNo == b)
		{
			textcolor(GREEN + BLINK);
			cprintf("Record Found.....");
			cout << "\nThe Details are : \n\n";
			textcolor(WHITE);
			cprintf("Students Roll No.      ---->");
			cout << s1.RNo << endl;
			cprintf("Students name          ---->");
			cout << s1.Name << endl;
			cprintf("Area                   ---->");
			cout << s1.Area << endl;

			cprintf("Pick Up Time           ---->");
			cout << s1.Time << endl;
			cprintf("Studens Contact Number ---->");
			cout << s1.PhNo << endl;
			cprintf("Students Fees          ---->");
			cout << s1.Fee << endl;
			return 1;
		}
	}
	f1.close();
	return 0;
}

void update(int c)  //TO UPDATE IN THE FILE
{
	int p = 0;
	fstream f5, f4;
	f5.open("stud.dat", ios::in);
	if (!f5)
		cout << "\n\t\t\t file cannot be opened";
	textcolor(YELLOW);
	cprintf("S C A N N I N G..........W A I T");
	delay(1000);
	f4.open("temp.dat", ios::out);
	while (f5.read((char*)&s1, sizeof(s1)))
	{
		if (s1.RNo == c)
		{
			p = 1;
			cout << "\n\t\t\t";
			textcolor(GREEN + BLINK);
			cprintf("Record Found...");
			cout << "\n\t\t\t What do you wish to update : ";
			cout << "\n\t\t\t 1. Time.:\n\t\t\t 2. Contact No : \n\t\t\t 3. Area \n\t\t\t 4.Fees" << endl;
			int upch;
			cin >> upch;
			if (upch == 1)

			{
				cout << "\n\t\t\tEnter the new Time for :  ";
				cin >> s1.Time;
			}
			else if (upch == 2)
			{
				cout << "\n\t\t\t Enter the new Contact No : ";
				cin >> s1.PhNo;
			}
			else if (upch == 3)
			{
				cout << "\n\t\t\t Enter the new Area : ";
				cin >> s1.Area;
			}
			else if (upch == 4)
			{
				cout << "\n\t\t\t Enter the new Fees : ";
				cin >> s1.Fee;
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
		textcolor(GREEN + BLINK);
		cprintf("U P D A T E D   S U C C E S S F U L L Y");

		delay(1000);
	}
	f5.close();
	f4.close();
	remove("stud.dat");
	rename("temp.dat", "stud.dat");
}
void del(int b)  //TO DELETE IN THE FILE
{
	fstream f6, f7;
	f6.open("stud.dat", ios::in);
	f7.open("temp.dat", ios::out);
	int h = 0;
	textcolor(YELLOW);
	cprintf("S C A N N I N G..........W A I T");
	delay(1000);
	while (f6.read((char*)&s1, sizeof(s1)))
	{
		if (s1.RNo != b)
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
		textcolor(GREEN + BLINK);

		cprintf("Record deleted successfully....");
	}
	f6.close();
	f7.close();
	remove("stud.dat");
	rename("temp.dat", "stud.dat");
}