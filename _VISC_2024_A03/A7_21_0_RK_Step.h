#pragma once

#include "B7_21_10_Lio2D.h"
#include "B7_21_20_PKtau.h"

void A7_21_0_RK_Step(int Step, double Tau) {
//	int Km = K - 1, 
int x, y;
double Save;
int Old, Nxt;

if (Step == 1) {
	B7_21_10_Lio2D(0,1, RO1,U1,V1,E1,  KRO1,KU1,KV1,KE1); //������ ������ ���� "�������" ����.
	B7_21_10_Lio2D(0,2, RO2,U2,V2,E2,  KRO2,KU2,KV2,KE2); //������ ������ ���� "�������" ����.
	
	B7_21_20_PKtau(Tau,      RO1,U1,V1,E1,  RO2,U2,V2,E2,
							 GRO1[1],GU1[1],GV1[1],GE1[1],  
							 GRO2[1],GU2[1],GV2[1],GE2[1]); //������ (�� ����) ��� �����-�����.
}
	
else {
	Old = (Step+1) % 2;
	Nxt = Step % 2;
	
	B7_21_10_Lio2D(Old,1, GRO1[Old],GU1[Old],GV1[Old],GE1[Old],  KRO1,KU1,KV1,KE1); //������ ������ ���� "�������" ����.
	B7_21_10_Lio2D(Old,2, GRO2[Old],GU2[Old],GV2[Old],GE2[Old],  KRO2,KU2,KV2,KE2); //������ ������ ���� "�������" ����.
	
	B7_21_20_PKtau(Tau,      
		GRO1[Old],GU1[Old],GV1[Old],GE1[Old],  GRO2[Old],GU2[Old],GV2[Old],GE2[Old],
		GRO1[Nxt],GU1[Nxt],GV1[Nxt],GE1[Nxt],  GRO2[Nxt],GU2[Nxt],GV2[Nxt],GE2[Nxt]); //������ (�� ����) ��� �����-�����.
}

}

