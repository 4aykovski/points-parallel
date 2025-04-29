#pragma once

void A7_2_2_RK_LayerUp() {

int Nxt,x,y;

//if (TypeTau == '2') Nxt = 0;
//else                Nxt = 1;
	
for (y = 1; y <= Nyp; y++) { //DO K = 1,NYp
	for(x=1; x<=Nxp; x++) { //DO I = 1,NXp
		RO1[y][x]= GRO1[y][x];
		U1[y][x] = GU1[y][x];
		V1[y][x] = GV1[y][x];
		E1[y][x] = GE1[y][x];
		RO2[y][x]= GRO2[y][x];
		U2[y][x] = GU2[y][x];
		V2[y][x] = GV2[y][x];
		E2[y][x] = GE2[y][x];
	} //ENDDO
} //ENDDO



}

