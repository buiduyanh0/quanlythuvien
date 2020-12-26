#include "PhieuMuonTraSach.h"
#include "QuanLyDocGia.h"
#include "QuanLySach.h"

//Khai bao so luong sach va doc gia sach lon nhat
#define MaxSach 10000
#define MaxDG 1000

//Khai bao thong tin muon tra sach
char MSMuon[MaxDG][25];
char ISBNMuon[MaxSach][30];

char MSTra[MaxDG][25];

int ngaymuon[MaxSach];
int thangmuon[MaxSach];
int nammuon[MaxSach];

//Ngay,thang,nam tra sach du kien
int ngaytraDK[MaxSach];
int thangtraDK[MaxSach];
int namtraDK[MaxSach];

//Ngay,thang,nam tra sach thuc te
int ngaytraTT[MaxSach];
int thangtraTT[MaxSach];
int namtraTT[MaxSach];

int n; // Bien so luong phieu muon sach duoc lap 
int h; // Bien so luong phieu tra sach duoc lap
int demsachmuon = 0; // Bien dem so luong sach duoc muon
int sl[MaxSach]; // Bien so luong sach duoc muon boi mot doc gia trong mot lan

using namespace std;

/*-------------Ham Nhap Thong Tin Cho Phieu Muon Sach-------------*/
/*
+)Nhan vao:
MSMuon[MaxDG][25]; ISBNMuon[MaxSach][30]; ngaymuon[MaxSach]; thangmuon[MaxSach]; nammuon[MaxSach];
+)Tra ve:
Thong tin phieu muon
*/
void NhapPhieuMuon()
{
	while (true)
	{
		if (n >= MaxDG)
			printf("Khong du bo nho de cap nhat thong tin sach!!");
		else
		while (n < MaxDG)
		{
			// Nhap ma doc gia:
			fflush(stdin);
			printf("\n +)Nhap ma doc gia muon sach: ");
			gets_s(MSMuon[n]);

			// Nhap ngay muon sach:
			printf(" +)Nhap thoi diem muon sach:\n");

			printf("\t+)Nhap ngay muon sach: ");
			scanf_s("%d", &ngaymuon[n]);

			printf("\t+)Nhap thang muon sach: ");
			scanf_s("%d", &thangmuon[n]);

			printf("\t+)Nhap nam muon sach: ");
			scanf_s("%d", &nammuon[n]);

			// Nhap ISBN danh sach cac sach ma doc gia muon:
			printf(" +)Nhap so luong sach doc gia muon: ");
			scanf_s("%d", &sl[n]);

			for (int j = 0; j < sl[n]; j++)
			{
				fflush(stdin);
				printf(" +)Nhap ISBN cua quyen sach thu %d: ", j + 1);
				gets_s(ISBNMuon[j]);
				demsachmuon++;
			}
			n++;
			break;
		}
		break;
	}
}

