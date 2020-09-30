//HEADER FILES
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<dos.h>
#include<iomanip>
#include<graphics.h>
#include<process>

//GLOBAL VARIABLES
int temp;
char ch;
fstream file;
int adminflag;

//PROTOTYPES OF FUNCTIONS USED
void main_menu();
void my_exit();
void sub_menu(char);
void admin();
void srch_cabs();
void search_cno();
void search_model();
void book_cab();
void cancel_cab();
void add_cab();
void view_cabs();
void modify_cab();
void delete_cab();
void all_bookings();



//CLASS - CAB - FOR CREATING AND ACCESSING CAB DATABASE
class cab
{
	int CNO;
	char Destination[100];
	char Source[100];
	float Distance;
	float charge;
	char status[50];
	float Price;
	char caridno[50];
	char carmodel[50];

public:
	cab()
	{
		CNO = 0;
		strcpy(Destination,"NA");
		strcpy(Source,"NA");
		Distance = 0;
		charge = 0;
		strcpy(status, "NOT BOOKED");
		strcpy(caridno, "NA");
		strcpy(carmodel, "NA");
	}
	void Getdata()
	{
		gotoxy(2,5);
		cprintf("INPUT CAB NO:");
		gotoxy(2,7);
		cprintf("INPUT Cab Model:");
		gotoxy(2,9);
		cprintf("INPUT Cab ID No.:");
		gotoxy(2,11);
		cprintf("INPUT Charge KM:");
		gotoxy(16,5);
		cin>>CNO;
		gotoxy(19,7);
		gets(carmodel);
		gotoxy(20,9);
		gets(caridno);
		gotoxy(19,11);
		cin>>charge; 
	}
	void Showdata()
	{
		gotoxy(2,8);
		clreol();
		cprintf("CAB NO:");
		gotoxy(2,10);
		clreol();
		cprintf("CAR MODEL:");
		gotoxy(2,12);
		clreol();
		cprintf("CAR ID NO:");
		gotoxy(2,14);
		clreol();
		cprintf("CHARGE PER KM:");
		gotoxy(10,8);
		cout<<CNO;
		gotoxy(13,10);
		puts(carmodel);
		gotoxy(13,12);
		puts(caridno);
		gotoxy(16,14);
		cout<<charge;
	}
	void ShowRowCol()
	{
		cout<<setw(10)<<CNO<<setw(20)<<carmodel<<setw(20)<<caridno<<setw(15)<<charge<<setw(14)<<status<<endl;
	}
	char* getcarmodel()
	{
		return carmodel;
	}
	char* getcarid()
	{
		return caridno;
	}
	char* getstatus()
	{
		return status;
	}
	char* getcabstatus()
	{
		return status;
	}
	char* getcabmodel()
	{
		return carmodel;
	}
	float getcabdistance()
	{
		return Distance;
	}
	char* getcabdestination()
	{
		return Destination;
	}
	char* getcabsource()
	{
		return Source;
	}
	float getcabprice()
	{
		return Price;
	}
	int getcno()
	{
		return CNO;
	}
	void showbookings()
	{
		cout<<setw(10)<<CNO<<setw(15)<<Source<<setw(15)<<Destination<<setw(10)<<Price<<setw(15)<<Distance<<endl;
	}
	void modify()
	{
		gotoxy(2,8);
		cprintf("INPUT NEW CAB NO:");
		gotoxy(2,10);
		cprintf("INPUT NEW CAR MODEL:");
		gotoxy(2,12);
		cprintf("INPUT NEW CAR ID NO.:");
		gotoxy(2,14);
		cprintf("INPUT NEW CHARGE PER KM:");
		gotoxy(20,8);
		cin>>CNO;
		gotoxy(25,10);
		gets(carmodel);
		gotoxy(25,12);
		gets(caridno);
		gotoxy(27,14);
		cin>>charge;
	}
	void showmod()
	{
		gotoxy(2,8);
		cprintf("CAB NO:");
		gotoxy(2,10);
		cprintf("CAR MODEL:");
		gotoxy(2,12);
		cprintf("CAR ID NO:");
		gotoxy(2,14);
		cprintf("CHARGE PER KM:");
		gotoxy(10,8);
		cout<<CNO;
		gotoxy(18,10);
		puts(carmodel);
		gotoxy(18,12);
		puts(caridno);
		gotoxy(18,14);
		cout<<charge;
	}
	void showbook()
	{
		gotoxy(2,6);
		cprintf("CAB NO:");
		gotoxy(2,8);
		cprintf("CAR MODEL:");
		gotoxy(2,10);
		cprintf("CAR ID NO:");
		gotoxy(2,12);
		cprintf("SOURCE:");
		gotoxy(2,14);
		cprintf("DESTINATION:");
		gotoxy(2,16);
		cprintf("TOTAL PRICE:");
		gotoxy(10,6);
		cout<<CNO;
		gotoxy(12,8);
		puts(carmodel);
		gotoxy(13,10);
		puts(caridno);
		gotoxy(10,12);
		puts(Source);
		gotoxy(15,14);
		puts(Destination);
		gotoxy(15,16);
		cout<<Price;
	}
	void book()
	{
		gotoxy(2,16);
		cprintf("INPUT DESTINATION:");
		gotoxy(21,16);
		gets(Destination);
		gotoxy(2,17);
		cprintf("INPUT SOURCE PLACE:");
		gotoxy(22,17);
		gets(Source);
		gotoxy(2,18);
		cprintf("INPUT DISTANCE IN KM:");
		gotoxy(24,18);
		cin>>Distance;
		Price = charge*Distance;
		strcpy(status,"BOOKED");
		gotoxy(2,19);
		cprintf("TOTAL COST:");
		cout<<Price;
	}
	void unbook()
	{
		strcpy(Destination, "NA");
		strcpy(Source, "NA");
		Distance=0;
		Price=0;
		strcpy(status,"NOT BOOKED");
	}
};
class trans
{
	char model[50];
	char source[40];
	char destination[40];
	float distance;
	char status[50];
	float price;
public:
	trans()
	{
		strcpy(destination,"NA");
		strcpy(status,"NA");
		strcpy(model,"NA");
		distance =0;
		price =0;
	}
	char* returndestination()
	{
		return destination;
	}
	float returndistance()
	{
		return distance;
	}
	char* returnmodel()
	{
		return model;
	}
	void getmodel(char a[])
	{
		strcpy(model,a);
	}
	void getdestination(char b[])
	{
		strcpy(destination,b);
	}
	void getdistance(float c)
	{
		distance = c;
	}
	void getprice(float e)
	{
		price =e;
	}
	void getstatus(char d[])
	{
		strcpy(status,d);
	}
	void getsource(char f[])
	{
		strcpy(source,f);
	}
	void showdata()
	{
		cout<<setw(15)<<model<<setw(15)<<source<<setw(15)<<destination<<setw(10)<<price<<setw(10)<<distance<<setw(15)<<status;

	}
	void cancel()
	{
		strcpy(status,"CANCELLED");
	}
};
void transaction()
{
	trans t;
	textmode(C80);
	highvideo();
	adminflag=1;
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(35,2);
	cprintf("TRANSACTIONS\r\n");
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	cout<<setw(15)<<"Model |"<<setw(15)<<"SOURCE |"<<setw(15)<<"DESTINATION |"<<setw(10)<<"COST |"<<setw(10)<<"Distance |"<<setw(15)<<"STATUS |";
	int flag =0;
	file.open("transaction.dat", ios::binary | ios::in);
	while(file.read((char*)&t, sizeof(t)))
	{
			t.showdata();
			flag =1;
	}
	file.close();
	for(temp = 0; temp<80; temp++)
	{
		cprintf("=");
	}
	if(flag == 0)
	{
		textbackground(WHITE);
		textcolor(RED + BLINK);
		cprintf("NO TRANSACTIONS FOUND IN DATABASE\r\n");
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf("Press Any Key to return to MAIN Menu:\r\n");
		gotoxy(40,7);
		getche();
		delay(500);
		main_menu();
	}
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(1,23);
	cprintf("Press Any to return to MAIN MENU\n\r");
	for(temp = 0; temp<80;temp++)
	{
		cprintf("=");
	}
	gotoxy(36,23);
	getch();
	delay(500);
	main_menu();
}
//MAIN FUNCTION
void main()
{
	clrscr();
	int gd = DETECT, gm, errorcode;
	initgraph(&gd, &gm, "");
	textmode(C40);
	setbkcolor(BLACK);
	textcolor(WHITE);
	for(temp =0; temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(2,24);
	for(temp =0;temp<39;temp++)
	{
		cprintf("=");
	}
	gotoxy(4,10);
	cprintf("C A R  R E N T A L   S Y S T E M");
	gotoxy(5,20);
	cprintf("Developer - Akshay Kumar Ravi");
	getch();
	textcolor(WHITE);
	main_menu();
	closegraph();
}

//EXIT FUNCTION
void my_exit()
{
	clrscr();
	highvideo();
	textmode(C40);
	for(temp =0; temp<40;temp++)
	{
		cprintf("*");
	}
	for(temp =2;temp<25;temp++)
	{
		gotoxy(1,temp);
		cprintf("*");
		gotoxy(40,temp);
		cprintf("*");
	}
	gotoxy(2,24);
	for(temp =0;temp<39;temp++)
	{
		cprintf("*");
	}
	gotoxy(3,12);
	cprintf("THANKS FOR USING, HAVE A NICE DAY :)");
	gotoxy(15,20);
	cprintf("Exiting");
	for(temp =0;temp<3;temp++)
	{
		delay(400);
		cprintf(". ");
		delay(400);
	}
	exit(0);
}

//FUNCTION FOR MAIN MENU
void main_menu()
{
	clrscr();
	adminflag = 0;
	highvideo();
	textmode(C40);
	setbkcolor(BLACK);
	textcolor(WHITE);
	for(temp =0; temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(13,2);
	cprintf("M A I N   M E N U\r\n");
	for(temp=0;temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(2,24);
	for(temp =0;temp<39;temp++)
	{
		cprintf("=");
	}
	gotoxy(10,7);
	cprintf("1) ADMINISTRATOR MENU");
	gotoxy(10,10);
	cprintf("2) Book CAB");
	gotoxy(10,13);
	cprintf("3) CANCEL BOOKING");
	gotoxy(10,16);
	cprintf("4) TRANSACTION");
	gotoxy(2,18);
	for(temp = 0; temp<39;temp++)
	{
		cprintf("=");
	}
	gotoxy(2,19);
	textcolor(WHITE + BLINK);
	cprintf("INPUT YOUR CHOICE:");
	gotoxy(2,21);
	textcolor(WHITE);
	for(temp = 0;temp<39;temp++)
	{
		cprintf("=");
	}
	textcolor(WHITE);
	gotoxy(2,23);
	cprintf("Press <ESC> to Exit");
	gotoxy(20,19);
	ch = getche();
	delay(100);
	sub_menu(ch);
}
void sub_menu(char ch)
{
	textmode(C40);
	switch(ch)
	{
		case '1': admin();
			  break;
		case '2': book_cab();
			  break;
		case '3': cancel_cab();
			  break;
		case '4': transaction();
			  break;
		case  27: my_exit();
			  break;
		default: textcolor(RED);
			 textbackground(WHITE);
			 gotoxy(1,19);
			 clreol();
			 cprintf("INVALID SELECTION, ENTER AGAIN");
			 textcolor(WHITE);
			 textbackground(BLACK);
			 sound(800);
			 delay(500);
			 nosound();
			 main_menu();
	}
}

//FUNCTION TO SEARCH CABS BY CAB NUMBER
void search_cno()
{
	cab c;
	clrscr();
	textmode(C80);
	highvideo();
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(35,2);
	cprintf("SEARCH CABS BY CNO\r\n");
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	int tmp;
	cprintf("ENTER CAB NO TO SEARCH:");
	gotoxy(24,4);
	cin>>tmp;
	for(temp =0;temp<80;temp++)
	{
		cprintf("=");
	}
	cout<<setw(10)<<"| CAB NO |"<<setw(20)<<"| CAR MODEL |"<<setw(20)<<"| CAR ID NO. |"<<setw(15)<<"| CHARGE |"<<setw(14)<<"| STATUS |"<<endl;
	int flag =0;
	file.open("cab.dat", ios::binary | ios::in);
	while(file.read((char*)&c, sizeof(c)))
	{
		if(tmp == c.getcno())
		{
			flag=1;
			c.ShowRowCol();
		}
	}
	file.close();
	for(temp = 0; temp<80; temp++)
	{
		cprintf("=");
	}
	if(flag == 0)
	{
		textbackground(WHITE);
		textcolor(RED + BLINK);
		cprintf("NO CABS FOUND WITH THIS CNO\r\n");
		textcolor(WHITE);
		textbackground(BLACK);

		getch();
		delay(2000);
	}
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(1,23);

	for(temp = 0; temp<80;temp++)
	{
		cprintf("=");
	}
	gotoxy(36,23);
	getch();
	delay(500);

}

//FUNCTION TO SEARCH CABS BY CAR MODEL
void search_model()
{
	cab c;
	clrscr();
	textmode(C80);
	highvideo();
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(35,2);
	cprintf("SEARCH CABS BY MODEL\r\n");
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	char tmp[100];
	cprintf("ENTER CAR MODEL TO SEARCH:");
	gotoxy(30,4);
	gets(tmp);
	for(temp =0;temp<80;temp++)
	{
		cprintf("=");
	}
	cout<<setw(10)<<"| CAB NO |"<<setw(20)<<"| CAR MODEL |"<<setw(20)<<"| CAR ID NO. |"<<setw(15)<<"| CHARGE |"<<setw(14)<<"| STATUS |"<<endl;
	int flag =0;
	file.open("cab.dat", ios::binary | ios::in);
	while(file.read((char*)&c, sizeof(c)))
	{
		if(strcmpi(tmp,c.getcarmodel())==0)
		{
			flag =1;
			c.ShowRowCol();
		}
	}
	file.close();
	for(temp = 0; temp<80; temp++)
	{
		cprintf("=");
	}
	if(flag == 0)
	{
		textbackground(WHITE);
		textcolor(RED + BLINK);
		cprintf("NO CABS FOUND WITH THIS SOURCE\r\n");
		textcolor(WHITE);
		textbackground(BLACK);

		getch();
		delay(2000);
	}
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(1,23);

	for(temp = 0; temp<80;temp++)
	{
		cprintf("=");
	}
	gotoxy(36,23);
	getch();
	delay(500);
}

//FUNCTION FOR USER TO BOOK CABS
void book_cab()
{
	clrscr();
	cab c;
	highvideo();
	textmode(C40);
	setbkcolor(BLACK);
	textcolor(WHITE);
	for(temp =0; temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(15,2);
	cprintf("BOOK A CAB\r\n");
	for(temp=0;temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(2,24);
	for(temp =0;temp<39;temp++)
	{
		cprintf("=");
	}
	char tmp[100];
	gotoxy(2,4);
	cprintf("Enter CAB MODEL:");
	gotoxy(19,4);
	gets(tmp);
	gotoxy(15,6);
	cprintf("SEARCHING");
	for(temp=0;temp<3;temp++)
	{
		cprintf(". ");
	}
	long pos;
	int flag =0;
	file.open("cab.dat",ios::in | ios::binary | ios::out);
	trans t;
	fstream obj;
	obj.open("transactions.dat",ios::in | ios::binary | ios::out | ios::app);
	while(file.read((char*)&c,sizeof(c)))
	{
		pos=file.tellg();
		if(strcmpi(tmp,c.getcarmodel())==0)
		{
			gotoxy(15,6);
			cprintf("MATCH FOUND");
			c.Showdata();
			if(strcmpi(c.getstatus(),"BOOKED")==0)
			{
				gotoxy(1,18);
				cprintf("ALREADY BOOKED PRESS ANY KEY TO OTHER");
				getch();
				gotoxy(1,18);
				clreol();
				continue;
			}
			gotoxy(1,20);
			cprintf("BOOK THIS CAB, PRESS [y/Y] To Confirm:");
			gotoxy(39,20);
			ch = getche();
			if(ch=='y'||ch=='Y')
			{
				c.book();
				t.getmodel(c.getcabmodel());
				t.getdestination(c.getcabdestination());
				t.getsource(c.getcabsource());
				t.getprice(c.getcabprice());
				t.getdistance(c.getcabdistance());
				t.getstatus("BOOKED");
				gotoxy(15,21);
				cprintf("BOOKING CAB");
				for(temp =0;temp<3;temp++)
				{
					delay(300);
					cprintf(". ");
					delay(300);
				}
				gotoxy(15,21);
				clreol();
				cprintf("BOOKING SUCESSFULL");
				file.seekg(pos-sizeof(c));
				file.write((char*)&c,sizeof(c));
				obj.write((char*)&t,sizeof(t));
				flag = 1;
				break;
			}
			else
			{
				gotoxy(15,21);
				cprintf("CAB NOT BOOKED");
				flag=1;
				break;
			}

		}
	}
	file.close();
	obj.close();
	if(flag==0)
	{
		gotoxy(15,6);
		cprintf("NO MATCH FOUND");
		gotoxy(2,23);
		cprintf("Press Any Key To Return To Main Menu");
		gotoxy(39,23);
		getch();
		main_menu();
	}
	else
	{
		gotoxy(2,23);
		cprintf("Press Any Key To Return To Main Menu");
		gotoxy(39,23);
		getch();
		main_menu();
	}
}

//FUNCTION FOR  CANCLE A BOOKING
void cancel_cab()
{
	clrscr();
	cab c;
	highvideo();
	textmode(C40);
	setbkcolor(BLACK);
	textcolor(WHITE);
	for(temp =0; temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(15,2);
	cprintf("CANCEL BOOKING\r\n");
	for(temp=0;temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(2,24);
	for(temp =0;temp<39;temp++)
	{
		cprintf("=");
	}
	gotoxy(10,5);
	cprintf("SEARCHING FOR BOOKINGS");
	for(temp =0;temp<2;temp++)
	{
		delay(300);
		cprintf(".");
		delay(300);
	}
	long pos;
	int flag=0;
	file.open("cab.dat",ios::binary | ios::in | ios::out);
	while(file.read((char*)&c,sizeof(c)))
	{
		pos = file.tellg();
		if(strcmp(c.getstatus(),"BOOKED")==0)
		{
			gotoxy(10,5);
			clreol();
			gotoxy(15,5);
			cprintf("YOUR BOOKING FOUND");
			c.showbook();
			gotoxy(1,20);
			clreol();
			gotoxy(1,19);
			clreol();
			cprintf("CANCEL BOOKING, Press [y/y] To Confirm:");
			gotoxy(40,19);
			ch = getche();
			if(ch=='y'||ch=='Y')
			{
				gotoxy(10,20);
				clreol();
				cprintf("CANCELLING YOUR BOOKING");
				fstream obj;
				trans t;
				long pos2;
				obj.open("transactions.dat", ios::in | ios::out | ios::binary);
				while(obj.read((char*)&t,sizeof(t)))
				{
					pos2 = obj.tellg();
					if(strcmp(t.returnmodel(),c.getcabmodel())==0&&strcmp(t.returndestination(),c.getcabdestination())==0)
					{
						t.cancel();
						obj.seekg(pos2-sizeof(t));
						obj.write((char*)&t,sizeof(t));
					}
				}
				obj.close();
				for(temp =0;temp<3;temp++)
				{
					delay(300);
					cprintf(". ");
					delay(300);
				}
				c.unbook();
				file.seekg(pos-sizeof(c));
				file.write((char*)&c,sizeof(c));
				gotoxy(10,20);
				clreol();
				gotoxy(5,20);
				clreol();
				cprintf("YOUR BOOKING SUCESSFULLY CANCELLED");
			}
			else
			{
				gotoxy(10,20);
				clreol();
				cprintf("BOOKING NOT CANCELLD");
			}
			flag=1;
		}
	}
	file.close();
	if(flag==0)
	{
		gotoxy(10,5);
		clreol();
		gotoxy(5,5);
		cprintf("NO BOOKING FOUND FROM YOUR NAME");
		gotoxy(2,23);
		cprintf("Press ANY KEY To Return");
		gotoxy(26,23);
		getch();
		main_menu();
	}
	else
	{
		gotoxy(2,23);
		cprintf("Press ANY KEY To Return");
		gotoxy(26,23);
		getch();
		main_menu();
	}
}

//FUNCTION FOR ADMINISTRATOR MENU
void admin()
{
	clrscr();
	highvideo();
	textmode(C40);
	setbkcolor(BLACK);
	textcolor(WHITE);
	for(temp =0; temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(13,2);
	cprintf("ADMINISTRATOR MENU\r\n");
	for(temp=0;temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(2,24);
	for(temp =0;temp<39;temp++)
	{
		cprintf("=");
	}
	char password[10];
	gotoxy(2,8);
	if(adminflag==0)
	{
		cprintf("ENTER ADMINSTRATOR PASSWORD:");
		gets(password);
	}
	if(strcmp(password,"123456")==0||adminflag==1)
	{
		if(adminflag ==0)
		{
			gotoxy(2,10);
			adminflag=1;
			cprintf("Correct Password, Redirecting");
			for(int i=0;i<3;i++)
			{
				delay(300);
				cprintf(". ");
				delay(300);
			}
		}
		start:
		gotoxy(2,10);
		clreol();
		gotoxy(2,8);
		clreol();
		gotoxy(10,5);
		cprintf("1) ADD CABS IN DATABSE");
		gotoxy(10,8);
		cprintf("2) VIEW CAB DATABASE");
		gotoxy(10,11);
		cprintf("3) MODIFY CABS");
		gotoxy(10,14);
		cprintf("4) DELETE CABS");
		gotoxy(10,17);
		cprintf("5) VIEW ALL BOOKINGS");
		gotoxy(2,19);
		for(temp = 0; temp<39;temp++)
		{
			cprintf("=");
		}
		gotoxy(2,20);
		cprintf("INPUT YOUR CHOICE:");
		gotoxy(2,21);
		for(temp = 0;temp<39;temp++)
		{
			cprintf("=");
		}
		gotoxy(2,23);
		cprintf("Press <ESC> To Return To Main Menu");
		gotoxy(23,20);
		ch = getch();
		switch(ch)
		{

			case '1': add_cab();
				  break;
			case '2': view_cabs();
				  break;
			case '3': modify_cab();
				  break;
			case '4': delete_cab();
				  break;
			case '5': all_bookings();
				  break;
			case  27: main_menu();
				  break;
			default: textcolor(RED);
				 textbackground(WHITE);
				 gotoxy(1,20);
				 clreol();
				 cprintf("INVALID SELECTION, ENTER AGAIN");
				 textcolor(WHITE);
				 textbackground(BLACK);
				 sound(800);
				 delay(500);
				 nosound();
				 gotoxy(1,20);
				 clreol();
				 goto start;
		}
	}
	else
	{
		gotoxy(2,10);
		cprintf("INVALID PASSWORD");
		gotoxy(2,12);
		cprintf("Returning to Main Menu");
		for(int i=0;i<3;i++)
		{
			delay(300);
			cprintf(". ");
			delay(300);
		}
		main_menu();
	}
}


//FUNCTION TO ADD CABS IN CAB DATABASE - ONLY ACCESSIBLE TO ADMINISTRATOR
void add_cab()
{
	adminflag=1;
	cab c;
	clrscr();
	highvideo();
	textmode(C40);
	setbkcolor(BLACK);
	textcolor(WHITE);
	for(temp =0; temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(13,2);
	cprintf("ADD  CABS IN DB\r\n");
	for(temp=0;temp<40;temp++)
	{
		cprintf("=");
	}
	gotoxy(2,24);
	for(temp =0;temp<39;temp++)
	{
		cprintf("=");
	}
	gotoxy(2,21);
	textcolor(WHITE);
	for(temp = 0;temp<39;temp++)
	{
		cprintf("=");
	}
	textcolor(WHITE);
	gotoxy(2,22);
	cprintf("Press <ESC> to Return to ADMIN Menu\n\r");
	c.Getdata();
	gotoxy(2,14);
	cprintf("PROCESSING");
	for(temp = 0;temp<3;temp++)
	{
		delay(300);
		cprintf(". ");
		delay(300);
	}
	file.open("cab.dat", ios::binary | ios::app | ios::out);
	file.write((char*)&c,sizeof(c));
	file.close();
	gotoxy(2,14);
	clreol();
	cprintf("SAVE SUCESSFULL");
	gotoxy(2,23);
	cprintf("Press any key to ADD MORE CABS");
	gotoxy(32,23);
	ch = getch();
	if(ch == 27)
	{
		delay(500);
		admin();
	}
	else
	{
		delay(500);
		add_cab();
	}

}

//FUNCTION TO VIEW ALL CABS IN CAB DATABASE - CAN BE ACCESSED BY BOTH USER AND ADMIN
void view_cabs()
{
	cab c;
	textmode(C80);
	highvideo();
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(35,2);
	cprintf("VIEW ALL CABS\r\n");
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	cout<<setw(10)<<"| CAB NO |"<<setw(20)<<"| CAR MODEL |"<<setw(20)<<"| CAR ID NO. |"<<setw(15)<<"| CHARGE |"<<setw(14)<<"| STATUS |"<<endl;
	int flag =0;
	file.open("cab.dat", ios::binary | ios::in);
	while(file.read((char*)&c, sizeof(c)))
	{
		flag =1;
		c.ShowRowCol();
	}
	file.close();
	for(temp = 0; temp<80; temp++)
	{
		cprintf("=");
	}
	if(flag == 0)
	{
		textbackground(WHITE);
		textcolor(RED + BLINK);
		cprintf("NO CABS FOUND IN DATABASE\r\n");
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf("Press Any Key to return to Main Menu:\r\n");
		gotoxy(40,8);
		getche();
		delay(500);
	}
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(1,23);
	cprintf("Press Any to return to PREVIOUS MENU\n\r");
	for(temp = 0; temp<80;temp++)
	{
		cprintf("=");
	}
	gotoxy(36,23);
	getch();
	delay(500);
	if(adminflag == 1)
	{
		admin();
	}
	else
	{
		main_menu();
	}
}

//FUNCTION TO MODIY A CAB DETAILS IN CAB DATABASE - ONLY ACCESSIBLE TO ADMINISTRATOR
void modify_cab()
{
	adminflag=1;
	cab c;
	textmode(C80);
	highvideo();
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(35,2);
	cprintf("MODIFY CABS\r\n");
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	int tmpcno;
	gotoxy(2,4);
	cprintf("Enter CAB NO Of The Cab:");
	gotoxy(27,4);
	cin>>tmpcno;
	gotoxy(35,6);
	cprintf("Searching");
	for(temp =0;temp<3;temp++)
	{
		delay(300);
		cprintf(". ");
		delay(300);
	}
	int flag =0;
	long pos;
	file.open("cab.dat", ios::binary | ios::out | ios::in);
	int mark =0;
	while(file.read((char*)&c,sizeof(c)))
	{
		pos = file.tellg();
		if(tmpcno == c.getcno())
		{
			if(mark==1)
			{	gotoxy(25,6);
				clreol();
				cprintf("Searching for More Cabs With This CNO");
				for(int i=0;i<3;i++)
				{
					cprintf(". ");
				}
			}
			gotoxy(25,6);
			clreol();
			gotoxy(35,6);
			clreol();
			cprintf("MATCH FOUND");
			c.showmod();
			gotoxy(2,16);
			cprintf("Press [y/Y] To Modify This CAB:");
			gotoxy(33,16);
			ch=getch();
			if(ch=='y'||ch=='Y')
			{
				gotoxy(2,8);
				clreol();
				gotoxy(2,10);
				clreol();
				gotoxy(2,12);
				clreol();
				gotoxy(2,14);
				clreol();
				gotoxy(2,16);
				clreol();
				c.modify();
				file.seekg(pos-sizeof(c));
				file.write((char*)&c, sizeof(c));
				gotoxy(35,21);
				cprintf("Modifying");
				for(temp = 0;temp<3;temp++)
				{
					delay(300);
					cprintf(". ");
					delay(300);
				}
				gotoxy(35,21);
				clreol();
				cprintf("MODIFICATION SUCCESSFULL");
			}
			else
			{
				gotoxy(35,21);
				cprintf("MODIFICATION CANCELLED");
				delay(500);
				gotoxy(35,21);
				clreol();
			}
			flag=1;
			mark =1;
		}
	}
	file.close();
	if(flag == 0)
	{
		gotoxy(35,6);
		clreol();
		cprintf("NO MATCH FOUND");
		gotoxy(2,23);
		cprintf("Press Any Key To Return To Admin Menu");
		gotoxy(39,23);
		getch();
		delay(300);
		admin();
	}
	else
	{
		gotoxy(2,23);
		cprintf("Press Any Key To Return To Admin Menu");
		gotoxy(39,23);
		getch();
		delay(300);
		admin();

	}
}

//FUNCTION TO DELETE A CAB FOR CAB DATABASE - ONLY ACCESSIBLE TO ADMINISTRATOR
void delete_cab()
{
	adminflag=1;
	cab c;
	textmode(C80);
	highvideo();
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(35,2);
	cprintf("DELETE A CAB\r\n");
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	int tmpcno;
	int mark = 0;
	gotoxy(2,4);
	cprintf("Enter CAB NO Of The Cab:");
	gotoxy(27,4);
	cin>>tmpcno;
	gotoxy(35,6);
	cprintf("Searching");
	for(temp =0;temp<3;temp++)
	{
		delay(300);
		cprintf(". ");
		delay(300);
	}
	int flag =0;
	file.open("cab.dat", ios::binary | ios::in);
	ofstream tmp;
	tmp.open("temp.dat", ios::binary | ios::out | ios::app);
	while(file.read((char*)&c,sizeof(c)))
	{
		if(mark ==1)
		{
			gotoxy(25,6);
			cprintf("SEARCHING FOR MORE CABS WITH THIS CAB NO");
			for(temp = 0;temp<3;temp++)
			{
				delay(300);
				cprintf(". ");
				delay(300);
			}
			mark=0;
		}
		if(tmpcno == c.getcno())
		{
			gotoxy(25,6);
			clreol();
			gotoxy(35,6);
			clreol();
			cprintf("MATCH FOUND");
			c.Showdata();
			gotoxy(30,20);
			clreol();
			gotoxy(2,18);
			clreol();
			gotoxy(2,18);
			cprintf("ARE YOU SURE YOU WANT TO DELETE THIS CAB, Press <Y/y> To Confirm:");
			gotoxy(67,18);
			ch = getch();
			if(ch=='Y' || ch=='y')
			{
				gotoxy(30,20);
				cprintf("DELETING RECORD FROM DB");
				for(temp = 0;temp<3;temp++)
				{
					delay(300);
					cprintf(". ");
					delay(300);
				}
				gotoxy(30,20);
				clreol();
				cprintf("SUCESSFULLY DELETED");
				mark=1;
			}
			else
			{
				tmp.write((char*)&c,sizeof(c));
				mark=1;
			}
			flag =1;
		}
		else
		{
			tmp.write((char*)&c,sizeof(c));
		}
	}
	file.close();
	tmp.close();
	remove("cab.dat");
	rename("temp.dat","cab.dat");
	if(flag == 0)
	{
		gotoxy(1,6);
		clreol();
		gotoxy(35,6);
		clreol();
		cprintf("NO MATCH FOUND");
		gotoxy(2,23);
		cprintf("Press Any Key To Return To Admin Menu");
		gotoxy(39,23);
		getch();
		delay(300);
		admin();
	}
	else
	{
		gotoxy(2,23);
		cprintf("Press Any Key To Return To Admin Menu");
		gotoxy(39,23);
		getch();
		delay(300);
		admin();

	}
}

//FUNCTION TO VIEW LIST OF ALL BOOKED CABS
void all_bookings()
{
	cab c;
	textmode(C80);
	highvideo();
	adminflag=1;
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(35,2);
	cprintf("VIEW ALL BOOKINGS\r\n");
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	cout<<setw(10)<<"CAB NO |"<<setw(15)<<"SOURCE |"<<setw(15)<<"DESTINATION |"<<setw(10)<<"COST |"<<setw(15)<<"Distance |"<<endl;
	int flag =0;
	file.open("cab.dat", ios::binary | ios::in);
	while(file.read((char*)&c, sizeof(c)))
	{
		if(strcmp(c.getstatus(),"BOOKED")==0)
		{
			c.showbookings();
			flag =1;
		}
	}
	file.close();
	for(temp = 0; temp<80; temp++)
	{
		cprintf("=");
	}
	if(flag == 0)
	{
		textbackground(WHITE);
		textcolor(RED + BLINK);
		cprintf("NO BOOKINGS FOUND IN DATABASE\r\n");
		textcolor(WHITE);
		textbackground(BLACK);
		cprintf("Press Any Key to return to Administrator Menu:\r\n");
		gotoxy(40,7);
		getche();
		delay(500);
		admin();
	}
	for(temp =0; temp<80; temp++)
	{
		cprintf("=");
	}
	gotoxy(1,23);
	cprintf("Press Any to return to ADMIN MENU\n\r");
	for(temp = 0; temp<80;temp++)
	{
		cprintf("=");
	}
	gotoxy(36,23);
	getch();
	delay(500);
	admin();
}
