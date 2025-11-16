#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Buku {
    char judul[100];
    char penulis[100];
    char penerbit[100];
    char genre[50];
    int tahun;
    int halaman;
};

int main() {
    struct Buku data[50];
    int n, i;
    FILE *fp;

    printf("=============================================\n");
    printf("        PROGRAM DATA BUKU PERPUSTAKAAN       \n");
    printf("=============================================\n");
    printf("Masukkan jumlah buku yang ingin didata: ");
    scanf("%d", &n);
    getchar(); // Membersihkan buffer

    for (i = 0; i < n; i++) {
        printf("\n--- Data Buku ke-%d ---\n", i + 1);
        printf("Judul Buku        : ");
        fgets(data[i].judul, sizeof(data[i].judul), stdin);
        data[i].judul[strcspn(data[i].judul, "\n")] = 0;

        printf("Nama Penulis      : ");
        fgets(data[i].penulis, sizeof(data[i].penulis), stdin);
        data[i].penulis[strcspn(data[i].penulis, "\n")] = 0;

        printf("Nama Penerbit     : ");
        fgets(data[i].penerbit, sizeof(data[i].penerbit), stdin);
        data[i].penerbit[strcspn(data[i].penerbit, "\n")] = 0;

        printf("Genre Buku        : ");
        fgets(data[i].genre, sizeof(data[i].genre), stdin);
        data[i].genre[strcspn(data[i].genre, "\n")] = 0;

        printf("Tahun Terbit      : ");
        scanf("%d", &data[i].tahun);
        printf("Jumlah Halaman    : ");
        scanf("%d", &data[i].halaman);
        getchar();
    }

    // Menulis data ke file menggunakan fprintf
    fp = fopen("data_buku.txt", "w");
    if (fp == NULL) {
        printf("Gagal membuka file untuk menulis!\n");
        return 1;
    }

    fprintf(fp, "===============================================================\n");
    fprintf(fp, "                    DATA BUKU PERPUSTAKAAN                     \n");
    fprintf(fp, "===============================================================\n");
    fprintf(fp, "%-3s %-25s %-20s %-15s %-8s %-8s\n", "No", "Judul", "Penulis", "Genre", "Tahun", "Halaman");
    fprintf(fp, "----------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        fprintf(fp, "%-3d %-25s %-20s %-15s %-8d %-8d\n", 
                i + 1, data[i].judul, data[i].penulis, data[i].genre, data[i].tahun, data[i].halaman);
    }

    fclose(fp);

    // Menampilkan hasil ke layar dengan format rapi
    printf("\n===============================================================\n");
    printf("                    DATA BUKU PERPUSTAKAAN                     \n");
    printf("===============================================================\n");
    printf("%-3s %-25s %-20s %-15s %-8s %-8s\n", "No", "Judul", "Penulis", "Genre", "Tahun", "Halaman");
    printf("----------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-3d %-25s %-20s %-15s %-8d %-8d\n", 
                i + 1, data[i].judul, data[i].penulis, data[i].genre, data[i].tahun, data[i].halaman);
    }

    printf("\nData buku berhasil disimpan ke file 'data_buku.txt'.\n");
    return 0;
}
