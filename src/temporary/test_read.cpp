using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

typedef struct Date
{
    int hour;
    int minute;
    int second;
    int timeZone;
    int day;
    string month;
    int year;
} Date;


bool hasNextLog (ifstream & file)
{
#ifdef MAP
    cout << "Appel à la methode Read::hasNextLog" << endl;
#endif

	if ( !file.eof() && file.peek() != char_traits<wchar_t>::eof() )
	{
#ifdef MAP
	cout << "Read::hasNextLog = true" << endl;
#endif
		return true;
	}
#ifdef MAP
	cout << "Read::hasNextLog = false" << endl;
#endif
	return false;
} //----- Fin de hasNextLog

void readNextLog (ifstream & file)
{
#ifdef MAP
    cout << "Appel à la methode Read::readNextLog" << endl;
#endif
    string line;
    getline(file, line);
    //----- recherche de la racine
    string rootFinder ( "\"GET " );
    int rootBegin  ( line.find ( rootFinder ) + rootFinder.size ( ) );
    int rootEnd    ( line.find ( " HTTP", rootBegin ) );
    int rootLength ( rootEnd - rootBegin );
    string root ( line.substr ( rootBegin, rootLength ) );
    //----- recherche de la cible
    int targetBegin  ( line.find ( '"', rootEnd + 15) + 1 );
    int targetEnd    ( line.find ( "\" \"", targetBegin) );
    int targetLength ( targetEnd - targetBegin );
    string target ( line.substr ( targetBegin, targetLength ) );
    //----- recherche de la date
    Date date;
    int dateBegin ( line.find ( '[' ) + 1);
    line = line.substr ( dateBegin, line.find( ']') - dateBegin );
    line.replace ( line.find ( '/' ) , 1, 1, ' ' );
    line.replace ( line.find ( '/' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    istringstream streamDate ( line ); 
    streamDate >> date.day;
    streamDate >> date.month;
    streamDate >> date.year;
    streamDate >> date.hour;
    streamDate >> date.minute;
    streamDate >> date.second;
    if (streamDate.get() == 32) // 32 correspond à +
    {
        streamDate >> date.timeZone;
    }
    else
    {
        streamDate >> date.timeZone;
        date.timeZone = - date.timeZone;
    }
    date.timeZone /= 100;
    cout << "( " << root << " ; " << target << " ; ";
    cout << date.day << " ; ";
    cout << date.month << " ; ";
    cout << date.year << " ; ";
    cout << date.hour << " ; ";
    cout << date.minute << " ; ";
    cout << date.second << " ; ";
    cout <<  (( date.timeZone >= 0 ) ? '+' : '-' );
    cout << date.timeZone << " )" << endl;

} //----- Fin de readNextLog

int main(int argc, char* argv[])
{
        ifstream file ("/home/ulysse/Eclipse/TP3/anonyme.log"/*argv[1]*/, ios::in);  // on ouvre en lecture
        
        if (file)  // si l'ouverture a fonctionné
        {
                string toPrint[2];
                while (hasNextLog(file))
                {
                    readNextLog(file);
                }
                file.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier "<< argv[1] << endl;
 
        return 0;
}