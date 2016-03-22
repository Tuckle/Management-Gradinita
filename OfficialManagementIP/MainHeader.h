#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

ofstream print("Test.txt", std::ios::out);
ofstream log_this("Logs.txt", std::ios::app);

typedef struct
{
	TCHAR achName[MAX_PATH];
	TCHAR achPosition[12];
	int nGamesPlayed;
	int nGoalsScored;
} TxtBoxGroups;
TxtBoxGroups Groups[76];
////
struct Kid {
	unsigned int ID = 0, Grupa = 0, Varsta = 0;
	//char  *Nume,*Prenume, *Adresa, *Nume_mama, *Nume_tata, *Varsta;
	char Nume[40], Prenume[100], Adresa[100], Nume_mama[100], Nume_tata[100];
	//string Nume, Prenume, Adresa, Nume_mama, Nume_tata, Varsta;
	//TCHAR *Nume, *Prenume, *Adresa, *Nume_mama, *Nume_tata, *Varsta;
};
struct NrOfKidsPerGroup {
	unsigned int Grupa1 = 0, Grupa2 = 0, Grupa3 = 0;
};

Kid all_kids[76], Group1[26], Group2[26], Group3[26], SearchArray[76];
NrOfKidsPerGroup kidspergr;

//
void GetRidofSpaces(char s[]) {
	while (s[0] == ' ') {
		strcpy(s, s + 1);
	}
	int i = strlen(s) - 1;
	while (s[i] == ' ') {
		i--;
	}
	s[i + 1] = '\0';
}
void update_logs(Kid first, Kid second, int option) {//1 save, 2 delete, 3 add
	time_t timer;
	time(&timer);
	char *timestamp = ctime(&timer);
	switch (option) {
	case 1://save
	{
		log_this << ' ' << timestamp << " A fost editata inregistrarea: din(" <<
			first.ID << '|' << first.Nume << '|' << first.Prenume << '|' << first.Varsta << '|' << first.Adresa << '|' <<
			first.Nume_mama << '|' << first.Nume_tata << ')' << " in (" << second.ID << '|' << second.Nume << '|' <<
			second.Prenume << '|' << second.Varsta << '|' << second.Adresa << '|' << second.Nume_mama << '|' << second.Nume_tata << ");" << '\n';
		break;
	}
	case 2://delete
	{
		log_this << ' ' << timestamp << " A fost stearsa inregistrarea: (" << first.ID << '|' << first.Nume << '|' << first.Prenume << '|' <<
			first.Varsta << '|' << first.Adresa << '|' << first.Nume_mama << '|' << first.Nume_tata << ");" << '\n';
		break;
	}
	case 3://add
	{
		log_this << ' ' << timestamp << " A fost adaugata inregistrarea: (" << first.ID << '|' << first.Nume << '|' << first.Prenume << '|' <<
			first.Varsta << '|' << first.Adresa << '|' << first.Nume_mama << '|' << first.Nume_tata << ");" << '\n';
		break;
	}
	case 4://application open
	{
		log_this << ' ' << timestamp << " Aplicatia a fost deschisa." << '\n';
		break;
	}
	default:
		break;
	}
}