/*-------------Ham Tinh Thoi Gian Tra Sach Du Kien-------------*/
/*
+)Nhan vao:
ngaymuon,thangmuon,nammuon
+)Tra ve:
Cac gia tri ngaytraDK, thangtraDK, namtraDK
*/
void ThoiGianTraDuKien()
{
	//Xac dinh so ngay thuc te tu thangmuon nhap vao
	int SNTT;
	switch (thangmuon[n - 1])
	{
		//Cac thang co 31 ngay
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		SNTT = 31;
		break;
		//Cac thang 30 ngay
	case 4:
	case 6:
	case 9:
	case 11:
		SNTT = 30;
		break;
	case 2:
		if (nammuon[n - 1] % 400 == 0)//Xac dinh xem co phai la nam nhuan khong
			SNTT = 29;
		else
			SNTT = 28;
	}

	/*----------------------Xac Dinh Ngay Tra Du Kien----------------------*/
	// Xu ly cac ngay thuong:
	if (ngaymuon[n - 1] == SNTT)
	{
		ngaytraDK[n - 1] = 6;
		thangtraDK[n - 1] = thangmuon[n - 1] + 1;
		namtraDK[n - 1] = nammuon[n - 1];
	}
	else
	{
		ngaytraDK[n - 1] = ngaymuon[n - 1] + 6;//Thoi han muon sach toi da 7 ngay
		if (ngaytraDK[n - 1] > SNTT)//Neu ngaytraDK vuot qua SNTT(30 or 31 ngay) thi thuc hien khoi lenh nay
		{
			ngaytraDK[n - 1] = ngaytraDK[n - 1] - SNTT;
			thangtraDK[n - 1] = thangmuon[n - 1] + 1;

			//if (ngaytraDK[n - 1] == 0)//Neu ngaytraDK = SNTT(30 or 31 ngay) thi thuc hien khoi lenh nay
			//{
			//	ngaytraDK[n - 1] = SNTT;
			//	thangtraDK[n - 1] = thangmuon[n - 1];
			//}
		}
		else
			thangtraDK[n - 1] = thangmuon[n - 1];

		namtraDK[n - 1] = nammuon[n - 1];

	}

	// Xu ly nhung ngay cuoi nam
	if (thangtraDK[n - 1] > 12)
	{
		thangtraDK[n - 1] = 1;//Thang tra du kien da qua thang 1 nam lien ke nam sau do
		namtraDK[n - 1] = nammuon[n - 1] + 1;//Nam tra du kien se bang nam truoc do +1
	}
}
/*-------------Ham Xuat Thong Tin Phieu Muon Sach-------------*/
/*
+)Nhan vao:
MSMuon[]; ISBNMuon[];
+)Tra ve:
Thong tin phieu muon
*/
void XuatPhieuMuon()
{

	printf("\n======================> PHIEU MUON SACH CUA DOC GIA <======================\n");
	// Xuat ma so doc gia muon sach:
	printf(" +)Ma so doc gia muon sach: ");
	puts(MSMuon[n - 1]);

	// Xuat thoi diem muon sach:
	printf(" +)Thoi diem muon sach cua do gia ma so %s la: %d-%d-%d", MSMuon[n - 1], ngaymuon[n - 1], thangmuon[n - 1], nammuon[n - 1]);

	// Xuat thoi diem tra sach du kien:
	printf("\n +)Thoi diem tra sach du kien cua doc gia co ma so %s la: %d-%d-%d", MSMuon[n - 1], ngaytraDK[n - 1], thangtraDK[n - 1], namtraDK[n - 1]);

	// Xuat danh sach cac sach duoc muon:
	printf("\n +)Danh sach ISBN cac sach duoc muon la:\n");
	for (int j = 0; j < sl[n - 1]; j++)
	{
		printf("\t +)ISBN cua quyen sach thu %d: ", j + 1);
		puts(ISBNMuon[j]);
	}

	// Xuat canh bao neu mat sach va tra sach tre:
	printf("\n LUU Y: ");
	printf("\n+) Doc gia tre han tra sach(7 ngay ke tu ngay muon sach) cho thu vien se phat 5000ð/1ngaytre.Mong doc gia thuc hien dung quy dinh cua thu vien.Xin cam on!!");
	printf("\n+) Neu mat sach se phai boi thuong 200%%  gia tri cua sach.\n");
	printf("=============================================================================\n");
}

