// Pattern Classic Factory
#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Sport{   //<--- Общее обозначение всех элементов группы
    public:
    virtual void transfer() {};
    virtual ~Sport(){}
};


/*ФУТБОЛЬНЫЕ КЛУБЫ*/
class FC_Barselona:public Sport{//<--- Футбольный клуб "Барселона"
public:
    void transfer(){
        cout << "Barselona's tranfer\n";
    }
};
class FC_Spartak:public Sport{//<--- Футбольный клуб "Спартак"
public:
    void transfer(){
        cout << "Spartak's tranfer\n";
    }
};

/*БАСКЕТБОЛЬНЫЕ КЛУБЫ*/
class BC_Unics :public Sport {	//<--Баскетбольный клуб "Уникс"
public:
    void transfer(){
        cout << "Unics's tranfer\n";
    }
};
class BC_Fenix:public Sport {	//<--Баскетбольный клуб "Феникс"
public:
    void transfer(){
        cout << "Fenix's tranfer\n";
    }
};

///////////////////////////////////////////////////////////////

class ClubCreator{ //<--- Привет, я - царь; Обозначает создание клуба
public:
    virtual Sport* factoryMethod() = 0;
    virtual ~ClubCreator(){};
};

class FC_Barselona_Creator:public ClubCreator{  //<-- дитё царя
public:
    Sport* factoryMethod(){
           return new FC_Barselona; //<--  Выделяет память для объекта клуб "Барселона"
           }
};

class FC_Spartak_Creator:public ClubCreator{    //<-- дитё царя
    Sport* factoryMethod(){
           return new FC_Spartak;    //<-- Выделяет память для объекта клуб "Спартак"
           }
};

class BC_Unics_Creator:public ClubCreator{   //<-- дитё царя
     Sport* factoryMethod(){
            return new BC_Unics;
            }
};

class BC_Fenix_Creator:public ClubCreator{    //<-- дитё царя
    Sport* factoryMethod(){
            return new BC_Fenix;
            }
};


int main()
{
    FC_Barselona_Creator Barselona_Creator; /*Создаём базу спортивных клубов */
    FC_Spartak_Creator   Spartak_Creator;
    BC_Unics_Creator     Unix_Creator;
    BC_Fenix_Creator     Fenix_Creator;

    ClubCreator *FC_Barselona = &Barselona_Creator; // Создаём ссылки на футбольные клубы
    ClubCreator *FC_Spartak   = &Spartak_Creator;

    vector<Sport*> foot_clubs;  //Создаём массив футбольных клубов
    foot_clubs.emplace_back(FC_Barselona->factoryMethod()); //Заполняем массив футбольными клубами
    foot_clubs.emplace_back(FC_Spartak->factoryMethod());

    ClubCreator *BC_Unics = &Barselona_Creator; //Создаём ссылки на баскетбольные клубы
    ClubCreator *BC_Fenix = &Fenix_Creator;

    vector<Sport*> basket_clubs; //создаём массив баскетбольных клубов
    basket_clubs.emplace_back(BC_Unics->factoryMethod()); //Заполняем массив баскетбольных клубов
    basket_clubs.emplace_back(BC_Fenix->factoryMethod());

    //////////////////////////////////

     for (auto it=foot_clubs.begin(); it!=foot_clubs.end();it++) (*it)->transfer();
	 for (auto it=basket_clubs.begin(); it!=basket_clubs.end();it++) (*it)->transfer();

    //////////////////////////////////

    for (auto it=foot_clubs.begin(); it!=foot_clubs.end();it++) delete *it; //Чистим память обходом
    for (auto it=basket_clubs.begin(); it!=basket_clubs.end();it++) delete *it; //каждого массива



}