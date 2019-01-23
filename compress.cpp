/*

SLOW

*/

//
//#include<bits/stdc++.h>
//using namespace std ;
//
//int main() {
//
//  //string s = "BAABABBBAABBBBAA" ;
//  freopen("in1.txt","r",stdin) ;
//  freopen("out11.txt","w",stdout) ;
//  int cases ;
//  cin >> cases ;
//  while( cases -- ) {
//    string s ;
//    cin >> s ;
//    map<string,int>mp ;
//    mp[""]=0;
//    int idx = 1 ;
//    int itr = 0 ;
//    vector<pair<char,int>>Compress ;
//
//    while( itr < s.size() ) {
//      string tmp = "" ;
//      char ch ;
//      int i ;
//      for( i = itr ; i < s.size() ; i++ ) {
//        tmp+=s[i] ;
//        ch = s[i] ;
//        if( mp.find(tmp) == mp.end() ) {
//          itr = i+1 ;
//          break ;
//        }
//      }
//      if( i > itr )itr = i ;
//      if( mp.find(tmp) == mp.end() ) {
//        mp[tmp]=idx++ ;
//        tmp.pop_back();
//        Compress.push_back( {ch,mp[tmp]}) ;
//      } else {
//        Compress.push_back( {'#',mp[tmp]}) ;
//      }
//    }
//    for( int i =0 ; i < Compress.size() ; i++ ) {
//      cout << Compress[i].second << Compress[i].first ;
//    }cout << endl ;
//  }
//  return 0 ;
//}




/*

FAST

*/



#include<bits/stdc++.h>
using namespace std ;

struct Trie {
  int idx ;
  Trie * node[26] ;
  Trie() {
    idx = -1 ;
    for( int i = 0 ; i < 26 ; i++ ) {
      node[i] = NULL ;
    }
  }
}*root ;


void Insert( string str , int idx ) {
  Trie *curr = root ;
  int p = 0 ;
  for( int i = 0 ; str[i] ; i++ ) {
    int id = str[i] - 'A' ;
    if( curr->node[id] == NULL ) {
      curr->node[id] = new Trie() ;
    }
    curr= curr->node[id] ;
  }
  curr->idx = idx ;
  return ;
}


void del( Trie *cur ) {
  for( int i =0 ; i < 10 ; i++ ) {
    if( cur ->node[i] ) {
      del( cur->node[i] ) ;
      delete( cur->node[i] ) ;
    }
    cur->idx = -1 ;
  }
}

int main() {

  //string s = "BAABABBBAABBBBAA" ;
  freopen("in2.txt","r",stdin) ;
  freopen("out2.txt","w",stdout) ;
  int cases ;
  cin >> cases ;
  while( cases -- ) {

    root = new Trie() ;

    string s ;
    cin >> s ;
    map<string,int>mp ;
    mp[""]=0;
    int idx = 1;
    int itr = 0 ;
    vector<pair<char,int>>Compress ;

    while( itr < s.size() ) {
      Trie * curr = root ;
      string tmp = "" ;
      char ch ;
      int i ;
      int isDiff = 0 ;
      int lastidx = 0 ;
      for( i = itr ; i < s.size() ; i++ ) {
        ch = s[i] ;
        int id = s[i] - 'A' ;
        if( curr->node[id] == NULL ) {
          isDiff = 1 ;
          curr->node[id] = new Trie() ;
        }
        curr= curr->node[id] ;
        if( isDiff ) {
          i++;
          curr->idx = idx++ ;
          break ;
        }
        tmp+=s[i] ;
        lastidx = curr->idx ;
      }
      itr = i ;
      if( isDiff )
        Compress.push_back( {ch,lastidx}) ;
      else
        Compress.push_back( {'#',curr->idx } ) ;
    }
    for( int i =0 ; i < Compress.size() ; i++ ) {
      cout << Compress[i].second << Compress[i].first ;
    }
    cout << "\n" ;

    del( root ) ;
  }
  return 0 ;
}