/*-------------Ham Nhap Thong Tin Cho Phieu Tra Sach-------------*/
/*
+)Nhan vao:
MSMuon[MaxDG][25];
+)Tra ve:
Thong tin phieu tra
*/
void NhapPhieuTra()
{
	while (true)
	{
		if (h >= MaxSach)
			printf("Khong du bo nho de cap nhat thong tin sach!!");
		else
		while (h < MaxSach)
		{

			// Nhap ma doc gia tra sach:
			fflush(stdin);
			printf("\n +)Nhap ma doc gia tra sach: ");
			gets_s(MSTra[h]);

			// Nhap thoi diem tra sach thuc te:
			printf("\t+)Nhap ngay tra sach thuc te : ");
			scanf_s("%d", &ngaytraTT[h]);

			printf("\t+)Nhap thang tra sach thuc te: ");
			scanf_s("%d", &thangtraTT[h]);

			printf("\t+)Nhap nam tra sach thuc te: ");
			scanf_s("%d", &namtraTT[h]);

			h++;
			break;
		}
		break;
	}
}
/*-------------Ham Tinh Tien Phat Khi Tra Sach Tre-------------*/
/*
+)Nhan vao:
ngaytraDK,thangtraDK,namtraDK,ngaytraTT,thangtraTT,namtraTT
+)Tra ve:
So tien phat
*/
int TienPhat(int ngaytraTT, int thangtraTT, int namtraTT, int ngaytraDK, int thangtraDK, int namtraDK)
{
	int songayquahan, tien, KC1, KC2;
	//Xet truong hop namtraDK = namtraTT ; thangtraDK = thangtraTT
	if (namtraDK == namtraTT)//Xet cung nam
	{
		if (thangtraDK == thangtraTT)//Xet cung thang
		{
			if (ngaytraDK == ngaytraTT || ngaytraDK > ngaytraTT)
				return 0;
			if (ngaytraDK < ngaytraTT)
			{
				songayquahan = ngaytraTT - ngaytraDK;
				tien = songayquahan * 5000;
				return tien;
			}
		}
		if (thangtraDK < thangtraTT)//Xet khac thang tra
		{
			if (thangtraDK == 2)//Xet thangtraDK la thang 2
			{
				if (namtraDK % 4 == 0 && namtraDK % 100 != 0)//Neu la nam nhuan
				{
					//Tinh khoang cach tu ngaytraTT cua thangtraTT toi ngaytraDK cua thangtraDK
					KC1 = ngaytraTT;
					int i = thangtraTT - 1;
					for (i; i > thangtraDK; i--)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
						{
							KC1 += 31;
						}
						else
						{
							KC1 += 30;
						}
					}
					songayquahan = KC1 + (29 - ngaytraDK);//Nam khong nhuan nen lay 29 ngay cua thang 2 tru di ngaytraDK la ra so ngay qua han nam trong thang 2
					tien = songayquahan * 5000;
					return tien;

				}
				else //Neu la nam khong nhuan
				{
					//Tinh khoang cach tu ngaytraTT cua thangtraTT toi ngaytraDK cua thangtraDK
					KC1 = ngaytraTT;
					int i = thangtraTT - 1;
					for (i; i > thangtraDK; i--)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
						{
							KC1 += 31;
						}
						else
						{
							KC1 += 30;
						}
					}
					songayquahan = KC1 + (28 - ngaytraDK);//Nam khong nhuan nen lay 28 ngay cua thang 2 tru di ngaytraDK la ra so ngay qua han nam trong thang 2
					tien = songayquahan * 5000;
					return tien;
				}
			}
			else //Neu thangtraDK khac thang 2
			{
				if (thangtraDK == 1 || thangtraDK == 3 || thangtraDK == 5 || thangtraDK == 7 || thangtraDK == 8 || thangtraDK == 10 || thangtraDK == 12)//Neu thangtraDK nam trong cac thang co 31 ngay
				{
					if (namtraDK % 4 == 0 && namtraDK % 100 != 0)//Neu la nam nhuan de xet truong hop thang 2
					{
						KC1 = ngaytraTT;
						int i = thangtraTT - 1;//Xet thang ke tiep
						for (i; i > thangtraDK; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
							{
								KC1 += 31;
							}
							else if (i == 2)
							{
								KC1 += 29;//Dang xet la nam nhuan nen + 29 ngay
							}
							else
							{
								KC1 += 30;
							}
						}
						songayquahan = KC1 + (31 - ngaytraDK);
						tien = songayquahan * 5000;
						return tien;
					}
					else //Truong hop khong phai nam nhuan danh cho thang 2
					{
						KC1 = ngaytraTT;
						int i = thangtraTT - 1;//Xet thang ke tiep
						for (i; i > thangtraDK; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
							{
								KC1 += 31;
							}
							else if (i == 2)
							{
								KC1 += 28;//Dang xet la nam khong nhuan nen + 28 ngay
							}
							else
							{
								KC1 += 30;
							}
						}
						songayquahan = KC1 + (31 - ngaytraDK);
						tien = songayquahan * 5000;
						return tien;
					}
				}
				else // Xet truong hop thangtraDK la cac thang co 30 ngay
				{
					if (namtraDK % 4 == 0 && namtraDK % 100 != 0)//Neu la nam nhuan de xet truong hop thang 2
					{
						KC1 = ngaytraTT;
						int i = thangtraTT - 1;//Xet thang ke tiep
						for (i; i > thangtraDK; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
							{
								KC1 += 31;
							}
							else if (i == 2)
							{
								KC1 += 29;//Dang xet la nam nhuan nen + 29 ngay
							}
							else
							{
								KC1 += 30;
							}
						}
						songayquahan = KC1 + (30 - ngaytraDK);
						tien = songayquahan * 5000;
						return tien;
					}
					else //Truong hop khong phai nam nhuan danh cho thang 2
					{
						KC1 = ngaytraTT;
						int i = thangtraTT - 1;//Xet thang ke tiep
						for (i; i > thangtraDK; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
							{
								KC1 += 31;
							}
							else if (i == 2)
							{
								KC1 += 28;//Dang xet la nam khong nhuan nen + 28 ngay
							}
							else
							{
								KC1 += 30;
							}
						}
						songayquahan = KC1 + (30 - ngaytraDK);
						tien = songayquahan * 5000;
						return tien;
					}
				}
			}
		}
	}
	else //Xet truong hop namtraDK < namtraTT
	{
		KC2 = 0;
		//-----------------------Tinh khoang cach tu ngaytraDK,thangtraDK toi 31-12-namtraDK (1)-----------------------------

		if (thangtraDK == 2)//Xet thangtraDK la thang 2
		{
			if (namtraDK % 4 == 0 && namtraDK % 100 != 0)//Neu la nam nhuan
			{
				//Tinh khoang cach tu ngaytraTT cua thangtraTT toi ngaytraDK cua thangtraDK
				int i = thangtraDK + 1;
				for (i; i <= 12; i++)
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
					{
						KC2 += 31;
					}
					else
					{
						KC2 += 30;
					}
				}
				songayquahan = KC2 + (29 - ngaytraDK);//Nam khong nhuan nen lay 29 ngay cua thang 2 tru di ngaytraDK la ra so ngay qua han nam trong thang 2
			}
			else //Neu la nam khong nhuan
			{
				int i = thangtraDK + 1;
				for (i; i <= 12; i++)
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
					{
						KC2 += 31;
					}
					else
					{
						KC2 += 30;
					}
				}
				songayquahan = KC2 + (28 - ngaytraDK);//Nam khong nhuan nen lay 28 ngay cua thang 2 tru di ngaytraDK la ra so ngay qua han nam trong thang 2
			}
		}
		else //Neu thangtraDK khac thang 2
		{
			if (thangtraDK == 1 || thangtraDK == 3 || thangtraDK == 5 || thangtraDK == 7 || thangtraDK == 8 || thangtraDK == 10 || thangtraDK == 12)//Neu thangtraDK nam trong cac thang co 31 ngay
			{
				if (namtraDK % 4 == 0 && namtraDK % 100 != 0)//Neu la nam nhuan de xet truong hop thang 2
				{
					int i = thangtraDK + 1;//Xet thang ke tiep
					for (i; i <= 12; i++)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
						{
							KC2 += 31;
						}
						else if (i == 2)
						{
							KC2 += 29;//Dang xet la nam nhuan nen + 29 ngay
						}
						else
						{
							KC2 += 30;
						}
					}
					songayquahan = KC2 + (31 - ngaytraDK);//Vi thangtraDK dang nam trong pham vi cac thang co 31 ngay nen lay 31 tru di ngaytraDK la ra so ngay qua han trong thangtraDK
				}
				else //Truong hop khong phai nam nhuan danh cho thang 2
				{
					int i = thangtraDK + 1;//Xet thang ke tiep
					for (i; i <= 12; i++)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
						{
							KC2 += 31;
						}
						else if (i == 2)
						{
							KC2 += 28;//Dang xet la nam khong nhuan nen + 28 ngay
						}
						else
						{
							KC2 += 30;
						}
					}
					songayquahan = KC2 + (31 - ngaytraDK);
				}
			}
			else // Xet truong hop thangtraDK la cac thang co 30 ngay
			{
				if (namtraDK % 4 == 0 && namtraDK % 100 != 0)//Neu la nam nhuan de xet truong hop thang 2
				{
					int i = thangtraDK + 1;//Xet thang ke tiep
					for (i; i <= 12; i++)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
						{
							KC2 += 31;
						}
						else if (i == 2)
						{
							KC2 += 29;//Dang xet la nam nhuan nen + 29 ngay
						}
						else
						{
							KC2 += 30;
						}
					}
					songayquahan = KC2 + (30 - ngaytraDK);//Vi dang xet cac thangtraDK nam trong pham vi cac thang co 30 ngay nen lay 30 tru di ngaytraDK la ra so ngay qua han nam trong thangtraDK
				}
				else //Truong hop khong phai nam nhuan danh cho thang 2
				{
					int i = thangtraDK + 1;//Xet thang ke tiep
					for (i; i <= 12; i++)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
						{
							KC2 += 31;
						}
						else if (i == 2)
						{
							KC2 += 28;//Dang xet la nam khong nhuan nen + 28 ngay
						}
						else
						{
							KC2 += 30;
						}
					}
					songayquahan = KC2 + (30 - ngaytraDK);
				}
			}
		}

		//----------------------Tinh khoang cach tu ngaytraTT-thangtraTT-namtraTT toi 1-1-namtraTT (2)-----------------

		int songayquahan2;
		if (namtraTT % 4 == 0 && namtraTT % 100 != 0)//Xet nam nhuan
		{
			if (thangtraTT == 1)
			{
				songayquahan2 = ngaytraTT;
			}
			else if (thangtraTT == 2)
			{
				songayquahan2 = ngaytraTT + 31;//so ngay qua han se bang ngay hien tai cua thang 2 + 31 ngay thang 1
			}
			else
			{
				songayquahan2 = ngaytraTT;
				int i = thangtraTT - 1;
				for (i; i > 0; i--)
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
					{
						songayquahan2 += 31;
					}
					else if (i == 2)
					{
						songayquahan2 += 29;//Dang xet trong nam nhuan
					}
					else
					{
						songayquahan2 += 30;
					}
				}
			}
		}
		else //Neu la nam khong nhuan
		{
			if (thangtraTT == 1)
			{
				songayquahan2 = ngaytraTT;
			}
			else if (thangtraTT == 2)
			{
				songayquahan2 = ngaytraTT + 31;//so ngay qua han se bang ngay hien tai cua thang 2 + 31 ngay thang 1
			}
			else
			{
				songayquahan2 = ngaytraTT;
				int i = thangtraTT - 1;
				for (i; i > 0; i--)
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
					{
						songayquahan2 += 31;
					}
					else if (i == 2)
					{
						songayquahan2 += 28;//Dang xet trong nam khong nhuan
					}
					else
					{
						songayquahan2 += 30;
					}
				}
			}
		}

		//-----------Tinh so ngay cua cac nam o giua namtraDK - namtraTT------------------(3)

		int songayquahan3 = 0;
		for (int i = namtraTT - 1; i > namtraDK; i--)
		{
			if (i % 4 == 0 && i % 100 != 0)//Neu nam xet la nam nhuan
			{
				songayquahan3 += 366;
			}
			else //Nguoc lao nam xet khong phai la nam nhuan
			{
				songayquahan3 += 365;
			}
		}

		//Cong (1) + (2) + (3) de cho ra tong so ngay qua han
		int tongsongayquahan = songayquahan + songayquahan2 + songayquahan3;
		tien = tongsongayquahan * 5000;
		return tien;

	}
}

