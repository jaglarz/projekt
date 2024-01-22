#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>
#include <vector>



using namespace std;


void StronaStartowa() {
    cout << "************************************************************" << endl;
    cout << "*                  Sklep Wedkarski \"Barwena\"               *" << endl;
    cout << "*              Projekt obiektowej aplikacji C++            *" << endl;
    cout << "*       											        *" << endl;
    cout << "************************************************************" << endl;
    
	
	Sleep(2000);
    system("cls");
}

void wyswietl_kategorie(){
	cout<<"Wybierz kategorie produktu: "<<endl;
    cout<<"1. Wedki"<<endl;
    cout<<"2. Kolowrotki"<<endl;
    cout<<"3. Przynety"<<endl;
    cout<<"4. Splawiki"<<endl;
    cout<<"5. Zylki i plecionki"<<endl;
    cout<<"6. Akcesoria"<<endl<<"Wybor: "<<endl;
    
    
    
}



class Produkt{
public: 
    virtual void wyswietl()= 0;
	virtual double pobierzCene() const = 0;
};



class SklepWedkarski {
public:
	
	
	
    void pokaz(Produkt* produkt){
        produkt->wyswietl();
    }
    
};

class Wedka :public Produkt{
public:
    
    Wedka(string n, double c, string p): nazwa{n}, cena(c), parametr(p) {}
    Wedka() : nazwa("brak"), cena(0.0), parametr("brak") {}
    
    void wyswietl(){
        cout<<"Nazwa: "<<nazwa<<" Cena"<<cena<<" Dlugosc:"<<parametr<<" m"<<endl;
    }
    string nazwa;
    double cena;
    string parametr;
    
        void ustaw(string naz, double cen, string par)
    {
    	nazwa=naz;
    	cena=cen;
    	parametr=par;
	}
	
	 double pobierzCene() const override {
        return cena;
    }
};


//kolowrotek nie ma parametru

class Kolowrotek :public Produkt{
public:  

	string nazwa;
    double cena;
    string parametr;
  
    Kolowrotek(string n, double c, string p): nazwa(n), cena(c), parametr(p) {}
    Kolowrotek() : nazwa("brak"), cena(0.0), parametr("brak") {}
    void wyswietl(){
        cout<<"Nazwa: "<<nazwa<<" Cena: "<<cena<<" "<<endl;
    }
    
    
        void ustaw(string naz, double cen, string par)
    {
    	nazwa=naz;
    	cena=cen;
    	parametr=par;
	}
	
	 double pobierzCene() const override {
        return cena;
    }
};


// przyneta ma kolor

class Przyneta :public Produkt{
public: 
	
	string nazwa;
    double cena;
    string parametr;
    
   
    Przyneta(string n, double c, string p): nazwa(n), cena(c), parametr(p) {}
    Przyneta() : nazwa("brak"), cena(0.0), parametr("brak") {}
    void wyswietl(){
        cout<<"Nazwa: "<<nazwa<<" Cena: "<<cena<<" Kolor: "<<parametr<<endl;
    }
    
        void ustaw(string naz, double cen, string par)
    {
    	nazwa=naz;
    	cena=cen;
    	parametr=par;
	}
	
	 double pobierzCene() const override {
        return cena;
    }
};

//parametr w splawiku to rodzaj

class Splawik :public Produkt{
public:   

	string nazwa;
    double cena;
    string parametr;
	 
    Splawik(string n, double c, string p): nazwa(n), cena(c), parametr(p) {}
    Splawik() : nazwa("brak"), cena(0.0), parametr("brak") {}
    void wyswietl(){
        cout<<"Nazwa: "<<nazwa<<" Cena: "<<cena<<" Rodzaj: "<<parametr<<endl;
    }
   
    
        void ustaw(string naz, double cen, string par)
    {
    	nazwa=naz;
    	cena=cen;
    	parametr=par;
	}
	
	 double pobierzCene() const override {
        return cena;
    }
};


