#include <iostream.h>
#include <conio.h>
#include <string.h>
# include "bt.h"
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include <iomanip>
//==============================================================================
// definisi konstruktor dari pohonbiner
//==============================================================================
Kontak::Kontak()
{
  HWND hWnd = GetConsoleWindow();
textcolor(1);
SetConsoleTitle("  oleh : 0x214ff ");

  akar = NULL;
  jumlah=10;


}

//==================================
Kontak::~Kontak()
{
hapus_semua_simpul(akar);
}

//==================================
void Kontak::hapus_semua_simpul( Kontak *simpul )
{
  if ( simpul)
 hapus_semua_simpul( simpul->kiri );
 //hapus_semua_simpul( simpul->kanan );
delete simpul;
}

////////////////////////////////////////////////////////////////////////////////
//tambah simpul
//dengan nilai balik : 1. data sudah ditambahkan//
//                     2. data sudah ada//
////////////////////////////////////////////////////////////////////////////////
int Kontak::tambah( char *nama,char *telp )
{

  //cout<<"nama : ===="<<nama;
  Kontak * simpul;
  simpul = new Kontak;
  simpul->kiri = NULL;
  simpul->kanan = NULL;
  simpul->induk = NULL;
  strcpy(simpul->nama,nama);
  strcpy(simpul->telp,telp);
  if ( akar == NULL )
  {
    akar = simpul;
    return ( 1 );
  }
  else
    return ( tambah( akar, simpul ) );

}

////////////////////////////////////////////////////////////////////////////////
//  tambah()
//  nilai balik 1. data sudah ditambahkan
//              2. data sudah ada
////////////////////////////////////////////////////////////////////////////////
int Kontak::tambah( Kontak * ortu, Kontak * baru )
{
  if ( strcmp(baru->nama,ortu->nama)==0 )
  {
    delete baru;
    return ( 0 );
  }
  else
  if (  strcmp(baru->nama,ortu->nama)<0)
  {
    if ( !ortu->kiri )
    {
      ortu->kiri = baru;
      baru->induk = ortu;
    }
    else
      return ( tambah( ortu->kiri, baru ) );
  }
  else
  if ( !ortu->kanan )
  {
    ortu->kanan = baru;
    baru->induk = ortu;
  }
  else
    return ( tambah( ortu->kanan, baru ) );
  return ( 1 );
}
//
////////////////////////////////////////////////////////////////////////////////
//  menpilkan semua data
////////////////////////////////////////////////////////////////////////////////
void Kontak::tampil()
{//cout<<"aaa";

  tampil( akar );
  jumlah=10;
}

void Kontak::tampil( Kontak * simpul )
{HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  if ( simpul )
  {
    if ( simpul->kiri ) tampil( simpul->kiri );
    //==============
    int warna=116;
   if (jumlah%2!=0)
   warna=112;
   SetConsoleTextAttribute( hConsole, warna );
   gotoxy(28,jumlah);cout <<simpul->nama;
   gotoxy(55,jumlah);cout << simpul->telp<< endl;
   SetConsoleTextAttribute(hConsole,112);


 //  gotoxy(27,jumlah+1);cout<<char(196);
    jumlah+=2;

    if ( simpul->kanan ) tampil( simpul->kanan );
  }
}

