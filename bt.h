#include <iostream.h>
#include <string.h>
# ifndef KONTAK_H
# define KONTAK_H

class Kontak
{
  friend istream& operator >>(istream& in, Kontak& P)
  {
    P.menu_awal();
    return in;
  }
  friend ostream& operator <<(ostream& out, Kontak& Q)
  {
    //Q.Menu();
    return out;
  }
private:

  Kontak * akar;
  Kontak * induk;
  Kontak * kiri;
  Kontak * kanan;
  char nama[40];
  char telp[20];
  int jumlah;
  char kd[8];
public:
  Kontak();
  ~Kontak();
  //=============
  int tambah( Kontak * ortu, Kontak * baru );
 Kontak * cari( Kontak * simpul, char * nama );
 Kontak * edit( Kontak * simpul, char * nama );
 void hapus_semua_simpul( Kontak * simpul );
 void tampil( Kontak * simpul );
  //=============
  int tambah( char * nama, char * telp );
  int hapus( char * nama );
  int edit( char *nama);

  int cari( char * nama );
  void tampil();
  void cetak_search( Kontak * simpul,char* dicari );
  void cetak_search(char* dicari);
//====menu===
bool cek(char *telp, bool a);
void kotak_warna(int aRow, int aCol, int aHeight, int aWidth,int warna, bool aShadow);
void xBACK_GROUND(int ForgC, int BackC);
void menu_awal();
void menu_utama();
void menu_pilih();
void menu_password();
void menu_add();
void tampil_pilih();
void tabel_tampil();
void menu_other();
void menu_utama2();
void keluar();
void Set_password();
void ganti_password();
void Password();
void about_this();
int plus();
};
#endif
