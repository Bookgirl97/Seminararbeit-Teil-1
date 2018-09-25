#include <iostream>
#include <fstream>
#include <string>

using namespace std;     

char eingabe;
string datei; 	
char zeichen; 
string h; 
string g;
fstream t;
fstream f;
fstream c; 
struct Buch
{
    string eins;
    string eeins;
    string eeeins;
    string zwei;
    string zzwei; 
    string zzzwei;
    string drei;
    string ddrei; 
    string dddrei;
    string vier;
    string vvier; 
    string vvvier;
};

// --  diese Funktion liest eine Person vom istream
istream& lese_ein( istream& in, Buch& p )
{
    getline( in, p.eins, ';');
    getline( in, p.eeins, ';');
    getline( in, p.eeeins, '\n');
    getline( in, p.zwei, ';');
    getline( in, p.zzwei, ';');
    getline( in, p.zzzwei, '\n');
    getline( in, p.drei, ';');
    getline( in, p.ddrei, ';');
    getline( in, p.dddrei, '\n');
    getline( in, p.vier, ';');
    getline( in, p.vvier, ';');
    getline( in, p.vvvier, '\n');
    return in;
}

void aufrufen()
{


t.open("daten.xml", ios::in);
while(!t.eof()){
	getline(t, h);
	cout << h << endl;
}
t.close();
cin.get();

t.open("Mappe1.csv", ios::in);
while(!t.eof()){
	getline(t, h);
	cout << h << endl;
}
t.close();
cin.get();
   
}


void konvertieren()
{
	cout << "Benenne die DTD-Datei( + .dtd) und ihren Pfad:  ";
	cin >> datei;
	ofstream gg(datei.c_str());
f.open("my.dtd", ios::in);
while(!f.eof()){
	getline(f, g);
	gg << g << endl;
}

f.close();
cin.get();

    gg << "<!ELEMENT buecher (Etage,Regalnummer,Exemplare)>" << endl; 
    gg << "     <!ELEMENT Etage (#PCDATA)> <!ATTLIST Etage xmlns CDATA #FIXED ''> " << endl;
	
    gg <<"	    <!ELEMENT Regalnummer (buch)+> <!ATTLIST Regalnummer xmlns CDATA #FIXED ''>" << endl; 

    gg << "     <!ELEMENT Exemplare (#PCDATA)> <!ATTLIST Exemplare xmlns CDATA #FIXED ''>" << endl; 
    gg.close();
	
	cout << "Benenne die XML-Datei( + .xml) und ihren Pfad:  ";
	cin >> datei;
	ofstream ff(datei.c_str());
		
t.open("daten.xml", ios::in);
while(!t.eof()){
	getline(t, h);
	ff << h << endl;
    ifstream csvread; 
	csvread.open("Mappe1.csv");
    if(!csvread.is_open()) 
        cerr << "Fehler beim Oeffnen der Datei!" << endl; 
    else { 
        for( Buch buch; lese_ein( csvread, buch ); ) { 
		if (h.find(" <buecher id='1'> ")!=string::npos) {
            ff << "<Etage>"<< buch.eins << "</Etage>"<< endl;
			ff << "<Regalnummer>"<< buch.eeins << "</Regalnummer>"<< endl;
		ff << "<Exemplare>" << buch.eeeins << "</Exemplare>" << endl;
			getchar();
			
       } 
	   
else if (h.find("2" )!=string::npos){
ff << "<Etage>"<< buch.zwei << "</Etage>"<< endl;
			ff << "<Regalnummer>"<< buch.zzwei << "</Regalnummer>"<< endl;
			ff << "<Exemplare>" << buch.zzzwei << "</Exemplare>" << endl;
			getchar();
	  } 
	  else if (h.find("3")!=string::npos){
ff << "<Etage>"<< buch.drei << "</Etage>"<< endl;
			ff << "<Regalnummer>"<< buch.ddrei << "</Regalnummer>"<< endl;
			ff << "<Exemplare>" << buch.dddrei << "</Exemplare>" << endl;
			getchar();
	  }
	 else if (h.find("4")!=string::npos){
ff << "<Etage>"<< buch.vier << "</Etage>"<< endl;
			ff << "<Regalnummer>"<< buch.vvier << "</Regalnummer>"<< endl;
			ff << "<Exemplare>" << buch.vvvier << "</Exemplare>" << endl;
			getchar();
	  }
	   } 
    } }
t.close();
cin.get();

    
}

int main(){

do{
    cout << "\n**Hauptmenue**" << endl;
	cout << "(A)ufrufen" << endl;
    cout << "(K)onvertieren" << endl;
    cout << "(B)eenden" << endl;
    cout << "Waehle aus:";
    cin >> eingabe;
    switch(eingabe){
       case ('A'): 
	   case ('a'):
	   cout << "Dateien: ";
	    aufrufen();
       break;
	   case ('K'): 
	   case ('k'): 
	   konvertieren();
       break;
       case ('B'): 
	   case ('b'): 
	   cout << "Die Schleife wurde beendet";
       break;
       default: cout << "Eingabe ungueltig";
	   break;
    }
} while (eingabe!= 'B' && eingabe!='b');

return 0;
}

