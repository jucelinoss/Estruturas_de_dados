/* Implementa??o da classe Time */
#include <iostream>  // Para usar a fun??o std::cout.
#include "time.h"    // Para visualizar a classe Time.

using namespace std; // Para escrever cout ao inv?s de
			 // std::cout.

/*
   Getters
 */
int Time::getHour() const {
	return hour;
}

int Time::getMinute() const {
	return minute;
}

int Time::getSecond() const {
	return second;
}

/*
  Nos m?todos "set", a classe est? recebendo como par?metro uma
  vari?vel com o mesmo nome do atributo. Esse fato faz com que o
  atributo seja "escondido". Por exemplo, no m?todo setHour abaixo,
  quando usarmos a vari?vel "hour", estaremos nos referindo ao
  par?metro e n?o ao atributo da classe.

  Para contornar esse problema, usamos a palavra reservada
  "this". Assim:

  this->hour, this->minute e this->second se referem aos atributos.

  hour, minute e second se referem aos par?metros dos m?todos abaixo.
 */

 /*
   Setters
  */
void Time::setHour(int hour) {
	this->hour = hour;
}

void Time::setMinute(int minute) {
	this->minute = minute;
}

void Time::setSecond(int second) {
	this->second = second;
}

void Time::print() const {
	cout << hour << ":" << minute << ":" << second << endl;
}

void Time::nextSecond() {
	second += 1;
	if (second >= 60) {
		second = 0;
		minute += 1;
	}
	if (minute >= 60) {
		minute = 0;
		hour += 1;
	}
	if (hour >= 24) {
		hour = 0;
	}
}

/*
  Deixei o construtor para o fim para voc? conhecer uma sintaxe
  alternativa para inicializa??o de atributos. Colocamos uma lista de
  inicializa??o ap?s a declara??o dos par?metros. Para separar os
  par?metros da lista de inicializa??o, usamos ":". A lista possui a
  sintaxe:

  atributo1(par?metroA), atributo2(par?metroB), ..., atributoN(par?metroM).
 */
Time::Time(int h, int m, int s)
{
	this->hour = h;
	this->minute = m;
	this->second = s;
}


//Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {
//	/*
//	  O corpo do m?todo executa ap?s as inicializa??es. Neste caso, ele
//	  est? vazio porque as inicialia??es eram tudo o que quer?amos
//	  fazer.
//	 */
//}
