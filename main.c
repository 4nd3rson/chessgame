#include <stdio.h>
#include <stdlib.h>

int minhapeca();
int bispo(int x1, int y1, int x2, int y2);
int torre(int x1, int y1, int x2, int y2);
int xequebispo(int x, int y, char Bispo);
int xequetorre(int x, int y, char Torre);
int renderiza_bispo(int i, int j, int l, int c, int vez);
int renderiza_torre(int i, int j, int l, int c, int vez);

char tabuleiro[8][8] = {
    { 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T' },
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'p' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
    { 't', 'c', 'b', 'q', 'k', 'b', 'c', 't' },
};

void promove_peao(int x2, int y2){
    int aux, repete = 1;

    while(repete){
        puts("\n>> PARABENS, SEU PEAO FOI PROMOVIDO! INFORME UMA PATENTE");
        puts("QUE DESEJA SE PROMOVER: ");
        puts(" -- 1. RAINHA");
        puts(" -- 2. BISPO");
        puts(" -- 3. CAVALO");
        puts(" -- 4. TORRE");
        printf(" -> ");
        scanf("%d", &aux);
        switch(x2){
        case 0:
            if(aux == 1) tabuleiro[x2][y2] = 'q', repete = 0;
            else if(aux == 2) tabuleiro[x2][y2] = 'b', repete = 0;
            else if(aux == 3) tabuleiro[x2][y2] = 'c', repete = 0;
            else if(aux == 4) tabuleiro[x2][y2] = 't', repete = 0;
            break;
        case 7:
            if(aux == 1) tabuleiro[x2][y2] = 'Q';
            else if(aux == 2) tabuleiro[x2][y2] = 'B', repete = 0;
            else if(aux == 3) tabuleiro[x2][y2] = 'C', repete = 0;
            else if(aux == 4) tabuleiro[x2][y2] = 'T', repete = 0;
            break;
        }
    }
    system("cls");
}

void movimento(int x1, int y1, int x2, int y2, int * x, int * y){

    tabuleiro[x2][y2] = tabuleiro[x1][y1];
    tabuleiro[x1][y1] = ' ';

    if((tabuleiro[x2][y2] == 'p' && x2 == 0) || (tabuleiro[x2][y2] == 'P' && x2 == 7)) promove_peao(x2, y2);

    if(tabuleiro[x2][y2] == 'k') (*x) = x2, (*y) = y2;
    else if(tabuleiro[x2][y2] == 'K') (*x) = x2, (*y) = y2;
}

void exibetabuleiro(){
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            printf("%c ", tabuleiro[i][j]);
        }
        putchar('\n');
    }
}

int xequerei(int x, int y, char Rei){

    if(tabuleiro[x + 1][y] == Rei) return 1;
    else if(tabuleiro[x - 1][y] == Rei) return 1;
    else if(tabuleiro[x + 1][y + 1] == Rei) return 1;
    else if(tabuleiro[x + 1][y - 1] == Rei) return 1;
    else if(tabuleiro[x - 1][y - 1] == Rei) return 1;
    else if(tabuleiro[x - 1][y + 1] == Rei) return 1;
    else if(tabuleiro[x][y - 1] == Rei) return 1;
    else if(tabuleiro[x][y + 1] == Rei) return 1;

    return 0;
}

int xequerainha(int x, int y, char Rainha){

    if(xequetorre(x, y, Rainha)) return 1;
    else if(xequebispo(x, y, Rainha)) return 1;

    return 0;
}

int xequebispo(int x, int y, char Bispo){
    int i, j;

    for(i = (x + 1), j = (y + 1); (i <= 7) && (j <= 7); i++, j++){
        if(tabuleiro[i][j] == Bispo) return 1;
        else if(tabuleiro[i][j] != ' ') break;
    }
    for(i = (x + 1), j = (y - 1); (i <= 7) && (j >= 0); i++, j--){
        if(tabuleiro[i][j] == Bispo) return 1;
        else if(tabuleiro[i][j] != ' ') break;
    }
    for(i = (x - 1), j = (y - 1); (i >= 0) && (j >= 0); i--, j--){
        if(tabuleiro[i][j] == Bispo) return 1;
        else if(tabuleiro[i][j] != ' ') break;
    }
    for(i = (x - 1), j = (y + 1); (i >= 0) && (j <= 7); i--, j++){
        if(tabuleiro[i][j] == Bispo) return 1;
        else if(tabuleiro[i][j] != ' ') break;
    }

    return 0;
}

