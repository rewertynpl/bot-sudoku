// 12d.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h> 
#include <time.h>
#include <iostream>
#include <windows.h>
#include <Shellapi.h>
#include <fstream>
#include <time.h>
#include <sys/timeb.h> // pomiar czasu 
#include <tchar.h>
using namespace std;


//http://januszg.hg.pl/teksty/budowa_pliku_bmp.html
//http://msdn.microsoft.com/en-us/library/aa383751%28VS.85%29.aspx
//http://guidecpp.cal.pl/docs,stdlibs,stdio,fread
//http://support.microsoft.com/kb/158898
//http://msdn.microsoft.com/en-us/library/dd183402%28v=VS.85%29.aspx

double (__cdecl pomiar_czasu)();
std::ostream& (__cdecl kol)(void* str,int i);
std::ostream& (__cdecl kol)(char* str,int i);
std::ostream& (__cdecl kol)(int str,int i);
std::ostream& (__cdecl kol2)(double str,int i);
void (__cdecl fun_ruchu1)(int tab_gry[1][9],int tab_ruchu[1][9][10]);
void (__cdecl fun_ruchu2)(int tab_gry[1][9],int tab_ruchu[1][9][10]);
void (__cdecl fun_ruchu3)(int tab_gry[1][9],int tab_ruchu[1][9][10]);

#define BITMAP_width11	0
#define BITMAP_height11	0
int szerokosc_1;
int wysokosc_1;

#pragma pack(push, 1)			// zeby nie dodawal sobie niepotrzebnych bitow (rozmiar nie podzielny przez 4) //
///////////////////
class cPixel11klasa
{//source kuzyn: https://github.com/tom7c3
public:
	int red11;//char red11;
	int green11;
	int blue11;
};

class cdata1111klasa
{//source kuzyn: https://github.com/tom7c3
public:
 cPixel11klasa **pixel;
 int x, wysokosc_0;
 cdata1111klasa(){};
 cdata1111klasa(int wysokosc_0,int x);
 ~cdata1111klasa(); 
 int getx() {return x;}
 int gety() {return wysokosc_0;}
};

cdata1111klasa::cdata1111klasa(int wysokosc_0,int x)
 {//source kuzyn: https://github.com/tom7c3
  this->x = x;
  this->wysokosc_0 = wysokosc_0;
  pixel = new cPixel11klasa*[wysokosc_0];
  for ( int i = 0; i < wysokosc_0; ++i )
  {
   pixel[i] = new cPixel11klasa[x];
  }
 }

cdata1111klasa::~cdata1111klasa()
 {   //source kuzyn: https://github.com/tom7c3
	 this->wysokosc_0 = wysokosc_0;
	 for(int i = 0; i < wysokosc_0; i++) 
	 delete[] pixel[i];
	 delete[] pixel;
 };



class cBMP11klasa
{
public:
	void loadBMP11(int,int,cdata1111klasa*,std::string);
} bmp11;

#pragma pack(pop)
//////////////////////
cdata1111klasa* data11;//////////////
cdata1111klasa* actual_bitmap11;/////////////
///////////////////////
//int width11;
//int height11;
int *table11;
POINT po1;
int width11;
int height11;
FILE *control_file11;
///////////////////////

void cBMP11klasa::loadBMP11(int wys,int szer,cdata1111klasa* data11,std::string path)
{//source kuzyn: https://github.com/tom7c3
	FILE *bmpfile;

	if ( (bmpfile = fopen (path.c_str(), "rb")) == NULL )
	{
		std::cout << "nieprawid³owa sciezka: " <<path.c_str()<< std::endl;
		return;
	}
	std::cout << "1odnaleziono plik: " <<path.c_str()<< std::endl;
			
	// ladowanie danych //
	fseek (bmpfile, 54, SEEK_SET);
	for ( int y = 0; y < wysokosc_1; ++y )
	{
 		for ( int x = 0; x < szerokosc_1; ++x )
		{		
			data11->pixel[y][x].blue11 = fgetc(bmpfile);			
			data11->pixel[y][x].green11 = fgetc(bmpfile);		
			data11->pixel[y][x].red11 = fgetc(bmpfile);
			fgetc(bmpfile);	   // pobieranie wartosci 0
		}		
	}
	fclose (bmpfile);	
}