//parametr w splawiku to grubosc 
class Zylka :public Produkt{
public:    

	string nazwa;
    double cena;
    string parametr;

    Zylka(string n, double c, string p): nazwa(n), cena(c), parametr(p) {}
    Zylka() : nazwa("brak"), cena(0.0), parametr("brak") {}
    void wyswietl(){
        cout<<"Nazwa: "<<nazwa<<" Cena: "<<cena<<" Grubosc: "<<parametr<<" mm"<<endl;
    }
    
        void ustaw(string naz, double cen, string par)
    {
    	nazwa=naz;
    	cena=cen;
    	parametr=par;
	}
    
     double pobierzCene() const override {
        return cena;
    }
};


//akcesoria bez parametru
class Akcesoria :public Produkt{
public:   
	string nazwa;
    double cena;
    string parametr;


 
    Akcesoria(string n, double c, string p): nazwa(n), cena(c), parametr(p) {}
    Akcesoria() : nazwa("brak"), cena(0.0), parametr("brak") {}
    
    void wyswietl(){
        cout<<"Nazwa: "<<nazwa<<" Cena: "<<cena<<" "<<endl;
    }
    
    void ustaw(string naz, double cen, string par)
    {
    	nazwa=naz;
    	cena=cen;
    	parametr=par;
	}
	 double pobierzCene() const override {
        return cena;
    }
    
};



class Kup {
private:
    class Koszyk {
    public:
        vector<Produkt*> produkty;

        void dodajProdukt(Produkt* produkt) {
            produkty.push_back(produkt);
        }

        void wyczyscKoszyk() {
            produkty.clear();
        }
    };

    Koszyk koszyk;

    double koszykowyKoszt() const {
        double koszt = 0.0;
        for (Produkt* produkt : koszyk.produkty) {
            koszt += produkt->pobierzCene();
        }
        return koszt;
    }

    string czasAktualny() const {
        time_t teraz = time(0);
        tm* czasTeraz = localtime(&teraz);
        char czasChar[80];
        strftime(czasChar, 80, "%Y-%m-%d %H:%M:%S", czasTeraz);
        return czasChar;
    }

public:
	
	
    void dodajProduktDoKoszyka(Produkt* produkt) {
        koszyk.dodajProdukt(produkt);
    }
    
    void wypiszKoszyk()
    {
    	cout<<"Wartosc koszyka: "<<koszykowyKoszt()<<" zl.0" <<endl;
	}

    void dokonajZakupu() {
        ofstream raport("raport.txt", ios::app);

        

        raport << "Data zakupu: " << czasAktualny() << endl;
    
        raport << "Koszt całkowity zakupow: " << koszykowyKoszt() << " PLN" << endl;
        raport << "---------------------------------------------" << endl;

		
		
		cout<<"Kupione produkty: "<<endl;
		for (Produkt* produkt : koszyk.produkty) {
            produkt->wyswietl();
            cout<< endl;
        }
        
        
		cout<<endl<<endl<<"Za zakupy zaplacisz: "<<koszykowyKoszt()<<endl;
		
        raport.close();
        koszyk.wyczyscKoszyk();
    }
};


