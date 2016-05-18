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
P = 1107300	평문 메시지
   C = 11073003 mod 1326991 = 875102
3) A는 암호문 ‘875102’를 B로 전송한다.
4) B는 받은 암호문 ‘875102’를 개인키 D(882715)로 복호화 한다.
      P = 875102882715 mod 1326991 = 1107300
5) 역 계산 (
B가 평문 1107300을 개인키로 암호화하여 A로 보낸 후 A가 공개키로 복호할 수 있다.
C = 1107300882715 mod 1326991 = 780814
P = 7808143 mod 77 = 1107300
*/
