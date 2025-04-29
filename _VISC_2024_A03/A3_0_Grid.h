#pragma once
//#include "A3_1_GridX.h"
//#include "A3_2_GridY.h"
void A3_1_GridX();
void A3_2_GridY();

void A3_0_Grid() {
	
	//	dL = 0.1;
//!!!!!!!!!!!!!!!!!!!!!!����������������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	xN = xN / (dL * 1000);
	xK = xK / (dL * 1000);
	x3 = x3 / (dL * 1000);
	yN = yN / (dL * 1000);
	yK = yK / (dL * 1000);
	h0 = h0 / (dL * 1000);
	dSW = dSW / (dL * 1000);

	Gxy1 = Gxy1 / (dL * 1000);
	Gxy2 = Gxy2 / (dL * 1000);
	Gxy3 = Gxy3 / (dL * 1000);
//!******************************************************************

	if(nf==0) {
		A3_1_GridX();
		A3_2_GridY();
	}
	
	else if(nf==1) {
//ifstream Rr21n("Rr21n.dat");
//		int i;
		int x, y;
		ifstream hx("hx.dat");
		ifstream hxX("hxX.dat");
		ifstream hy("hy.dat");
		ifstream hyY("hyY.dat");
		
		hx >> Nxp;
		hxX >> Nxp;
		hy >> Nyp;
		hyY >> Nyp;
		
		for(x=1; x<=Nxp; x++) {
			//Rr21n >> RO1[k][i];
			//hx << fixed << XVV[i] * 100 << endl;
			//hxX << scientific << HX[i] * 100 << endl;
			hx >> XVV[x];	XVV[x] *= 0.01;
			hxX >> HX[x];	HX[x]  *= 0.01;
		}
		
		for(y=3; y<=Nyp; y++) {
			//hy << scientific << YVV[i] * 100 << endl;
			//hyY << scientific << HY[i] * 100 << endl;
			hy >> YVV[y];	
			YVV[y] *= 0.01;
			hyY >> HY[y];	
			HY[y] *= 0.01;
		}
		if(BoundCondLower == 2) {
			YVV[1] = -YVV[5];
			YVV[2] = -YVV[4];
			HY[1] = HY[5];
			HY[2] = HY[4];
		}

		else if(BoundCondLower == 1) {
			HY[2] = HY[3] * qm3;
			YVV[2] = YVV[3] - HY[2];
			HY[1] = HY[2] * qm3;
			YVV[1] = YVV[2] - HY[1];
		}
		else { //(BoundCondLower != {1, 2}).
			cout << "Vveden nepravilnyj parametr dlya nijney granicy!!" << endl;
		}


		cout << "YVV[3] = " << YVV[3] * 100 << endl;
		cout << "YVV[2] = " << YVV[2] * 100 << endl;
		cout << "YVV[1] = " << YVV[1] * 100 << endl;

		hx.close();
		hxX.close();
		hy.close();
		hyY.close();
	}

	else { //if (nf != {1, 2}).
		cout << "Vveden nepravilnyj 'pyskovoj' parametr!!";
	}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!hmin = min(hx0, hy0)
	MN = max(Nxp, Nyp);

	Xmin = XVV[1] * dL * 1000;
	Xmax = XVV[Nxp] * dL * 1000;
	Ymin = YVV[1] * dL * 1000;
	Ymax = YVV[Nyp] * dL * 1000;

//	cout.precision(3);
	cout.precision(3);
	HeadFiles = to_string(Nxp) + " " + to_string(Nyp) + "\n";
	HeadFiles += to_string(Xmin) + " " + to_string(Xmax) + "\n";
	HeadFiles += to_string(Ymin) + " " + to_string(Ymax) + "\n";

	
	cout << endl;
	cout << "    N-K:  N   Np" << endl;
	cout << "X: " << IndexXN << '-' << IndexXK << ":";
	cout << Nx << "  " << Nxp << endl;
	cout << "Y: " << IndexYN/10 << IndexYN%10 << '-' << IndexYK << ":";
	cout << Ny << "  " << Nyp << endl;
	cout << "Nyp0 = " << Nyp0 << endl;
	cout << endl;
	
	int intYmin = abs(int(Ymin));
	cout << "(mm)\tmin\t  N\t  K\t max" << endl;
	cout<<fixed<<"X:   "<<Xmin<<"\t"<<xN*100<<"\t"<<xK*100<<"\t"<<Xmax<< endl;
	cout<<fixed<<"Y:   "<<"-"<<intYmin/100<<intYmin/10<<abs(Ymin-intYmin)<<
		"\t"<<yN*100<<"\t"<<yK*100<<"\t"<<Ymax<< "\n\n";

} //END  M3_0_Grid()




