#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <exception>
#include <clocale>
#include <regex>
#include <locale>
#include <codecvt>
#include <utility> // pair
#include <set>


using namespace std;

/*
bool priklausoSarasui(string& zod, map<string, pair <set<int>, int>>&sarasas ){
    
    auto iterator  = sarasas.begin();

    while(iterator != sarasas.end()){
        if (zod != iterator)
            return true;
        iterator++
    }
    return false;
}


bool zodzioKiekis(string& zod, map<string, pair <set<int>, int>>&sarasas, int k){

    map::iteratorerator iterator = sarasas.begin();

    while (iterator != sarasas.end()){
        if (zod == iterator) k++;
        iterator++;
    }
}*/


void skaitymas(map <string, pair <set<int>, int>>& sarasas, int &eilkiek){
   
    int nr = 0;
  //  eilkiek = 0;
    stringstream buffer;
    ifstream df ("tekstas.txt");
    buffer << df.rdbuf();
  //  string zod;
    string eil;
   // txt.append(".txt");
   // df.open(txt);

   try
        {
            if (!df.good())
                throw "Toks failas neegzistuoja.";
        }
        catch(const char *Message)
        {
            cout << Message << endl;
        }

    while(!df.eof()){
       eilkiek++;
       getline(df, eil, '\n');

       stringstream ss(eil); 
       string zod;
        nr++;
    while(ss >> zod){
        zod.erase(remove_if(zod.begin(), zod.end(), [](char character) {return !isalpha(character);}), zod.end());
                if(!zod.empty())
                {  transform(zod.begin(), zod.end(), zod.begin(), ::tolower);
                    sarasas[zod].first.insert(nr);
                    sarasas[zod].second++;
                }
    }
    eil.clear();
}
    
}


void isrinktiURL(string eil, vector<string>& URLS) {
	try {
	    regex reg("(((http|https)://)?www\\.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
	    sregex_iterator next(eil.begin(), eil.end(), reg);
		sregex_iterator end;
		while (next != end) {
		    smatch match = *next;
			if (match.str() != "")
				URLS.push_back(match.str());
			next++;
		}
	}
	catch   (regex_error & e) {
		cout << e.what() << endl;
	}
}

vector<string> rastiURLS() {

     ifstream df ("tekstas.txt");
//	txt.append(".txt");
   // df.open(txt);
	vector<string> URLS;
	string eil;
	for (int i = 0; !df.eof(); ++i) {
		getline (df, eil, '\n');
		isrinktiURL(eil, URLS);
	}
	return URLS;
}

void spausdinimas(map <string, pair <set<int>, int>> sarasas){
 //  ofstream rf ("Rezultatai.txt");
   ofstream rf ("test1.txt");

  //  cout << "Kuriamas rezultatu failas..." << endl; 

    for(const auto& zod : sarasas)
    {
        if (zod.second.second > 1)
        {
           // int i = 0;
            rf << "Zodis: " << zod.first << " | Kiekis: " << zod.second.second << "| Eilutes: ";
            
            for(auto eil : zod.second.first)
                rf << eil << " ";

            rf << endl;
            
        }
    }

      vector<string> URLS = rastiURLS();
      if (URLS.empty()){
         cout << "Tekste url adresu nera " << endl;
      }
      else {
         cout <<  "Tekste rasti URL adresai: " << endl;
         for (const auto& url : URLS)
            cout << url << endl;
      }

  //    cout << "Darbas baigtas" << endl;
      
 }

 void lentele(map<string, pair<set<int>, int>>sarasas, int &eilkiek){
     ofstream rf("Lentele.txt");

    rf << setw(18);
    for (int i = 0; i < eilkiek; i++){
        rf << i+1 << setw(3);
    }
    rf << endl;

     for (auto zod : sarasas){
         if (zod.second.second > 1){
             rf << zod.first;
             for (int i = 1; i <= eilkiek; i++){
                 for (auto eil : zod.second.first)
                     if (eil == i) rf << "+" << setw(3);
             }
             rf << endl;
         }
     }
 }

 int main(){
     int eilkiek;
     string eil;
     vector<string> URLS;
     map<string, pair<set<int>, int>>sarasas;

    isrinktiURL(eil, URLS);
    skaitymas(sarasas, eilkiek);
    spausdinimas(sarasas);
    lentele(sarasas, eilkiek);

 }
