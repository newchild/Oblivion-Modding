#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void createFile(char* name){
ofstream NeuerTextEditor;
NeuerTextEditor.open(name,ios_base::out);
NeuerTextEditor.close();
}
const int LineNoClip = 379;
const int LineHealthBar = 467;
bool choice;
char temp;
int main()
{
    createFile("Rename to Oblivion.ini");
    int line = 1;
    char zeile[2500], datei [50];
    streampos ausgabepos1,anfangpos,endepos;
    ifstream eingabe("Oblivion.ini",ios_base::in);
    if(eingabe.good()){
        ofstream ausgabe("Rename to Oblivion.ini",ios_base::out | ios_base::in|ios_base::ate);
        if(ausgabe.good()){
        eingabe.seekg(0L,ios::end);
        ausgabepos1 = ausgabe.tellp();
        eingabe.seekg(0L,ios::beg);
        anfangpos = ausgabe.tellp();
        while(eingabe.good()){
            if(line == LineNoClip){
                eingabe.getline(zeile,2500);
                cout << "Patch No-Clip?(1/0)";
                cin >> choice;
                if(choice){
                cout << endl << "Patching No-Clip..." << endl;
                ausgabe << "bDisablePlayerCollision=1" << endl;
                line++;
                cout << "Successfully patched No-Clip :)" << endl;
                }
                else{
                ausgabe << "bDisablePlayerCollision=0" << endl;
                line++;
                }

            }
            if(line == LineHealthBar){
                eingabe.getline(zeile,2500);
                cout << "Patch ShowHealthbars?(1/0)";
                cin >> choice;
                if(choice){
                cout << endl << "Patching Healthbars..." << endl;
                ausgabe << "bHealthBarShowing=1" << endl;
                line++;
                cout << "Successfully patched Healthbars :)" << endl;
                }
                else{
                ausgabe << "bHealthBarShowing=0" << endl;
                line++;
                }
            }
            if(line != LineNoClip | line != LineHealthBar){
            eingabe.getline(zeile,2500);
            ausgabe << zeile << endl;
            line++;
            }



        }
        }

    }
    cin >> temp;
    return 0;
}
