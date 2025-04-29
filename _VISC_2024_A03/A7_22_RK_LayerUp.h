#pragma once

void A7_2_2_RK_LayerUp() {

int Nxt,x,y;

if (TypeTau == '2') Nxt = 0;
else                Nxt = 1;
	
for (y = 1; y <= Nyp; y++) { //DO K = 1,NYp
	for(x=1; x<=Nxp; x++) { //DO I = 1,NXp
		RO1[y][x]= GRO1[Nxt][y][x];
		U1[y][x] = GU1[Nxt][y][x];
		V1[y][x] = GV1[Nxt][y][x];
		E1[y][x] = GE1[Nxt][y][x];
		RO2[y][x]= GRO2[Nxt][y][x];
		U2[y][x] = GU2[Nxt][y][x];
		V2[y][x] = GV2[Nxt][y][x];
		E2[y][x] = GE2[Nxt][y][x];
	} //ENDDO
} //ENDDO



}

