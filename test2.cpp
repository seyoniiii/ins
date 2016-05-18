#include "bigcalc.h"
#include <string>
#include <iostream>
using namespace std;
int main() {
  string sE="3", sD="882715", sP="1107300";
  BigUnsigned E=3,D,s,n=1326991,P,C;
//  E = stringToBigUnsigned(sE);
  D = stringToBigUnsigned(sD);
  P = stringToBigUnsigned(sP);
  C = modexp(P,E,n);  // P^E mod n
  cout << "C=" << C << endl;
  P = modexp(C,D,n);  // C^D mod n
  cout << "P=" << P << endl;
  return 0;
}
/*
P = 1107300	�� �޽���
   C = 11073003 mod 1326991 = 875102
3) A�� ��ȣ�� ��875102���� B�� �����Ѵ�.
4) B�� ���� ��ȣ�� ��875102���� ����Ű D(882715)�� ��ȣȭ �Ѵ�.
      P = 875102882715 mod 1326991 = 1107300
5) �� ��� (
B�� �� 1107300�� ����Ű�� ��ȣȭ�Ͽ� A�� ���� �� A�� ����Ű�� ��ȣ�� �� �ִ�.
C = 1107300882715 mod 1326991 = 780814
P = 7808143 mod 77 = 1107300
*/
