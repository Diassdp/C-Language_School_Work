#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Node{
    int data;
    Node *kiri;
    Node *kanan;
    Node *pohon;
}Node;

Node *pohon = NULL;

void tambah(Node **root, int databaru){
    if((*root)==NULL){
     Node *baru;
     baru = new Node;
     baru->data=databaru;
     baru->kiri=NULL;
     baru->kanan=NULL;
     (*root)=baru;
     (*root)->kiri=NULL;
     (*root)->kanan=NULL;
     printf("Kamar terbooking!");
    }
    else
        if(databaru<(*root)->data){
        tambah(&(*root)->kiri,databaru);
    }
    else
        if(databaru>(*root)->data){
        tambah(&(*root)->kanan,databaru);
    }
    else
        printf("Maaf Kamar sudah dibooking!");
}

void lihatdata(Node *root){
    if(root != NULL){
        lihatdata(root->kiri);
        if(root->data!=NULL){
            printf("%d", root->data);
        }
        lihatdata(root->kanan);
    }
}

void searchdata(Node**root, int cari){
    if((*root)==NULL){
        printf("Nomor kamar tidak terdaftar");
    }
    else
        if(cari<(*root)->data)
            searchdata(&(*root)->kiri,cari);
    else
        if(cari>(*root)->data)
            searchdata(&(*root)->kanan,cari);
    else
        printf("Nomor kamar yang dicari telah dibooking");
}

int count(Node *root){
    if(root==NULL){
        return 0;
    }
    else
        return count(root->kiri)+count(root->kanan)+1;
}

int height(Node*root){
    if(root==NULL){
        return -1;
    }
    else {
        int u = height(root->kiri);
        int v = height(root->kanan);
        if(u > v)
            return u+1;
        else
            return v+1;
    }
}

void hapus(Node **root, int del){
    Node *curr;
    Node *parent;
    curr = (*root);

    bool flag = false;

    while(curr != NULL){
        if(curr->data == del){
            flag = true;
            printf("Nomor kamar ditemukan!");
            break;
        }
        else{
            parent = curr;
            if(del>curr->data)
                curr = curr->kanan;
            else
                curr = curr->kiri;
        }
    }
    if(!flag){
        printf("Data tidak ditemukan. Penghapusan tidak bisa dilakukan");
        return;
    }

    if(height(pohon)==0){
        if(curr->kiri==NULL && curr->kanan==NULL){
            (*root) = NULL;
            return;
        }
    }
    else
    if(height(pohon)>0){
        if(curr->kiri==NULL && curr->kanan==NULL){
            parent->kiri = NULL;
            delete curr;
        }
        else {
            parent->kanan = NULL;
            delete curr;
        }
    return;
    }
    if((curr->kiri==NULL &&curr->kanan!=NULL)||curr->kiri!=NULL&&curr->kanan==NULL){
        if(curr->kiri==NULL && curr->kanan!=NULL){
            if(parent->kiri==curr){
                parent->kiri = curr->kanan;
                delete curr;
            }
            else{
                parent->kanan = curr->kanan;
                delete curr;
            }
        }
     else{
        if(parent->kiri==curr){
            parent->kiri = curr->kiri;
            delete curr;
        }
        else{
            parent->kanan = curr->kiri;
            delete curr;
        }
      }
      return;

    if(curr->kiri!=NULL&&curr->kanan!=NULL){
        Node *bantu;
        bantu = curr->kanan;
            if((bantu->kiri==NULL)&&(bantu->kanan==NULL)){
                curr = bantu;
                delete bantu;
                curr->kanan = NULL;
            }
            else{
               if((curr->kanan)->kiri!=NULL){
                Node *bantu2;
                Node *bantu3;
                bantu3 = curr->kanan;
                bantu2 = (curr->kanan)->kiri;
                while(bantu2->kiri!=NULL){
                    bantu3=bantu2;
                    bantu2=bantu2->kiri;
                }
                curr->data = bantu2->data;
                delete bantu2;
                bantu3->kiri = NULL;
               }
               else
               {
                Node *tmp;
                tmp= curr->kanan;
                curr->data = tmp->data;
                curr->kanan = tmp->kanan;
                delete tmp;
               }
            }
            return;
        }
    }
}

int main(){
    int pil;
    int del,cari;
    int data;
    while(1)
{
        system("cls");
        printf("\t#PROGRAM PENGGELOLAAN DATA PENGGUNJUNG HOTEL#");
        printf("\n\t=======================================");
        printf("\nMENU");
        printf("\n----\n");
        printf("[1]Tambah nomor kamar untuk membooking kamar\n");
        printf("[2]Lihat data\n");
        printf("[3]Delete\n");
        printf("[4]Kosongkan Data\n");
        printf("[5]Search\n");
        printf("[6]Jumlah Kamar terbooking\n");
        printf("[X]Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d",&pil);
    switch(pil)
    {
    case 1:
      {printf("\nINPUT: ");
        printf("\n-------");
        printf("\nMasukkan nomor kamar(01-99): ");
        scanf("%d",&data);
        tambah(&pohon,data);
        getchar();
        break;}
    case 2:
       { printf("\nLIHAT DATA: ");
        printf("\n------------");
        if(pohon!=NULL){
            lihatdata(pohon);
        }
        else
            printf("Masih Kosong!!");
        getchar();
        break;}
      case 3:
        { if(pohon!=NULL){
        printf("\nSEBELUM NOMOR KAMAR DIHAPUS: ");
        printf("\n-----------------------------");
        printf("\nDATA: ");
        lihatdata(pohon);
        printf("\n\nPENGHAPUSAN DATA: ");
        printf("\n------------------\n");
        printf("Masukkan nomor kamar yang ingin dihapus: ");
        scanf("%d", &del);

        hapus(&pohon,del);
        printf("\n\nSETELAH NOMOR KAMAR DIHAPUS: ");
        printf("\n-------------------------------");
        printf("\nDATA: ");
        lihatdata(pohon);
        }
        else
            printf("\nMASIH Kosong!");
            getchar();
            break;}
      case 4:
       { pohon=NULL;
        printf("\nPENGOSONGAN NOMOR KAMAR");
        printf("\n-----------------------");
        printf("\nData sudah dikosongkan!");

        getchar();
        break;
}
      case 5:
        {printf("\nOUTPUT->hanya untuk mengecek apakah data dimaksud terdapat dalam bookingan kamar hotel");
        printf("\n------------------------");
        if(pohon!=NULL){
            printf("\nDATA: ");
            lihatdata(pohon);
            printf("\n\nPENCARIAN DATA");
            printf("\n----------------");
            printf("\nMasukkan data yang ingin dicari: ");
            scanf("%d",&cari);
            searchdata(&pohon,cari);
        }
        else
            printf("\nMasih Kosong!");

        getchar();
        break;
}
      case 6:
      {  printf("\nJUMLAH KAMAR YANG TERBOOKING");
        printf("\n----------------------------");
        printf("\nJumlah Node: %d", count(pohon));
        getchar();
        break;
    case'X'|'x':
        exit(0);
        break;}
    }
}
}
