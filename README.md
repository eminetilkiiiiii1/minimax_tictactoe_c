 ❌⭕️ Tic Tac Toe - Minimax Algoritması ile Yapay Zeka (C Dili)

Bu proje, C programlama diliyle yazılmış basit bir *X-O (Tic Tac Toe)* oyunudur. Bilgisayar oyuncusu, kazanma olasılığına göre en iyi hamleyi seçmek için *Minimax algoritması* kullanır.

---

## 🧠 Özellikler

- Tek oyunculu (kullanıcı vs. bilgisayar)
- Bilgisayar Minimax algoritması ile oynar
- Terminal tabanlı arayüz
- Hatalı giriş kontrolü
- Kazanma, beraberlik ve oyun sonu mesajları

---

## 🎮 Oynanış

1. Program başlatılır.
2. Oyuncu X bilgisayar O seçer.
3. Oyun sırayla devam eder.
4. Bilgisayar en iyi hamleyi hesaplayarak oynar.
5. Oyun bittiğinde skor gösterilir.

---

## 🚀 Derleme ve Çalıştırma

### 🔧 Gereksinimler
- GCC derleyici (Linux / Mac / Windows için MinGW)

### 💻 Terminal Komutları

```bash
gcc main.c -o xo
./xo


---

🧪 Örnek Çıktı

1 | 2 | 3
    -----------
     4 | X | 6
    -----------
     7 | O | 9

Bilgisayarın hamlesi: 8


---

🧩 Algoritma: Minimax

Minimax algoritması, oyun ağacını gezerek en iyi stratejiyi belirler. Bilgisayar, maksimum kazancı hedeflerken oyuncunun minimum kaybını varsayar. Beraberlik en kötü senaryo olarak kabul edilir.


---

