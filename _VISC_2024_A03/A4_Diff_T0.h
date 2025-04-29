#pragma once

void A4_Diff_T0() {
double pi = 4 * atan(1.0);
double DifTime, DifC, DifH;
double DifTau, ccA, ccB;
int NDifTau;
double Ro101, Ro102, Ro103;
double rr;
double xrr, yrr, Radius1, Radius2, Radius3;
double td = 0.0, StepWriteOld, StepWriteNew;
//int i, k;
int x, y;

//cout << "M3_Diff_T0()" << endl;

	dd = dd / (dL*1000);
//!��������: �����.�����.� - �� �������� ������ � �� ��������� �������� ��..
	sd = sd * dd;   //!..�������� �����.�-�� �������� ������.
//	om = om2 / om1;
//	sigma = sigma / (dL*1000);


	DifTime = TimeDif / 1000;  //!����� ������������ ������������ ������� � ���.
	DifC = d0Nusl * 1e-4;		   //!����������� �������� � � * � / �
	DifH = h0 / 10;

	DifTau = DifH*DifH/(5.0*DifC);
    NDifTau = 1 + DifTime/DifTau;
	ccA = DifC * DifTau / pow(DifH,2);
	ccB = 1.0 - 4.0*ccA;

	Ro101 = alfa101*om / (1 + (om-1)*alfa101);
	Ro102 = alfa102*om / (1 + (om-1)*alfa102); //!������.��������� ��� 2 - � �����
	Ro103 = alfa103*om / (1 + (om-1)*alfa103); //!������.��������� ��� 3 - � �����

	rr = dd / 2;
	DifTau = DifTime / NDifTau;


	for(x=1; x<=Nxp; x++) { //do i = 1, nxp
		for(y=1; y<=Nyp; y++) { //do k = 1, nyp
			RO1[y][x] = 1.0;
			xrr = XVV[x];
			yrr = YVV[y];

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			if(KONF == 1) { //IF(KONF.EQ. 1) THEN
				Radius1 = sqrt(pow(xrr,2) + pow(yrr,2));
				Radius2 = sqrt(pow(xrr,2) + pow(yrr,2));
				Radius3 = 2 * rr; //����� ��������, �������� ����������� rr.
			}

			if(KONF == 2) { //IF(KONF.EQ. 2) THEN
				Radius1 = sqrt(pow(xrr,2) + pow(yrr-0.5*sd,2));
				Radius2 = sqrt(pow(xrr,2) + pow(yrr+0.5*sd,2));
				Radius3 = 2 * rr; //����� ��������, �������� ����������� rr.
			}

			if(KONF == 3) { //IF(KONF.EQ. 3) THEN
				Radius1 = sqrt(pow(xrr,2) + pow(yrr,2));
				Radius2 = sqrt(pow(xrr,2) + pow(yrr-sd,2));
				Radius3 = sqrt(pow(xrr,2) + pow(yrr+sd,2));
			}

			if(KONF == 4) { //IF(KONF.EQ. 4) THEN
Radius1 = sqrt(pow(xrr,2) + pow(yrr,2));
Radius2 = sqrt(pow(xrr-X3C*sd*cos(pi/6),2) + pow(yrr-sd*sin(pi/6),2));
Radius3 = sqrt(pow(xrr-X3C*sd*cos(pi/6),2) + pow(yrr+sd*sin(pi/6),2));
			}

			if(KONF == 5) { //IF(KONF.EQ. 5) THEN
				Radius1 = sqrt(pow(xrr-X3C*sd*cos(pi/6),2) + pow(yrr,2));
				Radius2 = sqrt(pow(xrr,2) + pow(yrr-sd*sin(pi/6),2));
				Radius3 = sqrt(pow(xrr,2) + pow(yrr+sd*sin(pi/6),2));
			}


			if(Radius1-rr <= h0*1E-3) { //IF(RADIUS1 <= RR) THEN
				RO1[y][x] = Ro101;
			}

			if(Radius2-rr <= h0*1E-3) { //IF(RADIUS2 <= RR) THEN
				RO1[y][x] = Ro102;
			}

			if(Radius3-rr <= h0*1E-3) { //IF(RADIUS3 <= RR) THEN
				RO1[y][x] = Ro103;
			}

			RO2[y][x] = (1 - RO1[y][x]) * om;
		} //enddo:for(k).

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!��������� �� ������ ���� � ������ ���������.
//!**********************************************************************
//!���������_Begin_4!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!���������.��.���.�� ����.��.(����� � 2 ���� �����.� - �� �����)

		if(BoundCondLower == 2) { //IF(ND.EQ. 2) THEN
			RO1[2][x] = RO1[4][x];
			RO1[1][x] = RO1[5][x];
		}
	} //enddo:for(i).
//!���������_End_4

	
//!***************************************************************
//	cout << "DifTime - 0.5 * DifTau = " << DifTime - 0.5 * DifTau << endl;
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	StepWriteOld = 0.0;

	while(td < DifTime-0.5*DifTau) { //DO WHILE(TD < DifTime-0.5*DifTau)
		for(x=IndexXN+1; x<=IndexXK; x++) { //do i = IL1 + 1, IR0
//!*******************************************************************
//!���������_Begin_5.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			for(y=IndexYN; y<=IndexYK; y++) {  //do k = NYdn, NYup

LRO1[y][x] = ccA * (RO1[y+1][x] + RO1[y-1][x] + RO1[y][x+1] + RO1[y][x-1] - 4.0*RO1[y][x]);
			}
		} //enddo:for(i).
//!@@@@ ��� ��������� 7 @@@@@@@@@@@@@@@@@!
		for(x=IndexXN+1; x<=IndexXK; x++) { //do i = IL1 + 1, IR0
			for(y=IndexYN; y<=IndexYK; y++) { //do k = NYdn, NYup  
				RO1[y][x] += LRO1[y][x];
			}

//!���������.��.���.�� ����.��.(����� � 2 ���� �����.� - �� �����)
			if(BoundCondLower == 2) { //IF(ND.EQ. 2) THEN
				RO1[2][x] = RO1[4][x];  //!@@@@@@@@@@ ��� ��������� @@@@@@@@@!
				RO1[1][x] = RO1[5][x];  //!@@@@@@@@@@ ��� ��������� @@@@@@@@@!
			}
//!���������_End_5.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		} //enddo
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		td = td + DifTau;
		StepWriteNew = int(td * 1.0e+2);
		if(StepWriteNew > StepWriteOld) { //IF(StepWriteNew > StepWriteOld) THEN
			cout << "TD = " << td * 1.0e+3 << " msec" << endl;
		} //END IF
		StepWriteOld = StepWriteNew;
	} //END DO (WHILE).

	for(x=1; x<=Nxp; x++) { //do i = 1, nxp
		for(y=1; y<=Nyp; y++) { //do k = 1, nyp
			RO2[y][x] = (1 - RO1[y][x]) * om;
		}
	} //enddo:for(i).

} //END SUBROUTINE S3_DIFF_T0_M

