//Dati il vettore v1 di 20 elementi e v2 di 5 elementi
//entrambi composti da elementi di tipo carattere
//Scrivi un programma che elimini da v1 gli elementi presenti
//anche in v2, sostituendoli con il carattere *

#include<iostream>
#include<cstdlib> //libreria che include system("cls")

using namespace std;

const int e1=20; //dimensione vettore1
const int e2=5;  //dimensione vettore2

const char carattere='*'; // carettere da inserire in caso l'elemento sia presente in entrambi i vettori

//prototipi
int menu();
void carica(char v1[], char v2[], string &s1);
void sostituisci(char v1[], char v2[], int &z);
void stampa(char v1[], char v2[], string s1);

int main(){

    int scelta;
    int z=0; //variabile contatore di n caratteri modificati
	char v1[e1];
	char v2[e2];

    string s1;

    do{

        scelta=menu();

        switch(scelta){
            
            case 1:{
                carica(v1,v2,s1);
                break;
            }

            case 2:{
                sostituisci(v1,v2,z);
                break;
            }

            case 3:{
                stampa(v1,v2,s1);
                break;
            }

            case 0:{
                cout<<"Sei uscito dal programma"<<endl;
            }
            
            default:{
            	cout<<"Scelta sbagliata"<<endl;
				break;
			}
        }

    }while(scelta!=0);

	
	system("pause");
	return 0;
}

int menu(){

    int scegli;

    cout<<"\t -----MENU'-----"<<endl;
    cout<<"1) Carica i vettori"<<endl;
    cout<<"2) Trova elementi in comune"<<endl;
    cout<<"3) Visualizza i vettori"<<endl;
    cout<<"0) Termina programma"<<endl;

    cout<<endl;

    cout<<"Fai una scelta: ";
    cin>>scegli;

    cout<<endl;

    if(scegli<0 || scegli>3){
        cout<<"Scelta sbagliata"<<endl;
        cout<<endl;

        cout << "Premi un tasto per continuare...";
        cin.ignore();// pulizia buffer input
        cin.get(); 
    }

    system("cls");

    return scegli;
}

void carica(char v1[], char v2[], string &s1){
	
	char verifica;

	
	cout<<"-----Vettore1-----"<<endl;
	
	for(int i=0; i<e1;i++){

        int c;
        bool y=true;

		cout<<"Inserisci il "<<i+1<<" elemento: ";
        cin>>verifica; //cin>>v1[i];

        c=i+1;

        for(int x=0;x<c;x++){

            if(v1[x]==verifica){
                cout<<"Errore, il carattere e' gia' stato inserito"<<endl;
                y=false;
                i=i-1;
                break;
            }
        }

        if(y==true){
            v1[i]=verifica;
            s1=s1+v1[i]+",";
        }
        
	}
	
	cout<<endl;
	
	cout<<"-----Vettore2-----"<<endl;
	
	for(int j=0; j<e2;j++){

        int c;
        bool y=true;


		cout<<"Inserisci il "<<j+1<<" elemento: ";
		cin>>verifica; //cin>>v2[i];

        c=j+1;

        for(int x=0;x<c;x++){

            if(v2[x]==verifica){
                cout<<"Errore, il carattere e' gia' stato inserito"<<endl;
                y=false;
                j=j-1;
                break;
            }
        }

        if(y==true){
            v2[j]=verifica;
        }
	}

    cout<<endl;

    cout << "Premi un tasto per continuare...";
    cin.ignore();// pulizia buffer input
    cin.get();

    system("cls");

}

void sostituisci( char v1[], char v2[], int &z){
	
	for(int i=0; i<e1;i++){
		
		for(int j=0;j<e2;j++){
			
			if(v1[i]==v2[j]){
				v1[i]=carattere;
                z++;
			}
			
		}
	}

    cout<<"Gli elementi sostituiti con "<<carattere<<" sono " <<z<<endl;

	
}

void stampa(char v1[], char v2[], string s1){

    int s;

    cout<<"1) Stampa i vettori originali"<<endl;
    cout<<"2) Stampa i vettori modificati"<<endl;

    cout<<endl;

    cout<<"Fai una scelta: ";
    cin>>s;

    if(s==1){

        cout<<"\t -----Vettore 1-----"<<endl;
        cout<<s1<<endl;

        cout<<"\t -----Vettore 2-----"<<endl;
        
        for(int j=0; j<e2;j++){
            cout<<v2[j]<<",";
        }

        cout<<endl;

    }
    else if(s==2){

        cout<<"\t -----Vettore 1-----"<<endl;

        for(int i=0; i<e1;i++){
            cout<<v1[i]<<",";
        }

        cout<<endl;

        cout<<"\t -----Vettore 2-----"<<endl;

        for(int j=0; j<e2;j++){
            cout<<v2[j]<<",";
        }

        cout<<endl;
    }
    else{
        cout<<"Scelta sbaglita"<<endl;
        cout<<endl;
    }

    cout<<"Premi qualsiasi tasto per continuare ";
    cin.ignore();// pulizia buffer input
    cin.get();

    system("cls");

}
