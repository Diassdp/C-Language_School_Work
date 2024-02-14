#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char jenis_data[10], nama_data[50];
  int ukuran_data, id;
} fragmen;
typedef struct elmt *alamatelmt;
typedef struct elmt
{
  fragmen kontainer;
  alamatelmt prev;
  alamatelmt next;
} elemen;
typedef struct
{
  elemen *first;
  elemen *tail;
} list;

void createList(list *L)
{
  (*L).first = NULL;
  (*L).tail = NULL;
}

void printElement(list L)
{
  if (L.first != NULL) // jika list tidak kosong
  {
    // inisialisasi
    elemen *bantu = L.first;
    int i = 1;
    while (bantu != NULL)
    {
      // Proses
      printf("==============================\n");
      printf("Elemen ke-%d\n", i);
      printf("Id\t: %d\n", bantu->kontainer.id);
      printf("Nama Data\t: %s\n", bantu->kontainer.nama_data);
      printf("Jenis Data\t: %s\n", bantu->kontainer.jenis_data);
      printf("Data Size\t: %d\n", bantu->kontainer.ukuran_data);
      printf("==============================\n");
      bantu = bantu->next;
      i++;
    }
  }
  else
  {
    // jika list kosong
    printf("List kosong\n");
  }
}

int countElement(list L)
{
  int hasil = 0;
  if (L.first != NULL)
  {
    elemen *bantu;
    bantu = L.first;
    while (bantu != NULL)
    {
      // proses
      hasil += 1;
      bantu = bantu->next;
    }
  }
  return hasil;
}

int checkNameData(char nama_data[], list L)
{
  int hasil = 0;
  if (L.first != NULL)
  {
    elemen *bantu;
    bantu = L.first;
    while (bantu != NULL)
    {
      if (strcmp(bantu->kontainer.nama_data, nama_data) == 0)
      {
        hasil = 1;
        break;
      }
      bantu = bantu->next;
    }
  }
  return hasil;
}

void addFirst(char nama_data[], char jenis_data[], int ukuran_data, int id, list *L)
{
  if (checkNameData(nama_data, *L) == 0)
  {
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nama_data, nama_data);
    strcpy(baru->kontainer.jenis_data, jenis_data);
    baru->kontainer.ukuran_data = ukuran_data;
    baru->kontainer.id = id;

    if ((*L).first == NULL)
    {
      baru->next = NULL;
      (*L).tail = baru;
    }
    else
    {
      // jika list tidak kosong
      baru->next = (*L).first;
      (*L).first = baru;
    }

    baru->prev = NULL;
    (*L).first = baru;
    baru = NULL;
  }
  else
  {
    printf("Mohon maaf, nama data tidak boleh sama!\n");
  }
}

void addAfter(elemen *before, char nama_data[], char jenis_data[], int ukuran_data, int id, list *L)
{
  if (before != NULL && checkNameData(nama_data, *L) == 0)
  {
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nama_data, nama_data);
    strcpy(baru->kontainer.jenis_data, jenis_data);
    baru->kontainer.ukuran_data = ukuran_data;
    baru->kontainer.id = id;

    if (before->next == NULL)
    {
      baru->next = NULL;
      (*L).tail = baru;
    }
    else
    {
      baru->next = before->next;
      baru->next->prev = baru;
    }
    baru->prev = before;
    before->next = baru;
    baru = NULL;
  }
}

void delFirst(list *L)
{
  if ((*L).first != NULL)
  {
    // list tidak kosong
    elemen *hapus = (*L).first;
    if (countElement(*L) == 1)
    {
      (*L).first = NULL;
      (*L).tail = NULL;
    }
    else
    {
      (*L).first = (*L).first->next;
      (*L).first->prev = NULL;
    }
    hapus->next = NULL;
    free(hapus);
  }
  else
  {
    printf("List kosong \n");
  }
}

void delAfter(elemen *before, list *L)
{
  if (before != NULL)
  {
    elemen *hapus = before->next;

    if (hapus != NULL)
    {
      if (hapus->next == NULL)
      {
        before->next = NULL;
        (*L).tail = before;
      }
      else
      {
        before->next = hapus->next;
        hapus->next->prev = before;
      }
      hapus->prev = NULL;
      hapus->next = NULL;
      free(hapus);
    }
  }
}

void delLast(list *L)
{
  if ((*L).first != NULL)
  {
    if (countElement(*L) == 1)
    {
      delFirst(L);
    }
    else
    {
      delAfter((*L).tail->prev, L);
    }
  }
}

void editData(list *L)
{
  char nama_data[50], jenis_data[50];
  int ukuran_data, id;
  elemen *bantu = L->first;
  printf("ENTER DATA ID TO EDIT: ");scanf("%d", &id);
  while (bantu != NULL)
  {
    if (id == bantu->kontainer.id)
    {
      fflush(stdin);
      printf("Nama data : ");
      gets(nama_data);
      printf("Jenis data : ");
      gets(jenis_data);
      printf("Ukuran data : ");
      scanf("%d", &ukuran_data);
      strcpy(bantu->kontainer.nama_data, nama_data);
      strcpy(bantu->kontainer.jenis_data, jenis_data);
      bantu->kontainer.ukuran_data = ukuran_data;
    }
    bantu = bantu->next;
  }
}

