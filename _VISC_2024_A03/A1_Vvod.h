#pragma once

void next(ifstream& vvod) {
	vvod.clear(); vvod.ignore(INT_MAX, '\n');
}

void A1_Vvod() {
//	HX[5] = 2.5;
ifstream vvod("__Vvod_Cpp.dat");
/*if (!vvod) {
	cout << "No file"; return -1;
}*/
vvod >> TypeTau; next(vvod);	
	//��� ���������� �� ������� (p-������������������, 1-�����, 2,3,4,5 �����-����).
vvod >> Akur; next(vvod);  	    //(0.9)- ������.
vvod >> h0; next(vvod);			//��� �����, �� (0.25).

vvod >> xN >> xK; next(vvod);	//���.� ����.��.���.�������, �� (-7.0 4.0).
vvod >> yN >> yK; next(vvod);	//���.� ����.��.���.�������, �� (-7.0 7.0).
vvod >> dd; next(vvod);			//������� ������ �� ��������, �� (3.0).
vvod >> x3 >> dSW; next(vvod);			//��������� ������� �����, �� (-6.0).

vvod >> sd; next(vvod);			//�����.�-��.�������� (������������).
vvod >> KONF; next(vvod);		//��� ������������ - 1-(1�) 2-(2�) 3-(3�) 4-(1�-UP) 5-(2�-UP).
vvod >> X3C; next(vvod);		//������ �������� �� ������� ����� ������ (�������������).
vvod >> am10p; next(vvod);		//�������.��.���� ����� � �� ������  (0 1).
vvod >> alfa101 >> alfa102 >> alfa103; next(vvod);
	
vvod >> Gxy1 >> Gxy2 >> Gxy3; next(vvod);	//������ ���.����, �� (5 10 200).
vvod >> qm1 >> qm2 >> qm3; next(vvod);		//(1.05 1.1 1.2) - ����������� ��� ����.
vvod >> BoundCondLeft >> BoundCondRight; next(vvod);				//(1 1) - ���.�� ��.�� �(���., ��)(1 - ����., 0 - ��.������).
vvod >> BoundCondLower; next(vvod);						//(2)- ������� �� ������ �������        1 - ��. 2 - �������.���.

vvod >> DtRestart; next(vvod);          //(10) - ������� ������� ��� Restart(���).
vvod >> DtConsol; next(vvod);	        //(10) - ������� ��������� �� �������(������)(dt).
vvod >> DtWriteStep; next(vvod);	    //(10) - ������� ������ �����������(���)(dxp).
vvod >> DtEmptyString; next(vvod);	    //(100) - ������� ��������� ������.
vvod >> TimeDif; next(vvod);	        //(35) - ����� ������.������������ ������� � ��������.
vvod >> TIME_MAX; next(vvod);	        //(300) - ����� ��������� ��������.

vvod >> cmax; next(vvod);               //(1.2) - ����� ����(1.095).
vvod >> sig1 >> sig2; next(vvod);       //(3.01 5.05) - ����������� ������� �������.(3.66 4.94)(3.19 5.66).
vvod >> gam1 >> gam2; next(vvod);       //(1.4 1.09) - ���������� �������� �����.(1.667 1.667)(1.4 1.09).
vvod >> om1 >> om2; next(vvod);         //(29.04 146.07) - ����� ������� 1 - ��, 2 - �� ����(40 131.2)(29.04 146.07).
vvod >> d0 >> anu12; next(vvod);        //(0.097  0.786) - ��������, �����������.

vvod >> vis10 >> vis20; next(vvod);     //(18.26 14.75) - �������� 1, �������� 2.
vvod >> anu1 >> anu2; next(vvod);       //(0.786 0.8)   - ������� 1, ������� 2.
vvod >> visS >> visVol1 >> visVol2; next(vvod); //(0.0 0.0) - ������ (��������) �������� ������� � ������� �����.

vvod >> concmin; next(vvod);	        //(0.0001) - ���������� ������������.
vvod >> U_shift; next(vvod);            //(1.788391) - �������� ������[� / �].


cout << "TypeTau = " << TypeTau << endl;
cout << "Akur = " << Akur << endl;
cout << "h0 = " << h0 << " mm." << endl;
cout << "xSW = " << x3 << " mm." << endl;

}


