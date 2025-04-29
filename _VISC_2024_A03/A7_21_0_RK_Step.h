#pragma once

#include "B7_21_10_Lio2D.h"
#include "B7_21_20_PKtau.h"

void A7_21_0_RK_Step(int Step, double Tau) {
//	int Km = K - 1, 
int x, y;
double Save;
int Old, Nxt;

	B7_21_10_Lio2D(1, GRO1,GU1,GV1,GE1,  LRO1,LU1,LV1,LE1); //Расчёт нового слоя "Первого" газа.
	B7_21_10_Lio2D(2, GRO2,GU2,GV2,GE2,  LRO2,LU2,LV2,LE2); //Расчёт нового слоя "Второго" газа.
	
	for (y = 1; y <= Nyp; y++) { //do k = 1,nyp
		for (x = 1; x <= Nxp; x++) { //do i = 1,nxp
			KRO1[y][x] += LRO1[y][x];
			KRO2[y][x] += LRO2[y][x];
			KU1[y][x] += LU1[y][x];
			KU2[y][x] += LU2[y][x];
			KV1[y][x] += LV1[y][x];
			KV2[y][x] += LV2[y][x];
			KE1[y][x] += LE1[y][x];
			KE2[y][x] += LE2[y][x];
		} //enddo
	} //enddo	

	B7_21_20_PKtau(Tau,      RO1,U1,V1,E1,  RO2,U2,V2,E2,
							 GRO1,GU1,GV1,GE1,  
							 GRO2,GU2,GV2,GE2); //Первый (из двух) шаг Рунге-Кутта.



/*
if (Step == 1) {
	B7_21_10_Lio2D(0,1, RO1,U1,V1,E1,  KRO1,KU1,KV1,KE1); //Расчёт нового слоя "Первого" газа.
	B7_21_10_Lio2D(0,2, RO2,U2,V2,E2,  KRO2,KU2,KV2,KE2); //Расчёт нового слоя "Второго" газа.
	
	B7_21_20_PKtau(Tau,      RO1,U1,V1,E1,  RO2,U2,V2,E2,
							 GRO1[1],GU1[1],GV1[1],GE1[1],  
							 GRO2[1],GU2[1],GV2[1],GE2[1]); //Первый (из двух) шаг Рунге-Кутта.
}
	
else {
	Old = (Step+1) % 2;
	Nxt = Step % 2;
	
	B7_21_10_Lio2D(Old,1, GRO1[Old],GU1[Old],GV1[Old],GE1[Old],  KRO1,KU1,KV1,KE1); //Расчёт нового слоя "Первого" газа.
	B7_21_10_Lio2D(Old,2, GRO2[Old],GU2[Old],GV2[Old],GE2[Old],  KRO2,KU2,KV2,KE2); //Расчёт нового слоя "Второго" газа.
	
	B7_21_20_PKtau(Tau,      
		GRO1[Old],GU1[Old],GV1[Old],GE1[Old],  GRO2[Old],GU2[Old],GV2[Old],GE2[Old],
		GRO1[Nxt],GU1[Nxt],GV1[Nxt],GE1[Nxt],  GRO2[Nxt],GU2[Nxt],GV2[Nxt],GE2[Nxt]); //Первый (из двух) шаг Рунге-Кутта.
}
*/


}

