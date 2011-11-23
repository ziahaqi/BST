
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib.h>
#include <iostream.h>
#include<dos.h>
#define WAIT(x) Sleep((long)(x));
#define SECOND 1000
#include "bt.h"
#define MaxNo_Menu 3
# include <fstream.h>

void Kontak::menu_utama2()
{
  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

  SetConsoleTextAttribute( hConsole, 112 );

  xBACK_GROUND( 20, 8 );
  kotak_warna( 10, 2, 4, 70, 7, true );
  SetConsoleTextAttribute( hConsole, 112 );
  gotoxy( 11, 3 ); cout << "       PHONE NUMBER SIMULATION WITH BINARY SEARCH TREE";
  kotak_warna( 4, 8, 22, 25, 3, true );
  SetConsoleTextAttribute( hConsole, 62 );
  gotoxy( 8, 9 );
  cout << " <OTHER MENU>";
  gotoxy( 4, 10 ); cout << "----------------------";


}




////////////////////////////////////////////////////////////////////////////////
// menu other
////////////////////////////////////////////////////////////////////////////////
void Kontak::menu_other()
{
  menu_utama2();
   int jumlah;
  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  Kontak ob_kontak;
  char Nama[40];
  char telpon[20];
  char * menu_list[MaxNo_Menu] =
  {
    "   CHANGE PASSWORD    ", "   ABOUT              ", "   BACK               "
  };
  int i, xpos = 4, ypos[MaxNo_Menu] =
  {
    13, 16,19
  };

  // list the menu
  for ( i = 0; i < MaxNo_Menu; ++i )
  {
    gotoxy( xpos, ypos[i] );
    textattr( 8 | 3 * 16 );
    cprintf( "%s", menu_list[i] );
  }

  // make menu available to choose
  i = 0;
  while ( 1 )
  {
    gotoxy( xpos, ypos[i] );
    textattr( 14 | 0 * 16 );
    cprintf( "%s", menu_list[i] );

    /* note : 72 -> UP button 75 -> RIGHT button 77 -> LEFT button 80 -> DOWN button */

    switch ( getch() )
    {
      case 72:
        if ( i > 0 )
        {
          gotoxy( xpos, ypos[i] );
          textattr( 8 | 3 * 16 );
          cprintf( "%s", menu_list[i] );
          --i;
        }
      break;

      case 80:
        if ( i < MaxNo_Menu - 1 )
        {
          gotoxy( xpos, ypos[i] );
          textattr( 8 | 3 * 16 );
          cprintf( "%s", menu_list[i] );
          ++i;
        }
      break;
//==============================================================================
      case 13:
//=========================================================about========
        if ( i == 0 )
        {
ganti_password();
        }
        //===============================about ----------------------------
        if ( i == 1 )
        {
  about_this();
  getch();
  menu_other();
        }
        //===================================menu edit--------------------------
        if ( i == 2 )
        {
menu_pilih();
        }

      break;
    }
  }
getch();
}



//==============================================================================
void Kontak::ganti_password()
{

  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

 menu_utama2();
 _setcursortype(2);
  char p[15];
  char x='A',t;
  int i=0;

 _setcursortype(2);
kotak_warna( 29, 10, 14, 70, 7, true );
kotak_warna( 45, 11, 13, 68, 1, false );
  SetConsoleTextAttribute( hConsole, 112 );
  gotoxy( 31, 12 );
  cout << "PASSWORD LAMA ";
  SetConsoleTextAttribute( hConsole, 30 );
  cout<<" ";
  while(t!='\r')
  {
         t=getch();
         if(t=='\b' && i>0)
         {
                 i--;
                 putch(t);
                 putch(' ');
                 putch(t);
         }
         else if(t!='\r' && t!='\b')
         {
                 cout<<'*';
                 p[i]=t;
                 i++;
         }
  }
  p[i]='\0';


char hasil=strcmp(p,kd);
if(hasil!=0)
{

  cout<<'\a';
  kotak_warna( 29, 20, 22, 70, 7, true );
  SetConsoleTextAttribute( hConsole, 124 );
  gotoxy(33,21);cout<<"         PASSWORD SALAH !!! ";
  getch();
  clrscr();
  ganti_password();
}
else{
in:
ofstream file("kode.DAT");
textcolor(1);
kotak_warna( 29, 10, 14, 70, 7, true );
kotak_warna( 45, 11, 13, 68, 1, false );
  SetConsoleTextAttribute( hConsole, 112 );
  gotoxy( 31, 12 );
  cout << "PASSWORD BARU ";
  SetConsoleTextAttribute( hConsole, 30 );
//==============================================================================
_setcursortype(2);
cout<<" ";
cin>>kd;

if (strlen(p)>8)
{
  cout<<'\a';
 kotak_warna( 29, 10, 14, 70, 7, true );
 SetConsoleTextAttribute( hConsole, 124 );
  gotoxy(31,12  );printf("Password Anda Lebih Dari 8 Karakter..!");
 getch();
  goto in;
}
else
  {
 file.write((char*)& kd,sizeof (kd));
 cout<<endl;
 file.close();
 }
}
menu_other();
}

