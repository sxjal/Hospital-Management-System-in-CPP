#include	<conio.h>
#include	<ctype.h>
#include	  <dos.h>
#include      <fstream.h>
#include	<stdio.h>
#include       <stdlib.h>
#include       <string.h>


ofstream a1,a2,a3;
ifstream b1,b2,b3;
int eof();

class HOSPITAL
{
	//int variables
	private:

	int flag_lt	;
	int age		;
	int stay_days	;
	int med_qty[10]	;

	//float variables
	float cons_charge	    ;
	float pt_stay_price	    ;
	float tpc_labtest	    ;
	float amount_med	    ;
	float total_med		    ;
	float total_bill	    ;
	float disc_amt		    ;
	float final_bill	    ;
	float pc_labtest[10]	    ;
	float individual_price[10]  ;

	//character variables
	char md_pmt		;
	char gender		;
	char phone[10]		;
	char pt_room[10]	;
	char dept[20]		;
	char name[20]		;
	char dname[30]		;
	char address[50]	;
	char nm_labtest[10][20]	;
	char med[10][20] 	;


//public Members
public:

//Constructor

HOSPITAL()
{
	//int members
	flag_lt	  = 0 	;
	age       = 0	;
	stay_days = 1	;

	//float members
	cons_charge      = 0  ;
	pt_stay_price    = 0  ;
	tpc_labtest      = 0  ;
	amount_med       = 0  ;
	total_med	 = 0  ;
	total_bill	 = 0  ;
	disc_amt	 = 0  ;
	final_bill	 = 0  ;

	//character members
	md_pmt = '\0'	;
	gender = '\0'	;

	//Loops
	for(int i = 0 ; i < 10 ; i++)
	{
		med_qty[i]	    =   0  ;
		pc_labtest[i]	    =   0  ;
		individual_price[i] =   0  ;
		phone[i]	    = '\0' ;
		pt_room[i]          = '\0' ;

		for(int j = 0 ; j < 20 ; j++)
		{
			nm_labtest[i][j] = '\0'	;
			med[i][j] = '\0'	;
		}//end of j loop
	}//end of i loop

	for(i = 0 ; i < 50 ; i++)
	{
		if(i < 20)
		{
			dept[i] = '\0' ;
			name[i] = '\0' ;
		}

		if(i < 30)
		{
			dname[i] = '\0';
		}

		address[i] = '\0'      ;
	}//end of i loop

}//end of constructor

void output()
{
	cout<<endl<<endl;
	cout<<"\n----------------------------------------------------------------|";
	for(int i=0;i<amount_med;i++)
	{
		cout<<"\n\n| MEDICINE "<<i+1<<" IS "<<med[i]<<" & ITS PRICE IS "<<individual_price[i];

	}

	cout<<"\n\n| TOTAL PRICE IS "<<total_med<<"------------------------------|";
	cout<<endl<<endl;

	cout<<"|-----------------------------------------------------------------|";
}

void output2()
{
	cout<<"\n----------------------------------------------------------------------------";
	cout<<"\n| PATIENT NAME - "<<name<<"                                                |";
	cout<<"\n| ADDRESS - "<<address<<"														        	|";
	cout<<"\n| GENDER - "<<gender<<"															      	|";
	cout<<"\n| PHONE - "<<phone<<" 															      	|";
	cout<<"\n---------------------------------------------------------------------------|";
}

void pt_info();
void room();
void print_bill();
void MEDICINE(int ch1);
void LABTEST(int ch1);
void total_bill_calc();
void md_payment();
void ip(int records, int choice);
void doc_details(int records);
void dept_list(int records,char (&dep)[60][20],int &departments);
void find_doc(char dep[60][20],int choice,int records);
void add_doc(int &records);
void del_doc(int &records,int choice);
void op();

};//end of class

// :: SCOPE RESOLUTION

void HOSPITAL :: room()
{

	char rooms[4][20] = {
				{"General Ward"},
				{"Semi Private"},
				{"Private"},
				{"Delux"}
			    };

	int price_rooms[4] = {500,1000,2000,5000};
	int ch = 0;

while(1)
{
	cout<<"\n* PATIENT ADMISSION *";
	cout<<"\n Available Rooms " ;

	for(int i = 0 ; i < 4 ; i++)
	{
		cout<<i+1<<"."<<rooms[i]<<endl;
	}

	cin>>ch;

	if(ch >= 1 && ch <=4)
	{
		break;
	}
	else
	{
		cout<<endl<<"Invalid input. Enter Again.";
		continue;
	}
}//end of while loop

	cout<<"\n Enter No of days stayed : ";
	cin>>stay_days;

ch += 1;

	strcpy(pt_room,rooms[ch]);
	pt_stay_price = price_rooms[ch];
	pt_stay_price *= stay_days;
}//end of function room