//#pragma once
void A3_1_GridX() {
//cout << "M2_Grid" << endl;
int x, Ng;
double xxx, hx0, qm;
double GRight3;
double HGXY[MX], XYVVG[MX];

//!���������� ���������� * ********************************************

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
hx0 = h0;          //!��� ����� � �������� �������.
xxx = xK - xN;  //!������ ��������� � �������� �������.
Nx = int((xxx + 0.1*h0) / h0) + 1;  //!��� - �� � - ����� � �������� �������.

Ng = 1;
HGXY[Ng] = hx0;
XYVVG[Ng] = 0.0;

//������.���������.�������� ��� ����� �����. �� X=0; �� ��.���.���.(�� ������� ���.����).
while(XYVVG[Ng] > xN) {
	Ng++;
	HGXY[Ng] = hx0;
	XYVVG[Ng] = XYVVG[Ng-1] - hx0;
}
IndexXN = Ng;

//������.���������.�������� ��� ����� �����..
while(XYVVG[Ng] > -Gxy3) {
	if(XYVVG[Ng] > xN-Gxy1) { //�� ������ �������������� ����.
		qm = qm1;
	}
	else if(XYVVG[Ng] > xN-Gxy1-Gxy2) { //�� ������ �������������� ����.
		qm = qm2;
	}
	else { //(XYVVG[Ng] > -Gxy3) �� ������� �������������� ����. �� ������ ����.
		qm = qm3;
	}
	Ng++;
	HGXY[Ng] = HGXY[Ng-1] * qm;
	XYVVG[Ng] = XYVVG[Ng-1] - HGXY[Ng];
}
IndexXN = Ng - IndexXN;


///����������� � ���������(����������) ��������������� �������� "�������" �����.
for(x=1; x<=Ng; x++) {
	HX[x] = HGXY[Ng-x+1];
	XVV[x] = XYVVG[Ng-x+1];
//	cout << i << "\t" << XVV[i] * 100 << "\t" << HX[i] * 100 << endl;
}
x--;

//���������� "�������" ����� ������ �� �=0; ��  ��.���.���.(�� ������� ���.����).
while(XVV[x] < xK) {
	x++;
	HX[x] = hx0;
	XVV[x] = XVV[x-1] + HX[x];
//	cout << i << "\t" << XVV[i] * 100 << "\t" << HX[i] * 100 << endl;
}

Ng = x;
IndexXK = x-1;

//cout << "�����.,�� ���.�����.��: " << TIME_MAX * 420 << endl;
GRight3 = TIME_MAX * tpaz * 420 / 1000 / 100;
cout << "Rasst.,na kot.raspr.: SW=" << GRight3*100 << ";  ";
cout << "Gxy3=" << Gxy3*100 << " mm." << endl;
cout << "TIME_MAX: " << TIME_MAX * tpaz << endl;
//GRight3 = Gxy3;

//���������� "�������" ����� ������..
while(XVV[x] < GRight3) {
	if(XVV[x] < xK+Gxy1) { //�� ������ �������������� ����.
		qm = qm1;
	}
	else if(XVV[x] < xK+Gxy1+Gxy2) { //�� ������ �������������� ����.
		qm = qm2;
	}
	else { //(XVV[i] < Gxy3). //�� ������� �������������� ����. �� ������ ����.
		qm = qm3;
	}
	x++;
	HX[x] = HX[x-1] * qm;
	XVV[x] = XVV[x-1] + HX[x];
}

Nxp = x;  //!������(P) ���������� � - �����.

for(x=Ng; x<=Nxp; x++) {HX[x] = HX[x+1];}
HX[Nxp]   = HX[Nxp-1]*qm3;
HX[Nxp+1] = HX[Nxp]*qm3;

//for (x = 0; x <= Nxp; x++) {
//	cout << XVV[i] * 100 << endl;
//}

} //END SUBROUTINE S2_GridX





