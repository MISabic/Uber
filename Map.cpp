#ifndef MAP_CPP
#define MAP_CPP

#include "Map.h"

#define INF     1<<28

Map::Map( ) {
    DoMapping( );
    loadDist ( );
    AddDriverDefault( );
}

/// This function will map the all location to a number
/// and will keep track of all the locations.

void Map::DoMapping( ) {

    /// Mapping All vertex to a number

    mp["Airport"] = 0,      mp["Badda"] = 1,            mp["Banani"] = 2;
    mp["Banglamotor"] = 3,  mp["Boshundhora"] = 4;
    mp["Dhanmondi"] = 5,    mp["Farmgate"] = 6,         mp["Gulistan"] = 7;
    mp["Gulshan"] = 8,      mp["Jatrabari"] = 9,        mp["Kuril"] = 10;
    mp["Malibagh"] = 11,    mp["Mirpur"] = 12,          mp["Mogbazar"] = 13;
    mp["Mohakhali"] = 14,   mp["Motijheel"] = 15,       mp["Newmarket"] = 16;
    mp["Notunbazar"] = 17,  mp["Rampura"] = 18,         mp["Shahbag"] = 19;
    mp["Shahjadpur"] = 20,  mp["Shantinagar"] = 21,     mp["Uttora"] = 22;

    /// Keeping track of vertex name and their index

    vertex[0] = "Airport",      vertex[1] = "Badda";
    vertex[2] = "Banani",       vertex[3] = "Banglamotor",      vertex[4] = "Boshundhora";
    vertex[5] = "Dhanmondi",    vertex[6] = "Farmgate",         vertex[7] = "Gulistan";
    vertex[8] = "Gulshan",      vertex[9] = "Jatrabari",        vertex[10] = "Kuril";
    vertex[11] = "Malibagh",    vertex[12] = "Mirpur",          vertex[13] = "Mogbazar";
    vertex[14] = "Mohakhali",   vertex[15] = "Motijheel",       vertex[16] = "Newmarket";
    vertex[17] = "Notunbazar",  vertex[18] = "Rampura",         vertex[19] = "Shahbag";
    vertex[20] = "Shahjadpur",  vertex[21] = "Shantinagar",     vertex[22] = "Uttora";
}

///  This function will build a graph from input data &
///  will calculate All pair shortest path using Floyed Warshal.

void Map::loadDist(  ) {

    ifstream inFile("Map.txt");

    double c;
    string src, dest;

    for( int i = 0; i < 23; i++ ) {
        for( int j = 0; j < 23; j++ ) {
            if( i == j )
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }

    /// Taking graph inputs.

    for( int i = 0; i < 27; i++ ) {
        inFile >> src >> dest >> c;

        //cout << src << " -- " << dest << " -- " << c << endl;

        graph[ mp[src] ].push_back( node( mp[dest], c ) );
        graph[ mp[dest] ].push_back( node( mp[src], c ) );
        cost[ mp[src] ][ mp[dest] ] = c;
        cost[ mp[dest] ][ mp[src] ] = c;
    }


    /// Running Floyed Warshal to calculate All pair shortest path.

    for( int k = 0; k < 23; k++ ) {
        for( int i = 0; i < 23; i++ ) {
            for( int j = 0; j < 23;  j++ ) {
                cost[i][j] = min( cost[i][k] + cost[k][j] , cost[i][j] );
            }
        }
    }



    inFile.close();
}

int Map::checkLocation(string location)
{
    for(int i=0; i<23; i++){
        if(vertex[i]==location)
            return 1;
    }
    return 0;
}

///  By default there will be some drivers in different locations
///  Here we are keeping track of their locations.

void Map::AddDriverDefault(  ) {

    ifstream inFile("Drivers.txt");

    string name, currLoc;

    while( inFile >> name >> currLoc ) {
        listOfDriverInNode[ mp[currLoc] ].insert( name );
    }

    inFile.close();
}

/// This function will return the distance from
/// a source to a destination.

double Map::GetCost( string src, string dest ) {
    return cost[ mp[src] ][ mp[dest] ];
}

/// This function will return a vector of the names of drivers
/// in the nearest point. To do this we used Djkastra's single
/// source shortest path Algorithm.

void Map::GetDrivers( string src, vector<string>& res) {

    int nCost[100];

    priority_queue<node> q;

    for( int i = 0; i < 25; i++ ) {
        nCost[ i ] = INF;
    }

    q.push( node( mp[src], 0 ) );
    nCost[ mp[src] ] = 0;
    node u;

    while( !q.empty() ) {

        u = q.top(); q.pop();

        if( listOfDriverInNode[ u.x ].size() != 0 ) {
            break;
        }

        int uCost = nCost[ u.x ];

        for( int i = 0; i < graph[ u.x ].size(); i++ ) {
            node v = graph[ u.x ][i];
            int vCost = u.cost + v.cost;

            if( vCost < nCost[ v.x ] ) {
                nCost[ v.x ] = vCost;
                q.push( v );
            }
        }
    }

    set<string> :: iterator it;

    for( it = listOfDriverInNode[ u.x ].begin(); it != listOfDriverInNode[ u.x ].end(); it++ ) {
        res.push_back( *(it) );
    }

}

/// This function will add new Drivers to there current location.

void Map::AddDriver( string name, string currLoc ) {
    listOfDriverInNode[ mp[currLoc] ].insert( name );
}

/// This function will reset the location of a existing driver.

void Map::SetLocation( string name, string currLoc ) {
    for( int i = 0; i < 23; i++ ) {
        if( listOfDriverInNode[i].count( name ) != 0 ) {
            listOfDriverInNode[i].erase( name );
        }
    }

    listOfDriverInNode[ mp[currLoc] ].insert( name );
}

/// Functions for debugging Starts here.

void Map::PrintDist( ) {
    for( int i = 0; i < 23; i++ ) {
        for( int j = 0; j < 23; j++ ) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

string Map::GetLocation( string name ) {

    for( int i = 0; i < 23; i++ ) {
        if( listOfDriverInNode[i].count( name ) != 0 ) {
            return vertex[i];
        }
    }

    return "NULL";
}

/// Functions for debugging Ends here.

#endif // MAP_CPP

