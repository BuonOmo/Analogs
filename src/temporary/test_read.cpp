using namespace std;
#include <iostream>
#include <string>
#include <fstream>


bool hasNextLog ( )
{
#ifdef MAP
    cout << "Appel à la methode Read::hasNextLog" << endl;
#endif

	if ( !file.eof() )
	{
		char c;
		file.get(c);
		if ( (int)c == 1 && file.eof() )
		{
			file.unget();
#ifdef MAP
	cout << "Read::hasNextLog = true" << endl;
#endif
			return true;
		}
	}
#ifdef MAP
	cout << "Read::hasNextLog = false" << endl;
#endif
	return false;
} //----- Fin de hasNextLog

Log readNextLog ( )
{
#ifdef MAP
    cout << "Appel à la methode Read::readNextLog" << endl;
#endif
    string line;
    getline(file, line);
    //----- recherche de la racine
    string rootFinder ( "\"GET " );
    int rootBegin  ( line.find ( rootFinder ) + rootFinder.size ( ) );
    int rootEnd    ( line.find ( '"', rootBegin ) );
    int rootLength ( rootEnd - rootBegin );
    string root ( line.substr ( rootBegin, rootLength ) );
    //----- recherche de la cible
    int targetBegin  ( line.find ( '"', rootEnd + 1 );
    int targetEnd    ( line.find ( '"', targetBegin + 1 ) );
    int targetLength ( targetEnd - targetBegin );
    string target ( line.substr ( targetBegin, targetEnd ) );
    //----- recherche de la date
    Date date;
    int dateBegin ( line.find ( '[' ) );
    line = line.substr ( dateBegin, line.find( ']') - dateBegin );
    line.replace ( line.find ( '/' ) , 1, 1, ' ' );
    line.replace ( line.find ( '/' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    ifstream streamDate ( line ); 
    streamDate >> date.year
    string month;
    streamDate >> month;
    switch (month)
    {
        case "Jan" : date.month ( 1 );
            break;
        case "Feb" : date.month ( 2 );
            break;
        case "Mar" : date.month ( 3 );
            break;
        case "Apr" : date.month ( 4 );
            break;
        case "May" : date.month ( 5 );
            break;
        case "Jun" : date.month ( 6 );
            break;
        case "Jul" : date.month ( 7 );
            break;
        case "Aug" : date.month ( 8 );
            break;
        case "Sep" : date.month ( 9 );
            break;
        case "Oct" : date.month ( 10 );
            break;
        case "Nov" : date.month ( 11 );
            break;
        case "Dec" : date.month ( 12 );
            break;
        default    : date.month ( -1 );
            break;
    }
    streamDate >> date.hour
    streamDate >> date.minute
    streamDate >> date.sec
    date.timeZone = 2 ; // ___________________________________________TODO

    return new Log(date, root, target);
} //----- Fin de readNextLog

int main(int argc, char* argv[])
{
        ifstream file ("/home/ulysse/Eclipse/TP3/anonyme.log"/*argv[1]*/, ios::in);  // on ouvre en lecture
 
        if (file)  // si l'ouverture a fonctionné
        {
                string toPrint[2];
                while (file)
                {
                    readNextLine(file);
                }
                file.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier "<< argv[1] << endl;
 
        return 0;
}