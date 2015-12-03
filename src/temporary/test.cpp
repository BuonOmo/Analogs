#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;


void graphVizConvert(int * list [3], int length, string shape = "note", string style = "\"\"", string color = "lightblue"){

	ofstream file ("results/graph.dot", ios::out | ios::trunc);
	
	if(file){
		file << "digraph AnalysisResult {" << endl;
		file << "node [color="<<color<<", style="<<style<<", shape="<<shape<<"];" << endl;

		for (int i(0) ; i < length ; i++)
		{
			file << '"' <<(char)list[i][0] << '"' << " -> " << '"' << (char)list[i][1]<< '"';
			file << " [label="<<list[i][2]<<", color="<<color<<"];" << endl;
		}
		file << "}" << endl;
		file.close();
	}
	else
	{
		cerr << "Impossible de creer le fichier !" << endl;
	}
	system("dot -Tpng -o results/graph.png results/graph.dot ; eog results/graph.png");
}
int main ()
{
	int ** tab;
	tab = new int *[20];
	for (int j(0) ; j <20 ; j++)
	{
		tab[j] = new int [3];
		tab[j][0]= rand() % 8 + 65;
		tab[j][1]= rand() % 8 + 65;
		tab[j][2]= rand() % 4 + 1;		
	}
	graphVizConvert(tab, 20);
}