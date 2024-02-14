#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//isi kontainer pada elemen(node)
typedef struct{
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaiMatkul;

//Mendeklarasikan struktur data elemen
typedef struct elmt *alamatelmt;
typedef struct elmt{
    nilaiMatkul kontainer;
    alamatelmt prev;
    alamatelmt next;
}elemen;

//membuat list ganda
typedef struct{
    elemen *first;
    elemen *tail;
}list;

void createList(list *L){
    (*L).first=NULL;
    (*L).tail=NULL;
}

void printElement(list L){
    if(L.first != NULL){
            //jika list tidak kosong
            //inisialisasi
            elemen *bantu=L.first;
            int i=1;

            while(bantu != NULL){
                //proses
                printf("elemen ke : %d\n", i);
                printf("NIM   \t: %s\n", bantu->kontainer.nim);
                printf("Nama  \t: %s\n", bantu->kontainer.nama);
                printf("Nilai \t: %s\n", bantu->kontainer.nilai);
                printf("-------------------------------------\n");

                //iterasi
                bantu = bantu->next;
                i=i+1;
            }
    }else{
        //jika list kosong
        printf("List Kosong\n");
    }
}

void addFirst(char nim[], char nama[], char nilai[], list *L){
    elemen *baru;
    baru=(elemen *) malloc(sizeof(elemen));

    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);

    if((*L).first==NULL){
        //jika list kosong
        baru->next=NULL;
        (*L).tail=baru;
    }else{
        //jika list tidak kosong
        baru->next=(*L).first;
        (*L).first=baru;
    }
    baru->prev=NULL;
    (*L).first=baru;
    baru=NULL;
}

void addAfter(elemen *before, char nim[], char nama[], char nilai[], list *L){
    if(before != NULL){
        elemen *baru;
        baru=(elemen *) malloc(sizeof(elemen));

        strcpy(baru->kontainer.nim, nim);
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.nilai, nilai);

        if(before->next==NULL){
            baru->next=NULL;
            (*L).tail=baru;
        }else{
            baru->next=before->next;
            baru->next->prev=baru;
        }
        baru->prev=before;
        before->next=baru;
        baru=NULL;
    }
}

void addLast(char nim[], char nama[], char nilai[], list *L){
    if((*L).first==NULL){
        //list kosong
        addFirst(nim, nama, nilai, L);
    }else{
        addAfter((*L).tail, nim, nama, nilai, L);
    }
}
int countElemen(list L){
    int hasil= 0;
    if(L.first != NULL){
        //tidak kosong
        elemen *bantu;
        bantu=L.first;
        while(bantu != NULL){
            //proses
            hasil=hasil+1;
            //iterasi
            bantu=bantu->next;
        }
    }
}

void delFirst(list *L){
    if((*L).first != NULL){
            //list tidak kosong
        elemen *hapus = (*L).first;
        if(countElemen(*L) == 1){
            (*L).first=NULL;
            (*L).tail=NULL;
        }else{
            (*L).first=(*L).first->next;
            (*L).first->prev=NULL;
        }
        hapus->next=NULL;
        free(hapus);
    }else{
        printf("List Kosong\n");
    }
}

int main(){
    list L;

    createList(&L);
    printElement(L);
    printf("=============================\n");
    addFirst("136", "Nana", "A", &L);
    addFirst("200", "Budi", "A", &L);
    addAfter(L.first->next, "135", "Iza", "A", &L);
    addAfter(L.first->next->next, "300", "Ari", "A", &L);
    addLast("137", "Rara", "A", &L);
    printElement(L);
    printf("=============================\n");
    delFirst(&L);
    printElement(L);
    return 0;
}