void load_templates11(int wys,int szer)
{
	bmp11.loadBMP11(wys,szer,&data11[0], "D://13/szablony/0.bmp");
	bmp11.loadBMP11(wys,szer,&data11[1], "D://13/szablony/1.bmp");	
	bmp11.loadBMP11(wys,szer,&data11[2], "D://13/szablony/2.bmp");
	bmp11.loadBMP11(wys,szer,&data11[3], "D://13/szablony/3.bmp");
	bmp11.loadBMP11(wys,szer,&data11[4], "D://13/szablony/4.bmp");
	bmp11.loadBMP11(wys,szer,&data11[5], "D://13/szablony/5.bmp");
	bmp11.loadBMP11(wys,szer,&data11[6], "D://13/szablony/6.bmp");
	bmp11.loadBMP11(wys,szer,&data11[7], "D://13/szablony/7.bmp");
	bmp11.loadBMP11(wys,szer,&data11[8], "D://13/szablony/8.bmp");
	bmp11.loadBMP11(wys,szer,&data11[9], "D://13/szablony/9.bmp");
	bmp11.loadBMP11(wys,szer,&data11[10], "D://13/szablony/11.bmp");
	bmp11.loadBMP11(wys,szer,&data11[11], "D://13/szablony/12.bmp");
	bmp11.loadBMP11(wys,szer,&data11[12], "D://13/szablony/13.bmp");
	bmp11.loadBMP11(wys,szer,&data11[13], "D://13/szablony/14.bmp");
	bmp11.loadBMP11(wys,szer,&data11[14], "D://13/szablony/15.bmp");
	bmp11.loadBMP11(wys,szer,&data11[15], "D://13/szablony/16.bmp");
	bmp11.loadBMP11(wys,szer,&data11[16], "D://13/szablony/17.bmp");
	bmp11.loadBMP11(wys,szer,&data11[17], "D://13/szablony/18.bmp");
	bmp11.loadBMP11(wys,szer,&data11[18], "D://13/szablony/19.bmp");
	bmp11.loadBMP11(wys,szer,&data11[19], "D://13/szablony/21.bmp");
	bmp11.loadBMP11(wys,szer,&data11[20], "D://13/szablony/22.bmp");
	bmp11.loadBMP11(wys,szer,&data11[21], "D://13/szablony/23.bmp");
	bmp11.loadBMP11(wys,szer,&data11[22], "D://13/szablony/24.bmp");
	bmp11.loadBMP11(wys,szer,&data11[23], "D://13/szablony/25.bmp");
	bmp11.loadBMP11(wys,szer,&data11[24], "D://13/szablony/26.bmp");
	bmp11.loadBMP11(wys,szer,&data11[25], "D://13/szablony/27.bmp");
	bmp11.loadBMP11(wys,szer,&data11[26], "D://13/szablony/28.bmp");
	bmp11.loadBMP11(wys,szer,&data11[27], "D://13/szablony/29.bmp");
	bmp11.loadBMP11(wys,szer,&data11[28], "D://13/szablony/31.bmp");
	bmp11.loadBMP11(wys,szer,&data11[29], "D://13/szablony/32.bmp");
	bmp11.loadBMP11(wys,szer,&data11[30], "D://13/szablony/33.bmp");
	bmp11.loadBMP11(wys,szer,&data11[31], "D://13/szablony/34.bmp");
	bmp11.loadBMP11(wys,szer,&data11[32], "D://13/szablony/35.bmp");
	bmp11.loadBMP11(wys,szer,&data11[33], "D://13/szablony/36.bmp");
	bmp11.loadBMP11(wys,szer,&data11[34], "D://13/szablony/37.bmp");
	bmp11.loadBMP11(wys,szer,&data11[35], "D://13/szablony/38.bmp");
	bmp11.loadBMP11(wys,szer,&data11[36], "D://13/szablony/39.bmp");
	
}

