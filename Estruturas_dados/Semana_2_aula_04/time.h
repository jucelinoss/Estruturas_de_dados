#pragma once
/*
  As primeiras linhas de c?digo deste arquivo servem para evitar que
  m?ltiplas defini??es da classe Time ocorram. Isso poderia ocorrer se
  voc? der include de dois pacotes que d?o include em "time.h"
*/

#ifndef TIME_H   // Inclua esse bloco apenas se TIME_H n?o est? definido
#define TIME_H   // Na primeira inclus?o, defina TIME_H para que este bloco n?o seja inclu?do mais de uma vez.

class Time {
private:  // Se??o Privada
 // Membros privados
	int hour;     // 0 - 23
	int minute;   // 0 - 59
	int second;   // 0 - 59
public:   // Se??o P?blica
	Time(int hour = 0, int minute = 0, int second = 0);
	int getHour() const;
	void setHour(int hour);
	int getMinute() const;
	void setMinute(int minute);
	int getSecond() const;
	void setSecond(int second);
	void print() const;
	void nextSecond();
};

#endif  // Final do bloco "#ifndef"