//data storing
int nr_data = 0, lgth_1group = 0, lgth_2group = 0, lgth_3group = 0, lgth_srcharray = 0;
void sort_groups() {
	for (int i = 0; i < lgth_1group - 1; i++) {
		for (int j = i + 1; j < lgth_1group; j++) {
			if (Group1[i].Nume > Group1[j].Nume) {
				swap(Group1[i], Group1[j]);
			}
		}
	}
	
	for (int i = 0; i < lgth_2group - 1; i++) {
		for (int j = i + 1; j < lgth_2group; j++) {
			if (Group2[i].Nume > Group2[j].Nume) {
				swap(Group2[i], Group2[j]);
			}
		}
	}

	for (int i = 0; i < lgth_3group - 1; i++) {
		for (int j = i + 1; j < lgth_3group; j++) {
			if (Group3[i].Nume > Group3[j].Nume) {
				swap(Group3[i], Group3[j]);
			}
		}
	}
}
void sort_search() {
	for (int i = 0; i < lgth_srcharray; i++) {
		for (int j = 0; j < lgth_srcharray; j++) {
			if (strcmp(SearchArray[i].Nume, SearchArray[j].Nume)>0) {
				swap(SearchArray[i].Nume, SearchArray[j].Nume);
			}
		}
	}
}
void sort_all_kids() {
	for (int i = 0; i < nr_data - 1; i++) {
		for (int j = i + 1; j < nr_data; j++) {
			if (all_kids[i].Nume > all_kids[j].Nume) {
				swap(all_kids[i], all_kids[j]);
			}
		}
	}
}
void attrib_data_to_groups() {
	for (int i = 0; i < nr_data; i++) {
		if (all_kids[i].Grupa == 1) {
			Group1[lgth_1group++] = all_kids[i];
		}
		else if (all_kids[i].Grupa == 2) {
			Group2[lgth_2group++] = all_kids[i];
		}
		else if (all_kids[i].Grupa == 3) {
			Group3[lgth_3group++] = all_kids[i];
		}
	}
}
void update_all_kis() {
	sort_groups();
	nr_data = 0;
	for (int i = 0; i < lgth_1group; i++) {
		all_kids[nr_data++] = Group1[i];
	}
	for (int i = 0; i < lgth_2group; i++) {
		all_kids[nr_data++] = Group2[i];
	}
	for (int i = 0; i < lgth_3group; i++) {
		all_kids[nr_data++] = Group3[i];
	}
	sort_all_kids();
}
void update_data_from_srch() {
	lgth_1group = lgth_2group = lgth_3group = 0;
	for (int i = 0; i < lgth_srcharray; i++) {
		if (SearchArray[i].Grupa == 1) {
			Group1[lgth_1group++] = SearchArray[i];
		}
		else if (SearchArray[i].Grupa == 2) {
			Group2[lgth_2group++] = SearchArray[i];
		}
		else if (SearchArray[i].Grupa == 3) {
			Group3[lgth_3group++] = SearchArray[i];
		}
	}
	update_all_kis();
}
void refresh_searcharray() {
	Kid copy; copy.ID = copy.Varsta = copy.Grupa = 0;
	strcpy(copy.Prenume, "");
	strcpy(copy.Nume_tata, copy.Prenume); strcpy(copy.Adresa, copy.Prenume);
	strcpy(copy.Nume, copy.Adresa); strcpy(copy.Nume_mama, copy.Adresa);
	while (lgth_srcharray > 0) {
		SearchArray[lgth_srcharray--] = copy;
	}
	SearchArray[lgth_srcharray] = copy;
}

