#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int rows = 10 ;
const int elements = 10 ;
int Matrix[rows][elements];     // Zona PC
int MyArea[rows][elements];     // Zona Mea

int last_nava = -1;
int last_nava_id = 0;

int last_my_nava = -1;
int last_my_nava_id = 0;

struct vapoare{
    int nrvap;          // Numarul de casute cu care incepi
    int nrvapramase;    // Numarul de casute ramase
    int coord[10][2];   // Coordonatele ocupate de vapor
};

vapoare Zona[10];
vapoare ZonaPC[10];

void AdaugaZona(int vapor, int dim, int coords[][2]){
    Zona[vapor].nrvap = dim;
    Zona[vapor].nrvapramase = dim;
    int i;
    for(i = 0; i < dim; i++){
        Zona[vapor].coord[i][0] = coords[i][0];
        Zona[vapor].coord[i][1] = coords[i][1];
        MyArea[coords[i][0]][coords[i][1]] = vapor;
    }
}

void AdaugaZonaPC(int vapor, int dim, int coords[][2]){
    ZonaPC[vapor].nrvap = dim;
    ZonaPC[vapor].nrvapramase = dim;
    int i;
    for(i = 0; i < dim; i++){
        ZonaPC[vapor].coord[i][0] = coords[i][0];
        ZonaPC[vapor].coord[i][1] = coords[i][1];
        Matrix[coords[i][0]][coords[i][1]] = vapor;
    }
}

int getRand0or1(){
    return rand() % 2;
}

int getRand0or3(){
    return rand() % 4;
}

int getCoordX(){
    return rand() % rows;
}

int getCoordY(){
    return rand() % elements;
}

void ZonaRandom(){
    /* Construire random nava 1 */
    int x = getCoordX();
    int y = getCoordY();
    int nava_1[1][2] = {{x, y}};
    AdaugaZona(1, 1, nava_1);

    /* Construire random nava 2 */
    int noroc = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((noroc == 1 && y+1 > 9) || (noroc == 0 && x+1 > 9));
    }while(MyArea[x][y] > 0 ||
        (
            (noroc == 1 && MyArea[x][y+1] > 0) ||
            (noroc == 0 && MyArea[x + 1][y] > 0)
         )
    );
    int nava_2[2][2];
    if(noroc == 1){
        nava_2[0][0] = x;
        nava_2[0][1] = y;
        nava_2[1][0] = x;
        nava_2[1][1] = y + 1;
    }else{
        nava_2[0][0] = x;
        nava_2[0][1] = y;
        nava_2[1][0] = x + 1;
        nava_2[1][1] = y;
    }
    AdaugaZona(2, 2, nava_2);

    /* Construire random nava 2 */
    noroc = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((noroc == 1 && (y+1 > 9 || y+2 > 9)) || (noroc == 0 && (x+1 > 9 || x+2 > 9)));
    }while(MyArea[x][y] > 0 ||
        (
            (noroc == 1 && (MyArea[x][y+1] > 0 || MyArea[x][y+2] > 0)) ||
            (noroc == 0 && (MyArea[x + 1][y] > 0 || MyArea[x + 2][y] > 0))
         )
    );
    int nava_3[3][2];
    if(noroc == 1){
        nava_3[0][0] = x;
        nava_3[0][1] = y;
        nava_3[1][0] = x;
        nava_3[1][1] = y + 1;
        nava_3[2][0] = x;
        nava_3[2][1] = y + 2;
    }else{
        nava_3[0][0] = x;
        nava_3[0][1] = y;
        nava_3[1][0] = x + 1;
        nava_3[1][1] = y;
        nava_3[2][0] = x + 2;
        nava_3[2][1] = y;
    }
    AdaugaZona(3, 3, nava_3);

    /* Construire random nava 4 */
    noroc = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((noroc == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9)) || (noroc == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9)));
    }while(MyArea[x][y] > 0 ||
        (
            (noroc == 1 && (MyArea[x][y+1] > 0 || MyArea[x][y+2] > 0 || MyArea[x][y+3] > 0)) ||
            (noroc == 0 && (MyArea[x + 1][y] > 0 || MyArea[x + 2][y] > 0 || MyArea[x + 3][y] > 0))
         )
    );
    int nava_4[4][2];
    if(noroc == 1){
        nava_4[0][0] = x;
        nava_4[0][1] = y;
        nava_4[1][0] = x;
        nava_4[1][1] = y + 1;
        nava_4[2][0] = x;
        nava_4[2][1] = y + 2;
        nava_4[3][0] = x;
        nava_4[3][1] = y + 3;
    }else{
        nava_4[0][0] = x;
        nava_4[0][1] = y;
        nava_4[1][0] = x + 1;
        nava_4[1][1] = y;
        nava_4[2][0] = x + 2;
        nava_4[2][1] = y;
        nava_4[3][0] = x + 3;
        nava_4[3][1] = y;
    }
    AdaugaZona(4, 4, nava_4);

    /* Construire random nava 5 */
    noroc = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((noroc == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9 || y+4 > 9)) || (noroc == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9 || x+4 > 9)));
    }while(MyArea[x][y] > 0 ||
        (
            (noroc == 1 && (MyArea[x][y+1] > 0 || MyArea[x][y+2] > 0 || MyArea[x][y+3] > 0 || MyArea[x][y+4] > 0)) ||
            (noroc == 0 && (MyArea[x + 1][y] > 0 || MyArea[x + 2][y] > 0 || MyArea[x + 3][y] > 0 || MyArea[x + 4][y] > 0))
         )
    );
    int nava_5[3][2];
    if(noroc == 1){
        nava_5[0][0] = x;
        nava_5[0][1] = y;
        nava_5[1][0] = x;
        nava_5[1][1] = y + 1;
        nava_5[2][0] = x;
        nava_5[2][1] = y + 2;
        nava_5[3][0] = x;
        nava_5[3][1] = y + 3;
        nava_5[4][0] = x;
        nava_5[4][1] = y + 4;
    }else{
        nava_5[0][0] = x;
        nava_5[0][1] = y;
        nava_5[1][0] = x + 1;
        nava_5[1][1] = y;
        nava_5[2][0] = x + 2;
        nava_5[2][1] = y;
        nava_5[3][0] = x + 3;
        nava_5[3][1] = y;
        nava_5[4][0] = x + 4;
        nava_5[4][1] = y;
    }
    AdaugaZona(5, 5, nava_5);
}

