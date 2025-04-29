#pragma once
#include "A7_21_0_RK_Step.h"
#include "A7_22_RK_LayerUp.h"

void A7_20_RungeKutt(double Tau) {
	int x, y;

//	L = f(Y);
//	K = L;
//	G = Y + h / 2 * K;

//	L = f(G);
//	K = K + L;
//	G = Y + h / 2 * K;

//	L = f(G);
//	K = K + L;
//	G = Y + (h / 3) * K;

//	Y1 = G;

	for (y = 1; y <= Nyp; y++) { //do k = 1,nyp
		for (x = 1; x <= Nxp; x++) { //do i = 1,nxp
			KRO1[y][x] = 0.0;
			KRO2[y][x] = 0.0;
			KU1[y][x] = 0.0;
			KU2[y][x] = 0.0;
			KV1[y][x] = 0.0;
			KV2[y][x] = 0.0;
			KE1[y][x] = 0.0;
			KE2[y][x] = 0.0;
		} //enddo
	} //enddo	

	A7_21_0_RK_Step(1, Tau / 2);
	A7_21_0_RK_Step(1, Tau / 2);
	A7_21_0_RK_Step(1, Tau / 3);

/*if (TypeTau == '5') {
	A7_21_0_RK_Step(1, Tau / 4);
	A7_21_0_RK_Step(2, Tau / 6);
	A7_21_0_RK_Step(3, 3.0*Tau / 8);
	A7_21_0_RK_Step(4, Tau / 2);
	A7_21_0_RK_Step(5, Tau);
}

else if (TypeTau == '3') {
	A7_21_0_RK_Step(1, Tau / 2);
	A7_21_0_RK_Step(2, Tau / 2);
	A7_21_0_RK_Step(3, Tau);
}

else if (TypeTau == '2') {
	A7_21_0_RK_Step(1, Tau / 2);
	A7_21_0_RK_Step(2, Tau);
}

else if (TypeTau == '1') {
	A7_21_0_RK_Step(1, Tau);
}

else { cout << "Nepravilno ukazan tip shemy!!!" << endl; }
*/

A7_2_2_RK_LayerUp();
}