#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv ) {
    long long t1, t2, freq,numOfLines=0,nread;
	char str[4096];
	int i=0;

	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	
	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
	
	FILE* f = fopen("a.txt","rb");

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек
	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	while(!feof(f)){
		nread = fread(str,1,4096,f);
		for(i=0;i<nread;i++){
			if (str[i]=='\n') numOfLines++;
		}
	}
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла
	cout << "\nTime spent:" << fixed << (t2-t1)/(1.*freq)<<endl<<"Number of lines:"<<numOfLines<<endl;

	fclose(f);

	return 0;
}