void ZonaPCRandom(){
    /* Construire random nava 1 */
    int x = getCoordX();
    int y = getCoordY();
    int nava_1[1][2] = {{x, y}};
    AdaugaZonaPC(1, 1, nava_1);

    /* Construire random nava 2 */
    int noroc = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((noroc == 1 && y+1 > 9) || (noroc == 0 && x+1 > 9));
    }while(Matrix[x][y] > 0 ||
        (
            (noroc == 1 && Matrix[x][y+1] > 0) ||
            (noroc == 0 && Matrix[x + 1][y] > 0)
         )
    );
    int nava_2[2][2];
    if(noroc == 1){
        nava_2[0][0] = x;
        nava_2[0][1] = y;
        nava_2[1][0] = x;
        nava_2[1][1] = y + 1;
    }else{
        nava_2[0][0] = x;
        nava_2[0][1] = y;
        nava_2[1][0] = x + 1;
        nava_2[1][1] = y;
    }
    AdaugaZonaPC(2, 2, nava_2);

    /* Construire random nava 2 */
    noroc = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((noroc == 1 && (y+1 > 9 || y+2 > 9)) || (noroc == 0 && (x+1 > 9 || x+2 > 9)));
    }while(Matrix[x][y] > 0 ||
        (
            (noroc == 1 && (Matrix[x][y+1] > 0 || Matrix[x][y+2] > 0)) ||
            (noroc == 0 && (Matrix[x + 1][y] > 0 || Matrix[x + 2][y] > 0))
         )
    );
    int nava_3[3][2];
    if(noroc == 1){
        nava_3[0][0] = x;
        nava_3[0][1] = y;
        nava_3[1][0] = x;
        nava_3[1][1] = y + 1;
        nava_3[2][0] = x;
        nava_3[2][1] = y + 2;
    }else{
        nava_3[0][0] = x;
        nava_3[0][1] = y;
        nava_3[1][0] = x + 1;
        nava_3[1][1] = y;
        nava_3[2][0] = x + 2;
        nava_3[2][1] = y;
    }
    AdaugaZonaPC(3, 3, nava_3);

    /* Construire random nava 4 */
    noroc = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((noroc == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9)) || (noroc == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9)));
    }while(Matrix[x][y] > 0 ||
        (
            (noroc == 1 && (Matrix[x][y+1] > 0 || Matrix[x][y+2] > 0 || Matrix[x][y+3] > 0)) ||
            (noroc == 0 && (Matrix[x + 1][y] > 0 || Matrix[x + 2][y] > 0 || Matrix[x + 3][y] > 0))
         )
    );
    int nava_4[4][2];
    if(noroc == 1){
        nava_4[0][0] = x;
        nava_4[0][1] = y;
        nava_4[1][0] = x;
        nava_4[1][1] = y + 1;
        nava_4[2][0] = x;
        nava_4[2][1] = y + 2;
        nava_4[3][0] = x;
        nava_4[3][1] = y + 3;
    }else{
        nava_4[0][0] = x;
        nava_4[0][1] = y;
        nava_4[1][0] = x + 1;
        nava_4[1][1] = y;
        nava_4[2][0] = x + 2;
        nava_4[2][1] = y;
        nava_4[3][0] = x + 3;
        nava_4[3][1] = y;
    }
    AdaugaZonaPC(4, 4, nava_4);

    /* Construire random nava 5 */
    noroc = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((noroc == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9 || y+4 > 9)) || (noroc == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9 || x+4 > 9)));
    }while(Matrix[x][y] > 0 ||
        (
            (noroc == 1 && (Matrix[x][y+1] > 0 || Matrix[x][y+2] > 0 || Matrix[x][y+3] > 0 || Matrix[x][y+4] > 0)) ||
            (noroc == 0 && (Matrix[x + 1][y] > 0 || Matrix[x + 2][y] > 0 || Matrix[x + 3][y] > 0 || Matrix[x + 4][y] > 0))
         )
    );
    int nava_5[3][2];
    if(noroc == 1){
        nava_5[0][0] = x;
        nava_5[0][1] = y;
        nava_5[1][0] = x;
        nava_5[1][1] = y + 1;
        nava_5[2][0] = x;
        nava_5[2][1] = y + 2;
        nava_5[3][0] = x;
        nava_5[3][1] = y + 3;
        nava_5[4][0] = x;
        nava_5[4][1] = y + 4;
    }else{
        nava_5[0][0] = x;
        nava_5[0][1] = y;
        nava_5[1][0] = x + 1;
        nava_5[1][1] = y;
        nava_5[2][0] = x + 2;
        nava_5[2][1] = y;
        nava_5[3][0] = x + 3;
        nava_5[3][1] = y;
        nava_5[4][0] = x + 4;
        nava_5[4][1] = y;
    }
    AdaugaZonaPC(5, 5, nava_5);
}