int xequecavalo(int x, int y, char Cavalo){

    if(tabuleiro[x + 2][y + 1] == Cavalo) return 1;
    else if(tabuleiro[x + 2][y - 1] == Cavalo) return 1;
    else if(tabuleiro[x - 2][y + 1] == Cavalo) return 1;
    else if(tabuleiro[x - 2][y - 1] == Cavalo) return 1;
    else if(tabuleiro[x + 1][y + 2] == Cavalo) return 1;
    else if(tabuleiro[x + 1][y - 2] == Cavalo) return 1;
    else if(tabuleiro[x - 1][y - 2] == Cavalo) return 1;
    else if(tabuleiro[x - 1][y + 2] == Cavalo) return 1;

    return 0;
}

int xequetorre(int x, int y, char Torre){
    int i;

    for(i = (x + 1); i <= 7; i++){
        if(tabuleiro[i][y] == Torre) return 1;
        else if(tabuleiro[i][y] != ' ') break;
    }
    for(i = (x - 1); i >= 0; i--){
        if(tabuleiro[i][y] == Torre) return 1;
        else if(tabuleiro[i][y] != ' ') break;
    }
    for(i = (y + 1); i <= 7; i++){
        if(tabuleiro[x][i] == Torre) return 1;
        else if(tabuleiro[x][i] != ' ') break;
    }
    for(i = (y - 1); i >= 0; i--){
        if(tabuleiro[x][i] == Torre) return 1;
        else if(tabuleiro[x][i] != ' ') break;
    }

    return 0;
}

int xequepeao(int x, int y, int vez, char Peao){

    switch(vez){
    case 1:
        if(tabuleiro[x-1][y+1] == Peao) return 1;
        else if(tabuleiro[x-1][y-1] == Peao) return 1;
        break;
    case 2:
        if(tabuleiro[x+1][y+1] == Peao) return 1;
        else if(tabuleiro[x+1][y-1] == Peao) return 1;
        break;
    }

    return 0;
}

int xeque(int x, int y, int vez){

    switch(vez){
    case 1:
        if(xequepeao(x, y, vez, 'P')) return 1;
        else if(xequetorre(x, y, 'T')) return 1;
        else if(xequecavalo(x, y, 'C')) return 1;
        else if(xequebispo(x, y, 'B')) return 1;
        else if(xequerainha(x, y, 'Q')) return 1;
        else if(xequerei(x, y, 'K')) return 1;
        break;
    case 2:
        if(xequepeao(x, y, vez, 'p')) return 1;
        else if(xequetorre(x, y, 't')) return 1;
        else if(xequecavalo(x, y, 'c')) return 1;
        else if(xequebispo(x, y, 'b')) return 1;
        else if(xequerainha(x, y, 'q')) return 1;
        else if(xequerei(x, y, 'k')) return 1;
        break;
    }

    return 0;
}

void simula_movimento(int x1, int y1, int x2, int y2, char aux, int opcao){

    switch(opcao){
    case 1: //FAZ
        tabuleiro[x2][y2] = tabuleiro[x1][y1];
        tabuleiro[x1][y1] = ' ';
        break;
    case 2: //DESFAZ
        tabuleiro[x1][y1] = tabuleiro[x2][y2];
        tabuleiro[x2][y2] = aux;
        break;
    }
}

int reiemxeque(int x1, int y1, int x2, int y2, int vez, int x, int y){
    char aux;

    aux = tabuleiro[x2][y2];

    simula_movimento(x1, y1, x2, y2, aux, 1);

    if(tabuleiro[x2][y2] == 'k' || tabuleiro[x2][y2] == 'K'){ x = x2, y = y2; }

    if(xeque(x, y, vez)){
        simula_movimento(x1, y1, x2, y2, aux, 2);
        return 1;
    }

    simula_movimento(x1, y1, x2, y2, aux, 2);

    return 0;
}

int rei(int x1, int y1, int x2, int y2){

    if(((x2 - x1) <= 1 && (x2 - x1) >= -1) && ((y2 - y1) <= 1 && (y2 - y1) >= -1)) return 1;

    return 0;
}

int rainha(int x1, int y1, int x2, int y2){

    if(x1 != x2 && y1 != y2){ if(bispo(x1, y1, x2, y2)) return 1; }
    else if((x1 == x2 && y1 != y2) || ((x1 != x2) && y1 == y2)){ if(torre(x1, y1, x2, y2)) return 1; }

    return 0;
}

