#include <iostream>
#include <list>
using namespace std;
class Polaczenie;
class Wydruk{
  public:
        static void drukujPolaczenie(Polaczenie p);
};
class Polaczenie{
private:
	time_t czasOdjazdu;
	time_t czasPrzyjazdu;
	string miejscePrzyjazdu;
	string miejsceOdjazdu;
public:
	Polaczenie(time_t cO,time_t cP, string mP, string mO)
        {
            this->czasOdjazdu=cO;
            this->czasPrzyjazdu=cP;
            this->miejscePrzyjazdu=mP;
            this->miejsceOdjazdu=mO;
        };
	string pobierzSzczegoly();
	void drukuj()
        {
          Wydruk::drukujPolaczenie();
        };
};
class MiejscePrzesiadki{
private:
	string miejscowosc;
	int peronPrzyjazdu;
	int peronOdjazdu;
public:
	MiejscePrzesiadki(string m,int pP,int pO)
        {
            this->miejscowosc=m;
            this->peronPrzyjazdu=pP;
            this->peronOdjazdu=pO;
        };
};
class PolaczeniePosrednie:public Polaczenie{
    private:
        MiejscePrzesiadki miejsceprzesiadki;
        time_t czasPrzesiadki;
    public:
        PolaczeniePosrednie(time_t cO,time_t cP,string mP,string mO,MiejscePrzesiadki miejsce,time_t czasP);
        string pobierzSzczegoly();
        void drukuj();
};
class PolaczenieBezposrednie:public Polaczenie{
    private:
        float dlugoscTrasy;
        float prowizorycznaCenaBiletu;
    public:
        PolaczenieBezposrednie(time_t cO,time_t cP,string mP,string mO,float dT,float pCB):dlugoscTrasy(dT),prowizorycznaCenaBiletu(pCB),Polaczenie(cO,cP,mP,mO)
            {
            }
        string pobierzSzczegoly;
        void drukuj();
};
class IPolaczenie{
    public:
       virtual string pobierzSzczegoly()=0;
       virtual void drukuj()=0;
};
class Wyszukiwanie{
    private:
        string przystanekPoczatkowy;
        string przystanekKoncowy;
        time_t data;
        int liczbaPrzesiadek;
    public:
        Wyszukiwanie(string pP,string pK,time_t d,int lP);
        list <IPolaczenie> szukajPolaczenia();
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
