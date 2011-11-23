#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib.h>
#include <iostream.h>
#include<dos.h>
# include <fstream.h>
#define WAIT(x) Sleep((long)(x));
#define SECOND 1000
#include "bt.h"
#define WAIT(x) Sleep((long)(x));
#define SECOND 1000
#define MaxNo_Menu 7
//#include "Kontak.h"
//================================================
//box
//================================================
void Kontak::kotak_warna( int aRow, int aCol, int aHeight, int aWidth, int warna, bool aShadow )
{
  _setcursortype( 0 );
  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  SetConsoleTextAttribute( hConsole, warna );
  int baris, kolom;
  int i, j;
  i = aRow;
  j = aCol;
  baris = aWidth;
  kolom = aHeight;

  while ( i <= baris )
  {
    while ( j <= kolom )
    {
      gotoxy( i, j ); cout << char( 219 );
      j++;
    }
    cout << "\n";
    i++;
    j = aCol;
  }
  if ( aShadow == true )
  {
    SetConsoleTextAttribute( hConsole, 0 );
    for ( int b = aCol + 1; b <= aHeight + 1; b++ )
    {
      gotoxy( aWidth + 1, b ); cout << char( 219 );
    }

    SetConsoleTextAttribute( hConsole, 0 );
    for ( int c = aRow + 1; c <= aWidth + 1; c++ )
    {
      gotoxy( c, aHeight + 1 ); cout << char( 219 );
    }
  }
}

//========================================================
//colour background
//========================================================
void Kontak::xBACK_GROUND( int depan, int belakang )
{
  WORD wColor = ( ( belakang & 0x0F ) << 4 ) + ( depan & 0x0F );
  //Get the handle to the current output buffer...
  HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  //This is used to reset the carat/cursor to the top left.
  COORD coord =
  {
    0, 0
  };
  //A return value... indicating how many chars were written
  //   not used but we need to capture this since it will be
  //   written anyway (passing NULL causes an access violation).
  DWORD count;

  //This is a structure containing all of the console info
  // it is used here to find the size of the console.
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  //Here we will set the current color
  SetConsoleTextAttribute( hStdOut, wColor );
  if ( GetConsoleScreenBufferInfo( hStdOut, & csbi ) )
  {
    //This fills the buffer with a given character (in this case 32=space).
    FillConsoleOutputCharacter( hStdOut, ( TCHAR )186, csbi.dwSize.X * csbi.dwSize.Y, coord, & count );

    FillConsoleOutputAttribute( hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, & count );
    //This will set our cursor position for the next print statement.
    SetConsoleCursorPosition( hStdOut, coord );
  }
  return;
}

//================================================
// menu utama
//================================================
void Kontak::menu_utama()
{
  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

  SetConsoleTextAttribute( hConsole, 112 );

  xBACK_GROUND( 20, 8 );
  kotak_warna( 10, 2, 4, 70, 7, true );
  SetConsoleTextAttribute( hConsole, 112 );
  gotoxy( 11, 3 ); cout << "       PHONE NUMBER SIMULATION WITH BINARY SEARCH TREE";


  kotak_warna( 4, 8, 24, 20, 7, true );
  SetConsoleTextAttribute( hConsole, 112 );
  gotoxy( 8, 9 );
  cout << " <MENU>";
  gotoxy( 4, 10 ); cout << "-----------------";



}

//================================================
// menu add
//================================================
void Kontak::menu_add()
{
  clrscr();
  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  Kontak ob_kontak;
  char Nama[40];
  char telpon[20];
  int bil;
  menu_utama();
  //menu_utama();
  SetConsoleTextAttribute( hConsole, 113 );
  gotoxy( 10, 11 ); cout << "ADD";
  SetConsoleTextAttribute( hConsole, 120 );
  gotoxy( 10, 13 ); cout << "LIST";
  gotoxy( 10, 15 ); cout << "EDIT";
  gotoxy( 10, 17 ); cout << "DELETE";
  gotoxy( 10, 19 ); cout << "SEARCH";
  gotoxy( 10, 21 ); cout << "ABOUT";
  gotoxy( 10, 23 ); cout << "EXIT";
  kotak_warna( 29, 10, 16, 70, 7, true );
  kotak_warna( 40, 11, 12, 68, 1, true );
  kotak_warna( 40, 14, 15, 68, 1, true );
  SetConsoleTextAttribute( hConsole, 112 );
  gotoxy( 31, 12 ); cout << "NAMA";
  gotoxy( 31, 15 ); cout << "TELEPON";
  SetConsoleTextAttribute( hConsole, 30 );

  gotoxy( 41, 12 );
  cin.getline( Nama, 40 );
  gotoxy( 41, 14 );
  cin.getline( telpon, 20 );

  ob_kontak.tambah( Nama, telpon );


  getch();
  getch();
  menu_pilih();

}

