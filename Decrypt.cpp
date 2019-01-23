#include<bits/stdc++.h>
using namespace std ;

string mp[1000000];
int main() {
  freopen("out.txt","r",stdin) ;
  freopen("re.txt","w",stdout) ;
  int cases , caseno= 1 ;
  string s ;
  while( cin >> s ) {
    mp[0]="" ;
    int idx = 1 ;
    for( int i = 0 ; i < s.size() ;) {
      int num = 0 , k ;
      for( ; s[i] >= '0' && s[i] <= '9' ; i++ ) {
        num *=10 ;
        num += (s[i]-'0') ;
      }
      char ch = s[i++] ;
      if( ch == '#' ) {
        cout << mp[num] ;
      } else {
        cout << mp[num]+ch ;
        mp[idx++] = mp[num]+ch ;
      }
    }
    cout << "\n" ;
  }
  return 0 ;

}
