#include<stdio.h>
#include<process.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
/*
This program is to create for cipher with encryption and decryption.
Here, the user only can see the cipher of the input after choosing the
encryption and after the decryption the cipher is show correctly.
*/
int MAX=128;
int MIN=128;
class CIPHER
{
char txt;
char msg[100];
public:
void encrypt();
void decrypt();
};
void CIPHER:: encrypt()
{
int i=0;
cout<<"\nEnter Your Message, When Complete Please Do Press Dot(.)\n";
while((txt=getch())!='.')
{
msg[i]=txt+MAX;
MAX--;
i++;
}
msg[i]='\0';
cout<<"\nYour Encrypted Message Is:"<<msg;
}
void CIPHER::decrypt()
{
int i=0;
while(i<strlen(msg))
{
msg[i]=msg[i]-MIN;
MIN--;
i++;
}
cout<<"\nYour Decrypted Message Is:"<<msg;
}
void main()
{
CIPHER c;
ofstream f1;
ifstream f2;
char ch;
clrscr();
system("cls");
cout<<"\n'E':Encryption Of My Message\n'D':Decryption Of My Message\n'Q':Quit";
cout<<"\nEnter The Choice:";
cin>>ch;
if(toupper(ch)=='E')
{
system("cls");
f1.open("CIPHER.dat",ios::out);
c.encrypt();
f1.write((char*)&c,sizeof(c));
f1.close();
}
else if(toupper(ch)=='D')
{
system("cls");
f2.open("CIPHER.dat",ios::in);
if(!f2)
{
system("cls");
cout<<"\nFile Not Exists";
}
else
{
//f2.read((char*)&c,sizeof(c)); **It Will Be Worked Soon
while(!f2.eof())
{
c.decrypt();
f2.read((char*)&c,sizeof(c));
}
}
f2.close();
}
else
{
cout<<"\nCreated By:Debajyoti Bhattacharjee\nEmail:bdebajyoti@hotmail.com\nThank You....!";
}
getch();
}
/*
Created By:Debajyoti Bhattacharjee
Email:bdebajyoti@hotmail.com
Thank You....!";
*/