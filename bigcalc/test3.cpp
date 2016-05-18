#include "bigcalc.h"
#include <string>
#include <iostream>
using namespace std;
int main() {
//  string sp="563",sq="2357", sE="3", sP="1107300", si="10000";
//  string sp="36791",sq="64951", sE="16769023", sP="1234567890", si="1000000000";
  string sp = "104723", sq = "104729", sE = "16769023", sP = "1234567890", si = "10000000";
  BigUnsigned p, q, E, D, s, n, P, C, t, i, ie;
  p = stringToBigUnsigned(sp);
  q = stringToBigUnsigned(sq);
  n = p * q;
  s = (p-1) * (q-1);
  E = stringToBigUnsigned(sE);
  ie = stringToBigUnsigned(si);
  cout << "n="<<n << ",s="<< s <<", E="<<E << endl;
  P = stringToBigUnsigned(sP);
  C = modexp(P,E,n);  // P^E mod n
  cout << "P="<<P << ", C=" << C << endl;
// find D
  for(i=1; i<ie; i++) {
    t = i * s + 1;
    if((t%E)==0) {
	 D = t / E;
	 cout << "i="<<i <<", D="<<D << " : ";
      P = modexp(C,D,n);  // C^D mod n
      cout << "C="<<C << ", P=" << P << endl;
    }
  }
  return 0;
}
/*
n=1326991,s=1324072, E=3
P=1107300, C=875102
i=2, D=882715 : C=875102, P=1107300
i=5, D=2206787 : C=875102, P=1107300
i=8, D=3530859 : C=875102, P=1107300
i=11, D=4854931 : C=875102, P=1107300
...
i=5042, D=2225323675 : C=875102, P=1107300
i=5045, D=2226647747 : C=875102, P=1107300
i=5048, D=2227971819 : C=875102, P=1107300
...
i=5108, D=2254453259 : C=875102, P=1107300
i=5111, D=2255777331 : C=875102, P=1107300
...
i=9992, D=4410042475 : C=875102, P=1107300
i=9995, D=4411366547 : C=875102, P=1107300
i=9998, D=4412690619 : C=875102, P=1107300
--------------
n=10967535067,s=10967325616, E=16769023
P=1234567890, C=8714468403
i=5730414, D=3747822175 : C=8714468403, P=1234567890
*/