///////////////////////////////////////////////////////////////////////////////

//===============================================
// menu password
//===============================================
void Kontak::menu_password()
{

  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  Kontak ob_kontak;
   plus();

  xBACK_GROUND( 20, 8 );
 _setcursortype(2);
  char p[15];
  char x='A',t;
  int i=0;
  kotak_warna( 14, 10, 14, 60, 7, true );
  kotak_warna( 30, 11, 13, 57, 1, false );
  SetConsoleTextAttribute( hConsole, 112 );
  gotoxy( 16, 12 );
  cout << "   PASSWORD   ";
  SetConsoleTextAttribute( hConsole, 30 );
  cout<<"   ";
  while(t!='\r')
 {
        t=getch();
        if(t=='\b' && i>0)
        {
                i--;
                putch(t);
                putch(' ');
                putch(t);
        }
        else if(t!='\r' && t!='\b')
        {
                cout<<'*';
                p[i]=t;
                i++;
        }
 }
 p[i]='\0';



ifstream file("kode.DAT");
file.read((char*)&kd,sizeof(kd));

file.close();
char hasil=strcmp(kd,p);
if(hasil!=0)
{
  cout<<'\a';
kotak_warna( 14, 10, 14, 60, 7, true );
 SetConsoleTextAttribute( hConsole, 124 );
 gotoxy(27,12);cout<<"   PASSWORD SALAH !!! ";
 getch();
 //clrscr();


  menu_password();
}

  //=============================================


gotoxy(26,11);cout<<" PASSWORD :";
clrscr();


  //================================================

  menu_pilih();

}


////////////////////////////////////////////////////////////////////////////////
// about this implementasi
////////////////////////////////////////////////////////////////////////////////

void Kontak::about_this()
{
  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  kotak_warna( 30, 8, 22, 70, 7, true );
  kotak_warna( 31, 9, 21, 69, 3, false );
  SetConsoleTextAttribute( hConsole, 62 );
  gotoxy(32,10);cout<<"Program ini merupakan program simulasi";
  gotoxy(32,11);cout<<"daftar telpon menggunakan ";
  gotoxy(32,12);cout<<"struktur data binary search tree(BST) ";
  gotoxy(32,13);cout<<"guna memenuhi TP struktur data";
  gotoxy(32,14);cout<<"# PROGRAMER : ";
  gotoxy(32,15);cout<<"Zia Ulhaq (08018038)";
  gotoxy(32,16);cout<<"Muslim Setya (08018045)";
  gotoxy(32,17);cout<<"Erwin Januarisman (08018021)";
  gotoxy(57,19);cout<<"salam coding";
  gotoxy(57,21);cout<<"   0x214ff";

}

////////////////////////////////////////////////////////////////////////////////
//  tabah
////////////////////////////////////////////////////////////////////////////////
int Kontak::plus()
{
 Kontak ob_kontak;
 ob_kontak.tambah( "zia","000" );
 ob_kontak.tambah("erwin","1111");
 return 0;
}
