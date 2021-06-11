#define pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <regex>


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
}


void isrinktiURL(string eil, vector<string>& URLS) {
	try {
	    regex reg("((http|https):\\/\\/)?(www\\.)?(\\w+\\.(com|org|lt)){1}");
	    sregex_iteratorerator next(eil.begin(), eil.end(), reg);
	    sregex_iteratorerator end;
		while (next != end) {
		    smatch match = *next;
			if (match.str() != "")
				URLS.push_back(match.str());
			next++;
		}
	}
	catch   regex_error & e) {
		cout << e.what() << endl;
	}
}

vector<string> rastiURLS(string& txt) {

     ifstream df;
	txt.append(".txt");
    df.open(txt);
	vector<string> URLS;
	string eil;
	for (int i = 0; !df.eof(); ++i) {
		getline (failas, eil, '\n');
		IsrinktiURL(eil, URLS);
	}
	return URLS;
}


void skaitymas(string& eil, int nr, string& txt, Zodis& zodis){
    
    nr = 1;
    cout << "Iveskite tekstinio failo pavadinima\n";
    cin >> txt;

    stringstream buffer;
    ifstream df;
    buffer << df.rdbuf();
    string zod;
    string line;
    txt.append(".txt");
    df.open(txt);

    while(!df.eof()){
       stringstream df(line); 
       getline(df, eil, '\n');

    while(df >> zod){
        Zodis.setzodis(zod);
        if(!priklausoSarasui){
            eilnr.push_back(nr);
            sarasas.insert(zod, Zodis);
        }
        else {
            eilnr.push_back(nr);
            zodziokiekis(zod, sarasas, Zodis.getkiekis());
    }



}}}

void spausdinimas(){
   ofstream rf "Rezultatai.txt"





      vector<string> URL = RastiURLS(txt);
      if (URLS.empty()){
         cout << "Tekste url adresu nera " << endl;
      }
      else {
         for (const auto& url : URLS)
            cout << url << endl;
      }
      
      }