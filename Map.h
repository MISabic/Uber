#ifndef MAP_H
#define MAP_H

#include<bits/stdc++.h>

using namespace std;

#define MAXX    1005

struct node {
    int x, cost;
    node() {}
    node( int a, int b ) {
        x = a;
        cost = b;
    }

    bool operator < (const node& n) const {
        return cost > n.cost;
    }
};

class Map {

private :
    string vertex[100];
    double cost[100][100];
    map<string, int> mp;
    vector< node > graph[MAXX];
    set< string > listOfDriverInNode[MAXX];
public :

    Map( );
    double GetCost( string , string  );
    void loadDist( );
    void PrintDist( );
    void AddDriver( );
    void DoMapping( );
    void AddDriverDefault( );
    void AddDriver( string, string );
    void SetLocation( string, string );
    int checkLocation(string);
    string GetLocation( string );
    void GetDrivers( string src, vector<string>& );

};

#endif // MAP_H

