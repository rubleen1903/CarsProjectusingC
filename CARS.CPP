//Cars impo and expo



#include<fstream>

#include<conio.h>

#include<graphics>

#include<string.h>

#include<stdio.h>

#include<dos.h>

#include<stdlib.h>

#include<iomanip.h>

class carsimpo

{

  char model[50];

  char place[50];

  long prc;

  char colour[50];

  int num;

  public:

  void display();

  void input();

  void output();

  int bussines(char[],int);

  int return_num()

  {  return num;}

  char* ret_mod()

  {  return model; }

  char* ret_place()

  { return place; }

};

class carsexpo

{ char model[50];

  char place[50];

  long prc;

  char colour[50];

  int num;

  public:

  void input();

  void output();

  char* ret_mod()

 { return model; }

 char* ret_place()

 { return place; }

};

int carsimpo::bussines(char mod[50],int n)

{ int flag=0;

   char pl[50];

  if(strcmpi(mod,model)==0)

  {

    if(n<=num)

    {  flag=1;

       num-=n;

       cout<<"\n Yes the car is available for export";

       cout<<"\n Enter the place of delivery= ";

       gets(pl); //stdio.h

       cout<<"\n Cost you need to pay= "<<prc*n;

       cout<<"\n Your delivery will be done by 3 days at "<<pl;

    }

    else cout<<"\n Sorry....We have only "<<num<<" "<<mod;

    if(num==0)

    flag=-1;

  }



 return flag;

}

void carsimpo::input()

{ clrscr();

  cout<<"\n Enter the model= ";

  gets(model);    //stdio.h

  cout<<"\n Enter the place from where it is imported =";

  gets(place);

  cout<<"\n Enter the price of the car= ";

  cin>>prc;

  cout<<"\n  Enter the colour of the car= ";

  gets(colour);

  cout<<"\n Enter the number of "<<model<<" imported= ";

  cin>>num;

}

void carsexpo::input()

{ clrscr();

  cout<<"\nEnter the model= ";

  gets(model);      //stdio.h

  cout<<"\nEnter the place to where it is exported= ";

  gets(place);

  cout<<"\nEnter the price of the car= ";

  cin>>prc;

  cout<<"\nEnter the colour of the car= ";

  gets(colour);

  cout<<"\nEnter number of "<<model<<" exported= ";

  cin>>num;

}

void carsimpo::output()

{ clrscr();

  cout<<"\n Model is= "<<model;

   cout<<"\n Price is= "<<prc;

   cout<<"\n Colour is= "<<colour;

   cout<<"\n Place from where it is imported= "<<place;

   cout<<"\nTotal number of "<<model<<" ="<<num;

}

void carsexpo::output()

{  clrscr();

   cout<<"\n Model is= "<<model;

   cout<<"\n Price is= "<<prc;

   cout<<"\n Colour is= "<<colour;

   cout<<"\n Place to where it is exported= "<<place;

   cout<<"\nTotal number of "<<model<<" ="<<num;

}



void carsimpo::display()

{ textcolor(6);  //conio.h

  cout<<"\n______________________________________________________________________\n";

  cout.setf(ios::left);cout<<setw(10); //iomanip

  cprintf("\nMODEL = ");cout<<model;cout.setf(ios::left);cout<<setw(10);  //conio.h

  cprintf("PRICE = ");cout<<prc; cout.setf(ios::left);cout<<setw(10);

  cprintf("COLOR = ");cout<<colour; cout.setf(ios::left);cout<<setw(10);

  cprintf(" NO.OF CARS = ");cout<<num;

  cout<<"\n______________________________________________________________________";

}

void Deli()

{ ifstream ifile("impo.dat",ios::binary);

  ofstream ofile("temp.dat",ios::binary);

  char ch; carsimpo ci;

  int size=sizeof(ci);

  if(!ifile)

  cout<<"\nNo data is found...";

 else

 {

  while(ifile.read((char*)&ci,size))

  { cout<<"\nModel of the car= "<<ci.ret_mod();

    cout<<"\nImported from= "<<ci.ret_place();

    cout<<"\nDo you want to delete this model(y/n)= ";

    cin>>ch;

    if(ch=='n'||ch=='N')

    ofile.write((char*)&ci,size);

    else

    cout<<"\nRecord is deleted...";

  }

 }

  ifile.close();

  ofile.close();

  remove("impo.dat");     //stdio.h

  rename("temp.dat","impo.dat");   //stdio

  getch();

}

void dele()

{ ifstream ifile("expo.dat",ios::binary);

  ofstream ofile("temp.dat",ios::binary);

  char ch;

  carsexpo ci;

  int size=sizeof(ci);

  if(!ifile)

  cout<<"\nNo data is found....";

 {

  while(ifile.read((char*)&ci,size))

  { cout<<"\n Model of the car = "<<ci.ret_mod();

    cout<<"\nExported to= "<<ci.ret_place();

   cout<<"\n Do you want to delete this model (y/n) = ";

   cin>>ch;

   if(ch=='n'||ch=='N')

   ofile.write((char*)&ci,size);

   else

   cout<<"\n Record is deleted ....";

  }

 }

  ifile.close();

  ofile.close();

  remove("expo.dat");  //stdio.h

  rename("temp.dat","expo.dat");  //stdio.h

  getch();   //conio.h

}