void sortJenisData(list *L)
{
  // list tidak kosong
  if ((*L).first != NULL)
  {
    elemen *bantu;
    bantu = (*L).first;
    int i = 1;
    char jenis_data[15];
    printf("jenis data yang dicari : ");
    fflush(stdin);gets(jenis_data);
    while (bantu != NULL)
    {
      if (strcmp(bantu->kontainer.jenis_data, jenis_data) == 0)
      {
        // Proses
        printf("=========================================\n");
        printf("Elemen ke-%d\n", i);
        printf("ID\t: %d\n", bantu->kontainer.id);
        printf("Nama Data\t: %s\n", bantu->kontainer.nama_data);
        printf("Jenis Data\t: %s\n", bantu->kontainer.jenis_data);
        printf("Data Size\t: %d\n", bantu->kontainer.ukuran_data);
        printf("=========================================\n");
		i++;
      }
      bantu = bantu->next;
    }
  }
}

void printSmallestSize(list *L)
{
  elemen *bantu;
  elemen *bantu2;
  elemen *pindah;
  bantu = (*L).first;
  bantu2 = bantu->next;
  pindah = bantu2;
  int temp;
  while (pindah != NULL)
  {
    if (bantu->kontainer.ukuran_data > bantu2->kontainer.ukuran_data)
    {
      bantu->kontainer = bantu2->kontainer;
    }
    bantu2 = bantu2->next;
    pindah = pindah->next;
  }
  printf("===================================\n");
  printf("ID\t: %d\n", bantu->kontainer.id);
  printf("Nama Data\t: %s\n", bantu->kontainer.nama_data);
  printf("Jenis Data\t: %s\n", bantu->kontainer.jenis_data);
  printf("Data Size\t: %d\n", bantu->kontainer.ukuran_data);
  printf("===================================\n");
}

void printLargestSize(list *L)
{
  elemen *bantu;
  elemen *bantu2;
  elemen *pindah;
  bantu = (*L).first;
  bantu2 = bantu->next;
  pindah = bantu2;
  int temp;
  while (pindah != NULL)
  {
    if (bantu->kontainer.ukuran_data < bantu2->kontainer.ukuran_data)
    {
      bantu->kontainer = bantu2->kontainer;
    }
    bantu2 = bantu2->next;
    pindah = pindah->next;
  }
  printf("=========================================\n");
  printf("ID\t: %d\n", bantu->kontainer.id);
  printf("Nama Data\t: %s\n", bantu->kontainer.nama_data);
  printf("Jenis Data\t: %s\n", bantu->kontainer.jenis_data);
  printf("Data Size\t: %d\n", bantu->kontainer.ukuran_data);
  printf("=========================================\n");
}

void addLast(char nama_data[], char jenis_data[], int ukuran_data, int id, list *L)
{
  if ((*L).first == NULL)
  {
    addFirst(nama_data, jenis_data, ukuran_data, id, L);
  }
  else
  {
    addAfter((*L).tail, nama_data, jenis_data, ukuran_data, id, L);
  }
}

int main(int argc, char const *argv[])
{
  list L;
  createList(&L);
  char nama_data[50], jenis_data[50];
  int ukuran_data, pilihan, id = 0;
  while(1){
  printf("\n===========[SIMULASI FRAGMENTASI HARDDISK MENU]===========\n");
  printf("1.Input Data Baru\n2.Delete Data First\n3.Delete Data Last\n4.Edit Data\n5.Cari Berdasarkan Jenis Data\n6.Ukuran Data Terbesar\n7.Ukuran Data Terkecil\n8.Print Fragmen\n9.Exit\n");
  printf("Masukan Pilihan: ");scanf("%d", &pilihan);
  switch (pilihan)
  {
  	case 1://input data
    printf("===[Data baru]===\n");
    fflush(stdin);
    printf("Nama Data:");gets(nama_data);
    printf("Jenis Data:");gets(jenis_data);
    printf("Data Size:");scanf("%d", &ukuran_data);
    addLast(nama_data, jenis_data, ukuran_data, id, &L);
    id++;break;   
    
  	case 2://Delete Data Pertama
    delFirst(&L);printElement(L);break; 
	  
  	case 3://Delete Data terakhir
	delLast(&L);printElement(L);break; 
    
  	case 4://Edit Data List
    editData(&L);break;
    
  	case 5://Seaarch melalui jenis data
    sortJenisData(&L);break;
    
  	case 6://Print Ukuran Terbesar dalam List
    printLargestSize(&L);break;
    
  	case 7://Print Ukuran Terkecil dalam List
    printSmallestSize(&L);break;
    
  	case 8://Print List 
    printElement(L);break;
    
  	case 9://Exit
    exit(0);break;
    
  	default:
    printf("Pilihan Tidak ada Dalam Pilihan\n");break;
  }
}return 0;
}
