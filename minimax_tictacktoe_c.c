#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Yazan: Emine TİLKİ
    Tarih: 09.06.2025
    Açıklama: Minimax algoritmasıyla çalışan basit bir X-O (Tic Tac Toe) oyunu.
              Oyuncu X, bilgisayar O oynar. Eğlenin :)
*/

void tahtaYazdir(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" ");
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

// Kazananı kontrol eder. X ya da O döner. Yoksa '-' döner.
char kazananVarMi(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Satır kontrol
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        // Sütun kontrol
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Çapraz kontrol
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return '-';
}

// Skoru hesaplar: O = bilgisayar, X = oyuncu
int puanla(char board[3][3]) {
    char kazanan = kazananVarMi(board);
    if (kazanan == 'O') return +10;
    if (kazanan == 'X') return -10;
    return 0;
}

int minimax(char board[3][3], int depth, int isMax) {
    int skor = puanla(board);

    // Kazanma durumlarında erken dönüş
    if (skor == 10) return skor - depth;
    if (skor == -10) return skor + depth;

    // Hamle kalmadıysa berabere
    int hamleVar = 0;
    for (int i = 0; i < 3 && !hamleVar; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '-') hamleVar = 1;

    if (!hamleVar) return 0;

    // Maksimum veya minimum puanı hesapla
    if (isMax) {
        int enIyi = -1000;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                    int deger = minimax(board, depth + 1, 0);
                    board[i][j] = '-';
                    if (deger > enIyi) enIyi = deger;
                }
        return enIyi;
    } else {
        int enIyi = 1000;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == '-') {
                    board[i][j] = 'X';
                    int deger = minimax(board, depth + 1, 1);
                    board[i][j] = '-';
                    if (deger < enIyi) enIyi = deger;
                }
        return enIyi;
    }
}

// Bilgisayarın en iyi hamlesini bul
void bilgisayarHamlesi(char board[3][3], int *row, int *col) {
    int enIyiDeger = -1000;
    *row = -1;
    *col = -1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '-') {
                board[i][j] = 'O';
                int deger = minimax(board, 0, 0);
                board[i][j] = '-';

                if (deger > enIyiDeger) {
                    enIyiDeger = deger;
                    *row = i;
                    *col = j;
                }
            }
}

int main() {
    char board[3][3];
    int hamleSayisi = 0;
    char kazanan = '-';

    // Tahtayı temizle
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '-';

    srand(time(NULL)); // Rastgele için, gerekirse

    printf("XO Oyununa Hoş Geldiniz! Siz X, bilgisayar O.\n");

    while (hamleSayisi < 9 && kazanan == '-') {
        tahtaYazdir(board);

        int satir, sutun;
        do {
            printf("Hamlenizi girin (satır ve sütun 0-2 arası):\n");
            printf("Satır: ");
            scanf("%d", &satir);
            printf("Sütun: ");
            scanf("%d", &sutun);
        } while (satir < 0 || satir > 2 || sutun < 0 || sutun > 2 || board[satir][sutun] != '-');

        board[satir][sutun] = 'X';
        hamleSayisi++;
        kazanan = kazananVarMi(board);
        if (kazanan != '-' || hamleSayisi >= 9) break;

        int compRow, compCol;
        bilgisayarHamlesi(board, &compRow, &compCol);
        board[compRow][compCol] = 'O';
        printf("Bilgisayar (%d, %d) oynadı.\n", compRow, compCol);
        hamleSayisi++;
        kazanan = kazananVarMi(board);
    }

    tahtaYazdir(board);

    if (kazanan == '-') {
        printf("Oyun berabere!\n");
    } else {
        printf("Kazanan: %c\n", kazanan);
    }

    return 0;
}