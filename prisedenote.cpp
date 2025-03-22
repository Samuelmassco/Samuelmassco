#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <numbers>
#include <cstdio>
#include <stack>
// ce file est une prise de note sur le  C++ 

int nb_aleatoire() {
    std::srand(std::time(0));  // Initialisation du générateur avec l'heure actuelle
    int random_number = std::rand() % 11;  // Nombre aléatoire entre 0 et 10
    std::cout << "Nombre aléatoire : " << random_number << std::endl;
    return random_number;
}


int array(){
    char hello[5]={'H','e','l','l','o'};// cree une sorte de liste de srting 
    int r[3]={4,2,3}; //liste de nombre cf int devant  
    std::cout <<"bjr ="<<hello[1]<<std::endl;//me sort le 3eme element de la liste
    std::cout <<"bjr ="<<hello<<std::endl;
    // les array sont initié a 0 !!
    
    return 0;//ma fonction est avec int donc elle doit retourné un entier (en general 0)
}


int pointers1(){

    int age=21;
    printf("adress of age %p\n", &age); //this is the adress
    printf("valuev %d\n", age);
    // we can store the value of the adress
    //* is the indiriction operatore 
    int *pAge=&age;//ceci est un pointer, il a son adresse a lui 
    //mais ça value est l'adresse de age 
    printf("value of pAge%p\n",pAge);
    printf("adress of pAge %p\n", &pAge);//l'adresse est differente de celle de age !!!!!
    // et donc on peut acceder a l'adresse dans la memoire 
    printf("value at adress (spoiler it s the same as age ) %d\n",*pAge);
    //on accesse la valeur a l'adresse on appelle cela deference !!!!
    return 0;
}

int exemple1ifelse(){
    //voici un exemple de comment structuré le if else dans un code 
    int a=3;
    int b=5;
    int *pA=&a;
    if (a==b){
        printf("a=b\n");
    }
    else{
        printf("a dif de b\n");
    }
    
    if (a==*pA)
    {
        printf("pointer okay\n");
    }
    else{
        printf("pointer not okay");
    }
    
    
    return 0;
}



int exemplewhile(){
    int a=3;
    int b=5;
    int *pA=&a;
    while (a<b)
    {
        a=a+1;
        printf(",%d",a);
    }
    printf("%d",a);
    return 0;
}




int exemplefor(){
    //structuer == for ( <initialization>; <condition>; <increment> )
    int a=0;
    int b=210;
    int *pA=&a;
    for (int i=1; i<=20; i++)
    {
        a=a+i;
        printf("sum from 0 %d\n",a);
    }
    
   
    printf("%d\n",a);
    if (pA==&a)
    {
        printf("pointer ok and stable even if the value affected to a has changed  ");
//we can see that actually the value change but the position in the memory doesnt ... interesting     
    }
    else{
        printf("pointer changed and problem  ");
    }
    
    return 0;
}

// si je decrlaire void la fonction ne retourne rien 
void boolean() {
    bool a=true;
    if (a==false)
    {
        printf("prob");
    }
    else{
        printf("yep\n");
    }
}





int exo0(){
    double pi=M_PI;
    int a=10;
    int b=pi+a;
    return 0;
}




//structure
int structure_data(){
//one data can be a groupe of data, struct is useful 
    struct meteo
    { // un element de type meteo a la localisation, l'heure , la temperature, la pression et si il pleut ou pas 
        std::string location;//
        int time;
        int temperature;
        double pressure;
        bool raining;
    };
    // ceci est un object de type meteo 
    meteo md;
    md.location="turin";
    md.time=1603;
    md.temperature=19;
    md.pressure=13.4;
    md.raining=true;

    printf("Location: %s\nTime: %d\nTemperature: %d\nPressure: %.2f\nRaining: %s\n", 
        md.location.c_str(), md.time, md.temperature, md.pressure, md.raining ? "Yes" : "No");
 ;


    return 0;
}


int f(int x){
    x=x+1;
    return x;
}

int calling_with_value(){//une 
    int y=5;
    int a=f(y);//une copie est crée y ne bouge pas mais le output si 
    printf("a=%d\n",a);
    printf("y=%d\n",y);// ne pas oublié le %d pour print in int
    return 0;
}    



struct meteo {
    std::string location;
    int time;
    int temperature;
    double pressure;
    bool raining;
};

// Fonction qui modifie la structure en la passant par référence
void update_meteo(meteo& md) {  
    md.temperature += 2;  // Augmente la température de 2 degrés
    md.pressure -= 0.5;   // Réduit la pression
    md.raining = !md.raining; // Inverse l'état de la pluie
}

// Fonction principale qui initialise un objet meteo et l'envoie à update_meteo
int calling__with__reference() {
    meteo md;
    md.location = "Turin";
    md.time = 1603;
    md.temperature = 19;
    md.pressure = 13.4;
    md.raining = true;


    update_meteo(md); // Passage par référence modifie la structure de base
    

    std::cout << "\nAprès modification:\n";
    std::cout << "Température: " << md.temperature << "\n";
    std::cout << "Pression: " << md.pressure << "\n";
    std::cout << "Pluie: " << (md.raining ? "Oui" : "Non") << "\n";

    return 0;
}