void create_new_bitmap111(int wys,int szer, HWND window,_TCHAR* str,int x2,int y2,int flaga)//
{
//source:
//https://msdn.microsoft.com/pl-pl/library/windows/desktop/dd183402(v=vs.85).aspx
//https://4programmers.net/Forum/C_i_C++/71931-C++_Zrzuty_ekranu

//https://www.codeproject.com/script/Content/ViewAssociatedFile.aspx?rzp=%2FKB%2Ffiles%2Fzip_utils%2F%2Fzip_utils_src.zip&zep=examples%2Fsimple%2Fsimple.cpp&obid=7530&obtid=2&ovid=1
	HANDLE hFile;//plik
	HDC hdcScreen;
    HDC hdcWindow;
    HDC hdcMemDC = NULL;
    HBITMAP hbmScreen = NULL;
    BITMAP bmpScreen;
	/*
	lub:
	BYTE *bits1; //<-- tu zapisane s¹ piksele
	HBITMAP hbm1 = CreateDIBSection(sdc1,bi1,DIB_RGB_COLORS,(void**)&bits1,NULL,0);
	HDC hdc1 = CreateCompatibleDC(sdc1); 
	HGDIOBJ hold = SelectObject(hdc1,hbm1);
	*/
	//Retrieve the handle to a display device context for the client area of the window. 
    hdcScreen = GetDC(NULL);
    hdcWindow = GetDC(window);
    //Create a compatible DC which is used in a BitBlt from the window DC
    hdcMemDC = CreateCompatibleDC(hdcWindow); 

    if(!hdcMemDC)
    {
       cout<<"CreateCompatibleDC has failed Failed"<<endl;
       goto done;
    }
	//////////
	//Get the client area for size calculation
    //RECT rcClient; //pobieranie x i y okna
    //GetClientRect(hWnd, &rcClient); //pobieranie x i y okna
	//////////
	//Create a compatible bitmap from the Window DC
    //hbmScreen = CreateCompatibleBitmap(hdcWindow, rcClient.right-rcClient.left, rcClient.bottom-rcClient.top);
    hbmScreen = CreateCompatibleBitmap(hdcWindow,szer,wys);
    
	if(!hbmScreen)
    {
        cout<<"CreateCompatibleBitmap Failed Failed"<<endl;
        goto done;
    }
	//Select the compatible bitmap into the compatible memory DC.
    SelectObject(hdcMemDC,hbmScreen);


	if(flaga==1)
	{
		///////////////////////////////////////////////////////////////////////////////
		//Bit block transfer into our compatible memory DC.						    ///
		if(!BitBlt(hdcMemDC,(-36+x2),(-172+y2),1600,1600,hdcWindow,0,0,SRCCOPY))///
		{																			///	
			cout<<"BitBlt has failed Failed"<<endl;									///			
			goto done;																///
		}																			///
		///////////////////////////////////////////////////////////////////////////////
	}


    //Get the BITMAP from the HBITMAP
    GetObject(hbmScreen,sizeof(BITMAP),&bmpScreen);

	BITMAPFILEHEADER   bmfHeader;  //file  
    BITMAPINFOHEADER   bi;//info
     
    bi.biSize = sizeof(BITMAPINFOHEADER);    
    bi.biWidth = bmpScreen.bmWidth;    
    bi.biHeight = bmpScreen.bmHeight;  
    bi.biPlanes = 1;    
    bi.biBitCount = 32;    
    bi.biCompression = BI_RGB;    
    bi.biSizeImage = 0;  
    bi.biXPelsPerMeter = 0;    
    bi.biYPelsPerMeter = 0;    
    bi.biClrUsed = 0;    
    bi.biClrImportant = 0;


	DWORD dwBmpSize = ((bmpScreen.bmWidth * bi.biBitCount + 31) / 32) * 4 * bmpScreen.bmHeight;

	HANDLE hDIB = GlobalAlloc(GHND,dwBmpSize); 
    char *lpbitmap = (char *)GlobalLock(hDIB);    

    //Gets the "bits" from the bitmap and copies them into a buffer 
    //which is pointed to by lpbitmap.
    GetDIBits(hdcWindow, hbmScreen, 0,(UINT)bmpScreen.bmHeight,lpbitmap,(BITMAPINFO *)&bi, DIB_RGB_COLORS);

	//A file is created, this is where we will save the screen capture.
	hFile=CreateFile((LPTSTR) str,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	
	//Add the size of the headers to the size of the bitmap to get the total file size
    DWORD dwSizeofDIB = dwBmpSize + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	//Offset to where the actual bitmap bits start.
    bmfHeader.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER); 
    //Size of the file
    bmfHeader.bfSize = dwSizeofDIB;	
	//bfType must always be BM for Bitmaps
    bmfHeader.bfType = 0x4D42; //BM   

	DWORD dwBytesWritten = 0;
	WriteFile(hFile, (LPSTR)&bmfHeader, sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
    WriteFile(hFile, (LPSTR)&bi, sizeof(BITMAPINFOHEADER), &dwBytesWritten, NULL);
    WriteFile(hFile, (LPSTR)lpbitmap, dwBmpSize, &dwBytesWritten, NULL);

	//Unlock and Free the DIB from the heap
    GlobalUnlock(hDIB);    
    GlobalFree(hDIB);

    //Close the handle for the file that was created
    CloseHandle(hFile);
       
    //Clean up
done:
    DeleteObject(hbmScreen);
    DeleteObject(hdcMemDC);
    ReleaseDC(NULL,hdcScreen);
//    ReleaseDC(hWnd,hdcWindow);
}
////////////////////////////////////////////////////////////////
int find_bitmap11(int m)
{
	bool _break = false;
	int counter = 0;
	int actual_number = -1;

	for ( int i = 0; i < 37; ++i )
	{
		for ( int y = 0; y < wysokosc_1; ++y )
		{
			for ( int x = 0; x < szerokosc_1; ++x )
			{
				int a1=actual_bitmap11[m].pixel[y][x].blue11;
				int a2=data11[i].pixel[y][x].blue11;
				int b1=actual_bitmap11[m].pixel[y][x].green11;
				int b2=data11[i].pixel[y][x].green11;
				int c1=actual_bitmap11[m].pixel[y][x].red11;
				int c2=data11[i].pixel[y][x].red11;
				
				if(((a1<=a2-30 )||(a1>=a2+30 ))&&((b1<=b2-30 )||(b1>=b2+30 ))&&((c1<=c2-100)||(c1>=c2+100))
				 ||((a1<=a2-30 )||(a1>=a2+30 ))&&((b1<=b2-100)||(b1>=b2+100))&&((c1<=c2-30 )||(c1>=c2+30 ))
				 ||((a1<=a2-100)||(a1>=a2+100))&&((b1<=b2-30 )||(b1>=b2+30 ))&&((c1<=c2-30 )||(c1>=c2+30 )))
				{
					//_break = true;
					//counter = 0;
					//break;
				}
				else
				{
					++counter;
				}
				
				if ( counter == szerokosc_1*wysokosc_1 -34)
				{
					actual_number = i;
					std::cout << "Bitmapy sa sobie rowne" << std::endl;
					std::cout <<" nr szablonu: "<<i<<" actual_number=  "<< actual_number <<" counter= "<< counter <<" m= "<< m+1 << std::endl;
					_break = true;
					counter = 0;
					goto koniec;
					break;
				}
				else if(y>=wysokosc_1-1&&x>=szerokosc_1-1)
				{
					std::cout << "Bitmapy sa nierowne" << std::endl;
					std::cout <<" nr szablonu: "<<i<<" actual_number=  "<< actual_number <<" counter= "<< counter <<" m= "<< m+1 << std::endl;
				}
				


			}
			if ( _break == true )
			{
				_break = false;
				break;
			}	
		}
		counter = 0;
		//if ( actual_number != -1 )
		//	break;
	}
	koniec:;
	return actual_number;
}
//////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	srand((int) time(0));
	szerokosc_1=18;
	wysokosc_1=28;
	data11=new cdata1111klasa[65];//////////////////////
	for(int i=0;i<65;i++)
	{
	data11[i].cdata1111klasa::cdata1111klasa(wysokosc_1,szerokosc_1);//////////////
	}
	actual_bitmap11=new cdata1111klasa[82];/////////////////////////	
	for(int i=0;i<82;i++)
	{
	actual_bitmap11[i].cdata1111klasa::cdata1111klasa(wysokosc_1,szerokosc_1);//////////////
	}
	//actual_bitmap11=new cdata1111klasa[1];/////////////////////////
	//actual_bitmap11[0].cdata1111klasa::cdata1111klasa(wysokosc_1,szerokosc_1);////////////////	
	//system("pause");

	//SetCursorPos(width11+200, height11+200);		
	//mouse_event(MOUSEEVENTF_LEFTDOWN,0 ,0,0,0);

	//Sleep(100);
	

	load_templates11(wysokosc_1,szerokosc_1);	

	//system("pause");
	int w11 = szerokosc_1, h11 = wysokosc_1;
	int bw1 = szerokosc_1, bh1 = wysokosc_1;
	int bw41=(bw1+3)&0xFFFFFFFC;
	//HANDLE hf;	
	BITMAPINFO bi1; 
	bi1.bmiHeader.biBitCount=24; 
	bi1.bmiHeader.biClrImportant=0;
    bi1.bmiHeader.biClrUsed=0;
	bi1.bmiHeader.biCompression=BI_RGB; 
	bi1.bmiHeader.biHeight=bh1;
    bi1.bmiHeader.biPlanes=1; 
	bi1.bmiHeader.biSize=40; 
	bi1.bmiHeader.biSizeImage=bw41*bh1*3;
	//bi1.bmiHeader.biSizeImage=bw*bh*3;
    bi1.bmiHeader.biWidth=bw1; 
	bi1.bmiHeader.biXPelsPerMeter=3780; 
	bi1.bmiHeader.biYPelsPerMeter=3780;
    bi1.bmiColors[0].rgbBlue=0; 
	bi1.bmiColors[0].rgbGreen=0; 
	bi1.bmiColors[0].rgbRed=0; 
	bi1.bmiColors[0].rgbReserved=0;

	//Sleep(1000);
	po1.x = BITMAP_width11;
	po1.y = BITMAP_height11;
	POINT p1;
	HWND he1,hf1;
	GetCursorPos(&p1);
	//he = WindowFromPoint(p1);
	he1=GetDesktopWindow();
//he1=FindWindow(_T("IEFrame"),_T("WorldWinner Cash Competitions on GSN - Windows Internet Explorer"));
	//hf1 = WindowFromPoint(po1);
	//ClientToScreen(he,&po1);
	width11 = po1.x;
	height11 = po1.y;

	////////////////
	std::fstream plik1;
	//plik.open("c:\\dane.txt",std::ios::in|std::ios::out);//czeba miec utworzony plik an dysku inaczej nei chce dzialac
	//plik1.open("c:\\dane1.txt",std::ios::in|std::ios::out);

	plik1.open("dane4.txt",std::ios::in|std::ios::out);
	if( plik1.good() == true )
	{
		std::cout << "Uzyskano dostep do pliku! dane4.txt" << std::endl;
		//tu operacje na pliku
	} else std::cout << "Dostep do pliku zostal zabroniony! dane4.txt" << std::endl;

////////////////////////////////////////
	_TCHAR str[81][15]={
		{_T("sample1.bmp")},
		{_T("sample2.bmp")},
		{_T("sample3.bmp")},
		{_T("sample4.bmp")},
		{_T("sample5.bmp")},
		{_T("sample6.bmp")},
		{_T("sample7.bmp")},
		{_T("sample8.bmp")},
		{_T("sample9.bmp")},
		{_T("sample10.bmp")},
		{_T("sample11.bmp")},
		{_T("sample12.bmp")},
		{_T("sample13.bmp")},
		{_T("sample14.bmp")},
		{_T("sample15.bmp")},
		{_T("sample16.bmp")},
		{_T("sample17.bmp")},
		{_T("sample18.bmp")},
		{_T("sample19.bmp")},
		{_T("sample20.bmp")},
		{_T("sample21.bmp")},
		{_T("sample22.bmp")},
		{_T("sample23.bmp")},
		{_T("sample24.bmp")},
		{_T("sample25.bmp")},
		{_T("sample26.bmp")},
		{_T("sample27.bmp")},
		{_T("sample28.bmp")},
		{_T("sample29.bmp")},
		{_T("sample30.bmp")},
		{_T("sample31.bmp")},
		{_T("sample32.bmp")},
		{_T("sample33.bmp")},
		{_T("sample34.bmp")},
		{_T("sample35.bmp")},
		{_T("sample36.bmp")},
		{_T("sample37.bmp")},
		{_T("sample38.bmp")},
		{_T("sample39.bmp")},
		{_T("sample40.bmp")},
		{_T("sample41.bmp")},
		{_T("sample42.bmp")},
		{_T("sample43.bmp")},
		{_T("sample44.bmp")},
		{_T("sample45.bmp")},
		{_T("sample46.bmp")},
		{_T("sample47.bmp")},
		{_T("sample48.bmp")},
		{_T("sample49.bmp")},
		{_T("sample50.bmp")},
		{_T("sample51.bmp")},
		{_T("sample52.bmp")},
		{_T("sample53.bmp")},
		{_T("sample54.bmp")},
		{_T("sample55.bmp")},
		{_T("sample56.bmp")},
		{_T("sample57.bmp")},
		{_T("sample58.bmp")},
		{_T("sample59.bmp")},
		{_T("sample60.bmp")},
		{_T("sample61.bmp")},
		{_T("sample62.bmp")},
		{_T("sample63.bmp")},
		{_T("sample64.bmp")},
		{_T("sample65.bmp")},
		{_T("sample66.bmp")},
		{_T("sample67.bmp")},
		{_T("sample68.bmp")},
		{_T("sample69.bmp")},
		{_T("sample70.bmp")},
		{_T("sample71.bmp")},
		{_T("sample72.bmp")},
		{_T("sample73.bmp")},
		{_T("sample74.bmp")},
		{_T("sample75.bmp")},
		{_T("sample76.bmp")},
		{_T("sample77.bmp")},
		{_T("sample78.bmp")},
		{_T("sample79.bmp")},
		{_T("sample80.bmp")},
		{_T("sample81.bmp")}}; 
	
	char str2[81][15]={
		{"sample1.bmp"},
		{"sample2.bmp"},
		{"sample3.bmp"},
		{"sample4.bmp"},
		{"sample5.bmp"},
		{"sample6.bmp"},
		{"sample7.bmp"},
		{"sample8.bmp"},
		{"sample9.bmp"},
		{"sample10.bmp"},
		{"sample11.bmp"},
		{"sample12.bmp"},
		{"sample13.bmp"},
		{"sample14.bmp"},
		{"sample15.bmp"},
		{"sample16.bmp"},
		{"sample17.bmp"},
		{"sample18.bmp"},
		{"sample19.bmp"},
		{"sample20.bmp"},
		{"sample21.bmp"},
		{"sample22.bmp"},
		{"sample23.bmp"},
		{"sample24.bmp"},
		{"sample25.bmp"},
		{"sample26.bmp"},
		{"sample27.bmp"},
		{"sample28.bmp"},
		{"sample29.bmp"},
		{"sample30.bmp"},
		{"sample31.bmp"},
		{"sample32.bmp"},
		{"sample33.bmp"},
		{"sample34.bmp"},
		{"sample35.bmp"},
		{"sample36.bmp"},
		{"sample37.bmp"},
		{"sample38.bmp"},
		{"sample39.bmp"},
		{"sample40.bmp"},
		{"sample41.bmp"},
		{"sample42.bmp"},
		{"sample43.bmp"},
		{"sample44.bmp"},
		{"sample45.bmp"},
		{"sample46.bmp"},
		{"sample47.bmp"},
		{"sample48.bmp"},
		{"sample49.bmp"},
		{"sample50.bmp"},
		{"sample51.bmp"},
		{"sample52.bmp"},
		{"sample53.bmp"},
		{"sample54.bmp"},
		{"sample55.bmp"},
		{"sample56.bmp"},
		{"sample57.bmp"},
		{"sample58.bmp"},
		{"sample59.bmp"},
		{"sample60.bmp"},
		{"sample61.bmp"},
		{"sample62.bmp"},
		{"sample63.bmp"},
		{"sample64.bmp"},
		{"sample65.bmp"},
		{"sample66.bmp"},
		{"sample67.bmp"},
		{"sample68.bmp"},
		{"sample69.bmp"},
		{"sample70.bmp"},
		{"sample71.bmp"},
		{"sample72.bmp"},
		{"sample73.bmp"},
		{"sample74.bmp"},
		{"sample75.bmp"},
		{"sample76.bmp"},
		{"sample77.bmp"},
		{"sample78.bmp"},
		{"sample79.bmp"},
		{"sample80.bmp"},
		{"sample81.bmp"}}; 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int tab_gry[9][9]={0};
	int tab_gry_flag[9][9]={0};
	int tab_ruchu[9][9][10]={0};
	int index10=0;
	int przes_szer=0;
	int przes_wys=0;

	cout<<"zrzut ekranu:"<<endl;
	system("pause");

	for(int wys=0;wys<9;wys++)
	{
		for(int szer=0;szer<9;szer++)
		{
			Sleep(5);
			przes_szer=szer*49;
			przes_wys=wys*49;
			if(szer==3||szer==4||szer==5){przes_szer=przes_szer+8;}
			if(szer==6||szer==7||szer==8){przes_szer=przes_szer+16;}
			if(wys==3||wys==4||wys==5){przes_wys=przes_wys+8;}
			if(wys==6||wys==7||wys==8){przes_wys=przes_wys+16;}
			create_new_bitmap111(wysokosc_1,szerokosc_1,he1,str[9*wys+szer],-przes_szer-15,-przes_wys-9,1);
			bmp11.loadBMP11(wysokosc_1,szerokosc_1,&actual_bitmap11[9*wys+szer],str2[9*wys+szer]);
		}
	}
	//////////
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{
			jeszczeraz1:;
			//if(kbhit()==1){goto od_nowa;}

			int actual_number1 = find_bitmap11(9*wysokosc+szerokosc);
			if ( actual_number1 == -1 )
			{
				index10++;			
				if(index10<10)
				{
					Sleep(3);
					przes_szer=szerokosc*49;
					przes_wys=wysokosc*49;
					if(szerokosc==3||szerokosc==4||szerokosc==5){przes_szer=przes_szer+8;}
					if(szerokosc==6||szerokosc==7||szerokosc==8){przes_szer=przes_szer+16;}
					if(wysokosc==3||wysokosc==4||wysokosc==5){przes_wys=przes_wys+8;}
					if(wysokosc==6||wysokosc==7||wysokosc==8){przes_wys=przes_wys+16;}
					create_new_bitmap111(wysokosc_1,szerokosc_1,he1,str[9*wysokosc+szerokosc],-przes_szer-15,-przes_wys-9,1);
					bmp11.loadBMP11(wysokosc_1,szerokosc_1,&actual_bitmap11[9*wysokosc+szerokosc],str2[9*wysokosc+szerokosc]);
					if(index10%5==0){cout<<"actual_number1= "<<actual_number1<<" index10= "<<index10<<endl;plik1<<"actual_number1= "<<actual_number1<<" index10= "<<index10<<endl;}
					else{}
					goto jeszczeraz1;
				}
				cout<<endl;
				kol("actual_number1= ",15),kol(actual_number1,10),kol(" index10= ",15),kol(index10,10),kol(" ",7)<<endl<<endl;
				plik1<<"actual_number1= "<<actual_number1<<" index10= "<<index10<<" "<<endl<<endl;
				//system("pause");	
				index10=0;
			//	std::cout << "nieprawidlowy uchwyt okna, ustaw kursor na wlasciwe okno" << std::endl;
			//	system("pause");
			//	return 0;
			}
			if(actual_number1>=10&&actual_number1<=18){actual_number1=actual_number1-9;}
			if(actual_number1>=19&&actual_number1<=27){actual_number1=actual_number1-18;}
			if(actual_number1>=28&&actual_number1<=36){actual_number1=actual_number1-27;}
			tab_gry[wysokosc][szerokosc]=actual_number1;
			if(actual_number1>0)
			{
			tab_gry_flag[wysokosc][szerokosc]=1;
			}
			else{tab_gry_flag[wysokosc][szerokosc]=0;}
		}
	}

	cout<<"po zrzucie ekranu:"<<endl;
	system("pause");
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{
			cout<<tab_gry[wysokosc][szerokosc]<<" ";

		}
		cout<<endl;
	}
		cout<<endl;

	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{
			for(int i=0;i<10;i++)
			{
			tab_ruchu[wysokosc][szerokosc][i]=i;
			}
		}
	}

	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			for(int i=0;i<10;i++)
			{
				if(tab_gry[wysokosc][szerokosc]==i)
				{
				tab_ruchu[wysokosc][szerokosc][i]=i;
				}
				else if(tab_gry[wysokosc][szerokosc]>0)
				{
				tab_ruchu[wysokosc][szerokosc][i]=0;
				}
			}
		}
	}
	

	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=8;szerokosc<9;szerokosc++)
		{		
			for(int i=0;i<10;i++)
			{
				cout<<tab_ruchu[wysokosc][szerokosc][i]<<" ";
			}
			cout<<"|";
		}
		cout<<endl;
	}
	cout<<endl;


	//////////
	fun_ruchu1(tab_gry,tab_ruchu);
	
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=8;szerokosc<9;szerokosc++)
		{		
			for(int i=0;i<10;i++)
			{
				cout<<tab_ruchu[wysokosc][szerokosc][i]<<" ";
			}
			cout<<"|";
		}
		cout<<endl;
	}
	cout<<endl;
	fun_ruchu2(tab_gry,tab_ruchu);
	
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=8;szerokosc<9;szerokosc++)
		{		
			for(int i=0;i<10;i++)
			{
				cout<<tab_ruchu[wysokosc][szerokosc][i]<<" ";
			}
			cout<<"|";
		}
		cout<<endl;
	}
	cout<<endl;
	fun_ruchu3(tab_gry,tab_ruchu);
	//////////
	
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=8;szerokosc<9;szerokosc++)
		{		
			for(int i=0;i<10;i++)
			{
				cout<<tab_ruchu[wysokosc][szerokosc][i]<<" ";
			}
			cout<<"|";
		}
		cout<<endl;
	}
	cout<<endl;

	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			for(int i=0;i<10;i++)
			{
				if(tab_ruchu[wysokosc][szerokosc][i]!=0)
				{
					cout<<tab_ruchu[wysokosc][szerokosc][i]<<" ";
				}
			}
			cout<<"|";
		}
		cout<<endl;
	}
	cout<<endl;



	system("pause");
	return 0;
}