int bispo(int x1, int y1, int x2, int y2){
    int i, j;

    if(x1 < x2){
        if(y1 < y2){
            for(i = (x1 + 1), j = (y1 + 1); (i < x2) && (j < y2); i++, j++){
                if(tabuleiro[i][j] != ' ') return 0;
            }
            return 1;
        }
        else if(y1 > y2){
            for(i = (x1 + 1), j = (y1 - 1); (i < x2) && (j > y2); i++, j--){
                if(tabuleiro[i][j] != ' ') return 0;
            }
            return 1;
        }
    }
    else if(x1 > x2){
        if(y1 < y2){
            for(i = (x1 - 1), j = (y1 + 1); (i > x2) && (j < y2); i--, j++) {
                if(tabuleiro[i][j] != ' ') return 0;
            }
            return 1;
        }
        else if(y1 > y2){
            for(i = (x1 - 1), j = (y1 - 1); (i > x2) && (j > y2); i--, j--) {
                if(tabuleiro[i][j] != ' ') return 0;
            }
            return 1;
        }
    }

    return 0;
}

int cavalo(int x1, int y1, int x2, int y2){

    if((y1 + 1) == y2 || (y1 - 1) == y2){
        if((x1 + 2) == x2) return 1;
        else if((x1 - 2) == x2) return 1;
    }
    if((x1 + 1) == x2 || (x1 - 1) == x2){
        if((y1 + 2) == y2) return 1;
        else if((y1 - 2) == y2) return 1;
    }

    return 0;
}

int torre(int x1, int y1, int x2, int y2){
    int i;

    if(x1 == x2 && y1 != y2){
        if(y1 > y2){
            for(i = y1 - 1; i > y2; i--){ if(tabuleiro[x1][i] != ' ') return 0; }
        }
        else if(y1 < y2){
            for(i = y1 + 1; i < y2; i++){ if(tabuleiro[x1][i] != ' ') return 0; }
        }
    }
    else if(x1 != x2 && y1 == y2){
        if(x1 > x2){
            for(i = x1 - 1; i > x2; i--){ if(tabuleiro[i][y1] != ' ') return 0; }
        }
        else if(x1 < x2){
            for(i = x1 + 1; i < x2; i++){ if(tabuleiro[i][y1] != ' ') return 0; }
        }
    }

    return 1;
}

int peao(int x1, int y1, int x2, int y2, int vez){
    int um, dois;

    if(vez == 1) um = 1, dois = 2, vez = 2;
    else um = -1, dois = -2, vez = 1;

    if((x1 - um) == x2 && y1 == y2){ if(tabuleiro[x2][y2] == ' ') return 1; }
    else if((x1 - um) == x2 && ((y1 - 1) == y2 || (y1 + 1) == y2)){ if(minhapeca(x2, y2, vez)) return 1; }
    else if((x1 - dois) == x2 && (y1 == y2) && ((x1 == 6) || (x1 == 1))){ if(tabuleiro[x1 - um][y1] == ' ' && tabuleiro[x1 - dois][y1] == ' ') return 1; }

    return 0;
}

int movimentopossivel(int x1, int y1, int x2, int y2, int vez){

    if(tabuleiro[x1][y1] == 'p' || tabuleiro[x1][y1] == 'P') return peao(x1, y1, x2, y2, vez);
    else if(tabuleiro[x1][y1] == 't' || tabuleiro[x1][y1] == 'T') return torre(x1, y1, x2, y2);
    else if(tabuleiro[x1][y1] == 'c' || tabuleiro[x1][y1] == 'C') return cavalo(x1, y1, x2, y2);
    else if(tabuleiro[x1][y1] == 'b' || tabuleiro[x1][y1] == 'B') return bispo(x1, y1, x2, y2);
    else if(tabuleiro[x1][y1] == 'q' || tabuleiro[x1][y1] == 'Q') return rainha(x1, y1, x2, y2);
    else if(tabuleiro[x1][y1] == 'k' || tabuleiro[x1][y1] == 'K') return rei(x1, y1, x2, y2);

    return 0;
}