int main() {
	
	StronaStartowa();
	
    SklepWedkarski sklep;
    Kup kupowanie;
    
    Wedka wedki[5]; int wedkii=0;
    Kolowrotek kolowrotki[5]; int kolowrotkii=0;
   	Przyneta przynety[7]; int przynetyi=0;
    Splawik splawiki[6]; int splawikii=0;
    Zylka zylki[6]; int zylkii=0;
	Akcesoria akcesor[9]; int akcesori=0;
	
	
	
	
	
	string n, p;
	int c,kategoria;
	
	
	ifstream plik_wejsciowy("produkty.txt");
	
    while (plik_wejsciowy >> n >> c >> p >> kategoria)
	 {
	 	
	 	//cout<<n<<" "<<c<<" "<<p<<" "<<kategoria<<endl;
	 	
        switch (kategoria) {
    case 1:
        wedki[wedkii].ustaw(n, c, p);
        wedkii++;
        break;

    case 2:
        kolowrotki[kolowrotkii].ustaw(n, c, p);
        kolowrotkii++;
        break;

    case 3:
        przynety[przynetyi].ustaw(n, c, p);
        przynetyi++;
        break;

    case 4:
        splawiki[splawikii].ustaw(n, c, p);
        splawikii++;
        break;

    case 5:
        zylki[zylkii].ustaw(n, c, p);
        zylkii++;
        break;

    case 6:
        akcesor[akcesori].ustaw(n, c, p);
        akcesori++;
        break;

    default:
        // Obsługa sytuacji, gdy kategoria jest nieznana
        break;
}
        
	}



    int koniec_zakupow=0;
    
    while(!koniec_zakupow)
    {
	
    wyswietl_kategorie();
    
    cin>>kategoria;
    
    system("cls");
    
    
    if (kategoria == 1) {
            
            for(int i=0;i<=(wedkii-1);i++)
            {
            	cout<<" "<< i<<".  ";
            	wedki[i].wyswietl();
			}
			
			int wybieranie=-1;
			cout<<"Ktory prokdukt dodac do koszyka: "<<endl;
			cin>>wybieranie;
			kupowanie.dodajProduktDoKoszyka(&wedki[wybieranie]);
            
        } else if (kategoria == 2) {
            
            for(int i=0;i<=(kolowrotkii-1);i++)
            {
            	cout<<" " <<i<<".  ";
            	kolowrotki[i].wyswietl();

			}
			
			int wybieranie=-1;
			cout<<"Ktory prokdukt dodac do koszyka: "<<endl;
			cin>>wybieranie;
			kupowanie.dodajProduktDoKoszyka(&kolowrotki[wybieranie]);
            
        } else if (kategoria == 3) {
            
        for(int i=0;i<=(przynetyi-1);i++)
            {
            	cout<<" "<< i<<".  ";
            	przynety[i].wyswietl();
			}  
			
			int wybieranie=-1;
			cout<<"Ktory prokdukt dodac do koszyka: "<<endl;
			cin>>wybieranie;
			kupowanie.dodajProduktDoKoszyka(&przynety[wybieranie]);  
            
        } else if (kategoria == 4) {
          
            for(int i=0;i<=(splawikii-1);i++)
            {
            	cout<<" "<< i<<".  ";
            	splawiki[i].wyswietl();
			}
			
			int wybieranie=-1;
			cout<<"Ktory prokdukt dodac do koszyka: "<<endl;
			cin>>wybieranie;
			kupowanie.dodajProduktDoKoszyka(&splawiki[wybieranie]);
            
        } else if (kategoria == 5) {
            
          for(int i=0;i<=(zylkii-1);i++)
            {
            	cout<<" "<< i<<".  ";
            	zylki[i].wyswietl();
			}  
			
			int wybieranie=-1;
			cout<<"Ktory prokdukt dodac do koszyka: "<<endl;
			cin>>wybieranie;
			kupowanie.dodajProduktDoKoszyka(&zylki[wybieranie]);
            
        } else if (kategoria == 6) {
            
            for(int i=0;i<=(akcesori-1);i++)
            {
            	cout<<" "<< i<<".  ";
            	akcesor[i].wyswietl();
			}
			
			int wybieranie=-1;
			cout<<"Ktory prokdukt dodac do koszyka: "<<endl;
			cin>>wybieranie;
			kupowanie.dodajProduktDoKoszyka(&akcesor[wybieranie]);
        }

	kupowanie.wypiszKoszyk();
    cout<<"Jesli chcesz zakonczyc zakupy wybierz 1, aby kontynuowac wybierz 0"<<endl;
    cin>>koniec_zakupow;
    
    system("cls");
    
    
}
	
	kupowanie.dokonajZakupu();
	
	

    
    
    plik_wejsciowy.close();
    
    
    
    return 0;
}