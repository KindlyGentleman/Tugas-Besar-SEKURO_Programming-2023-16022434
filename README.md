# Tugas Besar SEKURO 2023 Programming - Battleship Game

<p>&nbsp;</p>

## Informasi Kelompok dan Tugas
### Kelompok 3
1. (16022434) Muhammad Kamal
    - Melakukan pemrograman secara terpisah dan menggabungkan hasil program dalam satu hasil akhir
    - Mengimplementasikan ide dasar dan strukur sederhana dari program (menu, tampilan peta, dan kelas-kelas dasar kapal)
    - Menuliskan dokumentasi dan README.md

2. (16522131) Evan Arif Ariawan
    - Melakukan pemrograman secara terpisah dan menggabungkan hasil program dalam satu hasil akhir
    - Mengimplementasikan ide gamifikasi dan beberapa fitur kapal agar lebih menarik
    - Menuliskan dokumentasi

3. (13221086) Najmi Azzahra F **(Tidak Aktif)**

4. (19622011) Muhamad Rifki Virziadeili Harisman **(Tidak Aktif)**

<p>&nbsp;</p>

## Latar Belakang Problem

Latar belakang masalah program adalah adanya ancaman serangan dari armada kapal bajak laut Kurohige yang akan menyerang sebuah pulau. Kapten Luffy beserta anggota bajak laut Straw Hat dan Thousand Sunny akan berhadapan langsung dengan kapal Kurohige, namun armada lainnya akan menyerang pulau. Oleh karena itu, Kapten Luffy meminta Franky dan para CAKRU beserta penduduk pulau untuk membuat kapal yang akan menghalangi jalannya armada Kurohige.

<p>&nbsp;</p>

## Requirement and Objective

Program yang dibuat bertujuan untuk membantu Kapten Luffy dan para bajak laut dalam menghadapi serangan dari armada kapal bajak laut Kurohige. Program ini mengizinkan pengguna untuk mengendalikan kapal dan memberikan perintah untuk menyerang, bergerak, atau diam di tempat. Kapal memiliki kemampuan untuk membaca dan menampilkan posisi saat ini, bergerak di empat kuadran pada koordinat kartesian, dan menyerang lawan dengan damage konstan. Selain itu, kapal juga memiliki atribut health dan meriam kapal memiliki jarak tembak maksimum untuk menyerang lawan. Program ini juga memperhitungkan jarak antara kapal dan musuh.

Program ini akan berhenti ketika health kapal mencapai atau kurang dari 0 dan akan mengeluarkan jumlah kapal musuh yang berhasil dikalahkan. Oleh karena itu, para CAKRU dapat menambahkan mekanisme tambahan pada program untuk meningkatkan kemampuan kapal dalam menghadapi serangan dari armada kapal bajak laut Kurohige. Namun, program harus memenuhi spesifikasi yang telah ditetapkan, seperti kapal tidak dapat menabrak lawan dan tidak dapat keluar dari peta.

<p>&nbsp;</p>

## Alur Program / Flowchart

1. Program dimulai dengan meng-import library `iostream`, `cstdlib`, dan `ctime`.
2. Membuat kelas **Ship** yang merepresentasikan kapal dan memiliki beberapa method untuk memanipulasi kapal seperti *attack*, *move*, *getHealth*, dan lain-lain.
3. Kelas **Ship** memiliki atribut berupa koordinat *x* dan *y*, *health*, *max_range*, dan *symbol*.
4. Kelas **PlayerShip** dan **EnemyShip** merupakan turunan dari kelas Ship dan memiliki method tambahan, seperti konstruktor untuk mengatur *symbol* kapal.
5. Pada main program, map diinisialisasi dengan simbol '~' dan dimulai game loop.
6. Pada setiap iterasi game loop, map diprint, input player diterima, dan aksi yang sesuai dilakukan.
7. Jika input player adalah 'A' (attack), program akan melakukan pengecekan range dengan memanggil method *calculateDistance*, jika dalam range, musuh akan diserang dengan memanggil method *attack* pada objek player dan update map.
8. Jika input player adalah 'M' (move), program akan menerima input arah yang dituju dan memanggil method *move* pada objek player. Kemudian, map akan diupdate dengan simbol kapal yang sudah berpindah.
9. Program akan melakukan pengecekan apakah musuh sudah mati (health <= 0). Jika sudah mati, objek *enemy* akan dihapus dan diganti dengan objek baru dengan memanggil konstruktor **EnemyShip** dan update map.
10. Game loop akan berakhir jika health player <= 0.
11. Program selesai.