//#pragma once
void A3_2_GridY() {
	//cout << "M2_Grid" << endl;
	int y, Ng;
	double yyy, hy0, qm;
	double HGXY[MX], XYVVG[MX];

	//YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
	//!���������� ������ ������� ���ר���� �������.
	if(BoundCondLower == 2) {  //!!!������ �������!!!!!���������!!!!!!!!!!!!!!!!!!!
		yN = 0;
		Nyp0 = 3;
	}

	yyy = yK - yN;            //!������ ��������� � �������� �������.
	Ny = (yK + 0.1 * h0) / h0;  //!���������� Y - ����� � ������� ����� ���.�������.
	hy0 = h0;                 //!��� ����� �� Y.

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//��� ���ר�� ��� ���������**************************************************
	if(BoundCondLower == 1) { //Nd
		Ng = 1;
		HGXY[Ng] = hy0;
		XYVVG[Ng] = 0.0;

		//������.���������.�������� ��� ����� ����. �� Y=0; �� ��.���.���.(�� ������� ���.����).
		while(XYVVG[Ng] > yN) {
			Ng++;
			HGXY[Ng] = hy0;
			XYVVG[Ng] = XYVVG[Ng-1] - hy0;
			//		cout << XYVVG[Ng]*100 << endl;
		}
		IndexYN = Ng;

		//������.���������.�������� ��� ����� ����.
		while(XYVVG[Ng] > -Gxy3) {

			if(XYVVG[Ng] > yN-Gxy1) { //�� ������ �������������� ����.
				qm = qm1;
			}
			else if(XYVVG[Ng] > yN-Gxy1-Gxy2) { //�� ������ �������������� ����.
				qm = qm2;
			}
			else { //(XYVVG[Ng] > -Gxy3). �� ������� �������������� ����. �� ������ ����.
				qm = qm3;
			}

			Ng++;
			HGXY[Ng] = HGXY[Ng-1] * qm;
			XYVVG[Ng] = XYVVG[Ng-1] - HGXY[Ng];
			//		cout << XYVVG[Ng] * 100 << endl;
		}

		IndexYN = Ng - IndexYN;

		///����������� � ���������(����������) ��������������� �������� "�������" �����.
		for(y=1; y<=Ng; y++) {
			HY[y] = HGXY[Ng-y+1];
			YVV[y] = XYVVG[Ng-y+1];
			//	cout << i << "\t" << XVV[i] * 100 << "\t" << HX[i] * 100 << endl;
		}
		y--;

		//////****************************************
		Nyp0 = 1;
		//////****************************************
	}


	if(BoundCondLower == 2) { //Nd
		HY[1] = HY[2] = HY[3] = hy0;
		YVV[1] = -2 * hy0;
		YVV[2] = -hy0;
		YVV[3] = 0.0;
		y = 3;
	}


	//���������� "�������" ����� ����� �� Y=0; ��  ��.���.���.(�� ������� ���.����).
	while(YVV[y] < yK) {
		y++;
		HY[y] = hy0;
		YVV[y] = YVV[y-1] + HY[y];
		//	cout << YVV[i] * 100 << endl;
	}
	IndexYK = y - 1;

	//Ng = i;


	//���������� "�������" ����� �����.
	while(YVV[y] < Gxy3) {
		if(YVV[y] < yK+Gxy1) { //�� ������ �������������� ����.
			qm = qm1;
		}
		else if(YVV[y] < yK+Gxy1+Gxy2) { //�� ������ �������������� ����.
			qm = qm2;
		}
		else { //(YVV[i] < Gxy3). �� ������� �������������� ����.
			qm = qm3;
		}
		y++;
		HY[y] = HY[y-1] * qm;
		YVV[y] = YVV[y-1] + HY[y];
		//	cout << YVV[i] * 100 << endl;
	}


	//Nyp0 = i;
	Nyp = y;  //!������(P) ���������� Y - �����.

	for(y=Ng; y<=Nyp; y++) { HY[y] = HY[y+1]; }

	HY[Nyp] = HY[Nyp-1] * qm3;
	HY[Nyp+1] = HY[Nyp] * qm3;

} //END SUBROUTINE S2_GridY

