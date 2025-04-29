#pragma once
//COMMON / GGG / 

double xN, xK;					//����� � ������ ������� �������� �������.
double yN, yK;					//������ � ������� ������� �������� �������.
double Xmin, Xmax, Ymin, Ymax;	//������� ���� �������.
//�� Xmax ������ ��� �������� �� ������� �������� � ����� ����.

double h0;						//��� �������� �����.
double x3;						//��������� ������� �����.
double dSW;                     //������ �������� ������� �����.

double Gxy1, Gxy2, Gxy3;	    //������ �������������� ��Ψ�.
double qm1, qm2, qm3;           //!������������ ��� ����� � �������������� ��������.

double dL;						//���������������� ���������.

int MN;				     //max(Nxp, Nyp).
int Nx, Ny;			     //���������� ����� �������� �����.
int Nxp, Nyp, Nyp0;		 //���������� ����� ���� �����.
int Nxl, Nxr, Nyn, Nyv;

int IndexXN, IndexXK, IndexYN, IndexYK; //��������, ����� ��� ��������!!

int BoundCondLeft;  //� �������� ��� ���� ���������� Nl.
int BoundCondRight; //� �������� ��� ���� ���������� Nr.
int BoundCondLower; //� �������� ��� ���� ���������� Nd.


string HeadFiles;