/*-------------Ham Xuat Thong Tin Phieu Tra Sach-------------*/
/*
+)Nhan vao:
MSTra[]; ISBNTra[];
+)Tra ve:
Thong tin phieu tra
*/

void XuatPhieuTra()
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(MSMuon[i], MSTra[h - 1]) == 0)
		{
			printf("\n======================> PHIEU TRA SACH CUA DOC GIA <======================\n");

			// Xuat ma so doc gia tra sach:
			printf(" +)Ma so doc gia tra sach: ");
			puts(MSMuon[i]);

			// Xuat thoi diem muon sach:
			printf(" +)Thoi diem muon sach cua do gia ma so %s la %d/%d/%d: ", MSMuon[i], ngaymuon[i], thangmuon[i], nammuon[i]);

			// Xuat thoi diem tra sach du kien:
			printf("\n +)Thoi diem tra sach du kien cua doc gia co ma so %s la %d/%d/%d: ", MSMuon[i], ngaytraDK[i], thangtraDK[i], namtraDK[i]);

			// Xuat thoi diem tra sach thuc te:
			printf("\n +)Thoi diem tra sach thuc te cua doc gia co ma so %s la %d/%d/%d: ", MSMuon[i], ngaytraTT[i], thangtraTT[i], namtraTT[i]);

			// Xuat danh sach cac sach duoc muon:
			printf("\n Danh sach ISBN cac sach duoc muon la:\n");
			for (int j = 0; j < sl[i]; j++)
			{
				printf("\t +)ISBN cua quyen sach thu %d: ", j + 1);
				puts(ISBNMuon[j]);
			}

			// Xuat so tien bi phat neu tra sach tre
			printf(" +)So tien phat khi tra sach tre la: %d dong\n", TienPhat(ngaytraTT[i], thangtraTT[i], namtraTT[i], ngaytraDK[i], thangtraDK[i], namtraDK[i]));

			printf("============================================================================\n");

			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("Khong co thong tin doc gia tra sach!!");
}