////////////////////////////////////////////////////////////////////////////////
//  hapus()
//  nilai balik 0. data tidak ketemu
//              1. data ketemu
////////////////////////////////////////////////////////////////////////////////
int Kontak::hapus( char *nama )
{
  Kontak * simpul_dihapus;
  simpul_dihapus = cari( akar, nama );
  if ( simpul_dihapus == NULL )
    return (0);
  if ( !simpul_dihapus->kanan )
  {
    if ( !simpul_dihapus->kiri )
    {
      //--simpul yang akan dihapus sebagai daun
      //--(tidak punya anak)
      if ( simpul_dihapus == akar )
        akar == NULL;
      else
      if ( simpul_dihapus->induk->kiri == simpul_dihapus )
        simpul_dihapus->induk->kiri = NULL;
      else
        simpul_dihapus->induk->kanan = NULL;
    }
    else
    {
      //== simpul yang akan dihapus memilliki anak]
      // dihapus sebelah kiri saja
      if ( simpul_dihapus == akar )
      {
        akar = simpul_dihapus->kiri;
        akar->induk = NULL;
      }
      else
      if ( simpul_dihapus->induk->kiri == simpul_dihapus )
      {
        simpul_dihapus->induk->kiri = simpul_dihapus->kiri;
        simpul_dihapus->kiri->induk = simpul_dihapus->induk;
      }
      else
      {
        simpul_dihapus->induk->kanan = simpul_dihapus->kiri;
        simpul_dihapus->kiri->induk = simpul_dihapus->induk;
      }
    }
  }

  else
  if ( !simpul_dihapus->kiri )
  {
    //==simpul yang akan dihapus
    //==mempunyai anak disebelah kanan saja
    if ( simpul_dihapus == akar )
    {
      akar = simpul_dihapus->kanan;
      akar->induk = NULL;
    }
    else
    if ( simpul_dihapus->induk->kiri == simpul_dihapus )
    {
      simpul_dihapus->induk->kiri= simpul_dihapus->kanan;
      simpul_dihapus->kanan->induk = simpul_dihapus->induk;
    }
    else
    {
      simpul_dihapus->induk->kanan = simpul_dihapus->kanan;
      simpul_dihapus->kanan->induk = simpul_dihapus->induk;
    }
  }
  else
  {
    //simpul yang dihapus
    // memiliki dua buah subpohon
    Kontak * suksesor = simpul_dihapus->kanan;
    //==cari suksesor
    while ( suksesor->kiri != NULL )
      suksesor = suksesor->kiri;
    //== putaran suksesor dari pohon
    if ( suksesor->induk->kiri == suksesor )
    {
      suksesor->induk->kiri = suksesor->kanan;
      suksesor->kanan->induk = suksesor->induk;

      if(suksesor->kanan==NULL)
      suksesor->induk->kiri=NULL;
    }

    else
    {
      suksesor->induk->kanan = suksesor->kanan;//
      suksesor->kanan->induk = suksesor->induk;//

    }

    //data pada suksesor dikopikan ke simpul yang akan dihapus
    strcpy(simpul_dihapus->nama,suksesor->nama);
    strcpy(simpul_dihapus->telp,suksesor->telp);
    //ubah simpul yang ditunjuk suksesor ke simpul yang nantinyaa akan dihapus
    simpul_dihapus = suksesor;
  }
  delete simpul_dihapus;
  return (1);
}

////////////////////////////////////////////////////////////////////////////////
//  cari()
//  nilai balik NULL=data tidak ketemu
////////////////////////////////////////////////////////////////////////////////

Kontak * Kontak::cari( Kontak * simpul, char *nama )
{
  if ( simpul == NULL )
    return ( NULL );
  else
  if ( strcmp(nama,simpul->nama)==0 )
    return simpul;
  else
  if (strcmp( nama ,simpul->nama )<0)
    return ( cari( simpul->kiri, nama ) );
  else
    return ( cari( simpul->kanan, nama ) );
}

////////////////////////////////////////////////////////////////////////////////
//  cari()
// nilai balik 0. data tidak ketemu
//             1. data ketemu
////////////////////////////////////////////////////////////////////////////////
int Kontak::cari(char *nama)
{

  if(cari(akar,nama)==NULL)
  return 0;
  else
  return 1;

}
////////////////////////////////////////////////////////////////////////////////
// funsi cari berdasarkan substring
//
////////////////////////////////////////////////////////////////////////////////

void Kontak::cetak_search(char* dicari )
{
  cetak_search(akar,dicari );
  jumlah=10;
}
////////////////////////////////////////////////////////////////////////////////
// fungsi cetak hasil pencarian
////////////////////////////////////////////////////////////////////////////////

void Kontak::cetak_search( Kontak * simpul, char * dicari )
{
  HANDLE hConsole;
  hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  char xnama[40];
  char xtelp[20];
  if ( simpul )
  {
    if ( simpul->kiri )
      cetak_search( simpul->kiri, dicari );
      strcpy(xnama,simpul->nama);
      strcpy(xtelp,simpul->telp);
    if ( strstr( xnama, dicari ) )
    {
      //==============
      int warna=116;
      if (jumlah%2!=0)
      warna=112;
      SetConsoleTextAttribute( hConsole, warna );
      gotoxy(28,jumlah);cout <<simpul->nama;
      gotoxy(55,jumlah);cout << simpul->telp<< endl;
       jumlah++;

    }
    if ( simpul->kanan, dicari ) cetak_search( simpul->kanan, dicari );
  }
}

////////////////////////////////////////////////////////////////////////////////
// fungsi edit
////////////////////////////////////////////////////////////////////////////////
int Kontak::edit( char *nama )
{
if(cari(akar,nama)==NULL)
 return 0;
 else
 return 1;
}

////////////////////////////////////////////////////////////////////////////////
// edit
////////////////////////////////////////////////////////////////////////////////
Kontak * Kontak::edit( Kontak * simpul, char *nama )
{
  if ( simpul == NULL )
    return ( NULL );
  else
  if ( strcmp(nama,simpul->nama)==0 )
  {
    char xnama[40];
   char  xtelp[20];
   cout<<"nama :";cin.getline(xnama,40);
   cout<<"telp :";cin.getline(xtelp,20);
   strcpy(simpul->nama,xnama);
   strcpy(simpul->telp,xtelp);
    return simpul;
  }
  else
  if (strcmp( nama ,simpul->nama )<0)
    return ( cari( simpul->kiri, nama ) );
  else
    return ( cari( simpul->kanan, nama ) );
}
