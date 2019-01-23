#include<bits/stdc++.h>
using namespace std ;

int main(){

  srand(time(NULL)) ;

  freopen("in2.txt","w",stdout) ;
  int cases=1000 , caseno = 1 ;
  cout << cases << endl ;
  for( int i = 0; i < cases  ; i++ ){
    string s = "" ;
    for( int i = 0; i < 1000000 ; ){
      int k = rand()%200 ;
      int l = rand()%26 ;
      for(int p=0 ; p < k && i < 1000000 ;p++, i++ ){
        s += l+'A' ;
      }
    }
    cout << s << endl;
  }
  return 0 ;
}