int minhapeca(int x, int y, int vez){
    char letra = (vez == 1 ? 98 : 66);

    if(tabuleiro[x][y] == letra) return 1; letra+=1;
    if(tabuleiro[x][y] == letra) return 1; letra+=8;
    if(tabuleiro[x][y] == letra) return 1; letra+=5;
    if(tabuleiro[x][y] == letra) return 1; letra+=1;
    if(tabuleiro[x][y] == letra) return 1; letra+=3;
    if(tabuleiro[x][y] == letra) return 1;

    return 0;
}

int verifica(int x1, int y1, int x2, int y2, int vez, int x, int y){

    if((x1 >= 0 && x1 < 8) && (y1 >= 0 && y1 < 8)){
        if((x2 >= 0 && x2 < 8) && (y2 >= 0 && y2 < 8)){
            if(minhapeca(x1, y1, vez)){
                if(minhapeca(x2, y2, vez) == 0){
                    if(movimentopossivel(x1, y1, x2, y2, vez)){
                        if(reiemxeque(x1, y1, x2, y2, vez, x, y) == 0){
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int mover_rei(int x, int y, int vez){

    if(verifica(x, y, (x + 1), y, vez, x, y)) return 1;
    else if(verifica(x, y, (x + 1), (y + 1), vez, x, y)) return 1;
    else if(verifica(x, y, (x + 1), (y - 1), vez, x, y)) return 1;
    else if(verifica(x, y, (x - 1), (y + 1), vez, x, y)) return 1;
    else if(verifica(x, y, (x - 1), (y - 1), vez, x, y)) return 1;
    else if(verifica(x, y, (x - 1), y, vez, x, y)) return 1;
    else if(verifica(x, y, x, (y + 1), vez, x, y)) return 1;
    else if(verifica(x, y, x, (y - 1), vez, x, y)) return 1;

    return 0;
}

int renderiza_rainha(int i, int j, int x, int y, int vez){

    if(renderiza_bispo(i, j, x, y, vez)) return 1;
    else if(renderiza_torre(i, j, x, y, vez)) return 1;

    return 0;
}

int renderiza_bispo(int i, int j, int l, int c, int vez){
    int x, y;

    for(x = (i+1), y = (j+1); x <= 7 && y <= 7; x++, y++){ if(verifica(i, j, x, y, vez, l, c)) return 1; }
    for(x = (i+1), y = (j-1); x <= 7 && y >= 0; x++, y--){ if(verifica(i, j, x, y, vez, l, c)) return 1; }
    for(x = (i-1), y = (j-1); x >= 0 && y >= 0; x--, y--){ if(verifica(i, j, x, y, vez, l, c)) return 1; }
    for(x = (i-1), y = (j+1); x >= 0 && y <= 7; x--, y++){ if(verifica(i, j, x, y, vez, l, c)) return 1; }

    return 0;
}

int renderiza_cavalo(int i, int j, int x, int y, int vez){

    if(verifica(i, j, (i+2), (j+1), vez, x, y)) return 1;
    else if(verifica(i, j, (i+2), (j-1), vez, x, y)) return 1;
    else if(verifica(i, j, (i+1), (j+2), vez, x, y)) return 1;
    else if(verifica(i, j, (i+1), (j-2), vez, x, y)) return 1;
    else if(verifica(i, j, (i-1), (j-2), vez, x, y)) return 1;
    else if(verifica(i, j, (i-1), (j+2), vez, x, y)) return 1;
    else if(verifica(i, j, (i-2), (j-1), vez, x, y)) return 1;
    else if(verifica(i, j, (i-2), (j+1), vez, x, y)) return 1;

    return 0;
}

int renderiza_torre(int i, int j, int l, int c, int vez){
    int x, y;

    for(x = (i + 1); x <= 7; x++) if(verifica(i, j, x, j, vez, l, c)) return 1;
    for(x = (i - 1); x >= 0; x--) if(verifica(i, j, x, j, vez, l, c)) return 1;
    for(y = (j + 1); y <= 7; y++) if(verifica(i, j, i, y, vez, l, c)) return 1;
    for(y = (j - 1); y >= 0; y--) if(verifica(i, j, i, y, vez, l, c)) return 1;

    return 0;
}

int renderiza_peao(int i, int j, int x, int y, int vez){

    switch(vez){
    case 1:
        if(verifica(i, j, (i-1), j, vez, x, y)) return 1;
        if(verifica(i, j, (i-1), (j+1), vez, x, y)) return 1;
        if(verifica(i, j, (i-1), (j-1), vez, x, y)) return 1;
        if(verifica(i, j, (i-2), j, vez, x, y)) return 1;
        break;
    case 2:
        if(verifica(i, j, (i+1), j, vez, x, y)) return 1;
        if(verifica(i, j, (i+1), (j+1), vez, x, y)) return 1;
        if(verifica(i, j, (i-1), (j-1), vez, x, y)) return 1;
        if(verifica(i, j, (i+2), j, vez, x, y)) return 1;
        break;
    }

    return 0;
}

int renderiza(int x, int y, int vez){
    int i, j;

    if(vez == 1){
        for(i = 0; i <= 7; i++){
            for(j = 0; j <= 7; j++){
                if(tabuleiro[i][j] != ' '){
                    if(tabuleiro[i][j] == 'p'){ if(renderiza_peao(i, j, x, y, vez)) return 1; }
                    if(tabuleiro[i][j] == 't'){ if(renderiza_torre(i, j, x, y, vez)) return 1; }
                    if(tabuleiro[i][j] == 'c'){ if(renderiza_cavalo(i, j, x, y, vez)) return 1; }
                    if(tabuleiro[i][j] == 'b'){ if(renderiza_bispo(i, j, x, y, vez)) return 1; }
                    if(tabuleiro[i][j] == 'q'){ if(renderiza_rainha(i, j, x, y, vez)) return 1; }
                }
            }
        }
    }
    else if(vez == 2){
        for(i = 0; i <= 7; i++){
            for(j = 0; j <= 7; j++){
                if(tabuleiro[i][j] != ' '){
                    if(tabuleiro[i][j] == 'P'){ if(renderiza_peao(i, j, x, y, vez)) return 1; }
                    if(tabuleiro[i][j] == 'T'){ if(renderiza_torre(i, j, x, y, vez)) return 1; }
                    if(tabuleiro[i][j] == 'C'){ if(renderiza_cavalo(i, j, x, y, vez)) return 1; }
                    if(tabuleiro[i][j] == 'B'){ if(renderiza_bispo(i, j, x, y, vez)) return 1; }
                    if(tabuleiro[i][j] == 'Q'){ if(renderiza_rainha(i, j, x, y, vez)) return 1; }
                }
            }
        }
    }

    return 0;
}

int mate(int x, int y, int vez){
    if(mover_rei(x, y, vez)) return 0;
    else if(renderiza(x, y, vez)) return 0;

    return 1;
}

void jogando(int * x1, int * y1, int * x2, int * y2){
    printf(">> Enter the coordinate of the part you want to play: ");
    scanf("%d %d", x1, y1);
    printf(">> Enter the coordinate of the position where you want to play: ");
    scanf("%d %d", x2, y2);
}

void xeque_and_mate(int kingl, int kingc, int KingL, int KingC, int vez){

    if(vez == 1){
        if(xeque(kingl, kingc, vez)){
            printf("XEQUE ");
            if(mate(kingl, kingc, 1)){
                printf("E MATE!!");
                exit(0);
            }
        }
    }
    else{
        if(xeque(KingL, KingC, vez)){
            printf("XEQUE ");
            if(mate(KingL, KingC, 2)){
                printf("E MATE!!");
                exit(0);
            }
        }
    }
}

int chama_verificacao(int x1, int y1, int x2, int y2, int vez, int  kingl, int  kingc, int  KingL, int  KingC){

    switch(vez){
    case 1:
        if(verifica(x1, y1, x2, y2, vez, kingl, kingc)) return 1;
        break;
    case 2:
        if(verifica(x1, y1, x2, y2, vez, KingL, KingC)) return 1;
        break;
    }

    return 0;
}

int main(){
    int x1, y1, x2, y2, vez = 1;
    int kingl = 7, kingc = 4, KingL = 0, KingC = 4;

    while(1){

        while(1){

            exibetabuleiro();

            xeque_and_mate(kingl, kingc, KingL, KingC, vez);

            jogando(&x1, &y1, &x2, &y2);

            if(chama_verificacao(x1, y1, x2, y2, vez, kingl, kingc, KingL, KingC)){
                if(vez == 1) movimento(x1, y1, x2, y2, &kingl, &kingc);
                else movimento(x1, y1, x2, y2, &KingL, &KingC);
                break;
            }

            system("cls");
        }

        vez == 1 ? vez++ : vez--;
    }
    return 0;
}