void HOSPITAL :: pt_info()
{

	cout<<"\n ENTER PATIENT NAME - ";
	fflush(stdin);
	gets(name);

	cout<<"\n ENTER PATIENT AGE - ";
	cin>>age;

	while(1)
	{
		cout<<"\n ENTER PATIENT GENDER ('F' FOR FEMAL,'M' FOR MALE & 'T' FOR TRANSGENDER)- ";
		cin>>gender;

		if( gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f')
		{
			break;
		}
		else
		{
			cout<<"\n Invalid Gender.";
			cout<<"\n Enter Again.";
		}
	}
	cout<<"\n ENTER PATIENT ADDRESS - ";
	fflush(stdin);
	gets(address);

	cout<<"\n PHONE NO - ";
	fflush(stdin);
	gets(phone);

}// end of fucntion pt_info

void HOSPITAL :: LABTEST(int ch1)
{
flag_lt = 0l;
if(ch1 == 2)
{
	flag_lt = -1;
}
else
{
	tpc_labtest = 0;
	int n = 0;
	int sl_lt = 0;
	int pc_avail_labtest[5] = {{100},
				   {200},
				   {150},
				   {250},
				   {300}
				  };
	int i = 0;
	char avail_labtest[5][15] = {
					{"Blood Test"},
					{"Endoscopy"},
					{"MRI"},
					{"ECG"},
					{"X-Ray"}
				    };
	int choice = 0;
	cout<<"\n Enter No.of test(s) to be done : ";
	cin>>n;

for( i = 0 ; i < n ; i++)
{
	cout<<"\n\t     *----- Available test's -----*";
	cout<<"\n\t|  NAME |  price |";
	for(int a = 0 ; a < 5 ; a++)
	{
		cout<<"\n\t| "<<a+1<<"."<<avail_labtest[a]<<"   |   "<<pc_avail_labtest[a]<<"  |";
	}

	cout<<"\n Enter test's code : ";
	cin>>choice;

	if(choice >= 1 && choice <= 5)
	{
		sl_lt = choice - 1;
		strcpy(nm_labtest[i],avail_labtest[sl_lt]);
		pc_labtest[i] = pc_avail_labtest[sl_lt];
		tpc_labtest = tpc_labtest + pc_avail_labtest[sl_lt];
		i++;
		break;
	}
	else
	{
		 cout<<"\n Invalid code, Enter again." ;
		 continue;
	}
} // end of do while loop
}//end of else

}// End of function LABTEST

void HOSPITAL :: total_bill_calc()
{
	total_bill = tpc_labtest + (cons_charge * stay_days) + total_med + pt_stay_price;

}// end of function total_bill_calc

void HOSPITAL :: print_bill()
{
	cout<<"\n TOTAL : "<<total_bill;
	cout<<"\n DISC  : "<<disc_amt;
	cout<<"\n FINAL : "<<final_bill;

}//end of function

void HOSPITAL :: md_payment()
{
	while(1)
	{
		cout<<"\n Please enter the mode of payment. " ;
		cout<<"\n Press 'c' for Cash payment or else press 'd' for card payment.";
		cin>>md_pmt;

		if(md_pmt == 'c' || md_pmt == 'C')
		{
			disc_amt   = 7.5 * total_bill / 100;
			final_bill = total_bill - disc_amt ;
			break;
		}
		if(md_pmt == 'd' || md_pmt == 'D')
		{
			disc_amt   = 0.0;
			final_bill = total_bill - disc_amt ;
			break;
		}
		else
		{
			 cout<<"\n Invalid input please enter again.";
			 continue;
		}
	}// End of while loop

       /*	cout<<"\n Total bill amout  : "<<total_bill;
	cout<<"\n Discount given : "<<disc_amt;
	cout<<"\n Finall bill : "<<final_bill;
	 */
}// End of function md_payment

void HOSPITAL :: MEDICINE(int ch1)
{

if( ch1 == 1)
{	cout<<"\n ENTER HOW MANY MEDICINES - ";
	cin>>amount_med;

	for(int q = 0 ; q < amount_med ; q++)
	{
		cout<<"\n\n ENTER NAME OF MEDICINE "<<q+1<<":";
		fflush(stdin);
		gets(med[q]);

		cout<<"\n  ENTER ITS PRICE - ";
		cin>>individual_price[q];

		cout<<"\n ENTER QUANTITY - ";
		cin>>med_qty[q];

		total_med += individual_price[q] * med_qty[q];

	}
}//end of if

}//end of fucntion MEDICINE

void HOSPITAL::doc_details(int records)
{
	for(int i=0;i<records;i++)
	{
		b1.getline(dname,30);
		b2.getline(dept,20);
		b3>>cons_charge;
		cout<<"\n\n"<<i+1<<". Doctor: "<<dname;
		cout<<"\n   Department: "<<dept;
		cout<<"\n   Consultation charge: "<<cons_charge;
	}
}

void HOSPITAL::dept_list(int records,char (&dep)[60][20], int &departments)
{
	departments=0;
	for(int i=0;i<records;i++)
	{
		b2.getline(dept,20);
		int found=0;
		for(int j=0;j<departments;j++)
		{
			if(strcmpi(dept,dep[j])==0)
			{
				found=1;
			}
		}
		if(found==0)
		{
			cout<<endl<<departments+1<<". "<<dept;
			strcpy(dep[departments],dept);
			departments++;
		}
	 }
}

void HOSPITAL::find_doc(char dep[60][20],int choice, int records)
{
	char ch[20];
	int n=1;
	strcpy(ch,dep[choice-1]);
	for(int i=0;i<records;i++)
	{
		b1.getline(dname,30);
		b2.getline(dept,20);
		b3>>cons_charge;
		if(strcmpi(dept,ch)==0)
		{
			cout<<"\n\n"<<n<<". Doctor: "<<dname;
			cout<<"\n   Consultation charge: "<<cons_charge;
			n++;
		}
	}
}

void HOSPITAL::add_doc(int &records)
{
	char name[30],dep[20];
	int choice,found=0;
	cout<<"\nEnter Doctor's Name: ";
	fflush(stdin);
	gets(dname);
	cout<<"Enter Department: ";
	fflush(stdin);
	gets(dept);
	cout<<"Enter Consultation Charge: ";
	cin>>cons_charge;
	b1.seekg(0);
	b2.seekg(0);
	for(int j=0;j<records;j++)
	{
		b1.getline(name,30);
		b2.getline(dep,20);
		if((strcmpi(dname,name)==0) && (strcmpi(dept,dep)==0))
		{
			found=1;
		}
	}
	if(found==1)
	{
		cout<<"\nDoctor with same name already exists in the department.\nDo you still want to addnew record?\n(Enter 1 if yes and 2 if no): ";
		for(;;)
		{
			cin>>choice;
			if((choice==1) || (choice==2))
			break;
			else
			cout<<"\nInvalid choice. Enter input again: ";
		}
	}
	if((found==0) || ((found==1) && (choice==1)))
	{
		a1<<dname<<endl;
		a2<<dept<<endl;
		a3<<cons_charge<<endl;
		records++;
		cout<<"\nThe record has been added";
	}
}

void HOSPITAL::del_doc(int &records,int choice)
{
	for(int i=0;i<records;i++)
	{
		b1.getline(dname,30);
		b2.getline(dept,20);
		b3>>cons_charge;
		if((i+1)!=choice)
		{
			a1<<dname<<endl;
			a2<<dept<<endl;
			a3<<cons_charge<<endl;
		}
	}
	records--;
}

void HOSPITAL::ip(int records, int choice)
{
	for(int i=0;i<records;i++)
	{
		b1.getline(dname,30);
		b2.getline(dept,20);
		b3>>cons_charge;
		if((i+1)==choice)
		{
			break;
		}
	}
}

void HOSPITAL::op()
{
	cout<<"\nDoctor: "<<dname;
	cout<<"\nDepartment: "<<dept;
	cout<<"\nConsultation Charge: "<<cons_charge;
}
// end of class member functions

//Fucntions
int labtest_required(int ch1)
{
	while(1)
	{
		cout<<"\n LABTEST required?";
		cout<<"\n Enter 1 - yes, 2 -No.";
		cout<<"\n Choice : ";
		cin>>ch1;

		if(ch1 >= 1 && ch1 <= 2) break;
		else
		{
			cout<<"\n Invalid Input.";
			continue;
		}
	}// end of while
	return ch1;
}//end of function

int med_required(int ch1)
{
	while(1)
	{
		cout<<"\n Medicines required?";
		cout<<"\n Enter 1 - yes, 2 -No.";
		cout<<"\n Choice : ";
		cin>>ch1;

		if(ch1 >= 1 && ch1 <= 2) break;
		else
		{
			cout<<"\n Invalid Input.";
			continue;
		}
	}// end of while
	return ch1;
}//end of function

void line_prt()
{
	int dlay = 25;

	delay(dlay);
	cout<<"\n\t\t\t|------------------------------|";
	delay(dlay);
}

void print()
{

	int i = 0, j = 0 ;
	int p =1;
	char bar[50] = {"|||||||||||||||||||||||||"};
	int z = 0;
	for( i ; i < 25 ; i++,p += 4.5 )
	{
		clrscr();
		/*	z += 4.5;
		p = z;  */
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"\n\t\t\t\t CVJ  HOSPITAL " ;
		cout<<"\n\t\t\t\t  LOADING "<<p<<"%";
		cout<<"\n\t\t\t |------------------------|"<<endl;
		cout<<"\t\t\t |";
		for(j = 0; j<i ; j++)
		{
			cout<<bar[j];
			delay(5);
		}
		cout<<endl;

	}
	cout<<"|";

	clrscr();

	cout<<endl<<endl;
	cout<<"\n\n\n\t\t\t           CVS HOSPITAL	\t";
	delay(25);
	cout<<"\n\t\t\t*------------------------------*";
	delay(25);
	cout<<endl<<"\t\t\t|\t     MENU    	       |";

	cout<<"\n\t\t\t|1.|	OPD		       |";
	line_prt();

	cout<<"\n\t\t\t|2.|	PATIENT ADMISSION      |";
	line_prt();
	cout<<"\n\t\t\t|3.|	LAB-TEST	       |";
	line_prt();
	cout<<"\n\t\t\t|4.|	MEDICINE	       |";
	 line_prt();
	cout<<"\n\t\t\t|5.|	DOCTOR MANAGEMENT      |";
	line_prt();
	cout<<"\n\t\t\t|6.|	EXIT.		       |";
	line_prt();
	cout<<"\n\t\t\t|SELECT = ";
}//print function ends
//main fucntion starts

void main()
{
	clrscr();
	HOSPITAL h;
	char line[30],dept_list[60][20];
	b1.open("doc.txt",ios::in);
	int records=0,departments;
	while(!b1.eof())
	{
		b1.getline(line,30);
		records++;
	}
	records--;
	b1.close();

for(;;)
{
	int select;
	int ch;

while(1)
{       print();
	cin>>select;
	if(select >= 1	&& select <= 6)
		break;
	else
	{
		getch();
		cout<<"\n Invalid Input.";
		continue;
	}
}//end of while

switch(select)
{

case 1 :
	cout<<"\n\t\t* OPD DEPARTMENT * " ;
	int ch1;

	clrscr();

	h.pt_info();//pt details

	clrscr();

	b1.open("doc.txt",ios::in);
	b2.open("dept.txt",ios::in);
	b3.open("charge.txt",ios::in);

while(1)
{
	h.doc_details(records);

	b1.seekg(0);
	b2.seekg(0);
	b3.seekg(0);

	cout<<"\nEnter your choice: ";
	cin>>ch1;

	getch();

	if(ch1 >=1 && ch1 <= records)
			break;
	else
	{
		cout<<"\n Invalid Input Enter Again";
		continue;
	}
}//end of while

	h.ip(records,ch1);

	b1.close();
	b2.close();
	b3.close();

	clrscr();

	ch1 = labtest_required(ch1);
	if( ch1 == 1)
	{
		h.LABTEST(ch1);
	}

	ch1 = med_required(ch1);

	if( ch1 == 1)
	{
		h.MEDICINE(ch1);
	}

	h.total_bill_calc();// put variables in that

	h.md_payment();

	delay(100);
	h.print_bill();
	//getch();


	break;//end of case 1

case 2 :
	clrscr();
	cout<<"\n*\t\t PATIENT ADMISSION \t\t*" ;

	h.pt_info();//patient details

	clrscr();

	cout<<"\n Please select the type of room . " ;
	h.room();

	clrscr();

	int choice;

	b1.open("doc.txt",ios::in);
	b2.open("dept.txt",ios::in);
	b3.open("charge.txt",ios::in);

	clrscr();

	h.doc_details(records);

	b1.seekg(0);
	b2.seekg(0);
	b3.seekg(0);

	cout<<"\nEnter your choice: ";
	cin>>choice;

	h.ip(records,choice);

	b1.close();
	b2.close();
	b3.close();

	clrscr();

	ch1 = labtest_required(ch1);

	if(ch1 == 1)
	{
		h.LABTEST(ch1);
	}

	clrscr();

	ch1 = med_required(ch1);

	if( ch1 == 1)
	{
		h.MEDICINE(ch1);
	}

	clrscr();

	h.total_bill_calc();

	h.md_payment();

	h.print_bill();
	getch();
	break;

case 3 :
	clrscr();

	ch1 = 1;

	h.LABTEST(ch1);

	h.print_bill();
	break;

case 4 :
	clrscr();
	ch1 = 1;

	h.MEDICINE(ch1);

	h.print_bill();
	break;

case 5 :

	int ch_doc = 0 ;
while(1)
{
	clrscr();

	cout<<"\n DOCTORs MANAGEMENT " ;
	cout<<"\n MENU ";
	cout<<"\n1. Display details of doctors in a particular department";
	cout<<"\n2. Display list of departments";
	cout<<"\n3. Add a doctor to the list";
	cout<<"\n4. Delete a doctor from the list";
	cin>>ch_doc;

	if(ch_doc>= 1 && ch <= 4)
	{
		break;
	}
	else
	{
		cout<<"\n Invalid Input. " ;
		cout<<"\n Enter again. ";
		continue;
	}
}//end of while

switch(ch_doc)
{

case 1 :
	clrscr();
	int choice;

	b2.open("dept.txt",ios::in);
	b2.seekg(0);

	h.dept_list(records,dept_list,departments);

	for(;;)
	{
		cout<<"\nEnter your choice: ";
		cin>>choice;

		if(choice>=1 && choice<=departments) break;
		else
		{
			cout<<"\nInvalid choice";
			continue;
		}
	}
	clrscr();

	b1.open("doc.txt",ios::in);
	b2.seekg(0);
	b3.open("charge.txt",ios::in);

	h.find_doc(dept_list,choice,records);

	b1.close();
	b2.close();
	b3.close();

	break;

case 2 :
	clrscr();

	b2.open("dept.txt",ios::in);
	b2.seekg(0);

	h.dept_list(records,dept_list,departments);

	b2.close();
	break;
case 3:
	clrscr();

	a1.open("doc.txt",ios::app);
	a2.open("dept.txt",ios::app);
	a3.open("charge.txt",ios::app);

	b1.open("doc.txt",ios::in);
	b2.open("dept.txt",ios::in);

	h.add_doc(records);

	b1.close();
	b2.close();

	a1.close();
	a2.close();
	a3.close();

	break;

case 4:
	clrscr();

	choice = 0 ;

	b1.open("doc.txt",ios::in);
	b2.open("dept.txt",ios::in);
	b3.open("charge.txt",ios::in);

	h.doc_details(records);

	b1.seekg(0);;
	b2.seekg(0);
	b3.seekg(0);

	a1.open("temp1.txt",ios::out);
	a2.open("temp2.txt",ios::out);
	a3.open("temp3.txt",ios::out);

	for(;;)
	{
		cout<<"\nEnter the record number to be deleted: ";
		cin>>choice;

		if(choice>=1 && choice<=records) break;
		else
		cout<<"\nInvalid choice";
	}

	b2.seekg(0);

	h.del_doc(records,choice);

	cout<<"\nThe record has been deleted";

	a1.close();
	a2.close();
	a3.close();

	b1.close();
	b2.close();
	b3.close();

	remove("doc.txt");
	remove("dept.txt");
	remove("charge.txt");
	rename("temp1.txt","doc.txt");
	rename("temp2.txt","dept.txt");
	rename("temp3.txt","charge.txt");

	break;

}//end of switch
break;//end of case 5.

case 6 : exit(0);

}//end of main switch
getch();
}//end of infinite loop
getch();
}//end of program