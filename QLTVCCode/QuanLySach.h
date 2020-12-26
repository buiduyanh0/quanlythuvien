#ifndef _QLSach_
#define _QLSach_

#include <stdio.h>
#include <conio.h>
#include <string.h>

void NhapSach();
void XemSach();
void ThemSach();
void SuaSach(int h);
void XemThongTinSachDaSua(int h);
void MenuTuyChonChinhSuaSach(int h);
void XoaSach(int d);
void TimISBN(char isbn[25]);
void TimTheoTenSach(char tensach[25]);
int TKSachTV();//Thong ke sach trong thu vien
void TKSachTL();//Thong ke sach theo the loai

#endif