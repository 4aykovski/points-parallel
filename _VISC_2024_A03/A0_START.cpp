#pragma once

#include "FilesExtern.h"

#include "Common_AAA.h"
#include "Common_CCC.h"
#include "Common_DDD.h"
#include "Common_GGG.h"
#include "Common_TTT.h"
#include "Common_VVV.h"

//#include "Timer.h"
#include "FilesCreate.h"

#include "A1_Vvod.h"
#include "A2_Param.h"
#include "A3_0_Grid.h"
#include "A4_Diff_T0.h"
#include "A5_InitalCond.h"
#include "A6_0_WriteData0.h"
#include "A7_0_Evolution.h"

int main() {

	cout << "vvod from files: ";  //<< endl;
	cin >> nf;
	
	//cout << "RO1=" << RO1<<endl;
	A1_Vvod();
	A2_Param();
	
	A3_0_Grid();
	A4_Diff_T0();
	//M4_Param();
	A5_InitalCond();
	A6_0_WriteData0();

//	Timer t;
	A7_0_Evolution();

	cout << endl;
	return 0;
}




//////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

/*	cout << endl;
	cout << sd << " -- sd" << endl;	   //!�����.� - ��.��������(������������).
	cout << dd << " -- dd" << endl;	   //!������� ������(��.)..
	cout << sigma << " -- sigma" << endl;	   //!��������.
	cout << KONF << " -- KONF" << endl;     //!��� ������. - 1(1�), 2(2�), 3(3�), 4(1� - UP), 5(2� - UP).
	cout << X3C << " -- X3C" << endl;      //!������ �������� �� ������� ����� ������(1).
	cout << am10p << " -- am10p" << endl;    //!�������.��.���� ����� � �� ������(0 1).
	cout << alfa101 << ' ' << alfa102 << ' ' << alfa103 << " -- alfa101 alfa102 alfa103" << endl;
	//!�������.���.���� ����� � �� ������(0.0 0.0 0.0).

	cout << xN << ' ' << xK << " -- xN xK" << endl;	   //!�������.���.���.:���., ��., ����.
	cout << yN << ' ' << yK << " -- yN yK" << endl;	   //!�������.���.���. : ���., ��., ����.
	cout << x3 << " -- x3" << endl;	   //!�������.���.���. : ���., ��., ����.
	cout << h0 << " -- h0" << endl;	   //!��� �����, ��.

	cout << Nl1 << ' ' << Nl2 << ' ' << Nl3 << " -- Nl1 Nl2 Nl3" << endl;  //!��� - ��.���.���� �����.
	cout << Nr1 << ' ' << Nr2 << ' ' << Nr3 << " -- Nr1 Nr2 Nr3" << endl;  //!��� - ��.���.���� ������.
	cout << Nu1 << ' ' << Nu2 << ' ' << Nu3 << " -- Nu1 Nu2 Nu3" << endl;  //!��� - ��.���.���� ������.
	cout << qm1 << ' ' << qm2 << ' ' << qm3 << " -- qm1 qm2 qm3" << endl;  //!����������� ��� ����.
	cout << Nl << ' ' << Nr << " -- Nl Nr" << endl;	   //!���.�� ��.�� �(���., ��)(1 - ����., 0 - ��.������).
	cout << Nd << " -- Nd" << endl;		   //!������� �� ������ �������(1 - ��. 2 - �������.���.).

	//!*****************************************************************
	//!�������� � COMMON / TTT /
	cout << DtRestart << " -- DtRestart" << endl;      //!������� ������� ��� Restart(���).
	cout << DtConsol << " -- DtConsol" << endl;       //!������� ��������� �� �������(������)(dt).
	cout << DtWriteStep << " -- DtWriteStep" << endl;    //!������� ������ �����������(���)(dxp).
	cout << DtEmptyString << " -- DtEmptyString" << endl;  //!������� ��������� ������.
	cout << TimeDif << " -- TimeDif" << endl;	     //!����� ������.������������ ������� � ��������.
	cout << TIME_MAX << " -- TIME_MAX" << endl;	     //!����� ��������� ��������.

	//!*****************************************************************
	//!�������� � COMMON / CCC /

	cout << cmax << " -- cmax" << endl;	       //!����� ����(1.095).
	cout << sig1 << ' ' << sig2 << " -- sig1 sig2" << endl;	   //!��������.������� �������.(3.66 4.94)(3.19 5.66).
	cout << gam1 << ' ' << gam2 << " -- gam1 gam2" << endl;	   //!���������� �������� �����.(1.667 1.667)(1.4 1.09).
	cout << om1 << ' ' << om2 << " -- om1 om2" << endl;	   //!�����.�����.1 - 2 - ��.����.(40 131.2)(29.04 146.07).

	cout << d0 << ' ' << anu12 << " -- d0 anu12" << endl;	   //!��������, �����������.
	cout << vis10 << ' ' << anu1 << " -- vis10 anu1" << endl;   //!�������� 1, ������� 1.
	cout << vis20 << ' ' << anu2 << " -- vis10 anu1" << endl;   //!�������� 2, ������� 2.
	cout << Akur << " -- AKUR" << endl;		   //!������.
	cout << concmin << " -- concmin" << endl;	   //!���������� ������������.

	//!*******************************************************************************
	cout << U_shift << " -- U_shift" << endl;      //!�������� ������[� / �](-2.0).
	
*/
