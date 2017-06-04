#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int limit=100;
struct Number{ //Kiekvienas ksaičius turi atskirą vietą kiekvienąm skaitmeniui, ilgį ir tipą
    int Place[limit];
    int Length;
    int Type;
};
void Convert(char reader[],int start, int place[], int size){
    for(int i = start; i<size; i++){
        switch (reader[i]){
            case '0': place[i]=0; break;
            case '1': place[i]=1; break;
            case '2': place[i]=2; break;
            case '3': place[i]=3; break;
            case '4': place[i]=4; break;
            case '5': place[i]=5; break;
            case '6': place[i]=6; break;
            case '7': place[i]=7; break;
            case '8': place[i]=8; break;
            case '9': place[i]=9; break;
            case 'A': place[i]=10; break;
            case 'B': place[i]=11; break;
            case 'C': place[i]=12; break;
            case 'D': place[i]=13; break;
            case 'E': place[i]=14; break;
            case 'F': place[i]=15; break;
        }
    }
}
void Swaper(int place[], int from, int how){ //perkelia desimtaines reiksmes i masyvo pradzia
    for(int i=0; i<how; i++){
        swap(place[i],place[from+i]);
    }
}
void Read(int place[], int &size, int &type, int placedot[], int &sizedot, int &typedot){
    char reader[limit];
    cin>>reader;
    size = 1;
    int i=0;
    while('.' != reader[i]){
        i++;
    }
    size=i;
    sizedot=strlen(reader)-size-1;
    cin>>type;
    typedot=type;
    Convert(reader,0,place,size);
    Convert(reader,size+1,placedot,(int)strlen(reader));
    Swaper(placedot,size+1,sizedot);
}
void To10(int place[],int size, int type, int Rezplace[], int &Rezsize, int &Reztype){
    int container=0; //kintamajam priskirimia desimtaine reiksme
    for(int i=0; i<size-1; i++){
        container+=place[i];
        container*=type;
    }
    container+=place[size-1];
    //masyvo tipas ir dydis
    Rezsize=0;
    Reztype=10;
    //reiksme priskiriama masyvui

    while(container>=1){
        Rezplace[Rezsize]=container%10;
        container/=10;
        Rezsize++;
    }
    //masyvo reiksmes sukeiciamos vietomis
    for(int i=0; i<Rezsize/2; i++){
        swap(Rezplace[i],Rezplace[Rezsize-i-1]);
   }
}
void To10Dot(int place[], int size, int type, int Rezplace[], int &Rezsize, int &Reztype){
    long double container=0;
    for(int i=size-1; i>=0; i--){
        container+=place[i];
        container/=type;
    }
    for(int i=0; i<20; i++){
        container*=10;
        Rezplace[i]=(int)container%10;
        if(Rezplace[i]<1) Rezplace[i]=0;
    }
    Rezsize=20;
}
void From10dot(int place[], int size, int Rezplace[], int &Rezsize, int &Reztype, int choise){
    long double container=0;
    for(int i=size-1; i>=0; i--){
        container+=place[i];
        container/=10;
    }
    int i=0;
   while(container>0 && i<20){
        container*=choise;
        Rezplace[i++]=(int)container;
        container-=(int)container;
   }
   Rezsize=20;
   Reztype=choise;
}
void Line(){
    cout<< "------------------------------------------------\n";
}
void From10(int place[],int size, int Rezplace[], int &Rezsize, int &Reztype, int choise){
    int container=0;
    for(int i=0; i<size-1; i++){
        container+=place[i];
        container*=10;
    }
    container+=place[size-1];
    Rezsize=0;
    Reztype=choise;
    for(int i=0; container>=choise; i++){
        Rezplace[i]=container%choise;
        container/=choise;
        Rezsize=i+1;
    }
        Rezsize++;
        Rezplace[Rezsize-1]=container;
    for(int i=0; i<Rezsize/2; i++){
        swap(Rezplace[i],Rezplace[Rezsize-i-1]);
   }
}
void Write(int  place[], int size, int type){
    for(int i=0; i<size; i++){
        switch (place[i]){
            case 10: cout<< 'A'; break;
            case 11: cout<< 'B'; break;
            case 12: cout<< 'C'; break;
            case 13: cout<< 'D'; break;
            case 14: cout<< 'E'; break;
            case 15: cout<< 'F'; break;
            default: cout<< place[i];
        }
    }
}
int main(){
    bool stop=0;
    int choise;
    while(!stop){
        cout<< "Write number that you want to convert,\nThen write counting system of that number\n";
        Number Num1, Num1dot, Num2, Num2dot, Result, Resultdot;
        Read(Num1.Place, Num1.Length, Num1.Type, Num1dot.Place, Num1dot.Length, Num1dot.Type);
        Line();
        cout<< "Now write into which counting system you want to convert number \n";
        cin>>choise;
        Line();
        cout<< "Converted number is: ";
        To10(Num1.Place, Num1.Length, Num1.Type, Num2.Place, Num2.Length, Num2.Type);
        To10Dot(Num1dot.Place,Num1dot.Length,Num1dot.Type,Num2dot.Place,Num2dot.Length,Num2dot.Type);        if(choise==10){
            Write(Num2.Place, Num2.Length, Num2.Type); cout<<'.';
            Write(Num2dot.Place, Num2dot.Length,Num2dot.Type);
        }
        else{
            From10(Num2.Place, Num2.Length, Result.Place, Result.Length, Result.Type, choise);
            From10dot(Num2dot.Place,Num2dot.Length,Resultdot.Place,Resultdot.Length,Resultdot.Type,choise);
            Write(Result.Place, Result.Length, Result.Type); cout<<'.';
            Write(Resultdot.Place,Resultdot.Length,Resultdot.Type);
        }
        cout<<endl;
        system("Pause");
        system("cls");
        for(int i=0; i<20;i++){
            Resultdot.Place[i];
            Num2.Place[i];
            Num1.Place[i];
        }
    }
    return 0;
}