//read from files
void read_data() {
	//FILE *read = freopen(grupa, "r", stdin);
	nr_data = 0;
	ifstream read1("Grupa1", std::ios::in);
	ifstream read2("Grupa2", std::ios::in);
	ifstream read3("Grupa3", std::ios::in);

	if (!read1 || !read2 || !read3) {}
	else {
		int kidsnr = 0;
		read1 >> kidsnr; read1.get();
		kidspergr.Grupa1 = kidsnr;
			for (int count = 0; count < kidsnr; count++) {
				char line[1000];
				all_kids[nr_data].Grupa = 1;
				read1 >> all_kids[nr_data].ID;
				read1.getline(line, 1000);
				char *p;
				p = strtok(line, "|");
				strcpy(all_kids[nr_data].Nume, p + 1);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Prenume, p);
				p = strtok(NULL, "|");
				all_kids[nr_data].Varsta = atoi(p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Adresa, p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Nume_mama, p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Nume_tata, p);
				nr_data++;
			}
		read2 >> kidsnr; read2.get();
		kidspergr.Grupa2 = kidsnr;
			for (int count = 0; count < kidsnr; count++) {
				char line[1000];
				all_kids[nr_data].Grupa = 2;
				read2 >> all_kids[nr_data].ID;
				read2.getline(line, 1000);
				char *p;
				p = strtok(line, "|");
				strcpy(all_kids[nr_data].Nume, p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Prenume, p);
				p = strtok(NULL, "|");
				all_kids[nr_data].Varsta = atoi(p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Adresa, p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Nume_mama, p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Nume_tata, p);
				nr_data++;
			}
		read3 >> kidsnr; read3.get();
		kidspergr.Grupa3 = kidsnr;
			for (int count = 0; count < kidsnr; count++) {
				char line[1000];
				all_kids[nr_data].Grupa = 3;
				read3 >> all_kids[nr_data].ID;
				read3.getline(line, 1000);
				char *p;
				p = strtok(line, "|");
				strcpy(all_kids[nr_data].Nume, p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Prenume, p);
				p = strtok(NULL, "|");
				all_kids[nr_data].Varsta = atoi(p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Adresa, p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Nume_mama, p);
				p = strtok(NULL, "|");
				strcpy(all_kids[nr_data].Nume_tata, p);
				nr_data++;
			}
	}
		read1.close();
		read2.close();
		read3.close();
		
		for (int i = 0; i < nr_data; i++) {
			GetRidofSpaces(all_kids[i].Nume);
		}
		sort_all_kids();
		attrib_data_to_groups();
		/*for (int count = 0; count < nr_data; count++) {
			print << all_kids[count].ID << ' ' << all_kids[count].Nume << ' ' << all_kids[count].Prenume << ' ' << all_kids[count].Varsta << ' ' << all_kids[count].Adresa << ' ' << all_kids[count].Nume_mama << ' ' << all_kids[count].Nume_tata << '\n';
		}*/
}

//ID Generator + check exists data
bool Exists_Record(Kid Compare) {
	for (int i = 0; i < nr_data; i++) {
		if (Compare.Adresa == all_kids[i].Adresa && Compare.Grupa == all_kids[i].Grupa && Compare.Nume == all_kids[i].Nume&&
			Compare.Nume_mama == all_kids[i].Nume_mama&&Compare.Nume_tata == all_kids[i].Nume_tata
			&& Compare.Prenume == all_kids[i].Prenume && Compare.Varsta == all_kids[i].Varsta) {
			return true;
		}
	}
	return false;
}
bool Exists_ID(int IDnumber) {
	for (int count = 0; count < nr_data; count++) {
		if (IDnumber == all_kids[count].ID) {
			return false;
		}
	}
	return true;
}
int GetRandomValue() {
	srand(time(NULL));
	int IDnumber = rand();
	int randomize = rand() % 100;
	IDnumber /= randomize;
	if (IDnumber < 0) IDnumber = -IDnumber;
	IDnumber %= 1000000;
	return IDnumber;
}

//text check
bool E_only_Numbers(char *text) {
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] >= '0'&&text[i] <= '9') {}
		else return false;
	}
	return true;
}
bool E_only_Letters(char *text) {
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] >= 'a'&&text[i] <= 'z' || text[i] >= 'A'&&text[i] <= 'Z' || text[i]=='-' || text[i] == ' ') {}
		else return false;
	}
	return true;
}
bool E_only_LetandNumbs(char *text) {
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] >= 'a'&&text[i] <= 'z' || text[i] >= 'A'&&text[i] <= 'Z' || text[i] == '-' || text[i] == ',' || text[i] == ' ' || text[i] == '.' ||
			text[i] >= '0'&&text[i] <= '9') {}
		else return false;
	}
	return true;
}
bool E_no_symbols(char *text) {
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] >= 'a'&&text[i] <= 'z' || text[i] >= 'A'&&text[i] <= 'Z') { }
		else return false;
	}
	return true;
}

//END