/*-------------Ham Xuat Thong Tin Phieu Tra Sach-------------*/

void LapPhieuMuonTra()
{
	while (true)
	{
		printf("\n=====================> MENU TUY CHON LAP PHIEU MUON TRA <=====================\n");
		printf("\t+) <30>:Thoat lap phieu .\n");
		printf("\t+) <31>:Lap phieu muon sach.\n");
		printf("\t+) <32>:Lap phieu tra sach.\n");
		printf("===============================================================================\n");

		int sochon;
		printf("\nChon chuc nang so: ");
		scanf_s("%d", &sochon);

		if (sochon == 30)
			break;

		switch (sochon)
		{
		case 31:
			NhapPhieuMuon();
			ThoiGianTraDuKien();
			XuatPhieuMuon();
			break;
		case 32:
			NhapPhieuTra();
			ThoiGianTraDuKien();
			XuatPhieuTra();
			break;
		default:
			printf("Chuc nang khong ton tai.Vui long chon chuc nang khac!!");
			break;
		}
	}
}
/*-------------Ham Xuat Thong Ke So Luong Sach Duoc Muon-------------*/
/*
+)Tra ve:
So luong sach doc gia da muon
*/
int TKSachMuon()
{
	return demsachmuon;
}

/*-------------Ham Xuat Thong Ke Doc Gia Tra Sach Tre Han-------------*/
/*
+)Nhan vao:
ngaytraTT; ngaytraDK; thangtraTT; thangtraDK; namtraTT; namtraDK;
+)Tra ve:
So luong doc gia tre han
*/
int TKDGTreHan()
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (ngaytraTT[i]>ngaytraDK[i] || thangtraTT[i] > thangtraDK[i] || namtraTT[i] > namtraDK[i])
			dem++;
	}
	return dem;
}