////////////////////////////////
std::ostream& (__cdecl kol)(void* str,int i)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, i);
	return  cout<<str;
}
////////////////////////////////
std::ostream& (__cdecl kol)(int str,int i)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, i);
	return cout<<str;
}
////////////////////////////////
std::ostream& (__cdecl kol2)(double str,int i)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, i);
	return cout<<str;
}
////////////////////////////////
std::ostream& (__cdecl kol)(char* str,int i)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, i);
	return cout<<str;
}
////////////////////////////////

/////////////////////////////////////////////////////////////
double (__cdecl pomiar_czasu)()
{
   struct timeb czas;
   double wynik;

   // Wypelnij strukture 'czas' biezacym czasem
   ftime(&czas);

   // Teraz mamy:
   // * czas.time - liczba sekund, ktore uplynely od godziny
   //   00:00 czasu GMT dnia 1.01.1970
   // * czas.millitm - offset w milisekundach

   // Skonwertuj czas do typu double
   wynik = (double) czas.time;
   wynik += (double) czas.millitm / 1000.0;

   //Zwroc wynik
   return wynik;
}
/////////////////////////////////////////////////////////////
void (__cdecl fun_ruchu1)(int tab_gry[1][9],int tab_ruchu[1][9][10])
{
	int tmp1=0;
	//////////-1
	for(int wysokosc=0;wysokosc<3;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<3;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<3;wys++)
			{
				for(int szer=0;szer<3;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-2
	for(int wysokosc=3;wysokosc<6;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<3;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=3;wys<6;wys++)
			{
				for(int szer=0;szer<3;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-3
	for(int wysokosc=6;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<3;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=6;wys<9;wys++)
			{
				for(int szer=0;szer<3;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-4
	for(int wysokosc=0;wysokosc<3;wysokosc++)
	{
		for(int szerokosc=3;szerokosc<6;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<3;wys++)
			{
				for(int szer=3;szer<6;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-5
	for(int wysokosc=3;wysokosc<6;wysokosc++)
	{
		for(int szerokosc=3;szerokosc<6;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=3;wys<6;wys++)
			{
				for(int szer=3;szer<6;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-6
	for(int wysokosc=6;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=3;szerokosc<6;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=6;wys<9;wys++)
			{
				for(int szer=3;szer<6;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-7
	for(int wysokosc=0;wysokosc<3;wysokosc++)
	{
		for(int szerokosc=6;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<3;wys++)
			{
				for(int szer=6;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-8
	for(int wysokosc=3;wysokosc<6;wysokosc++)
	{
		for(int szerokosc=6;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=3;wys<6;wys++)
			{
				for(int szer=6;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-9
	for(int wysokosc=6;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=6;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=6;wys<9;wys++)
			{
				for(int szer=6;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
}//koniec funkcji
//////////////////////////////////////////

//////////////////////////////////////////
void (__cdecl fun_ruchu2)(int tab_gry[1][9],int tab_ruchu[1][9][10])
{
	int tmp1=0;
	//////////-1
	for(int wysokosc=0;wysokosc<1;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<1;wys++)
			{
				for(int szer=0;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-2
	for(int wysokosc=1;wysokosc<2;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=1;wys<2;wys++)
			{
				for(int szer=0;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-3
	for(int wysokosc=2;wysokosc<3;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=2;wys<3;wys++)
			{
				for(int szer=0;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-4
	for(int wysokosc=3;wysokosc<4;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=3;wys<4;wys++)
			{
				for(int szer=0;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-5
	for(int wysokosc=4;wysokosc<5;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=4;wys<5;wys++)
			{
				for(int szer=0;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-6
	for(int wysokosc=5;wysokosc<6;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=5;wys<6;wys++)
			{
				for(int szer=0;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-7
	for(int wysokosc=6;wysokosc<7;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=6;wys<7;wys++)
			{
				for(int szer=0;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-8
	for(int wysokosc=7;wysokosc<8;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=7;wys<8;wys++)
			{
				for(int szer=0;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-9
	for(int wysokosc=8;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=8;wys<9;wys++)
			{
				for(int szer=0;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
}//koniec funkcji
//////////////////////////////////////////

//////////////////////////////////////////
void (__cdecl fun_ruchu3)(int tab_gry[1][9],int tab_ruchu[1][9][10])
{
	int tmp1=0;
	//////////-1
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=0;szerokosc<1;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<9;wys++)
			{
				for(int szer=0;szer<1;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-2
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=1;szerokosc<2;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<9;wys++)
			{
				for(int szer=1;szer<2;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-3
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=2;szerokosc<3;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<9;wys++)
			{
				for(int szer=2;szer<3;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-4
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=3;szerokosc<4;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<9;wys++)
			{
				for(int szer=3;szer<4;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-5
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=4;szerokosc<5;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<9;wys++)
			{
				for(int szer=4;szer<5;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-6
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=5;szerokosc<6;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<9;wys++)
			{
				for(int szer=5;szer<6;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-7
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=6;szerokosc<7;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<9;wys++)
			{
				for(int szer=6;szer<7;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-8
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=7;szerokosc<8;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<9;wys++)
			{
				for(int szer=7;szer<8;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
	//////////-9
	for(int wysokosc=0;wysokosc<9;wysokosc++)
	{
		for(int szerokosc=8;szerokosc<9;szerokosc++)
		{		
			tmp1=tab_gry[wysokosc][szerokosc];
			for(int wys=0;wys<9;wys++)
			{
				for(int szer=8;szer<9;szer++)
				{					
					for(int i=0;i<10;i++)
					{
						if(tmp1==i)
						{
							tab_ruchu[wys][szer][i]=0;
						}
					}
				}
			}
		}
	}
}//koniec funkcji
//////////////////////////////////////////