//================================================
// menu pilih
//================================================
void Kontak::menu_pilih()
{

  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  Kontak ob_kontak;
  //ob_kontak.tambah( "zia","000" );
 // ob_kontak.tambah("erwin","1111");
  char Nama[40];
  char telpon[20];
  menu_utama();
  char * menu_list[MaxNo_Menu] =
  {
    "      ADD        ", "      LIST       ", "      EDIT       ",
    "      DELETE     ", "      SEARCH     ", "      OTHERS     ",
    "      EXIT       "
  };
  int i, xpos = 4, ypos[MaxNo_Menu] =
  {
    11, 13, 15, 17, 19, 21, 23
  };

  // list the menu
  for ( i = 0; i < MaxNo_Menu; ++i )
  {
    gotoxy( xpos, ypos[i] );
    textattr( 8 | 7 * 16 );
    cprintf( "%s", menu_list[i] );
  }

  // make menu available to choose
  i = 0;
  while ( 1 )
  {
    gotoxy( xpos, ypos[i] );
    textattr( 15 | 0 * 16 );
    cprintf( "%s", menu_list[i] );

    /* note : 72 -> UP button 75 -> RIGHT button 77 -> LEFT button 80 -> DOWN button */

    switch ( getch() )
    {
      case 72:
        if ( i > 0 )
        {
          gotoxy( xpos, ypos[i] );
          textattr( 8 | 7 * 16 );
          cprintf( "%s", menu_list[i] );
          --i;
        }
      break;

      case 80:
        if ( i < MaxNo_Menu - 1 )
        {
          gotoxy( xpos, ypos[i] );
          textattr( 8 | 7 * 16 );
          cprintf( "%s", menu_list[i] );
          ++i;
        }
      break;
//==============================================================================
      case 13:
//=========================================================tambah kontak========
        if ( i == 0 )
        {
       bool a = true;
          int strleng;
          kotak_warna( 29, 10, 16, 70, 7, true );
          kotak_warna( 40, 11, 12, 68, 1, false );
          kotak_warna( 40, 14, 15, 68, 1, false );
          SetConsoleTextAttribute( hConsole, 112 );
          gotoxy( 31, 12 ); cout << "NAMA";
          gotoxy( 31, 15 ); cout << "TELEPON";
          SetConsoleTextAttribute( hConsole, 30 );
          _setcursortype( 2 );
          gotoxy( 41, 12 );
          cin.getline( Nama, 40 );
          gotoxy( 41, 15 );
        atas:
          cin.getline( telpon, 20 );
          strleng = strlen( Nama );
          if ( strleng == 0 || strleng >= 40 )
          {
            kotak_warna( 29, 10, 16, 70, 7, true );
            SetConsoleTextAttribute( hConsole, 124 );
            gotoxy( 33, 13 ); cout << "\a        TIDAK DIIZIKAN !!";
            getch();
            goto b;


          }
          if ( cek( telpon, a ) )
          {
            kotak_warna( 29, 10, 16, 70, 7, true );
            SetConsoleTextAttribute( hConsole, 124 );
            gotoxy( 33, 13 ); cout << "\a  NOMOR HARUS BERUPA ANGKA !!";
            getch();
            goto b;
          }
else{
          if ( ob_kontak.cari( Nama ) )
          {
            kotak_warna( 29, 10, 16, 70, 7, true );
            SetConsoleTextAttribute( hConsole, 124 );
            gotoxy( 33, 13 ); cout << "\a          KONTAK SUDAH ADA..!!";
            getch();
            goto b;
            //clrscr();

          }

          ob_kontak.tambah( Nama, telpon );
          kotak_warna( 29, 10, 16, 70, 7, true );
            kotak_warna( 31, 12, 14, 68, 1, false );
            SetConsoleTextAttribute( hConsole, 30 );
            gotoxy( 33, 13 ); cout << "  KONTAK BERHASIL DIINPUTKAN..!!  ";
getch();
}
        b:
          clrscr();
          menu_utama();
          tampil_pilih();


        }
        //===============================menu tampil----------------------------
        if ( i == 1 )
        {
          tabel_tampil();
          ob_kontak.tampil();
          getch();
          clrscr();
          menu_utama();
          tampil_pilih();
          SetConsoleTextAttribute( hConsole, 113 );
          gotoxy( 10, 13 ); cout << "LIST";

        }
        //===================================menu edit--------------------------
        if ( i == 2 )
        {
          int strleng;
          bool a;
          kotak_warna( 10, 2, 4, 70, 7, true );
          SetConsoleTextAttribute( hConsole, 112 );
          gotoxy( 11, 3 ); cout << "NAMA YANG AKAN DI EDIT ";
          kotak_warna( 35, 3, 3, 68, 1, false );
          tabel_tampil();
          ob_kontak.tampil();
          SetConsoleTextAttribute( hConsole, 30 );
          _setcursortype( 2 );
          gotoxy( 36, 3 ); cin.getline( Nama, 40 );
          if ( !ob_kontak.cari( Nama ) )
          {
            kotak_warna( 25, 8, 24, 75, 7, true );
            kotak_warna( 29, 13, 19, 70, 4, false );
            kotak_warna( 31, 15, 17, 68, 1, false );
            SetConsoleTextAttribute( hConsole, 112 );
            gotoxy( 33, 16 ); cout << "\a         KONTAK TIDAK ADA!!       ";
            getch();
            goto bwh;
          }

          ob_kontak.hapus( Nama );
          //=========================================INPUT DATA BARU======================
          clrscr();
          menu_utama();
          tampil_pilih();
          ulang:
          SetConsoleTextAttribute( hConsole, 113 );
          gotoxy( 10, 15 ); cout << "EDIT";
          kotak_warna( 29, 10, 16, 70, 7, true );
          kotak_warna( 40, 11, 12, 68, 1, false );
          kotak_warna( 40, 14, 15, 68, 1, false );
          //===============ket
          kotak_warna( 29, 19, 23, 70, 7, false );
          kotak_warna( 31, 20, 22, 68, 4, false );
          SetConsoleTextAttribute( hConsole, 112 );
          gotoxy( 33, 21 ); cout << "    INPUTKAN KONTAK BARU...!!!    ";

          SetConsoleTextAttribute( hConsole, 112 );
          gotoxy( 31, 12 ); cout << "NAMA";
          gotoxy( 31, 15 ); cout << "TELEPON";
          SetConsoleTextAttribute( hConsole, 30 );
          _setcursortype( 2 );
          gotoxy( 41, 12 );
          cin.getline( Nama, 40 );
          gotoxy( 41, 15 );
          cin.getline( telpon, 20 );
          strleng=strlen(Nama);
          if ( strleng == 0 || strleng >= 40 )
          {
            kotak_warna( 29, 10, 16, 70, 7, true );
            kotak_warna( 31, 12, 14, 68, 1, false );
            SetConsoleTextAttribute( hConsole, 30 );
            gotoxy( 33, 13 ); cout << "\a   TIDAK DIIZIKAN !!";
            getch();
            goto bwh;


          }
          if ( cek( telpon, a ) )
          {
            kotak_warna( 29, 10, 16, 70, 7, true );
            kotak_warna( 31, 12, 14, 68, 1, false );
            SetConsoleTextAttribute( hConsole, 30 );
            gotoxy( 33, 13 ); cout << "\a NOMOR HARUS BERUPA ANGKA !!";
            getch();
            goto bwh;
          }

          if ( ob_kontak.cari( Nama ) )
          {
            kotak_warna( 29, 10, 16, 70, 7, true );
            SetConsoleTextAttribute( hConsole, 124 );
            gotoxy( 33, 13 ); cout << "\a          KONTAK SUDAH ADA..!!";

            getch();
            goto ulang;
            //clrscr();

          }

          ob_kontak.tambah( Nama, telpon );


        bwh:
          clrscr();
          menu_utama();
          tampil_pilih();
          SetConsoleTextAttribute( hConsole, 113 );
          gotoxy( 10, 15 ); cout << "EDIT";

        }
        //===================================menu delete------------------------
        if ( i == 3 )
        {
          kotak_warna( 10, 2, 4, 70, 7, true );
          SetConsoleTextAttribute( hConsole, 112 );
          gotoxy( 11, 3 ); cout << "NAMA YANG AKAN DI DELETE ";
          kotak_warna( 35, 3, 3, 68, 1, false );
          tabel_tampil();
          ob_kontak.tampil();
          SetConsoleTextAttribute( hConsole, 30 );
          _setcursortype( 2 );
          gotoxy( 36, 3 ); cin.getline( Nama, 40 );
          if ( !ob_kontak.cari( Nama ) )
          {
            kotak_warna( 25, 8, 24, 75, 7, true );
            kotak_warna( 29, 13, 19, 70, 4, false );
            kotak_warna( 31, 15, 17, 68, 1, false );
            SetConsoleTextAttribute( hConsole, 112 );
            gotoxy( 33, 16 ); cout << "\a         KONTAK TIDAK ADA!!       ";
            getch();
            goto bawah;
          }

          ob_kontak.hapus( Nama );
          kotak_warna( 25, 8, 24, 75, 7, true );
          kotak_warna( 29, 13, 19, 70, 1, false );
          SetConsoleTextAttribute( hConsole, 30 );
          gotoxy( 33, 16 ); cout << "     KONTAK BERHASIL DIHAPUS..!!   ";
          getch();
        bawah:
          clrscr();
          menu_utama();
          tampil_pilih();
          SetConsoleTextAttribute( hConsole, 113 );
          gotoxy( 10, 17 ); cout << "DELETE";

        }
        //===============================menu search()--------------------------
        if ( i == 4 )
        {
          kotak_warna( 29, 10, 16, 70, 7, true );
          kotak_warna( 40, 12, 14, 68, 1, false );

          SetConsoleTextAttribute( hConsole, 112 );
          gotoxy( 31, 13 ); cout << "NAMA";
          SetConsoleTextAttribute( hConsole, 30 );
          _setcursortype( 2 );
          gotoxy( 41, 13 );
          cin.getline( Nama, 40 );
          tabel_tampil();
          ob_kontak.cetak_search( Nama );
          getch();
          clrscr();
          menu_utama();
          tampil_pilih();
          SetConsoleTextAttribute( hConsole, 113 );
          gotoxy( 10, 19 ); cout << "SEARCH";


        }
        if(i==5)
        {
         menu_other();
        }

        if(i==6)
        {
         keluar();
        }

      break;
    }
  }

}