<p>&nbsp;</p>

## Penjelasan Kode

Secara umum, program ini adalah game sederhana yang menggunakan objek-objek kapal player dan musuh yang direpresentasikan oleh kelas **Ship**. Pada game loop, pemain dapat melakukan aksi seperti *attack* dan *move* untuk mengalahkan musuh. Game loop akan berlanjut sampai kesehatan pemain mencapai 0.

<p>&nbsp;</p>

## Instalasi

Tidak diperlukan instalasi khusus untuk menjalankan program ini.

<p>&nbsp;</p>

## Cara Menggunakan

1. Buka file program battleship.cpp
2. Compile program menggunakan compiler C++ yang tersedia pada komputer Anda
3. Jalankan program yang sudah dicompile
4. Ikuti instruksi yang muncul pada layar untuk bermain game

<p>&nbsp;</p>

## Cara Bermain

Untuk memainkan game ini, ikuti langkah-langkah berikut:

1. Salin program ke dalam file teks dan simpan dengan ekstensi .cpp.
2. Compile program dengan menggunakan compiler C++ yang tersedia di sistem Anda.
3. Jalankan program dengan menjalankan file yang dihasilkan oleh proses kompilasi.
4. Pada saat program dijalankan, Anda akan diminta untuk memasukkan perintah. Pilih perintah yang ingin Anda lakukan dan ikuti instruksi yang diberikan.
5. Ada tiga perintah yang tersedia:
    - 'A' untuk menyerang kapal musuh.
    - 'M' untuk memindahkan kapal Anda ke lokasi yang berbeda.
    - 'S' untuk tetap di tempat dan tidak melakukan apa-apa.
6. Jika Anda memilih perintah 'A', Anda akan diminta untuk memasukkan arah penyerangan. Jika kapal musuh berada dalam jarak serangan yang valid, kapal musuh akan diserang dan kesehatannya akan berkurang. Jika kapal musuh kalah, kapal baru akan muncul di lokasi acak di peta.
7. Jika Anda memilih perintah 'M', Anda akan diminta untuk memasukkan arah pergerakan. Jika pergerakan tidak melewati batas peta, kapal Anda akan dipindahkan ke lokasi yang diminta.
8. Jika Anda memilih perintah 'S', kapal Anda akan tetap di tempat dan tidak melakukan apa-apa.
9. Setelah setiap perintah, peta akan diperbarui dan dicetak di layar bersama dengan lokasi kapal Anda dan kapal musuh.
10. Game akan terus berlanjut sampai kapal Anda kehilangan semua kesehatannya.

Untuk informasi lebih lanjut dan *test case*, silakan pergi ke dokumentasi untuk melihat penjelasan secara teknis.

<p>&nbsp;</p>

## Informasi Tentang Game

1. Setelah program dijalankan, pemain akan melihat peta dengan simbol '~' yang merepresentasikan lautan.
2. Pemain akan mengontrol kapal player yang direpresentasikan dengan simbol 'T'.
3. Kapal musuh direpresentasikan dengan simbol 'M' dan akan muncul pada posisi acak pada awal permainan.
Pemain dapat memilih untuk menyerang musuh dengan input 'A', memindahkan kapal dengan input 'M', atau bertahan dengan input 'S'.
4. Jika pemain berhasil menyerang musuh, maka musuh akan hancur dan akan muncul musuh baru pada posisi acak.
5. Permainan berakhir jika kapal player kehilangan semua health-nya.