void Clear(){
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < elements; j++){
            Matrix[i][j] = 0 ;
            MyArea[i][j] = 0 ;
        }
}

int NumberOfShips(){
    int c = 0;
    for(int i = 1; i <= 5; i++)
        if(ZonaPC[i].nrvapramase != 0)
            c++;
    return c;
}

int NumberOfMyShips(){
    int c = 0;
    for(int i = 1; i <= 5; i++)
        if(Zona[i].nrvapramase != 0)
            c++;
    return c;
}

bool Attack(int x, int y){
    if(Matrix[x][y] > 0){
        int vapor = Matrix[x][y];
        ZonaPC[vapor].nrvapramase--;
        if(ZonaPC[vapor].nrvapramase > 0)
            last_nava = 1;
        else
            last_nava = 0;
        last_nava_id = vapor;
        Matrix[x][y] = -1;
        return true;
    }
    return false;
}

bool AttackMe(int x, int y){
    if(MyArea[x][y] > 0){
        int vapor = MyArea[x][y];
        Zona[vapor].nrvapramase--;
        if(Zona[vapor].nrvapramase > 0)
            last_my_nava = 1;
        else
            last_my_nava = 0;
        last_my_nava_id = vapor;
        MyArea[x][y] = -1;
        return true;
    }
    return false;
}