//==============================================
//tampilan loading
//==============================================

void Kontak::menu_awal()
{

   HANDLE hConsole;
   hConsole = GetStdHandle( STD_OUTPUT_HANDLE ); int i,x=33;
  //=============loading=========================


  xBACK_GROUND( 20, 8 ); kotak_warna( 14, 10, 14, 60, 7, true );
  kotak_warna( 30, 11, 13, 54, 1, false ); SetConsoleTextAttribute( hConsole, 112 ); gotoxy( 16, 12 ); cout << "       %  ";

  for(i=1;i<=100;i++) { SetConsoleTextAttribute( hConsole, 112 ); gotoxy(19,12);cout<<i; WAIT(0.03*SECOND);
  if(i==10||i==20||i==30||i==40||i==50||i==60||i==70||i==80||i==90||i==100) { SetConsoleTextAttribute( hConsole, 127 );
  gotoxy( x, 12 ); cout<<char(219); x=x+2; } }

  menu_password();
  getch();
}

void Kontak::tampil_pilih()
{
  char * menu_list[MaxNo_Menu] =
  {
    "ADD", "LIST", "EDIT", "DELETE", "SEARCH", "OTHERS", "EXIT"
  };
  int i, xpos = 10, ypos[MaxNo_Menu] =
  {
    11, 13, 15, 17, 19, 21, 23
  };

  // list the menu
  for ( i = 0; i < MaxNo_Menu; ++i )
  {
    gotoxy( xpos, ypos[i] );
    textattr( 8 | 7 * 16 );
    cprintf( "%s", menu_list[i] );
  }

}

