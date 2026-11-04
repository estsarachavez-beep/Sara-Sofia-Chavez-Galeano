#pragma once
#include <iostream>
class cnodo {
public:
	int ainfo;
	cnodo* asing; //Clase autoreferenciada 

	cnodo() { asing = NULL; }
	cnodo (int pdato)
	{ainfo = pdato; asing = NULL;}
}; 