void ShowFull(int type){
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << " -                     Welcome to BattleShip!                    -" << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << " -          PC Zone:                               My Area:      -" << endl;
    cout << " - - - 0 1 2 3 4 5 6 7 8 9 -           - - - 0 1 2 3 4 5 6 7 8 9 -" << endl;
    for (int i = 0; i < rows; i++){
        cout << " | " << i << " | ";
        for (int j = 0; j < elements; j++){
            if(Matrix[i][j] == -1)
                cout << "X ";
            else if(Matrix[i][j] == 0 || type == 0)
                cout << "* ";
            else if(Matrix[i][j] == 1)
                cout << (char)176 << " ";
            else if(Matrix[i][j] == 2)
                cout << (char)177 << " ";
            else if(Matrix[i][j] == 3)
                cout << (char)178 << " ";
            else if(Matrix[i][j] == 4)
                cout << (char)240 << " ";
            else if(Matrix[i][j] == 5)
                cout << (char)219 << " ";
            else
                cout << Matrix[i][j] << " " ;
        }
        cout << "|           | " << i << " | ";
        for (int j = 0; j < elements; j++)
            if(MyArea[i][j] == -1)
                cout << "X ";
            else if(MyArea[i][j] == 0)
                cout << "* ";
            else if(MyArea[i][j] == 1)
                cout << (char)176 << " ";
            else if(MyArea[i][j] == 2)
                cout << (char)177 << " ";
            else if(MyArea[i][j] == 3)
                cout << (char)178 << " ";
            else if(MyArea[i][j] == 4)
                cout << (char)240 << " ";
            else if(MyArea[i][j] == 5)
                cout << (char)219 << " ";
            else
                cout << MyArea[i][j] << " " ;
        cout << "|" << endl;
    }
    cout << " - - - - - - - - - - - - - -           - - - - - - - - - - - - - -" << endl;
    cout << " | The remaining ships: " << NumberOfShips();
    if(NumberOfShips() == 10)
        cout << " |           | ";
    else
        cout << "  |           | ";
    cout << "The remaining ships: " << NumberOfMyShips();
    if(NumberOfMyShips() == 10)
        cout << " | " << endl;
    else
        cout << "  | " << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

int main(){
    srand(time(NULL));
    Clear();

    ZonaRandom();
    ZonaPCRandom();

 //   for(int kk = 0; kk < 250; kk++)
  //      cout << kk << " " <<(char)kk << endl;


    int pos1,pos2;
    int posx = -1, posy = -1;
    char prompt = 'n';
    char work = 'n';

    // exite = 0;      // Eu am vrut sa ies din meci
    // exite = 1;      // Eu am castigat
    // exite = 2;      // PC a castigat

    int exite;
    int lovita = 0;
    int aifostlovit = 0;
    int verificare;


    do{
        cout << "You want to get out of the game faster? (y/n): ";
        cin >> work;
    }while(work != 'y' && work != 'n');

    while(1){
        system("cls");
        ShowFull(1);

        if((work == 'y' || work == 'n') && (prompt == 'y' || prompt == 'n')){
            if (lovita == 1 && last_nava == 1)
                cout << " Me: A fost distrusa o parte din nava (" << last_nava_id << ")! ... (" << pos1 << "," << pos2 << ")" << endl;
            else if (lovita == 1 && last_nava == 0)
                cout << " Me: A fost distrusa intreaga nava (" << last_nava_id << ")! ... (" << pos1 << "," << pos2 << ")" << endl;
            else if(lovita == 2)
                cout << " Me: No ship at that position!   ... (" << pos1 << "," << pos2 << ")" << endl;

            if(aifostlovit && last_my_nava == 1)
                cout << " PC: A fost distrusa o parte din nava (" << last_my_nava_id << ")! ... (" << posx << "," << posy << ")" << endl;
            else if(aifostlovit && last_my_nava == 0)
                cout << " PC: A fost distrusa intreaga nava (" << last_my_nava_id << ")! ... (" << posx << "," << posy << ")" << endl;
            else if(posx > -1 && posy > -1)
                cout << " PC: You were attacked at " << posx << "," << posy << " coordinates! " << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

            if(prompt == 'n' && NumberOfShips() != 0){
                do{
                    cout << " Me: Please input location: ";
                    cin >> pos1 >> pos2;
                }while(pos1 < 0 || pos1 > 10 || pos2 < 0 || pos2 > 10);
                if(Attack(pos1,pos2))
                    lovita = 1;
                else
                    lovita = 2;
            }
            if(aifostlovit == 1){
                do{
                    verificare = getRand0or3();
                }while(
                       (verificare == 0 && (posy + 1 >= 10 || MyArea[posx][posy + 1] < 0)) ||
                       (verificare == 1 && (posx + 1 >= 10 || MyArea[posx + 1][posy] < 0)) ||
                       (verificare == 2 && (posy - 1 < 0 || MyArea[posx][posy - 1] < 0)) ||
                       (verificare == 3 && (posx - 1 < 0 || MyArea[posx - 1][posy] < 0))
                );
                if(verificare == 0 && posy + 1 < 10){
                    posy += 1;
                    if(AttackMe(posx, posy))
                        aifostlovit = 1;
                    else
                        aifostlovit = 0;
                }else if(verificare == 1 && posx + 1 < 10){
                    posx += 1;
                    if(AttackMe(posx, posy))
                        aifostlovit = 1;
                    else
                        aifostlovit = 0;
                }else if(verificare == 2 && posy - 1 >= 0){
                    posy -= 1;
                    if(AttackMe(posx, posy))
                        aifostlovit = 1;
                    else
                        aifostlovit = 0;

                }else if(verificare == 3 && posx - 1 >= 0){
                    posx -= 1;
                    if(AttackMe(posx, posy))
                        aifostlovit = 1;
                    else
                        aifostlovit = 0;
                }else{
                    do{
                        posx = getCoordX();
                        posy = getCoordY();
                    }while(MyArea[posx][posy] < 0);
                    if(AttackMe(posx, posy))
                        aifostlovit = 1;
                    else
                        aifostlovit = 0;
                }
            }else{
                do{
                    posx = getCoordX();
                    posy = getCoordY();
                }while(MyArea[posx][posy] < 0);
                if(AttackMe(posx, posy))
                    aifostlovit = 1;
                else
                    aifostlovit = 0;
            }

             if(NumberOfShips() == 0){
                exite = 1;
                break;
            }
            if(NumberOfMyShips() == 0){
                exite = 2;
                break;
            }
        }

        if(work == 'y'){
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            if (lovita == 1 && last_nava == 1)
                cout << " Me: A fost distrusa o parte din nava (" << last_nava_id << ")! ... (" << pos1 << "," << pos2 << ")" << endl;
            else if (lovita == 1 && last_nava == 0)
                cout << " Me: A fost distrusa intreaga nava (" << last_nava_id << ")! ... (" << pos1 << "," << pos2 << ")" << endl;
            else if(lovita == 2){
                cout << " Me: No ship at that position!   ... (" << pos1 << "," << pos2 << ")" << endl;
            }
            if(aifostlovit && last_my_nava == 1)
                cout << " PC: A fost distrusa o parte din nava (" << last_my_nava_id << ")! ... (" << posx << "," << posy << ")" << endl;
            else if(aifostlovit && last_my_nava == 0)
                cout << " PC: A fost distrusa intreaga nava (" << last_my_nava_id << ")! ... (" << posx << "," << posy << ")" << endl;
            else if(posx > -1 && posy > -1)
                cout << " PC: You were attacked at " << posx << "," << posy << " coordinates! " << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << " Me: Do you want to surrender (y/n) ? " ;
            cin >> prompt;
        }
        if (prompt == 'y'){
            exite = 0;
            break;
        }
    }
    system("cls");
    ShowFull(1);
    if(exite == 0)
        cout << " You chose to quit the game !" << endl;
    else if(exite == 1)
        cout << "Congratulations, you won!" << endl;
    else if(exite == 2)
        cout << " It looks like the computer won!" << endl;

    return 0;
}

