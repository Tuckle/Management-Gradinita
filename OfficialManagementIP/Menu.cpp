#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "MainHeader.h"
#include <strsafe.h>//for stringcbprintf
#include <afxres.h>
#include <WinUser.h>

HWND windowHandle, groupsHandle, addHandle, srchHandle, editHandle;
HWND mviewgroups, madd, msearch;//Menu
HWND ListBox1, StaticText, Btn1, Btn2, Btn3;//Groups
HWND gview, gedit, gback;//Groups
HWND ListBox2, StaticText1, SearchBox;//Search
HWND sview, sedit, sback;//Search
HWND Txt1, Txt2, Txt3, Txt4, Txt5, Txt6, Txt7;//Edit
HWND esave, edelete, ecancel;//Edit
HWND txt1, txt2, txt3, txt4, txt5, txt6, txt7;//Add
HWND aadd, acancel;//Add
WNDPROC edit1,edit2,edit3,edit4,edit5,edit6,edit7,srchbox;
WNDCLASSEX WC, GR, ADD, SRCH, EDIT;
HDC hdcMem = NULL; HBITMAP hBmp = NULL; HBITMAP hBmpOld = NULL;


//Others
int which_group = 0, copy_i = -1, which_txt = 0, grbtn = 1, curs_set = -1, cursel_set = -1;
bool isgroup = false, view_was_clicked = false, found_image = true, list_focus = false, tab_press = false, is_edit = false, upordown = false;
void LoadPic()
{
	if (hdcMem)
		return;  // already loaded, no need to load it again

				 // note:  here you must put the file name in a TEXT() macro.  DO NOT CAST IT TO LPCSTR
	hBmp = (HBITMAP)LoadImage(NULL, TEXT("managkids.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (!hBmp)  // the load failed (couldn't find file?  Invalid file?)
	{
		if (found_image == true) {
			found_image = false;
			MessageBoxA(windowHandle, "Imaginea nu a putut fi gasita sau nu exista!", "Error", 0);
		}
		return;
	}

	hdcMem = CreateCompatibleDC(NULL);
	hBmpOld = (HBITMAP)SelectObject(hdcMem, hBmp);
}
void FreePic()
{
	if (hdcMem)
	{
		SelectObject(hdcMem, hBmpOld);
		DeleteObject(hBmp);
		DeleteDC(hdcMem);
	}
}
//////edit edit edit this!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool srch_ifexists(int param, char *info) {
	switch (param)
	{
	case 1: {
		int ID = atoi(info);
		int max_lgth = max(lgth_1group, max(lgth_2group, lgth_3group));
		for (int i = 0; i < max_lgth; i++) {
			if (i < lgth_1group && ID == Group1[i].ID)
			{
				if (which_group == 1 && i == copy_i)
				{

				}
				else return false;
			}
			if (i < lgth_2group && ID == Group2[i].ID)
			{
				if (which_group == 2 && i == copy_i)
				{

				}
				else return false;
			}
			if (i < lgth_3group && ID == Group3[i].ID)
			{
				if (which_group == 3 && i == copy_i)
				{

				}
				else return false;
			}
		}
		break;
		}
	case 2:{
		int max_lgth = max(lgth_1group, max(lgth_2group, lgth_3group));
		for (int i = 0; i < max_lgth; i++) {
			if (i < lgth_1group && info == Group1[i].Nume){
				if (which_group == 1 && i == copy_i){}
				else return false;
			}
			if (i < lgth_2group && info == Group2[i].Nume){
				if (which_group == 2 && i == copy_i){}
				else return false;
			}
			if (i < lgth_3group && info == Group3[i].Nume){
				if (which_group == 3 && i == copy_i){}
				else return false;
			}
		}
		break;
	}
	case 3: {
		int max_lgth = max(lgth_1group, max(lgth_2group, lgth_3group));
		for (int i = 0; i < max_lgth; i++) {
			if (i < lgth_1group && info == Group1[i].Prenume) {
				if (which_group == 1 && i == copy_i) {}
				else return false;
			}
			if (i < lgth_2group && info == Group2[i].Prenume) {
				if (which_group == 2 && i == copy_i) {}
				else return false;
			}
			if (i < lgth_3group && info == Group3[i].Prenume) {
				if (which_group == 3 && i == copy_i) {}
				else return false;
			}
		}
		break;
	}
	case 4: {
		int Varsta = atoi(info);
		int max_lgth = max(lgth_1group, max(lgth_2group, lgth_3group));
		for (int i = 0; i < max_lgth; i++) {
			if (i < lgth_1group && Varsta == Group1[i].Varsta) {
				if (which_group == 1 && i == copy_i) {}
				else return false;
			}
			if (i < lgth_2group && Varsta == Group2[i].Varsta) {
				if (which_group == 2 && i == copy_i) {}
				else return false;
			}
			if (i < lgth_3group && Varsta == Group3[i].Varsta) {
				if (which_group == 3 && i == copy_i) {}
				else return false;
			}
		}
		break;
	}
	case 5: {
		int max_lgth = max(lgth_1group, max(lgth_2group, lgth_3group));
		for (int i = 0; i < max_lgth; i++) {
			if (i < lgth_1group && info == Group1[i].Adresa) {
				if (which_group == 1 && i == copy_i) {}
				else return false;
			}
			if (i < lgth_2group && info == Group2[i].Adresa) {
				if (which_group == 2 && i == copy_i) {}
				else return false;
			}
			if (i < lgth_3group && info == Group3[i].Adresa) {
				if (which_group == 3 && i == copy_i) {}
				else return false;
			}
		}
		break;
	}
	case 6: {
		int max_lgth = max(lgth_1group, max(lgth_2group, lgth_3group));
		for (int i = 0; i < max_lgth; i++) {
			if (i < lgth_1group && info == Group1[i].Nume_mama) {
				if (which_group == 1 && i == copy_i) {}
				else return false;
			}
			if (i < lgth_2group && info == Group2[i].Nume_mama) {
				if (which_group == 2 && i == copy_i) {}
				else return false;
			}
			if (i < lgth_3group && info == Group3[i].Nume_mama) {
				if (which_group == 3 && i == copy_i) {}
				else return false;
			}
		}
		break;
	}
	case 7: {
		int max_lgth = max(lgth_1group, max(lgth_2group, lgth_3group));
		for (int i = 0; i < max_lgth; i++) {
			if (i < lgth_1group && info == Group1[i].Nume_tata) {
				if (which_group == 1 && i == copy_i) {}
				else return false;
			}
			if (i < lgth_2group && info == Group2[i].Nume_tata) {
				if (which_group == 2 && i == copy_i) {}
				else return false;
			}
			if (i < lgth_3group && info == Group3[i].Nume_tata) {
				if (which_group == 3 && i == copy_i) {}
				else return false;
			}
		}
		break;
	}
	default:
		return true;
		break;
	}
	return true;
}
//
void unfocus(UINT msg, WPARAM wParam) {
	if (msg == WM_KEYDOWN && wParam == VK_ESCAPE) {
		if (is_edit) {
			SetFocus(editHandle);
		}
		else SetFocus(addHandle);
	}
}
LRESULT CALLBACK EditProc1(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	unfocus(msg, wParam);
	if (msg == WM_KEYDOWN && wParam == VK_CONTROL) {
		if (is_edit) {
			SetFocus(Txt2);
			SendMessageA(Txt2, EM_SETSEL, 0, 100);
		}
		else {
			SetFocus(txt2);
			SendMessageA(txt2, EM_SETSEL, 0, 100);
		}
		return 0;
	}
	return CallWindowProc(edit1, hWnd, msg, wParam, lParam);
}
LRESULT CALLBACK EditProc2(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	unfocus(msg, wParam);
	if (msg == WM_KEYDOWN && wParam == VK_CONTROL) {
		if (is_edit) {
			SetFocus(Txt3);
			SendMessageA(Txt3, EM_SETSEL, 0, 100);
		}
		else {
			SetFocus(txt3);
			SendMessageA(txt3, EM_SETSEL, 0, 100);
		}
		return 0;
	}
	return CallWindowProc(edit2, hWnd, msg, wParam, lParam);
}
LRESULT CALLBACK EditProc3(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	unfocus(msg, wParam);
	if (msg == WM_KEYDOWN && wParam == VK_CONTROL) {
		if (is_edit) {
			SetFocus(Txt4);
			SendMessageA(Txt4, EM_SETSEL, 0, 100);
		}
		else {
			SetFocus(txt4);
			SendMessageA(txt4, EM_SETSEL, 0, 100);
		}
		return 0;
	}
	return CallWindowProc(edit3, hWnd, msg, wParam, lParam);
}
LRESULT CALLBACK EditProc4(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	unfocus(msg, wParam);
	if (msg == WM_KEYDOWN && wParam == VK_CONTROL) {
		if (is_edit) {
			SetFocus(Txt5);
			SendMessageA(Txt5, EM_SETSEL, 0, 100);
		}
		else {
			SetFocus(txt5);
			SendMessageA(txt5, EM_SETSEL, 0, 100);
		}
		return 0;
	}
	return CallWindowProc(edit4, hWnd, msg, wParam, lParam);
}
LRESULT CALLBACK EditProc5(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	unfocus(msg, wParam);
	if (msg == WM_KEYDOWN && wParam == VK_CONTROL) {
		if (is_edit) {
			SetFocus(Txt6);
			SendMessageA(Txt6, EM_SETSEL, 0, 100);
		}
		else {
			SetFocus(txt6);
			SendMessageA(txt6, EM_SETSEL, 0, 100);
		}
		return 0;
	}
	return CallWindowProc(edit5, hWnd, msg, wParam, lParam);
}
LRESULT CALLBACK EditProc6(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	unfocus(msg, wParam);
	if (msg == WM_KEYDOWN && wParam == VK_CONTROL) {
		if (is_edit) {
			SetFocus(Txt7);
			SendMessageA(Txt7, EM_SETSEL, 0, 100);
		}
		else {
			SetFocus(txt7);
			SendMessageA(txt7, EM_SETSEL, 0, 100);
		}
		return 0;
	}
	return CallWindowProc(edit6, hWnd, msg, wParam, lParam);
}
LRESULT CALLBACK EditProc7(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	unfocus(msg, wParam);
	if (msg == WM_KEYDOWN && wParam == VK_CONTROL) {
		if (is_edit) {
			SetFocus(Txt1);
			SendMessageA(Txt1, EM_SETSEL, 0, 100);
		}
		else {
			SetFocus(txt1);
			SendMessageA(txt1, EM_SETSEL, 0, 100);
		}
		return 0;
	}
	return CallWindowProc(edit7, hWnd, msg, wParam, lParam);
}
void addproc_open() {
	edit1 = (WNDPROC)SetWindowLongPtr(txt1, GWLP_WNDPROC, (LONG_PTR)EditProc1); ShowWindow(txt1, SW_SHOW);
	edit2 = (WNDPROC)SetWindowLongPtr(txt2, GWLP_WNDPROC, (LONG_PTR)EditProc2); ShowWindow(txt2, SW_SHOW);
	edit3 = (WNDPROC)SetWindowLongPtr(txt3, GWLP_WNDPROC, (LONG_PTR)EditProc3); ShowWindow(txt3, SW_SHOW);
	edit4 = (WNDPROC)SetWindowLongPtr(txt4, GWLP_WNDPROC, (LONG_PTR)EditProc4); ShowWindow(txt4, SW_SHOW);
	edit5 = (WNDPROC)SetWindowLongPtr(txt5, GWLP_WNDPROC, (LONG_PTR)EditProc5); ShowWindow(txt5, SW_SHOW);
	edit6 = (WNDPROC)SetWindowLongPtr(txt6, GWLP_WNDPROC, (LONG_PTR)EditProc6); ShowWindow(txt6, SW_SHOW);
	edit7 = (WNDPROC)SetWindowLongPtr(txt7, GWLP_WNDPROC, (LONG_PTR)EditProc7); ShowWindow(txt7, SW_SHOW);
}
void addproc_close() {
	SetWindowLongPtr(txt1, GWLP_WNDPROC, (LONG_PTR)edit1);
	SetWindowLongPtr(txt2, GWLP_WNDPROC, (LONG_PTR)edit2);
	SetWindowLongPtr(txt3, GWLP_WNDPROC, (LONG_PTR)edit3);
	SetWindowLongPtr(txt4, GWLP_WNDPROC, (LONG_PTR)edit4);
	SetWindowLongPtr(txt5, GWLP_WNDPROC, (LONG_PTR)edit5);
	SetWindowLongPtr(txt6, GWLP_WNDPROC, (LONG_PTR)edit6);
	SetWindowLongPtr(txt7, GWLP_WNDPROC, (LONG_PTR)edit7);
}
void editproc_open() {
	edit1 = (WNDPROC)SetWindowLongPtr(Txt1, GWLP_WNDPROC, (LONG_PTR)EditProc1); ShowWindow(Txt1, SW_SHOW);
	edit2 = (WNDPROC)SetWindowLongPtr(Txt2, GWLP_WNDPROC, (LONG_PTR)EditProc2); ShowWindow(Txt2, SW_SHOW);
	edit3 = (WNDPROC)SetWindowLongPtr(Txt3, GWLP_WNDPROC, (LONG_PTR)EditProc3); ShowWindow(Txt3, SW_SHOW);
	edit4 = (WNDPROC)SetWindowLongPtr(Txt4, GWLP_WNDPROC, (LONG_PTR)EditProc4); ShowWindow(Txt4, SW_SHOW);
	edit5 = (WNDPROC)SetWindowLongPtr(Txt5, GWLP_WNDPROC, (LONG_PTR)EditProc5); ShowWindow(Txt5, SW_SHOW);
	edit6 = (WNDPROC)SetWindowLongPtr(Txt6, GWLP_WNDPROC, (LONG_PTR)EditProc6); ShowWindow(Txt6, SW_SHOW);
	edit7 = (WNDPROC)SetWindowLongPtr(Txt7, GWLP_WNDPROC, (LONG_PTR)EditProc7); ShowWindow(Txt7, SW_SHOW);
}
void editproc_close() {
	SetWindowLongPtr(Txt1, GWLP_WNDPROC, (LONG_PTR)edit1);
	SetWindowLongPtr(Txt2, GWLP_WNDPROC, (LONG_PTR)edit2);
	SetWindowLongPtr(Txt3, GWLP_WNDPROC, (LONG_PTR)edit3);
	SetWindowLongPtr(Txt4, GWLP_WNDPROC, (LONG_PTR)edit4);
	SetWindowLongPtr(Txt5, GWLP_WNDPROC, (LONG_PTR)edit5);
	SetWindowLongPtr(Txt6, GWLP_WNDPROC, (LONG_PTR)edit6);
	SetWindowLongPtr(Txt7, GWLP_WNDPROC, (LONG_PTR)edit7);
}

LRESULT CALLBACK MenuProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CREATE: {
		mviewgroups = CreateWindow(TEXT("BUTTON"), TEXT("ViewGroups"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_DEFPUSHBUTTON, 10, 280, 100, 40, hwnd, (HMENU)1, NULL, NULL);
		madd = CreateWindow(TEXT("BUTTON"), TEXT("Add"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_DEFPUSHBUTTON, 130, 280, 100, 40, hwnd, (HMENU)2, NULL, NULL);
		msearch = CreateWindow(TEXT("BUTTON"), TEXT("Search"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_DEFPUSHBUTTON, 250, 280, 100, 40, hwnd, (HMENU)3, NULL, NULL);
		break;
	}
	case WM_PAINT: {
		LoadPic();  // call our LoadPic function to load the image
		InvalidateRect(hwnd, NULL, 0);  // tell the window it needs to redraw (sends a WM_PAINT message)
		PAINTSTRUCT ps;
		HDC hDC;
		hDC = BeginPaint(hwnd, &ps);
		
		SetTextColor(hDC, (COLORREF)"asdasfadsadasd");
		StretchBlt(hDC, 80, 200, 200, 62, hdcMem, 0, 0, 200, 62, SRCCOPY);
		TextOut(hDC, 110, 10, L"Management Project", strlen("Management Project"));
		TextOut(hDC, 30, 30, L"O gradinita are 3 grupe, iar in fiecare grupa pot fi", strlen("O gradinita are 3 grupe, iar in fiecare grupa pot fi"));
		TextOut(hDC, 30, 50, L"inscrisi cel mult 25 de copii si se aplica anumite", strlen("inscrisi cel mult 25 de copii si se aplica anumite"));
		TextOut(hDC, 20, 70, L"restrictii de varsta: grupa 1(0-2 ani),grupa 2(2-4 ani)", strlen("restrictii de varsta: grupa 1(0-2 ani),grupa 2(2-4 ani)"));
		TextOut(hDC, 30, 90, L"si grupa 3(4-6 ani), maxim 25 de copii pe grupa.", strlen("si grupa 3(4-6 ani), maxim 25 de copii pe grupa."));
		TextOut(hDC, 40, 120, L"Aplicatia va ofera sansa de a tine evidenta", strlen("Aplicatia va ofera sansa de a tine evidenta"));
		TextOut(hDC, 50, 140, L"fiecarui copil si a fiecare grupe, putand", strlen("fiecarui copil si a fiecare grupe, putand"));
		TextOut(hDC, 60, 160, L"edita, cauta, adauga si sterge date.", strlen("edita, cauta, adauga si sterge date."));
		EndPaint(hwnd, &ps);
		return 0;
		break;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case 1://show ViewGroups
		{
			is_edit = false;
			ShowWindow(groupsHandle, 5);
			ShowWindow(windowHandle, 0);
			break;
		}
		case 2://show Add
		{
			is_edit = false;
			addproc_open();
			SendMessageA(txt1, EM_SETSEL, 0, 100);
			ShowWindow(addHandle, 5);
			ShowWindow(windowHandle, 0);
			SetFocus(txt1);
			break;
		}
		case 3://show Search
		{
			is_edit = false;
			ShowWindow(srchHandle, 5);
			ShowWindow(windowHandle, 0);
			break;
		}
		default: break;
		}
		break;
	}
	case WM_KEYDOWN: {
		switch (wParam) {
		case 0x31: {
			SendMessageA(mviewgroups, BM_CLICK, 0, 0);
			break;
		}
		case 0x32: {
			SendMessageA(madd, BM_CLICK, 0, 0);
			break;
		}
		case 0x33: {
			SendMessageA(msearch, BM_CLICK, 0, 0);
			break;
		}
		case VK_ESCAPE: {
			SendMessageA(windowHandle, WM_CLOSE, 0, 0);
			break;
		}
		default: break;
		}
		break;
	}
	case WM_CLOSE: {
		{
			ofstream print("Grupa1");
			print << lgth_1group << '\n';
			for (int i = 0; i < lgth_1group; i++) {
				print << Group1[i].ID << ' ' << Group1[i].Nume << '|' << Group1[i].Prenume << '|' << Group1[i].Varsta << '|' << Group1[i].Adresa << '|' << Group1[i].Nume_mama << '|' << Group1[i].Nume_tata << '\n';
			}
		}
		{
			ofstream print("Grupa2");
			print << lgth_2group << '\n';
			for (int i = 0; i < lgth_2group; i++) {
				print << Group2[i].ID << ' ' << Group2[i].Nume << '|' << Group2[i].Prenume << '|' << Group2[i].Varsta << '|' << Group2[i].Adresa << '|' << Group2[i].Nume_mama << '|' << Group2[i].Nume_tata << '\n';
			}
		}
		{
			ofstream print("Grupa3");
			print << lgth_3group << '\n';
			for (int i = 0; i < lgth_3group; i++) {
				print << Group3[i].ID << ' ' << Group3[i].Nume << '|' << Group3[i].Prenume << '|' << Group3[i].Varsta << '|' << Group3[i].Adresa << '|' << Group3[i].Nume_mama << '|' << Group3[i].Nume_tata << '\n';
			}
		}
		for (int i = 0; i < 150; i++) {
			log_this << '_';
		}
		log_this << '\n';
		FreePic();
		DestroyWindow(hwnd);
		break;
	}
	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

LRESULT CALLBACK GroupsProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CREATE: {
		Btn1 = CreateWindow(TEXT("BUTTON"), TEXT("GRUPA 1"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 20, 70, 100, 50, hwnd, (HMENU)1, NULL, NULL);
		Btn2 = CreateWindow(TEXT("BUTTON"), TEXT("GRUPA 2"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 20, 140, 100, 50, hwnd, (HMENU)2, NULL, NULL);
		Btn3 = CreateWindow(TEXT("BUTTON"), TEXT("GRUPA 3"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 20, 210, 100, 50, hwnd, (HMENU)3, NULL, NULL);
		ListBox1 = CreateWindow(L"LISTBOX", L"", WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LBS_DISABLENOSCROLL | ES_AUTOHSCROLL | LBS_NOTIFY,
			140, 50, 260, 250, hwnd, (HMENU)21, NULL, NULL);
		StaticText = CreateWindow(TEXT("LISTBOX"), TEXT(""), WS_CHILD | WS_VISIBLE, 420, 50, 140, 140, hwnd, (HMENU)22, NULL, NULL);
		gedit = CreateWindow(TEXT("BUTTON"), TEXT("Edit"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 500, 220, 80, 30, hwnd, (HMENU)4, NULL, NULL);
		gview = CreateWindow(TEXT("BUTTON"), TEXT("View"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 410, 220, 80, 30, hwnd, (HMENU)6, NULL, NULL);
		gback = CreateWindow(TEXT("BUTTON"), TEXT("Back"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 450, 260, 80, 30, hwnd, (HMENU)5, NULL, NULL);
		break;
	}
	case WM_PAINT: {
		PAINTSTRUCT ps; HDC hDC; hDC = BeginPaint(hwnd, &ps);
		TextOut(hDC, 225, 10, L"View Groups", strlen("View Groups"));
		EndPaint(hwnd, &ps);
		break;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case 1://show Grupa1 in TextBox1
		{
			which_group = 1;
			// Add items to list. 
			HWND hwndList = GetDlgItem(hwnd, 21);
			// Set input focus to the list box.
			SetFocus(hwndList);
			SendMessage(StaticText, LB_RESETCONTENT, 0, 0);
			SendMessage(ListBox1, LB_RESETCONTENT, 0, 0);

			for (unsigned int i = 0; i < lgth_1group; i++) {
				char combine[1000];
				strcpy(combine, Group1[i].Nume);
				int lgth = strlen(combine);
				combine[lgth] = ','; 
				combine[lgth + 1] = '\0';
				strcat(combine, Group1[i].Prenume);
				SendMessageA(ListBox1, LB_ADDSTRING, 0, (LPARAM)(combine));
			}
			break;
		}
		case 2://show Grupa2 in TextBox1
		{
			which_group = 2;
			// Add items to list. 
			HWND hwndList = GetDlgItem(hwnd, 21);
			// Set input focus to the list box.
			SetFocus(hwndList);
			SendMessage(StaticText, LB_RESETCONTENT, 0, 0);
			SendMessage(ListBox1, LB_RESETCONTENT, 0, 0);

			for (unsigned int i = 0; i < lgth_2group; i++) {
				char combine[1000];
				strcpy(combine, Group2[i].Nume);
				int lgth = strlen(combine);
				combine[lgth] = ',';
				combine[lgth + 1] = '\0';
				strcat(combine, Group2[i].Prenume);
				SendMessageA(ListBox1, LB_ADDSTRING, 0, (LPARAM)(combine));
			}
			break;
		}
		case 3://show Grupa3 in TextBox1
		{
			which_group = 3;
			// Add items to list. 
			HWND hwndList = GetDlgItem(hwnd, 21);
			// Set input focus to the list box.
			SetFocus(hwndList);
			SendMessage(StaticText, LB_RESETCONTENT, 0, 0);
			SendMessage(ListBox1, LB_RESETCONTENT, 0, 0);

			for (unsigned int i = 0; i < lgth_3group; i++) {
				char combine[1000];
				strcpy(combine, Group3[i].Nume);
				int lgth = strlen(combine);
				combine[lgth] = ',';
				combine[lgth + 1] = '\0';
				strcat(combine, Group3[i].Prenume);
				SendMessageA(ListBox1, LB_ADDSTRING, 0, (LPARAM)(combine));
			}
			SendMessageA(hwndList, LBN_KILLFOCUS, 0, 0);
			break;
		}
		case 4://Edit
		{
			if (view_was_clicked) {
				is_edit = true;
				editproc_open();
				SetFocus(Txt1);
				SendMessageA(Txt1, EM_SETSEL, 0, 100);
				SendMessage(StaticText, LB_RESETCONTENT, 0, 0);
				SendMessage(ListBox1, LB_RESETCONTENT, 0, 0);
				isgroup = true;
				ShowWindow(editHandle, 5);
				ShowWindow(groupsHandle, 0);
				view_was_clicked = false;
			}
			break;
		}
		case 5://Back
		{
			SendMessage(StaticText, LB_RESETCONTENT, 0, 0);
			SendMessage(ListBox1, LB_RESETCONTENT, 0, 0);
			which_group = 0;
			ShowWindow(windowHandle, 5);
			ShowWindow(groupsHandle, 0);
			break;
		}
		case 6://View 
		{//View
			SendMessage(StaticText, LB_RESETCONTENT, 0, 0);

			int i = SendMessage(ListBox1, LB_GETCURSEL, 0, 0);
			copy_i = i;
			char a[500];
			SendMessageA(ListBox1, LB_GETTEXT, i, (LPARAM)a);

			if (i >= 0) {
				view_was_clicked = true;
				char *combine;
				combine = "ID:";
				SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
				char snr[100], age[100];
				int ID, Age;
				if (which_group == 1) {
					ID = Group1[i].ID;
					Age = Group1[i].Varsta;
				}
				else if (which_group == 2) {
					ID = Group2[i].ID;
					Age = Group2[i].Varsta;
				}
				else if (which_group == 3) {
					ID = Group3[i].ID;
					Age = Group3[i].Varsta;
				}
				{
					int nr = 0;
					while (ID > 0) {
						snr[nr++] = (char)((char)(ID % 10) + '0');
						ID /= 10;
					}
					snr[nr] = '\0';
					_strrev(snr);
					nr = 0;
					while (Age > 0) {
						age[nr++] = (char)((char)(Age % 10) + '0');
						Age /= 10;
					}
					age[nr] = '\0';
					_strrev(age);
				}
				if (which_group == 1) {
					combine = snr;
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = "Varsta:";
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = age;
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = "Adresa:";
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = Group1[i].Adresa;
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
				}
				else if (which_group == 2) {
					combine = snr;
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = "Varsta:";
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = age;
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = "Adresa:";
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = Group2[i].Adresa;
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
				}
				else if (which_group == 3) {
					combine = snr;
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = "Varsta:";
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = age;
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = "Adresa:";
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = Group3[i].Adresa;
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
				}
			}
			break;
		}
		default: break;
		}
		switch (HIWORD(wParam)) {
		case LBN_SELCHANGE: {
			if (LOWORD(wParam) == 21) {
				SendMessage(StaticText, LB_RESETCONTENT, 0, 0);
				int i = SendMessage(ListBox1, LB_GETCURSEL, 0, 0);
				copy_i = i;
				char a[500];
				SendMessageA(ListBox1, LB_GETTEXT, i, (LPARAM)a);

				if (i >= 0) {
					view_was_clicked = true;
					char *combine;
					combine = "ID:";
					SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					char snr[100], age[100];
					int ID, Age;
					if (which_group == 1) {
						ID = Group1[i].ID;
						Age = Group1[i].Varsta;
					}
					else if (which_group == 2) {
						ID = Group2[i].ID;
						Age = Group2[i].Varsta;
					}
					else if (which_group == 3) {
						ID = Group3[i].ID;
						Age = Group3[i].Varsta;
					}
					{
						int nr = 0;
						while (ID > 0) {
							snr[nr++] = (char)((char)(ID % 10) + '0');
							ID /= 10;
						}
						snr[nr] = '\0';
						_strrev(snr);
						nr = 0;
						while (Age > 0) {
							age[nr++] = (char)((char)(Age % 10) + '0');
							Age /= 10;
						}
						age[nr] = '\0';
						_strrev(age);
					}
					if (which_group == 1) {
						combine = snr;
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = "Varsta:";
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = age;
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = "Adresa:";
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = Group1[i].Adresa;
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					}
					else if (which_group == 2) {
						combine = snr;
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = "Varsta:";
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = age;
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = "Adresa:";
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = Group2[i].Adresa;
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					}
					else if (which_group == 3) {
						combine = snr;
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = "Varsta:";
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = age;
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = "Adresa:";
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
						combine = Group3[i].Adresa;
						SendMessageA(StaticText, LB_ADDSTRING, 0, (LPARAM)(combine));
					}
				}
				break;
			}
			break;
		}
		case LBN_DBLCLK: {
			if (LOWORD(wParam) == 21) {
				if (view_was_clicked) {
					is_edit = true;
					editproc_open();
					SetFocus(Txt1);
					SendMessageA(Txt1, EM_SETSEL, 0, 100);
					SendMessage(StaticText, LB_RESETCONTENT, 0, 0);
					SendMessage(ListBox1, LB_RESETCONTENT, 0, 0);
					isgroup = true;
					ShowWindow(editHandle, 5);
					ShowWindow(groupsHandle, 0);
					view_was_clicked = false;
				}
			}
			break;
		}
		default: break;
		}
		break;
	}
	case WM_KEYDOWN:{
		switch (wParam) {
		case VK_DOWN: {
			if (!is_edit)
			{
				int nroflines = SendMessageA(ListBox1, LB_GETLISTBOXINFO, 0, 0);
				curs_set = (curs_set + 1) % nroflines;
				SendMessageA(ListBox1, LB_SETCURSEL, curs_set, 0);
			}
			break;
		}
		case VK_UP: {
			if (!is_edit) {
				int nroflines = SendMessageA(ListBox1, LB_GETLISTBOXINFO, 0, 0);
				if (curs_set == 0) {
					curs_set = nroflines - 1;
				}
				else if (curs_set > 0) curs_set--;
				if (curs_set >= 0) SendMessageA(ListBox1, LB_SETCURSEL, curs_set, 0);
			}
			break;
		}
		case VK_TAB: {
			tab_press = true;
			curs_set = 0;
			if (grbtn == 1) { SendMessageA(Btn1, BM_CLICK, 0, 0); grbtn = 2; }
			else if (grbtn == 2) { SendMessageA(Btn2, BM_CLICK, 0, 0); grbtn = 3; }
			else if (grbtn == 3) { SendMessageA(Btn3, BM_CLICK, 0, 0); grbtn = 1; }
			SetFocus(hwnd);
			break;
		}
		case VK_RETURN: {
			if (tab_press && !is_edit) {
				is_edit = true;
				copy_i = curs_set;
				SendMessage(StaticText, LB_RESETCONTENT, 0, 0);
				SendMessage(ListBox1, LB_RESETCONTENT, 0, 0);
				editproc_open();
				SetFocus(Txt1);
				SendMessageA(Txt1, EM_SETSEL, 0, 100);
				isgroup = true;
				ShowWindow(editHandle, 5);
				ShowWindow(groupsHandle, 0);
				view_was_clicked = false;
			}
			tab_press = false;
			break;
		}
		case VK_ESCAPE: {
			tab_press = false;
			SendMessageA(groupsHandle, WM_CLOSE, 0, 0);
			break;
		}
		case 0x31: {
			SendMessageA(gview, BM_CLICK, 0, 0);
			break;
		}
		case 0x32: {
			SendMessageA(gedit, BM_CLICK, 0, 0);
			break;
		}
		case 0x33: {
			SendMessageA(gback, BM_CLICK, 0, 0);
			break;
		}
		default: break;
		}
		break;
	}
	case WM_CLOSE: {
		SendMessage(StaticText, LB_RESETCONTENT, 0, 0);
		SendMessage(ListBox1, LB_RESETCONTENT, 0, 0);
		copy_i = -1; which_group = 0;
		ShowWindow(windowHandle, 5);
		ShowWindow(groupsHandle, 0);
		break;
	}
	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

LRESULT CALLBACK AddProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CREATE: {
		aadd = CreateWindow(TEXT("BUTTON"), TEXT("ADD"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 80, 240, 100, 40, hwnd, (HMENU)1, NULL, NULL);
		acancel = CreateWindow(TEXT("BUTTON"), TEXT("CANCEL"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 200, 240, 100, 40, hwnd, (HMENU)2, NULL, NULL);
		txt1 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 85, 20, 275, 20, hwnd, (HMENU)21, NULL, NULL);
		txt2 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 85, 50, 275, 20, hwnd, (HMENU)22, NULL, NULL);
		txt3 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 85, 80, 275, 20, hwnd, (HMENU)23, NULL, NULL);
		txt4 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 85, 110, 275, 20, hwnd, (HMENU)24, NULL, NULL);
		txt5 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 85, 140, 275, 20, hwnd, (HMENU)25, NULL, NULL);
		txt6 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 170, 250, 20, hwnd, (HMENU)26, NULL, NULL);
		txt7 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 200, 250, 20, hwnd, (HMENU)27, NULL, NULL);
		break;
	}
	case WM_PAINT: {
		//SetFocus(txt1);
		//Set ID Random
		int nr = 0;
		int ID = (GetRandomValue() % 1000000);
		while (!Exists_ID(ID)) {
			ID = (GetRandomValue() % 1000000);
		}
		char snr[1000];
		while (ID > 0) {
			snr[nr++] = (char)((char)(ID % 10) + '0');
			ID /= 10;
		}
		snr[nr] = '\0';
		_strrev(snr);
		SetWindowTextA(txt1, snr);
		//S_ID_Rand
		PAINTSTRUCT ps;
		HDC hDC;
		hDC = BeginPaint(hwnd, &ps);
		SetBkMode(hDC, TRANSPARENT);
		TextOut(hDC, 20, 20, L"ID:", strlen("ID:"));
		TextOut(hDC, 20, 50, L"Nume:", strlen("Nume:"));
		TextOut(hDC, 20, 80, L"Prenume:", strlen("Prenume:"));
		TextOut(hDC, 20, 110, L"Varsta:(Luni)", strlen("Varsta:"));
		TextOut(hDC, 20, 140, L"Adresa:", strlen("Adresa:"));
		TextOut(hDC, 20, 170, L"Nume mama:", strlen("Nume mama:"));
		TextOut(hDC, 20, 200, L"Nume tata:", strlen("Nume tata:"));
		EndPaint(hwnd, &ps);
		return 0;
		break;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case 2: {//Cancel
			which_group = 0;
			ShowWindow(windowHandle, 5);
			ShowWindow(addHandle, 0);
			SetWindowTextA(txt1, ""); SetWindowTextA(txt2, ""); SetWindowTextA(txt3, ""); SetWindowTextA(txt4, ""); SetWindowTextA(txt5, ""); SetWindowTextA(txt6, ""); SetWindowTextA(txt7, "");
			break;
		}
		case 1: {//Save
			char data1[1000], data2[1000], data3[1000], data4[1000], data5[1000], data6[1000], data7[1000];
			GetWindowTextA(txt1, data1, 1000); GetWindowTextA(txt2, data2, 1000);
			GetWindowTextA(txt3, data3, 1000); GetWindowTextA(txt4, data4, 1000);
			GetWindowTextA(txt5, data5, 1000); GetWindowTextA(txt6, data6, 1000);
			GetWindowTextA(txt7, data7, 1000);
			GetRidofSpaces(data1); GetRidofSpaces(data2); GetRidofSpaces(data3); GetRidofSpaces(data4); GetRidofSpaces(data5); GetRidofSpaces(data6); GetRidofSpaces(data7);
			if (strlen(data1) == 0 || strlen(data2) == 0 || strlen(data3) == 0 || strlen(data4) == 0 || strlen(data5) == 0 ||
				strlen(data6) == 0 || strlen(data7) == 0) {
				MessageBoxA(addHandle, "Trebuiesc completate toate casutele!", "Try again", MB_OK | MB_ICONWARNING);
			}
			else if (!srch_ifexists(1, data1)) {
				MessageBoxA(addHandle, "ID-ul introdus exista deja!", "Try again", MB_OK);
			}
			else if (!E_only_Numbers(data1)) {
				MessageBoxA(addHandle, "ID-ul trebuie sa contina doar cifre!", "Try again", MB_OK);
			}
			else if (!E_no_symbols(data2)) {
				MessageBoxA(addHandle, "Numele trebuie sa contina numai litere!", "Try again", MB_OK);
			}
			else if (!E_only_Letters(data3)) {
				MessageBoxA(addHandle, "Prenumele trebuie sa contina numai litere!", "Try again", MB_OK);
			}
			else if (!E_only_Numbers(data4)) {
				MessageBoxA(addHandle, "Varsta trebuie sa contina numai cifre!", "Try again", MB_OK);
			}
			else if (atoi(data4) >= 7) {
				MessageBoxA(addHandle, "Varsta trebuie sa fie intre 0 - 7 ani!", "Try again", MB_OK);
			}
			else if (!E_only_LetandNumbs(data5)) {
				MessageBoxA(addHandle, "Adresa poate contine doar cifre si litere!", "Try again", MB_OK);
			}
			else if (!E_only_Letters(data6)) {
				MessageBoxA(addHandle, "Numele mamei trebuie sa contina numai litere!", "Try again", MB_OK);
			}
			else if (!E_only_Letters(data7)) {
				MessageBoxA(addHandle, "Numele tatalui trebuie sa contina numai litere!", "Try again", MB_OK);
			}
			else {
				int Varsta = atoi(data4);
				if (Varsta < 2) {
					if (lgth_1group == 25) {
						MessageBoxA(addHandle, "Grupa 1 este deja plina, nu se mai pot adauga copii.", "Try again", MB_OK);
					}
					else {
						Group1[lgth_1group].ID = atoi(data1);
						strcpy(Group1[lgth_1group].Nume, data2);
						strcpy(Group1[lgth_1group].Prenume, data3);
						Group1[lgth_1group].Varsta = atoi(data4);
						strcpy(Group1[lgth_1group].Adresa, data5);
						strcpy(Group1[lgth_1group].Nume_mama, data6);
						strcpy(Group1[lgth_1group++].Nume_tata, data7);
						lgth_1group--;
						if (Exists_Record(Group1[lgth_1group])) {
							MessageBoxA(addHandle, "Error", "Inregistrarea exista deja!", 1);
						}
						else {
							lgth_1group++;
							update_logs(Group1[lgth_1group - 1], Group1[lgth_1group - 1], 3);
							update_all_kis();
							ShowWindow(windowHandle, 5);
							ShowWindow(addHandle, 0);
						}
					}
				}
				else if (Varsta < 4) {
					if (lgth_2group == 25) {
						MessageBoxA(addHandle, "Grupa 2 este deja plina, nu se mai pot adauga copii.", "Try again", MB_OK);
					}
					else {
						Group2[lgth_2group].ID = atoi(data1);
						strcpy(Group2[lgth_2group].Nume, data2);
						strcpy(Group2[lgth_2group].Prenume, data3);
						Group2[lgth_2group].Varsta = atoi(data4);
						strcpy(Group2[lgth_2group].Adresa, data5);
						strcpy(Group2[lgth_2group].Nume_mama, data6);
						strcpy(Group2[lgth_2group].Nume_tata, data7);

						if (Exists_Record(Group2[lgth_2group])) {
							MessageBoxA(addHandle, "Error", "Inregistrarea exista deja!", 1);
						}
						else {
							lgth_2group ++;
							update_logs(Group2[lgth_2group - 1], Group2[lgth_2group - 1], 3);
							update_all_kis();
							ShowWindow(windowHandle, 5);
							ShowWindow(addHandle, 0);
						}
					}
				}
				else if (Varsta < 7) {
					if (lgth_3group == 25) {
						MessageBoxA(addHandle, "Grupa 3 este deja plina, nu se mai pot adauga copii.", "Try again", MB_OK);
					}
					else {
						Group3[lgth_3group].ID = atoi(data1);
						strcpy(Group3[lgth_3group].Nume, data2);
						strcpy(Group3[lgth_3group].Prenume, data3);
						Group3[lgth_3group].Varsta = atoi(data4);
						strcpy(Group3[lgth_3group].Adresa, data5);
						strcpy(Group3[lgth_3group].Nume_mama, data6);
						strcpy(Group3[lgth_3group].Nume_tata, data7);

						if (Exists_Record(Group3[lgth_3group])) {
							MessageBoxA(addHandle, "Error", "Inregistrarea exista deja!", MB_OK | MB_ICONERROR);
						}
						else {
							lgth_3group++;
							update_logs(Group3[lgth_3group - 1], Group3[lgth_3group - 1], 3);
							update_all_kis();
							ShowWindow(windowHandle, 5);
							ShowWindow(addHandle, 0);
						}
					}
				}
				SetWindowTextA(txt1, ""); SetWindowTextA(txt2, ""); SetWindowTextA(txt3, ""); SetWindowTextA(txt4, ""); SetWindowTextA(txt5, ""); SetWindowTextA(txt6, ""); SetWindowTextA(txt7, "");
			}
			sort_all_kids();
			sort_groups();
			break;
		}
		default: break;
		}
		break;
	}
	case WM_KEYDOWN: {
		switch (wParam)
		{
		case VK_ESCAPE: {
			SendMessageA(addHandle, WM_CLOSE, 0, 0);
			break;
		}
		case VK_TAB: {
			break;
		}
		default:
			break;
		}
		break;
	}
	case WM_CLOSE: {
		addproc_close();
		which_group = 0;
		ShowWindow(windowHandle, 5);
		ShowWindow(addHandle, 0);
		SetWindowTextA(txt1, ""); SetWindowTextA(txt2, ""); SetWindowTextA(txt3, ""); SetWindowTextA(txt4, ""); SetWindowTextA(txt5, ""); SetWindowTextA(txt6, ""); SetWindowTextA(txt7, "");
		update_all_kis();
		//DestroyWindow(hwnd);
		break;
	}
	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
	default: {
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	}
}

LRESULT CALLBACK SrchBoxProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_KEYDOWN && (wParam == VK_ESCAPE || wParam == VK_UP || wParam == VK_DOWN)) {
		SetFocus(srchHandle);
		return 0;
	}
	CallWindowProc(srchbox, hWnd, msg, wParam, lParam);
}
LRESULT CALLBACK SrchProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CREATE: {
		ListBox2 = CreateWindow(L"LISTBOX", L"", WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LBS_DISABLENOSCROLL | ES_AUTOHSCROLL | LBS_NOTIFY,
			20, 60, 380, 240, hwnd, (HMENU)21, NULL, NULL);
		StaticText1 = CreateWindow(TEXT("LISTBOX"), TEXT(""), WS_CHILD | WS_VISIBLE, 420, 60, 140, 105, hwnd, (HMENU)22, NULL, NULL);
		SearchBox = CreateWindow(TEXT("EDIT"), TEXT("numere(pentru ID) sau litere(pentru nume)"), WS_CHILD | WS_VISIBLE | WS_BORDER, 20, 30, 380, 20, hwnd, (HMENU)23, NULL, NULL);
		srchbox = (WNDPROC)SetWindowLongPtr(SearchBox, GWLP_WNDPROC, (LONG_PTR)SrchBoxProc);

		sedit = CreateWindow(TEXT("BUTTON"), TEXT("Edit"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 495, 225, 80, 30, hwnd, (HMENU)4, NULL, NULL);
		sview = CreateWindow(TEXT("BUTTON"), TEXT("View"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 410, 225, 80, 30, hwnd, (HMENU)6, NULL, NULL);
		sback = CreateWindow(TEXT("BUTTON"), TEXT("Back"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 450, 260, 80, 30, hwnd, (HMENU)5, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("Search"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 410, 20, 160, 30, hwnd, (HMENU)3, NULL, NULL);
		break;
	}
	case WM_PAINT: {
		SetFocus(SearchBox);
		SendMessageA(SearchBox, EM_SETSEL, 0, 100);
		PAINTSTRUCT ps;
		HDC hDC;
		hDC = BeginPaint(hwnd, &ps);
		TextOut(hDC, 20, 10, L"Scrieti in casuta de mai jos ceea ce doriti sa cautati:",
			strlen("Scrieti in casuta de mai jos ceea ce doriti sa cautati:"));
		EndPaint(hwnd, &ps);
		return 0;
		break;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case 3: //Search
		{//Search
			upordown = false;
			SendMessage(StaticText1, LB_RESETCONTENT, 0, 0);
			SendMessage(ListBox2, LB_RESETCONTENT, 0, 0);
			char data1[1000];
			lgth_srcharray = 0;
			GetWindowTextA(SearchBox, data1, 1000);
			if (strlen(data1) > 0) {
				if (!E_only_Numbers(data1)) {
					if (!E_only_Letters(data1)) {
						MessageBoxA(srchHandle, "Casuta de text poate contine fie numai litere, fie numai numere!", "Try again", MB_OK);
					}
					else {
						int frecv[76];
						char dataa[1000];
						for (int i = 0; i < nr_data; i++) {
							frecv[i] = 0;
						}
						strcpy(dataa, data1);
						_strlwr(dataa);
						for (int i = 0; i < nr_data; i++) {
							if (frecv[i] == 0 && strlen(dataa) <= strlen(all_kids[i].Nume) && strlen(dataa)>0) {
								char tryit[1000]; strcpy(tryit, all_kids[i].Nume);
								char trythis[1000];
								_strlwr(tryit); strcpy(trythis, tryit);
								if (strcmp(dataa, tryit) == 0 || strcmp(dataa, trythis) == 0) {
									SearchArray[lgth_srcharray++] = all_kids[i];
									frecv[i] = 1;
									char combine[1000];
									strcpy(combine, SearchArray[lgth_srcharray - 1].Nume);
									strcat(combine, ", ");
									strcat(combine, SearchArray[lgth_srcharray - 1].Prenume);
									SendMessageA(ListBox2, LB_ADDSTRING, 0, (LPARAM)(combine));
								}
								else {//cautare dupa nume
									bool inside = false;
									char name[1000];
									strcpy(name, all_kids[i].Nume);
									_strlwr(name);
									if (strstr(name, dataa) != 0) {
										SearchArray[lgth_srcharray++] = all_kids[i];
										frecv[i] = 1; inside = true;
										char combine[1000];
										strcpy(combine, SearchArray[lgth_srcharray - 1].Nume);
										strcat(combine, ", ");
										strcat(combine, SearchArray[lgth_srcharray - 1].Prenume);
										SendMessageA(ListBox2, LB_ADDSTRING, 0, (LPARAM)(combine));
									}
									//cautarea pe prenume
									if (!inside) {
										////
										char pname[1000] = "";
										strcpy(pname, all_kids[i].Prenume);
										_strlwr(pname);
										if (strstr(pname, dataa) != 0 && frecv[i] == 0) {
											SearchArray[lgth_srcharray++] = all_kids[i];
											frecv[i] = 1;
											char combine[1000];
											strcpy(combine, SearchArray[lgth_srcharray - 1].Nume);
											strcat(combine, ", ");
											strcat(combine, SearchArray[lgth_srcharray - 1].Prenume);
											SendMessageA(ListBox2, LB_ADDSTRING, 0, (LPARAM)(combine));
										}
									}
								}
							}
						}//bigfor
					}
				}
				else if (!E_only_Letters(data1)) {
					if (!E_only_Numbers(data1)) {
						MessageBoxA(srchHandle, "Casuta de text poate contine fie numai litere, fie numai numere!", "Try again", MB_OK);
					}
					else if (strlen(data1) > 0) {
						for (int i = 0; i < nr_data; i++) {
							char copy[1000];
							int copyid = all_kids[i].ID;
							int copy_lgth = 0;
							while (copyid > 0) {
								copy[copy_lgth++] = (char)(copyid % 10) + '0';
								copyid /= 10;
							}
							if (all_kids[i].ID == 0) {
								copy[copy_lgth++] = '0';
							}
							copy[copy_lgth] = '\0';
							_strrev(copy);
							if (strstr(copy, data1) != 0) {
								SearchArray[lgth_srcharray++] = all_kids[i];
								char combine[1000];
								strcpy(combine, SearchArray[lgth_srcharray - 1].Nume);
								strcat(combine, ", ");
								strcat(combine, SearchArray[lgth_srcharray - 1].Prenume);
								SendMessageA(ListBox2, LB_ADDSTRING, 0, (LPARAM)(combine));
							}
						}
					}
				}
			}
			break;
		}
		case 4://Edit
		{
			if (view_was_clicked) {
				is_edit = true;
				editproc_open();
				SetFocus(Txt1);
				SendMessageA(Txt1, EM_SETSEL, 0, 100);
				isgroup = false;
				ShowWindow(editHandle, 5);
				ShowWindow(srchHandle, 0);
				view_was_clicked = false;
			}
			break;
		}
		case 5://Back
		{
			SendMessage(StaticText1, LB_RESETCONTENT, 0, 0);
			SendMessage(ListBox2, LB_RESETCONTENT, 0, 0);
			SetWindowTextA(SearchBox, "");
			which_group = 0;
			ShowWindow(windowHandle, 5);
			ShowWindow(srchHandle, 0);
			break;
		}
		case 6://View 
		{//View
			SendMessage(StaticText1, LB_RESETCONTENT, 0, 0);

			int i = SendMessage(ListBox2, LB_GETCURSEL, 0, 0);
			copy_i = i; char a[500];
			which_group = SearchArray[i].Grupa;
			SendMessageA(ListBox2, LB_GETTEXT, i, (LPARAM)a);

			if (i >= 0) {
				view_was_clicked = true;
				char *combine;
				combine = "ID:";
				SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
				char snr[100], age[100];
				int ID, Age;
				ID = SearchArray[i].ID;
				Age = SearchArray[i].Varsta;
				{
					int nr = 0;
					while (ID > 0) {
						snr[nr++] = (char)((char)(ID % 10) + '0');
						ID /= 10;
					}
					snr[nr] = '\0';
					_strrev(snr);
					nr = 0;
					while (Age > 0) {
						age[nr++] = (char)((char)(Age % 10) + '0');
						Age /= 10;
					}
					age[nr] = '\0';
					_strrev(age);
				}
				combine = snr;
				SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
				combine = "Varsta(luni):";
				SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
				combine = age;
				SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
				combine = "Adresa:";
				SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
				combine = SearchArray[i].Adresa;
				SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
			}
			break;
		}
		}
		switch (HIWORD(wParam)) {
		case EN_CHANGE: {
			upordown = false;
			if (LOWORD(wParam) == 23) {
				SendMessage(StaticText1, LB_RESETCONTENT, 0, 0);
				SendMessage(ListBox2, LB_RESETCONTENT, 0, 0);
				char data1[1000];
				lgth_srcharray = 0;
				GetWindowTextA(SearchBox, data1, 1000);
				if (strlen(data1) > 0) {
					if (!E_only_Numbers(data1)) {
						if (!E_only_Letters(data1)) {
							MessageBoxA(srchHandle, "Casuta de text poate contine fie numai litere, fie numai numere!", "Try again", MB_OK);
						}
						else {
							int frecv[76];
							char dataa[1000];
							for (int i = 0; i < nr_data; i++) {
								frecv[i] = 0;
							}
							strcpy(dataa, data1);
							_strlwr(dataa);
							for (int i = 0; i < nr_data; i++) {
								if (frecv[i] == 0 && strlen(dataa) <= strlen(all_kids[i].Nume) && strlen(dataa)>0) {
									char tryit[1000]; strcpy(tryit, all_kids[i].Nume);
									char trythis[1000];
									_strlwr(tryit); strcpy(trythis, tryit);
									if (strcmp(dataa, tryit) == 0 || strcmp(dataa, trythis) == 0) {
										SearchArray[lgth_srcharray++] = all_kids[i];
										frecv[i] = 1;
										char combine[1000];
										strcpy(combine, SearchArray[lgth_srcharray - 1].Nume);
										strcat(combine, ", ");
										strcat(combine, SearchArray[lgth_srcharray - 1].Prenume);
										SendMessageA(ListBox2, LB_ADDSTRING, 0, (LPARAM)(combine));
									}
									else {//cautare dupa nume
										bool inside = false;
										char name[1000];
										strcpy(name, all_kids[i].Nume);
										_strlwr(name);
										if (strstr(name, dataa) != 0) {
											SearchArray[lgth_srcharray++] = all_kids[i];
											frecv[i] = 1; inside = true;
											char combine[1000];
											strcpy(combine, SearchArray[lgth_srcharray - 1].Nume);
											strcat(combine, ", ");
											strcat(combine, SearchArray[lgth_srcharray - 1].Prenume);
											SendMessageA(ListBox2, LB_ADDSTRING, 0, (LPARAM)(combine));
										}
										//cautarea pe prenume
										if (!inside) {
											////
											char pname[1000] = "";
											strcpy(pname, all_kids[i].Prenume);
											_strlwr(pname);
											if (strstr(pname, dataa) != 0 && frecv[i] == 0) {
												SearchArray[lgth_srcharray++] = all_kids[i];
												frecv[i] = 1;
												char combine[1000];
												strcpy(combine, SearchArray[lgth_srcharray - 1].Nume);
												strcat(combine, ", ");
												strcat(combine, SearchArray[lgth_srcharray - 1].Prenume);
												SendMessageA(ListBox2, LB_ADDSTRING, 0, (LPARAM)(combine));
											}
										}
									}
								}
							}//bigfor
						}
					}
					else if (!E_only_Letters(data1)) {
						if (!E_only_Numbers(data1)) {
							MessageBoxA(srchHandle, "Casuta de text poate contine fie numai litere, fie numai numere!", "Try again", MB_OK);
						}
						else if (strlen(data1) > 0) {
							for (int i = 0; i < nr_data; i++) {
								char copy[1000];
								int copyid = all_kids[i].ID;
								int copy_lgth = 0;
								while (copyid > 0) {
									copy[copy_lgth++] = (char)(copyid % 10) + '0';
									copyid /= 10;
								}
								if (all_kids[i].ID == 0) {
									copy[copy_lgth++] = '0';
								}
								copy[copy_lgth] = '\0';
								_strrev(copy);
								if (strstr(copy, data1) != 0) {
									SearchArray[lgth_srcharray++] = all_kids[i];
									char combine[1000];
									strcpy(combine, SearchArray[lgth_srcharray - 1].Nume);
									strcat(combine, ", ");
									strcat(combine, SearchArray[lgth_srcharray - 1].Prenume);
									SendMessageA(ListBox2, LB_ADDSTRING, 0, (LPARAM)(combine));
								}
							}
						}
					}
				}
			}
			break;
		}
		case LBN_SELCHANGE: {
			if (LOWORD(wParam) == 21) {
				SendMessage(StaticText1, LB_RESETCONTENT, 0, 0);

				int i = SendMessage(ListBox2, LB_GETCURSEL, 0, 0);
				copy_i = i;
				char a[500];
				which_group = SearchArray[i].Grupa;
				SendMessageA(ListBox2, LB_GETTEXT, i, (LPARAM)a);

				if (i >= 0) {
					view_was_clicked = true;
					char *combine;
					combine = "ID:";
					SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
					char snr[100], age[100];
					int ID, Age;
					ID = SearchArray[i].ID;
					Age = SearchArray[i].Varsta;
					{
						int nr = 0;
						while (ID > 0) {
							snr[nr++] = (char)((char)(ID % 10) + '0');
							ID /= 10;
						}
						snr[nr] = '\0';
						_strrev(snr);
						nr = 0;
						while (Age > 0) {
							age[nr++] = (char)((char)(Age % 10) + '0');
							Age /= 10;
						}
						age[nr] = '\0';
						_strrev(age);
					}
					combine = snr;
					SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = "Varsta(luni):";
					SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = age;
					SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = "Adresa:";
					SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
					combine = SearchArray[i].Adresa;
					SendMessageA(StaticText1, LB_ADDSTRING, 0, (LPARAM)(combine));
				}
				break;
			}
			break;
		}
		case LBN_DBLCLK: {
			if (LOWORD(wParam) == 21) {
				if (view_was_clicked) {
					SetFocus(Txt1);
					SendMessageA(Txt1, EM_SETSEL, 0, 100);
					is_edit = true;
					editproc_open();
					isgroup = false;
					ShowWindow(editHandle, 5);
					ShowWindow(srchHandle, 0);
					view_was_clicked = false;
				}
			}
			break;
		}
						 break;
		}
		break;
	}
	case WM_KEYDOWN: {
		switch (wParam)
		{
		case 0x31: {
			SendMessageA(sview, BM_CLICK, 0, 0);
			break;
		}
		case 0x32: {
			SendMessageA(sedit, BM_CLICK, 0, 0);
			break;
		}
		case 0x33: {
			SendMessageA(sback, BM_CLICK, 0, 0);
			break;
		}
		case VK_ESCAPE: {
			upordown = false;
			SendMessageA(srchHandle, WM_CLOSE, 0, 0);
			break;
		}
		/*case VK_DOWN: {
			upordown = true;
			int nroflines = SendMessageA(ListBox2, LB_GETLISTBOXINFO, 0, 0);
			cursel_set = (cursel_set + 1) % nroflines;
			SendMessageA(ListBox1, LB_SETCURSEL, cursel_set, 0);
			break;
		}
		case VK_UP: {
			upordown = true;
			int nroflines = SendMessageA(ListBox2, LB_GETLISTBOXINFO, 0, 0);
			if (cursel_set == 0) {
				cursel_set = nroflines - 1;
			}
			else if (cursel_set > 0) cursel_set--;
			if (cursel_set >= 0) SendMessageA(ListBox2, LB_SETCURSEL, cursel_set, 0);
			break;
		}*/
		default: break;
		}
		break;
	}
	case WM_CLOSE: {
			upordown = false;
			SendMessage(ListBox2, LB_RESETCONTENT, 0, 0);
			SendMessage(StaticText1, LB_RESETCONTENT, 0, 0);
			SetWindowTextA(SearchBox, "");
			which_group = 0;
			ShowWindow(windowHandle, 5);
			ShowWindow(srchHandle, 0);
			break;
		}
	case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

LRESULT CALLBACK EditProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CREATE: {
		is_edit = true;
		esave = CreateWindow(TEXT("BUTTON"), TEXT("Save"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 20, 240, 100, 40, hwnd, (HMENU)1, NULL, NULL);
		edelete = CreateWindow(TEXT("BUTTON"), TEXT("Delete"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 140, 240, 100, 40, hwnd, (HMENU)2, NULL, NULL);
		ecancel = CreateWindow(TEXT("BUTTON"), TEXT("Cancel"), WS_VISIBLE | WS_CHILD | WS_BORDER | BS_FLAT, 260, 240, 100, 40, hwnd, (HMENU)3, NULL, NULL);
		Txt1 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 85, 20, 275, 20, hwnd, (HMENU)21, NULL, NULL);
		Txt2 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 85, 50, 275, 20, hwnd, (HMENU)22, NULL, NULL);
		Txt3 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 85, 80, 275, 20, hwnd, (HMENU)23, NULL, NULL);
		Txt4 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 85, 110, 275, 20, hwnd, (HMENU)24, NULL, NULL);
		Txt5 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 85, 140, 275, 20, hwnd, (HMENU)25, NULL, NULL);
		Txt6 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 170, 250, 20, hwnd, (HMENU)26, NULL, NULL);
		Txt7 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 200, 250, 20, hwnd, (HMENU)27, NULL, NULL);
		break;
		}
	case WM_PAINT: {
			if (isgroup) {
				if (which_group == 1) {
					int nr = 0, ID = Group1[copy_i].ID, Age = Group1[copy_i].Varsta;
					char snr[1000], age[1000];
					{
						while (ID > 0) {
							snr[nr++] = (char)((char)(ID % 10) + '0');
							ID /= 10;
						}
						snr[nr] = '\0';
						_strrev(snr);
						nr = 0;
						while (Age > 0) {
							age[nr++] = (char)((char)(Age % 10) + '0');
							Age /= 10;
						}
						if (Group1[copy_i].Varsta == 0) {
							age[nr++] = '0';
						}
						age[nr] = '\0';
						_strrev(age);
					}
					SetWindowTextA(Txt1, snr);
					SetWindowTextA(Txt2, Group1[copy_i].Nume);
					SetWindowTextA(Txt3, Group1[copy_i].Prenume);
					SetWindowTextA(Txt4, age);
					SetWindowTextA(Txt5, Group1[copy_i].Adresa);
					SetWindowTextA(Txt6, Group1[copy_i].Nume_mama);
					SetWindowTextA(Txt7, Group1[copy_i].Nume_tata);
				}
				else if (which_group == 2) {
					int nr = 0, ID = Group2[copy_i].ID, Age = Group2[copy_i].Varsta;
					char snr[1000], age[1000];
					{
						while (ID > 0) {
							snr[nr++] = (char)((char)(ID % 10) + '0');
							ID /= 10;
						}
						snr[nr] = '\0';
						_strrev(snr);
						nr = 0;
						while (Age > 0) {
							age[nr++] = (char)((char)(Age % 10) + '0');
							Age /= 10;
						}
						age[nr] = '\0';
						_strrev(age);
					}
					SetWindowTextA(Txt1, snr);
					SetWindowTextA(Txt2, Group2[copy_i].Nume);
					SetWindowTextA(Txt3, Group2[copy_i].Prenume);
					SetWindowTextA(Txt4, age);
					SetWindowTextA(Txt5, Group2[copy_i].Adresa);
					SetWindowTextA(Txt6, Group2[copy_i].Nume_mama);
					SetWindowTextA(Txt7, Group2[copy_i].Nume_tata);
				}
				else if (which_group == 3) {
					int nr = 0, ID = Group3[copy_i].ID, Age = Group3[copy_i].Varsta;
					char snr[1000], age[1000];
					{
						while (ID > 0) {
							snr[nr++] = (char)((char)(ID % 10) + '0');
							ID /= 10;
						}
						snr[nr] = '\0';
						_strrev(snr);
						nr = 0;
						while (Age > 0) {
							age[nr++] = (char)((char)(Age % 10) + '0');
							Age /= 10;
						}
						age[nr] = '\0';
						_strrev(age);
					}
					SetWindowTextA(Txt1, snr);
					SetWindowTextA(Txt2, Group3[copy_i].Nume);
					SetWindowTextA(Txt3, Group3[copy_i].Prenume);
					SetWindowTextA(Txt4, age);
					SetWindowTextA(Txt5, Group3[copy_i].Adresa);
					SetWindowTextA(Txt6, Group3[copy_i].Nume_mama);
					SetWindowTextA(Txt7, Group3[copy_i].Nume_tata);
				}
			}
			else {
				int nr = 0, ID = SearchArray[copy_i].ID, Age = SearchArray[copy_i].Varsta;
				char snr[1000], age[1000];
				{
					while (ID > 0) {
						snr[nr++] = (char)((char)(ID % 10) + '0');
						ID /= 10;
					}
					snr[nr] = '\0';
					_strrev(snr);
					nr = 0;
					while (Age > 0) {
						age[nr++] = (char)((char)(Age % 10) + '0');
						Age /= 10;
					}
					age[nr] = '\0';
					_strrev(age);
				}
				SetWindowTextA(Txt1, snr);
				SetWindowTextA(Txt2, SearchArray[copy_i].Nume);
				SetWindowTextA(Txt3, SearchArray[copy_i].Prenume);
				SetWindowTextA(Txt4, age);
				SetWindowTextA(Txt5, SearchArray[copy_i].Adresa);
				SetWindowTextA(Txt6, SearchArray[copy_i].Nume_mama);
				SetWindowTextA(Txt7, SearchArray[copy_i].Nume_tata);
			}
		PAINTSTRUCT ps;
		HDC hDC;
		hDC = BeginPaint(hwnd, &ps);
		SetBkMode(hDC, TRANSPARENT);
		TextOut(hDC, 20, 20, L"ID:", strlen("ID:"));
		TextOut(hDC, 20, 50, L"Nume:", strlen("Nume:"));
		TextOut(hDC, 20, 80, L"Prenume:", strlen("Prenume:"));
		TextOut(hDC, 20, 110, L"Varsta:", strlen("Varsta:"));
		TextOut(hDC, 20, 140, L"Adresa:", strlen("Adresa:"));
		TextOut(hDC, 20, 170, L"Nume mama:", strlen("Nume mama:"));
		TextOut(hDC, 20, 200, L"Nume tata:", strlen("Nume tata:"));
		EndPaint(hwnd, &ps);
		return 0;
		break;
		}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case 3: {//Cancel
			is_edit = false;
			editproc_close();
			if (isgroup == true) {
				ShowWindow(groupsHandle, 5);
			}
			else {
				ShowWindow(srchHandle, 5);
			}
			ShowWindow(editHandle, 0);
			SetWindowTextA(Txt1, ""); SetWindowTextA(Txt2, ""); SetWindowTextA(Txt3, ""); SetWindowTextA(Txt4, ""); SetWindowTextA(Txt5, ""); SetWindowTextA(Txt6, ""); SetWindowTextA(Txt7, "");
			update_all_kis();
			copy_i = -1;
			SendMessage(StaticText1, LB_RESETCONTENT, 0, 0);
			SendMessage(ListBox2, LB_RESETCONTENT, 0, 0);
			break;
		}
		case 2: {//Delete
			is_edit = false;
			if (which_group == 1) {
				Group1[lgth_1group] = Group1[copy_i];
				Kid copy = Group1[copy_i];
				for (int i = copy_i; i < lgth_1group; i++) {
					swap(Group1[i], Group1[i + 1]);
				}
				lgth_1group--;
				update_logs(copy, copy, 2);
			}
			else if (which_group == 2) {
				Group2[lgth_2group] = Group2[copy_i];
				Kid copy = Group2[copy_i];
				for (int i = copy_i; i < lgth_2group; i++) {
					swap(Group2[i], Group2[i + 1]);
				}
				lgth_2group--;
				update_logs(copy, copy, 2);
			}
			else if (which_group == 3) {
				Group3[lgth_3group] = Group3[copy_i];
				Kid copy = Group3[copy_i];
				for (int i = copy_i; i < lgth_3group; i++) {
					swap(Group3[i], Group3[i + 1]);
				}
				lgth_3group--;
				update_logs(copy, copy, 2);
			}
			if (isgroup == true) {
				ShowWindow(groupsHandle, 5);
			}
			else {
				ShowWindow(srchHandle, 5);
			}
			ShowWindow(editHandle, 0);
			SetWindowTextA(Txt1, ""); SetWindowTextA(Txt2, ""); SetWindowTextA(Txt3, ""); SetWindowTextA(Txt4, ""); SetWindowTextA(Txt5, ""); SetWindowTextA(Txt6, ""); SetWindowTextA(Txt7, "");
			update_all_kis();
			copy_i = -1;
			SendMessage(StaticText1, LB_RESETCONTENT, 0, 0);
			SendMessage(ListBox2, LB_RESETCONTENT, 0, 0);
			break;
		}
		case 1: {//Save
			is_edit = false;
			if (which_group == 1) {
				char data1[1000], data2[1000], data3[1000], data4[1000], data5[1000], data6[1000], data7[1000];
				GetWindowTextA(Txt1, data1, 1000);
				GetWindowTextA(Txt2, data2, 1000);
				GetWindowTextA(Txt3, data3, 1000);
				GetWindowTextA(Txt4, data4, 1000);
				GetWindowTextA(Txt5, data5, 1000);
				GetWindowTextA(Txt6, data6, 1000);
				GetWindowTextA(Txt7, data7, 1000);
				GetRidofSpaces(data1); GetRidofSpaces(data2); GetRidofSpaces(data3); GetRidofSpaces(data4); GetRidofSpaces(data5); GetRidofSpaces(data6); GetRidofSpaces(data7);
				if (strlen(data1) == 0 || strlen(data2) == 0 || strlen(data3) == 0 || strlen(data4) == 0 || strlen(data5) == 0 ||
					strlen(data6) == 0 || strlen(data7) == 0) {
					MessageBoxA(addHandle, "Trebuiesc completate toate casutele!", "Try again", MB_OK);
				}
				else if (!srch_ifexists(1, data1)) {
					MessageBoxA(editHandle, "ID-ul introdus exista deja!", "Try again", MB_OK);
				}
				else if (!E_only_Numbers(data1)) {
					MessageBoxA(editHandle, "ID-ul trebuie sa contina doar cifre!", "Try again", MB_OK);
				}
				else if (!E_no_symbols(data2)) {
					MessageBoxA(editHandle, "Numele trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data3)) {
					MessageBoxA(editHandle, "Prenumele trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (!E_only_Numbers(data4)) {
					MessageBoxA(editHandle, "Varsta trebuie sa contina numai cifre!", "Try again", MB_OK);
				}
				else if (!E_only_LetandNumbs(data5)) {
					MessageBoxA(editHandle, "Adresa poate contine doar cifre si litere!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data6)) {
					MessageBoxA(editHandle, "Numele mamei trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data7)) {
					MessageBoxA(editHandle, "Numele tatalui trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (atoi(data4) >= 4) {
					if (lgth_3group <= 25) {
						Kid first, second;
						first = Group1[copy_i];
						int k = copy_i;
						for (int l = k; l < lgth_1group - 1; l++) {
							swap(Group1[k], Group1[k + 1]);
						}
						lgth_1group--;
						Group3[lgth_3group].ID = atoi(data1);
						strcpy(Group3[lgth_3group].Nume, data2);
						strcpy(Group3[lgth_3group].Prenume, data3);
						Group3[lgth_3group].Varsta = atoi(data4);
						strcpy(Group3[lgth_3group].Adresa, data5);
						strcpy(Group3[lgth_3group].Nume_mama, data6);
						strcpy(Group3[lgth_3group].Nume_tata, data7);

						second = Group3[lgth_3group++];
						update_logs(first, second, 1);
						if (isgroup == true) {
							ShowWindow(groupsHandle, 5);
						}
						else {
							ShowWindow(srchHandle, 5);
						}
						ShowWindow(editHandle, 0);
						update_all_kis();
					}
					else {
						MessageBoxA(editHandle, "Grupa 3 este plina!", "Try again", MB_OK | MB_ICONWARNING);
					}
				}
				else if (atoi(data4) >= 2) {
					if (lgth_2group <= 25) {
						Kid first, second;
						first = Group1[copy_i];
						int k = copy_i;
						for (int l = k; l < lgth_1group - 1; l++) {
							swap(Group1[k], Group1[k + 1]);
						}
						lgth_1group--;
						Group2[lgth_2group].ID = atoi(data1);
						strcpy(Group2[lgth_2group].Nume, data2);
						strcpy(Group2[lgth_2group].Prenume, data3);
						Group2[lgth_2group].Varsta = atoi(data4);
						strcpy(Group2[lgth_2group].Adresa, data5);
						strcpy(Group2[lgth_2group].Nume_mama, data6);
						strcpy(Group2[lgth_2group].Nume_tata, data7);

						second = Group2[lgth_2group++];
						update_logs(first, second, 1);
						if (isgroup == true) {
							ShowWindow(groupsHandle, 5);
						}
						else {
							ShowWindow(srchHandle, 5);
						}
						ShowWindow(editHandle, 0);
						update_all_kis();
					}
					else {
						MessageBoxA(editHandle, "Grupa 2 este plina!", "Try again", MB_OK | MB_ICONWARNING);
					}
				}
				else {
					Kid first, second;
					first = Group1[copy_i];
					Group1[copy_i].ID = atoi(data1);
					strcpy(Group1[copy_i].Nume, data2);
					strcpy(Group1[copy_i].Prenume, data3);
					Group1[copy_i].Varsta = atoi(data4);
					strcpy(Group1[copy_i].Adresa, data5);
					strcpy(Group1[copy_i].Nume_mama, data6);
					strcpy(Group1[copy_i].Nume_tata, data7);

					second = Group1[copy_i];
					update_logs(first, second, 1);
					if (isgroup == true) {
						ShowWindow(groupsHandle, 5);
					}
					else {
						ShowWindow(srchHandle, 5);
					}
					ShowWindow(editHandle, 0);
					update_all_kis();
				}
			}
			else if (which_group == 2) {
				char data1[1000], data2[1000], data3[1000], data4[1000], data5[1000], data6[1000], data7[1000];
				GetWindowTextA(Txt1, data1, 1000);
				GetWindowTextA(Txt2, data2, 1000);
				GetWindowTextA(Txt3, data3, 1000);
				GetWindowTextA(Txt4, data4, 1000);
				GetWindowTextA(Txt5, data5, 1000);
				GetWindowTextA(Txt6, data6, 1000);
				GetWindowTextA(Txt7, data7, 1000);
				GetRidofSpaces(data1); GetRidofSpaces(data2); GetRidofSpaces(data3); GetRidofSpaces(data4); GetRidofSpaces(data5); GetRidofSpaces(data6); GetRidofSpaces(data7);
				if (strlen(data1) == 0 || strlen(data2) == 0 || strlen(data3) == 0 || strlen(data4) == 0 || strlen(data5) == 0 ||
					strlen(data6) == 0 || strlen(data7) == 0) {
					MessageBoxA(addHandle, "Trebuiesc completate toate casutele!", "Try again", MB_OK);
				}
				else if (!srch_ifexists(1, data1)) {
					MessageBoxA(editHandle, "ID-ul introdus exista deja!", "Try again", MB_OK);
				}
				else if (!E_only_Numbers(data1)) {
					MessageBoxA(editHandle, "ID-ul trebuie sa contina doar cifre!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data2)) {
					MessageBoxA(editHandle, "Numele trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data3)) {
					MessageBoxA(editHandle, "Prenumele trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (!E_only_Numbers(data4)) {
					MessageBoxA(editHandle, "Varsta trebuie sa contina numai cifre!", "Try again", MB_OK);
				}
				else if (!E_only_LetandNumbs(data5)) {
					MessageBoxA(editHandle, "Adresa poate contine doar cifre si litere!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data6)) {
					MessageBoxA(editHandle, "Numele mamei trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data7)) {
					MessageBoxA(editHandle, "Numele tatalui trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (atoi(data4) >= 4) {
					if (lgth_3group <= 25) {
						Kid first, second;
						first = Group2[copy_i];
						int k = copy_i;
						for (int l = k; l < lgth_2group - 1; l++) {
							swap(Group2[k], Group2[k + 1]);
						}
						lgth_2group--;
						Group3[lgth_3group].ID = atoi(data1);
						strcpy(Group3[lgth_3group].Nume, data2);
						strcpy(Group3[lgth_3group].Prenume, data3);
						Group3[lgth_3group].Varsta = atoi(data4);
						strcpy(Group3[lgth_3group].Adresa, data5);
						strcpy(Group3[lgth_3group].Nume_mama, data6);
						strcpy(Group3[lgth_3group].Nume_tata, data7);

						second = Group3[lgth_3group++];
						update_logs(first, second, 1);
						if (isgroup == true) {
							ShowWindow(groupsHandle, 5);
						}
						else {
							ShowWindow(srchHandle, 5);
						}
						ShowWindow(editHandle, 0);
						update_all_kis();
					}
					else {
						MessageBoxA(editHandle, "Grupa 3 este plina!", "Try again", MB_OK | MB_ICONWARNING);
					}
				}
				else if (atoi(data4) < 2) {
					if (lgth_1group <= 25) {
						Kid first, second;
						first = Group2[copy_i];
						int k = copy_i;
						for (int l = k; l < lgth_2group - 1; l++) {
							swap(Group2[k], Group2[k + 1]);
						}
						lgth_2group--;
						Group1[lgth_1group].ID = atoi(data1);
						strcpy(Group1[lgth_1group].Nume, data2);
						strcpy(Group1[lgth_1group].Prenume, data3);
						Group1[lgth_1group].Varsta = atoi(data4);
						strcpy(Group1[lgth_1group].Adresa, data5);
						strcpy(Group1[lgth_1group].Nume_mama, data6);
						strcpy(Group1[lgth_1group].Nume_tata, data7);

						second = Group1[lgth_1group++];
						update_logs(first, second, 1);
						if (isgroup == true) {
							ShowWindow(groupsHandle, 5);
						}
						else {
							ShowWindow(srchHandle, 5);
						}
						ShowWindow(editHandle, 0);
						update_all_kis();
					}
					else {
						MessageBoxA(editHandle, "Grupa 1 este plina!", "Try again", MB_OK | MB_ICONWARNING);
					}
				}
				else {
					Kid first, second;
					first = Group2[copy_i];
					Group2[copy_i].ID = atoi(data1);
					strcpy(Group2[copy_i].Nume, data2);
					strcpy(Group2[copy_i].Prenume, data3);
					Group2[copy_i].Varsta = atoi(data4);
					strcpy(Group2[copy_i].Adresa, data5);
					strcpy(Group2[copy_i].Nume_mama, data6);
					strcpy(Group2[copy_i].Nume_tata, data7);

					second = Group2[copy_i];
					update_logs(first, second, 1);
					if (isgroup == true) {
						ShowWindow(groupsHandle, 5);
					}
					else {
						ShowWindow(srchHandle, 5);
					}
					ShowWindow(editHandle, 0);
					update_all_kis();
				}
			}
			else if (which_group == 3) {
				char data1[1000], data2[1000], data3[1000], data4[1000], data5[1000], data6[1000], data7[1000];
				GetWindowTextA(Txt1, data1, 1000);
				GetWindowTextA(Txt2, data2, 1000);
				GetWindowTextA(Txt3, data3, 1000);
				GetWindowTextA(Txt4, data4, 1000);
				GetWindowTextA(Txt5, data5, 1000);
				GetWindowTextA(Txt6, data6, 1000);
				GetWindowTextA(Txt7, data7, 1000);
				GetRidofSpaces(data1); GetRidofSpaces(data2); GetRidofSpaces(data3); GetRidofSpaces(data4); GetRidofSpaces(data5); GetRidofSpaces(data6); GetRidofSpaces(data7);
				if (strlen(data1) == 0 || strlen(data2) == 0 || strlen(data3) == 0 || strlen(data4) == 0 || strlen(data5) == 0 ||
					strlen(data6) == 0 || strlen(data7) == 0) {
					MessageBoxA(addHandle, "Trebuiesc completate toate casutele!", "Try again", MB_OK);
				}
				else if (!srch_ifexists(1, data1)) {
					MessageBoxA(editHandle, "ID-ul introdus exista deja!", "Try again", MB_OK);
				}
				else if (!E_only_Numbers(data1)) {
					MessageBoxA(editHandle, "ID-ul trebuie sa contina doar cifre!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data2)) {
					MessageBoxA(editHandle, "Numele trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data3)) {
					MessageBoxA(editHandle, "Prenumele trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (!E_only_Numbers(data4)) {
					MessageBoxA(editHandle, "Varsta trebuie sa contina numai cifre!", "Try again", MB_OK);
				}
				else if (!E_only_LetandNumbs(data5)) {
					MessageBoxA(editHandle, "Adresa poate contine doar cifre si litere!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data6)) {
					MessageBoxA(editHandle, "Numele mamei trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (!E_only_Letters(data7)) {
					MessageBoxA(editHandle, "Numele tatalui trebuie sa contina numai litere!", "Try again", MB_OK);
				}
				else if (atoi(data4) < 4 && atoi(data4)>=2) {
					if (lgth_2group <= 25) {
						Kid first, second;
						first = Group3[copy_i];
						int k = copy_i;
						for (int l = k; l < lgth_3group - 1; l++) {
							swap(Group3[k], Group3[k + 1]);
						}
						lgth_3group--;
						Group2[lgth_2group].ID = atoi(data1);
						strcpy(Group2[lgth_2group].Nume, data2);
						strcpy(Group2[lgth_2group].Prenume, data3);
						Group2[lgth_2group].Varsta = atoi(data4);
						strcpy(Group2[lgth_2group].Adresa, data5);
						strcpy(Group2[lgth_2group].Nume_mama, data6);
						strcpy(Group2[lgth_2group].Nume_tata, data7);

						second = Group2[lgth_2group++];
						update_logs(first, second, 1);
						if (isgroup == true) {
							ShowWindow(groupsHandle, 5);
						}
						else {
							ShowWindow(srchHandle, 5);
						}
						ShowWindow(editHandle, 0);
						update_all_kis();
					}
					else {
						MessageBoxA(editHandle, "Grupa 2 este plina!", "Try again", MB_OK | MB_ICONWARNING);
					}
				}
				else if (atoi(data4) < 2) {
					if (lgth_1group <= 25) {
						Kid first, second;
						first = Group3[copy_i];
						int k = copy_i;
						for (int l = k; l < lgth_3group - 1; l++) {
							swap(Group3[k], Group3[k + 1]);
						}
						lgth_3group--;
						Group1[lgth_1group].ID = atoi(data1);
						strcpy(Group1[lgth_1group].Nume, data2);
						strcpy(Group1[lgth_1group].Prenume, data3);
						Group1[lgth_1group].Varsta = atoi(data4);
						strcpy(Group1[lgth_1group].Adresa, data5);
						strcpy(Group1[lgth_1group].Nume_mama, data6);
						strcpy(Group1[lgth_1group].Nume_tata, data7);

						second = Group1[lgth_1group++];
						update_logs(first, second, 1);
						if (isgroup == true) {
							ShowWindow(groupsHandle, 5);
						}
						else {
							ShowWindow(srchHandle, 5);
						}
						ShowWindow(editHandle, 0);
						update_all_kis();
					}
					else {
						MessageBoxA(editHandle, "Grupa 1 este plina!", "Try again", MB_OK | MB_ICONWARNING);
					}
				}
				else {
					Kid first, second;
					first = Group3[copy_i];
					Group3[copy_i].ID = atoi(data1);
					strcpy(Group3[copy_i].Nume, data2);
					strcpy(Group3[copy_i].Prenume, data3);
					Group3[copy_i].Varsta = atoi(data4);
					strcpy(Group3[copy_i].Adresa, data5);
					strcpy(Group3[copy_i].Nume_mama, data6);
					strcpy(Group3[copy_i].Nume_tata, data7);

					second = Group3[copy_i];
					update_logs(first, second, 1);
					if (isgroup == true) {
						ShowWindow(groupsHandle, 5);
					}
					else {
						ShowWindow(srchHandle, 5);
					}
					ShowWindow(editHandle, 0);
					update_all_kis();
				}
			}
			SetWindowTextA(Txt1, ""); SetWindowTextA(Txt2, ""); SetWindowTextA(Txt3, ""); SetWindowTextA(Txt4, ""); SetWindowTextA(Txt5, ""); SetWindowTextA(Txt6, ""); SetWindowTextA(Txt7, "");
			copy_i = -1;
			SendMessage(StaticText1, LB_RESETCONTENT, 0, 0);
			SendMessage(ListBox2, LB_RESETCONTENT, 0, 0);
			break;
		}
		}
		break;
		}
	case WM_KEYDOWN: {
		switch (wParam)
		{
		case VK_ESCAPE: {
			SendMessageA(editHandle, WM_CLOSE, 0, 0);
			break;
		}
		default:
			break;
		}
		break;
	}
	case WM_CLOSE: {
		is_edit = false;
		editproc_close();
		SetWindowTextA(Txt1, ""); SetWindowTextA(Txt2, ""); SetWindowTextA(Txt3, ""); SetWindowTextA(Txt4, ""); SetWindowTextA(Txt5, ""); SetWindowTextA(Txt6, ""); SetWindowTextA(Txt7, "");
		update_all_kis();
		if (isgroup == true) {
			ShowWindow(groupsHandle, 5);
		}
		else {
			ShowWindow(srchHandle, 5);
		}
		ShowWindow(editHandle, 0);
		break;
	}
	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	update_logs(Group1[0], Group1[0], 4);
	read_data();
	//WNDCLASSEX WC;
	{
		WC.cbSize = sizeof(WNDCLASSEX);
		WC.cbClsExtra = 0;
		WC.cbWndExtra = 0;
		WC.hIconSm = 0;

		WC.hInstance = hInstance;
		WC.lpfnWndProc = MenuProc;
		WC.style = CS_HREDRAW | CS_VREDRAW;
		WC.lpszClassName = L"Menu";
		WC.lpszMenuName = 0;
		WC.hCursor = LoadCursor(0, IDC_ARROW);
		WC.hIcon = LoadIcon(0, IDI_INFORMATION);
		WC.hbrBackground = (HBRUSH)GetStockObject(WHITENESS);
	}
	//
	RegisterClassEx(&WC);
	//WNDCLASSEX GR;
	{
		GR.cbSize = sizeof(WNDCLASSEX);
		GR.cbClsExtra = 0;
		GR.cbWndExtra = 0;
		GR.hIconSm = 0;

		GR.hInstance = hInstance;
		GR.lpfnWndProc = GroupsProc;
		GR.style = CS_HREDRAW | CS_VREDRAW;
		GR.lpszClassName = L"Groups";
		GR.lpszMenuName = 0;
		GR.hCursor = LoadCursor(0, IDC_ARROW);
		GR.hIcon = LoadIcon(0, IDI_INFORMATION);
		GR.hbrBackground = (HBRUSH)GetStockObject(WHITENESS);
	}
	//
	RegisterClassEx(&GR);
	//WNDCLASSEX ADD
	{
		ADD.cbSize = sizeof(WNDCLASSEX);
		ADD.cbClsExtra = 0;
		ADD.cbWndExtra = 0;
		ADD.hIconSm = 0;

		ADD.hInstance = hInstance;
		ADD.lpfnWndProc = AddProc;
		ADD.style = CS_HREDRAW | CS_VREDRAW;
		ADD.lpszClassName = L"Inscriere";
		ADD.lpszMenuName = 0;
		ADD.hCursor = LoadCursor(0, IDC_ARROW);
		ADD.hIcon = LoadIcon(0, IDI_INFORMATION);
		ADD.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	}
	RegisterClassEx(&ADD);
	//WNDCLASSEX SRCH
	{
		SRCH.cbSize = sizeof(WNDCLASSEX);
		SRCH.cbClsExtra = 0;
		SRCH.cbWndExtra = 0;
		SRCH.hIconSm = 0;

		SRCH.hInstance = hInstance;
		SRCH.lpfnWndProc = SrchProc;
		SRCH.style = CS_HREDRAW | CS_VREDRAW;
		SRCH.lpszClassName = L"Search";
		SRCH.lpszMenuName = 0;
		SRCH.hCursor = LoadCursor(0, IDC_ARROW);
		SRCH.hIcon = LoadIcon(0, IDI_INFORMATION);
		SRCH.hbrBackground = (HBRUSH)GetStockObject(WHITENESS);
	}
	RegisterClassEx(&SRCH);
	//WNDCLASSEX EDIT
	{
		EDIT.cbSize = sizeof(WNDCLASSEX);
		EDIT.cbClsExtra = 0;
		EDIT.cbWndExtra = 0;
		EDIT.hIconSm = 0;

		EDIT.hInstance = hInstance;
		EDIT.lpfnWndProc = EditProc;
		EDIT.style = CS_HREDRAW | CS_VREDRAW;
		EDIT.lpszClassName = L"Editare";
		EDIT.lpszMenuName = 0;
		EDIT.hCursor = LoadCursor(0, IDC_ARROW);
		EDIT.hIcon = LoadIcon(0, IDI_INFORMATION);
		EDIT.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	}
	RegisterClassEx(&EDIT);
	
	//RECT rc;

	//GetWindowRect(windowHandle, &rc);

	int _x = (GetSystemMetrics(SM_CXSCREEN) - 760) / 2;//set it in the center of the screen not where it is now
	int _y = (GetSystemMetrics(SM_CYSCREEN) - 600) / 2;

	windowHandle = CreateWindow(L"Menu", L"Menu", WS_SYSMENU | WS_MINIMIZEBOX | WS_DLGFRAME,
		_x, _y, 380, 380, 0, 0, hInstance, 0);
	//
	groupsHandle = CreateWindow(L"Groups", L"View Groups", WS_SYSMENU | WS_MINIMIZEBOX,
		_x, _y, 600, 360, 0, 0, hInstance, 0);
	//
	addHandle = CreateWindow(L"Inscriere", L"Add", WS_SYSMENU | WS_MINIMIZEBOX,
		_x, _y, 400, 340, 0, 0, hInstance, 0);
	//
	srchHandle = CreateWindow(L"Search", L"Search", WS_SYSMENU | WS_MINIMIZEBOX,
		_x, _y, 600, 340, 0, 0, hInstance, 0);
	//
	editHandle = CreateWindow(L"Editare", L"Edit", WS_SYSMENU | WS_MINIMIZEBOX,
		_x, _y, 400, 340, 0, 0, hInstance, 0);
	//
	if (windowHandle == 0 || groupsHandle == 0 || addHandle == 0 || editHandle == 0 || srchHandle == 0) {
		MessageBoxA(0, "Create window failed!", "Error", 0);
	}
	//
	ShowWindow(windowHandle, nCmdShow);
	//
	UpdateWindow(windowHandle);

	//
	MSG msg;
	SecureZeroMemory(&msg, sizeof(MSG));//initialize all comp with 0/NULL
	int returnValue = 0;

	while ((returnValue = GetMessage(&msg, 0, 0, 0)) != 0) {
		if (returnValue == -1) {
			MessageBoxA(windowHandle, "Shiat! Try again!", "Somewhere went wrong", 0);
			break;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;

	return 0;
}
//END