//==================================================================
// tabel tampil
//==================================================================
void Kontak::tabel_tampil()
{
  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  kotak_warna( 25, 8, 24, 75, 7, true );
  kotak_warna( 26, 9, 9, 74, 0, false );
  Kontak ob_kontak;

  SetConsoleTextAttribute( hConsole, 14 );
  gotoxy( 35, 9 );
  cout << "NAMA";
  gotoxy( 60, 9 );
  cout << "TELPON";
  SetConsoleTextAttribute( hConsole, 112 );
  //tengah
  int bil=0;
  for ( int b = 10; b <= 22; b++ )
  {
if(bil%2==0)
    {
    gotoxy( 53, b ); cout << char( 186 );
    bil++;
    }
else
    {

      gotoxy( 53, b ); cout << char( 206 );
      bil++;
    }
  }
  gotoxy(53,23);cout<<char(202);
  //kiri
 bil=0;
for ( int b = 10; b <= 22; b++ )
  {
    if(bil%2==0)
    {
    gotoxy( 26, b ); cout << char( 186 );
    bil++;
    }
    else
    {
    gotoxy( 26, b ); cout << char( 204 );
    bil++;
    }
  }
  gotoxy(26,23);cout<<char(200);
//kanan
 bil=0;
for ( int b = 10; b <= 22; b++ )
  {
if(bil%2==0)
    {
    gotoxy( 74, b ); cout << char( 186 );
    bil++;
    }
    else
    {
      gotoxy( 74, b ); cout << char( 185 );
    bil++;
    }
  }
gotoxy(74,23);cout<<char(188);
for ( int b = 27; b <= 52; b++ )
  {
    gotoxy( b, jumlah+1 ); cout << char( 205 );
  }

//==
for(int myjum=10;myjum<=23;myjum+=2)
{
for ( int b=54; b <= 73; b++ )
  {
    gotoxy( b, myjum+1 ); cout << char( 205 );
  }

for ( int b = 27; b <= 52; b++ )
  {
    gotoxy( b, myjum+1 ); cout << char( 205 );
  }
}
}