void add_five(int* num) {// part d'un pointeur qui pointe a value 
    if (num != nullptr) { // Vérifier que le pointeur n'est pas nul
        *num += 5;  // Ajoute 5 à la valeur pointée
    }
}

int passage__pointeur() {
    int value = 10;
    std::cout << "Avant : " << value << std::endl;
    add_five(&value); // On passe l'adresse de value a la fonction

    std::cout << "Après : " << value << std::endl;
    return 0;
}



int stack__explain() {
    std::stack<int> s;
    
    s.push(1);  // Ajoute 1
    s.push(2);  // Ajoute 2
    s.push(3);  // Ajoute 3

    std::cout << "Top element: " << s.top() << std::endl; // Affiche 3, le dernier element de la liste

    s.pop();  // Retire 3
    std::cout << "Top element after pop: " << s.top() << std::endl; // Affiche 2

    //la diff max entre une liste et une stack c'est que en stack il y'a des element qui peuvent etre vide en liste non 

    return 0;
}



using namespace std;

// On veut définir une classe qui contient des infos communes POUR TOUS LES ÉLÉMENTS 
class BankAccount { // (convention PascalCase)
public: // L'accesseur "public" permet d'accéder aux membres en dehors de la classe
    string name; // Nom du client 
    int balance; // Solde du compte
    void add__money(int amount){//ajoute une fonction qui peut etre modifier les amount 
        balance=balance+amount;//ceci est tres pratique 
    }
    void printing(){
        cout << name << " has " << balance << " dollars." << endl;
    }//j'ai def une fonction sur la classe tres pratique 
};

// On a défini ce qu'est l'objet BankAccount



void introClassBank() { 
    BankAccount samBank; //creation d'un compte en banque pour sam 
    samBank.name = "Sam's Account"; //nom 
    samBank.balance = 23;//solde 
//print 
    cout << samBank.name << " has " << samBank.balance << " dollars." << endl;

    BankAccount alex;//creation d'un compte pour alex 
    alex.balance=3000000;
    alex.name="alex";

    alex.balance=alex.balance-200; //alex fait un retrait de 200
    //ceci mets a jour l'account 
    cout << alex.name << " has " << alex.balance << " dollars." << endl;
    samBank.add__money(200);//ceci est une autre maniere de modifier  le solde peut etre tres pratique pour des operations plus complqué 
    samBank.printing();// pour print c'est quand meme mieux WAWWWWW
}





using namespace std;
//constructure with cats 
void cat_program() {
    class Cat {
    private:
        string name;
        string color;
        string toy;

    public:
        // Constructeur
        Cat() {//on def un chat nomé idk 
            name = "idk";
            color = "idk";
            toy = "idk";
        }

        // Méthode pour afficher les informations du chat
        void print_cat() {
            cout << "\n" << name << endl;
            cout << " " << color << endl;
            cout << " " << toy << endl;
        }

        Cat(string n){
            name=n;
            color="idk";
            toy="idk";
        }

        Cat(string n, string c, string t ){
            name=n;
            color=c;
            toy=t;
        }


    };

    Cat cat1;  // Création d'un objet de type Cat
    cat1.print_cat(); // Appel de la méthode d'affichage
    Cat Cat2("blanche");//creer un nouveau chat du nom de blance et appelle Cat2 
    Cat2.print_cat();
    Cat Cat3("garfield","orange","ballon");//crer un nouveau chat 3 input  
    Cat3.print_cat();
}




//////////////////////////////////
////  TEMPLATES

class Int_array {
    public:
        int array[10]; // Tableau de 10 entiers

        void fill(int value) { // Remplit le tableau avec la valeur "value"
            for (int i = 0; i < 10; i++)
                array[i] = value;
        }

        int& at(int index) { // Permet d’accéder à un élément du tableau
            return array[index];
        }
    };


// Template pour une classe générique (doit être déclaré en dehors des fonctions)
//ceci creer une classe general, la meme que pour la class int array mais je peux mettre du int, du float, et autre type de data

template <typename T> 
class Array {
public:
    T array[10]; // T est la classe generique ! 

    void fill(T value) { // Remplit le tableau avec la valeur "value"
        for (int i = 0; i < 10; i++)
            array[i] = value;
    }

    T& at(int index) { // Permet d’accéder à un élément du tableau
        return array[index];
    }
};

// Fonction qui utilise le template
void class_template() {
    Array<int> intArr; // Crée un tableau de 10 entiers
    intArr.fill(4); // Remplit le tableau avec des 4

    cout << "Valeur à l'index 4 : " << intArr.at(4) << endl; // Affiche 4
    Array<string>std_arr;
    std_arr.fill("KENOBIIIIIIII");
    cout << "avec le meme template je peux avoir d'autre chose  " << std_arr.at(4) << endl;


}






int main() {
    class_template(); // Appel de la fonction contenant tout le code
    return 0;
}