void main()

{

  clrscr();

   void graph();

   void init();

  graph();

  carsimpo CI;

  carsexpo CE;

  ofstream ofile;

  ofstream sfile;

  ifstream ifile;

  int ch,sizei,sizee;

  sizei=sizeof(CI);

  sizee=sizeof(CE);

  char ans;

  do

  { clrscr();

   textcolor(6);

    cprintf("\n             MAIN MENU          ");cout<<endl;

    textcolor(4);

    cprintf("\n 1. To add the details of imported cars");cout<<endl;

    cprintf("\n 2. To add the details of exported cars");cout<<endl;

    cprintf("\n 3. To purchase cars");cout<<endl;

    cprintf("\n 4. To show the details of all imported cars");cout<<endl;

    cprintf("\n 5. To show the details of all exported cars");cout<<endl;

    cprintf("\n 6. To delete the details of an imported car");cout<<endl;

    cprintf("\n 7. To delete the details of an exported car");cout<<endl;

    cprintf("\n 8. Exit");cout<<endl;

    cout<<"\n    Enter your choice (1-8) = ";

  cin>>ch;

  switch(ch)

      {

	case 1:clrscr();

	       char ans='y';

		sfile.open("showcars",ios::binary|ios::app);

		ofile.open("impo.dat",ios::binary|ios::app);

	       while(ans=='y'||ans=='Y')

	       { CI.input();

		 ofile.write((char*)&CI,sizei);

		 sfile.write((char*)&CI,sizei);

		 cout<<"\nDo you want to enter more(y/n)= ";

		 cin>>ans;

	       }sfile.close();

	       ofile.close();

	       break;

	case 2:clrscr();

		ans='y';

		ofile.open("expo.dat",ios::binary|ios::app);

	       while(ans=='y'||ans=='Y')

	       { CE.input();

		 ofile.write((char*)&CE,sizee);

		 cout<<"\nDo you want to enter more(y/n)= ";

		 cin>>ans;

	       } ofile.close();

	       break;

	case 3: clrscr();

		char mod[50];

		int n,count=0;

		ifile.open("showcars",ios::binary);

		ofile.open("temp.dat",ios::binary);

		if(!ifile)

		cout<<"\nNo data is found....";

		else

	     {

		while(ifile.read((char*)&CI,sizei))

		{ CI.display();

		  count++;

		}

		if(count==0)

		cout<<"\n\n\n\nNo car is available...";

		else

	       { ifile.close();

		ifile.open("showcars",ios::binary);

		cout<<"\nEnter the model of the car to be exported= ";

		gets(mod);      //stdio.h

		cout<<"\nHow many "<<mod<<" do you want to export= ";

		cin>>n;

		if(n==0)

		cout<<"\n Wrong Input";

		else

	      { int flag,found=0;

		while(ifile.read((char*)&CI,sizei))

		{ flag=CI.bussines(mod,n);

		  if(flag!=-1)

		  ofile.write((char*)&CI,sizei);

		  if((flag==1)||(CI.return_num()==0))

		  found=1;

		}

		 if(found==0)

		 cout<<"\nRequired car is not available...";

		 ofile.close();

		 ifile.close();

		 remove("showcars");     //stdio.h

		 rename("temp.dat","showcars");   //stdio.h

	       }

	      }

	     }

	     ofile.close();

	     ifile.close();

	     break;

	case 4:clrscr();

		ifile.open("impo.dat",ios::binary);

		if(!ifile)

		cout<<"\nNo data is found...";

		else

	      { cout<<"\nDetails of all imported cars...";

		while(ifile.read((char*)&CI,sizei))

		{ CI.output();

		  getch(); clrscr();

		}



	      }	ifile.close();



		break;

	case 5: clrscr();

		ifile.open("expo.dat",ios::binary);

		if(!ifile)

		cout<<"\nNo data is found...";

		else

	      { cout<<"\nDetails of all exported cars....";

		while(ifile.read((char*)&CE,sizee))

		{ CE.output();

		  getch(); clrscr();

		}

	      }	ifile.close();

		break;

	case 6: Deli();

		break;

	case 7: dele();

		break;

	case 8: init();

		 break;

	default: cout<<"\nWrong choice";

      } getch();

    }while(ch!=9);

}



void graph()

{

    int count=50;

    clrscr();

    cprintf("\n\n\n\n");

    while(count--)

    {

	sound(10*random(100));  //dos.h for sound and stdlib for random

	delay(75);              //dos.h

	nosound();              //dos.h

	textattr(random(16));   //conio.h

	cprintf(" SALE ");

	cprintf("\n");

    }

    clrscr();

    textcolor(6);   //conio.h

    cprintf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t WELCOME TO THE CAR SHOWROOM \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

    getch();

}

void init()

{ clrscr();

   int gd=DETECT,gm,x,y;

   initgraph(&gd,&gm,"c:\\turboc3\\bgi");     //Initializing Graphics Mode

   setbkcolor(BLUE); //using graphics.h

   setcolor(WHITE);  //using graphics.h

   settextstyle(5,HORIZ_DIR,3); // uisng graphics.h

   outtextxy(160,180,"!!  THANK YOU   !!");        //using graphics.h

   outtextxy(120,280," Press any key to EXIT");    //using graphics.h

  getch();

}

