//========================cek input==================================
bool Kontak::cek( char * telp, bool a )
{  for ( int i = 0; i <= sizeof( telp ); i++ )
  {
    if ( (telp[i] >= char( 48 )) && (telp[i] <= char( 57 )) )
    {
      a = false;
      break;
    }
  }
  getch();
  return a;
}

////////////////////////////////////////////////////////////////////////////////
// fungsi exit
////////////////////////////////////////////////////////////////////////////////
void Kontak::keluar()
{
  xBACK_GROUND( 20, 8 );
 kotak_warna( 10, 4, 20, 70, 7, true );

 HANDLE hConsole;
hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
_setcursortype( 0 );
SetConsoleTextAttribute( hConsole, 116 );

 gotoxy( 12, 5 );
  cout << char( 201 );
  for ( int i = 1; i <= 55; i++ )
  {
    cout << char( 205 );
    WAIT(0.01*SECOND);
  }
  cout << char( 187 );
 WAIT(0.01*SECOND);
//tepi kanan----------------------------------------
for ( int i = 6; i <= 18; i++ )
{
  gotoxy( 68, i ); cout << char( 186 ) << endl;
 WAIT(0.01*SECOND);
}

//bawah----------------------------------------------
 gotoxy( 12, 19 );
  WAIT(0.01*SECOND);
 cout << char( 200 );
 for ( int i = 1; i <= 55; i++ )
 {
   cout << char( 205 );
    WAIT(0.01*SECOND);
 }
 cout << char( 188 );

  //garis tepi kiri ----------------------------------
  for ( int i = 6; i <= 18; i++ )
  {
    gotoxy( 12, i ); cout << char( 186 ) << endl;
     WAIT(0.01*SECOND);
  }

kotak_warna( 17, 8, 16, 63, 8, false );
kotak_warna( 20, 11, 13, 60, 1, false );
SetConsoleTextAttribute( hConsole, 30 );
char pesan[]=".............TERIMAKASIH............";
int count=22;
for(int i=0;i<=strlen(pesan);i++)
{
gotoxy(count,12);cout<<pesan[i];
count++;
WAIT(0.04*SECOND);

}
cout<<'\a';
WAIT(0.4*SECOND);
cout<<'\a';
WAIT(0.4*SECOND);
cout<<'\a';
exit(1);
}

