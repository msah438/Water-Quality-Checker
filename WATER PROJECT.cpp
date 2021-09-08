#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

class water
{
protected:
char name[30],date[30];
int ph;
int hardness;
int cl;

public:

void get()
{

cout<<endl;
cout<<endl;

cout<<"   --- MUNICIPAL CORPORATION JALANDHAR ----  "<<endl;
cout<<endl;
 cout<<" ---- WATER QUALITY CHECKER ----\n\n";

cout<<" Enter Name of Place"<<endl;
cin>>name;

cout<<" Enter PH value of water(0-14)"<<endl;
cin>>ph;

cout<<" Enter the date of the sample: "<<endl;
cin>>date;
}
void display()
{

    cout<<" PLACE:"<<name<<endl;

    cout<<" DATE OF SAMPLE:"<<date<<endl;

}





};
class abc : public water
{
public:

    void get()
    {


cout<<" Enter Amount of calcium carbonate(CACO3)[0-450]"<<endl;
cin>>hardness;

cout<<" Enter amount of chlorine(0-10)"<<endl;
cin>>cl;
}
};
class calculation : public abc
{
public:

    void calcl()
{
    if(cl>=0 && cl<4)
    {
        cout<<" NO CHLORINE"<<endl;
    }
    if(cl=4)
    {
        cout<<" PURIFIED WITH CHLORINE"<<endl;
    }
if(cl>4 && cl<=10)
    {
        cout<<" NO CHLORINE"<<endl;
    }
}
void calph()
{

    if(ph>=0&& ph <=1)
    {
        cout<<" WATER IS OF BATTERY ACID TYPE"<<endl;
    }

     if(ph>1 && ph <=3)
    {
        cout<<" WATER IS OF LEMON JUICE TYPE"<<endl;
    }
     if(ph>3 && ph <=4)
    {
        cout<<" WATER IS OF WINE TYPE"<<endl;
    }
     if(ph>4 && ph <=6)
    {
        cout<<" WATER IS OF NORMAL RAIN TYPE"<<endl;
    }
     if(ph>6 && ph <=8)
    {
        cout<<" WATER IS PURIFIED"<<endl;
    }
     if(ph>8 && ph <=9)
    {
        cout<<" WATER IS OF BAKING SODA TYPE"<<endl;
    }
     if(ph>9 && ph <=10)
    {
        cout<<" WATER IS OF SOFT SOAP TYPE"<<endl;
    }
     if(ph>10 && ph <=12)
    {
        cout<<" WATER IS OF AMMONIA TYPE"<<endl;
    }
     if(ph>12 && ph <=14)
    {
        cout<<" WATER IS OF LYE TYPE"<<endl;
    }
    cout<<endl<<"------------------------------------------------------------------"<<endl;
cout<<endl;
}

void calhar()
{
    if(hardness>=0 && hardness <=43)
    {
        cout<<" WATER IS SOFT"<<endl;
    }
    if(hardness>43 && hardness <=150)
    {
        cout<<" WATER IS SLIGHTLY HARD"<<endl;
    }
    if(hardness>150 && hardness <=300)
    {
        cout<<" WATER IS MODERATELY HARD"<<endl;
    }
    if(hardness>300 && hardness <=450)
    {
        cout<<" WATER IS HARD"<<endl;
    }
    if(hardness>450)
    {
        cout<<" WATER IS VERY HARD"<<endl;
    }
}


};
main()

{


calculation c[5];
int i;
int choice;

cout<<endl;
cout<<endl;
cout<<"   --- MUNICIPAL CORPORATION JALANDHAR ----  "<<endl;
cout<<endl;
 cout<<"      ---- WATER QUALITY CHECKER ----\n\n";
cout<<endl;
cout<<" PRESS 1 TO ADD DATA"<<endl;

cout<<endl;
cout<<" PRESS 2 TO DISPLAY DATA"<<endl;
cin>>choice;
switch(choice)
{
case 1:
    {


    ofstream of("water.dat");

for(i=0;i<2;i++)
{
    c[i].water::get();
    c[i].abc::get();
    of.write((char*)&c[i],sizeof(c[i]));
}
of.close();
  break;
}
case 2:
    {


    ifstream iff("water.dat");
    for(i=0;i<2;i++)
    {

        iff.read((char*)&c[i],sizeof(c[i]));
        cout<<endl;
        cout<<" WATER SAMPLE "<<i+1<<endl;
        cout<<endl;
        c[i].display();
            c[i].calcl();
            c[i].calhar();
            c[i].calph();
    }
    iff.close();

break;
}
default:
    {
        cout<<endl;
        cout<<" SORRY - WRONG CHOICE ENTERED";
        cout<<endl;
    }
}
}
