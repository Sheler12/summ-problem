#include "iostream"
#include "math.h"
#include <stdio.h>
#include <time.h>
#include <fstream>

using namespace std;

struct combined {
    string array_;
    int quan;
    int maxim;
};

const int base = 85;
const int n = 9;
const int arr_def_size = 200;
int now_in_rec [n + 1] = {};
int glob_counter = 0;


int BinSearch(int arr[], int count_, int key);
void rec_func_copy( int free_num [], int start_int, int arr_size, int limit, int depth);
void rec_func (int free_num [], int start_int, int arr_size, int limit, int depth);
int and_merge (int input[],int arr_size ,int shift, int output[]);

ofstream fout;


int main(){
    fout.open ("c:\\C++\\Files\\prob.txt");
    if (!fout) {
        cout << "Файл не открыт\n\n";
        for (int i = 0; i < 100; i--);
        return -1;
    }
    int data [arr_def_size] = {};
    for (int i = 0; i < arr_def_size - 1; i++){
        data [i] = i + 1;
    }
    now_in_rec [0] = 1;
    rec_func_copy (data, 1, arr_def_size - 1, base, 0);
    /*int data[] = {1 , 2 , 3, 5, 7, 10, 13 , 15};
    int data2 [8] = {};
    std::cout << and_merge(data, 8, 3, data2) << "\n";
    for (int i = 0; i < 8; i++){
        std::cout << data2[i] << " ";
    }*/
}

void rec_func_copy (int free_num [], int start_int, int arr_size, int limit, int depth){
    int start_place = BinSearch(free_num, arr_size, start_int);
    int index_of_max = -1;
    int transl [arr_def_size];
    int tr_size;
    if (arr_size != 0){
        for (int i = start_place; free_num [i] < limit; i++){
            std::cout << free_num[i] << " ";
            time_t seconds = time(NULL);
            tm* timeinfo = localtime(&seconds);
            cout << (*timeinfo).tm_hour << ":";
            if ((*timeinfo).tm_min < 10){
                cout << 0 <<(*timeinfo).tm_min;
            }else{
                cout <<(*timeinfo).tm_min;
            }
            if ((*timeinfo).tm_sec < 10){
                cout << ":" << 0 <<(*timeinfo).tm_sec << "\n";
            }else{
                cout << ":" <<(*timeinfo).tm_sec << "\n";
            }
            tr_size = and_merge(free_num, arr_size, free_num[i], transl);
            now_in_rec [depth] = free_num [i];
            rec_func (transl, free_num[i] + 1, tr_size, limit, depth + 1);
            now_in_rec [depth] = -1;
        }
    }
    if (depth == n - 1){
        glob_counter++;
        for (int i = 0; i < n - 1; i++){
            fout << now_in_rec [i] << " ";
        }
        fout << "\n";
    }
}

void rec_func (int free_num [], int start_int, int arr_size, int limit, int depth){
    int start_place = BinSearch(free_num, arr_size, start_int);
    int index_of_max = -1;
    int transl [arr_def_size];
    int tr_size;
    if (arr_size != 0){
        for (int i = start_place; free_num [i] < limit; i++){
            tr_size = and_merge(free_num, arr_size, free_num[i], transl);
            now_in_rec [depth] = free_num [i];
            rec_func (transl, free_num[i] + 1, tr_size, limit, depth + 1);
            now_in_rec [depth] = -1;
        }
    }
    if (depth == n - 1){
        glob_counter++;
        for (int i = 0; i < n - 1; i++){
            fout << now_in_rec [i] << " ";
        }
        fout << "\n";
        cout << glob_counter <<"\n";
    }
    string str;
    if (index_of_max != -1){
        str = " " + to_string(free_num [index_of_max]);
    }else{
        str = "";
    }
}

int BinSearch(int arr [], int border, int key) {
  int l = 0;
  int u = border - 1;
  int m;
  while (l <= u) {
    m = (l + u) / 2;
    if (arr[m] == key) return m;
    if (arr[m] < key) l = m + 1;
    if (arr[m] > key) u = m - 1;
  }
  return l;
}

int and_merge (int input[],int arr_size ,int shift, int output[]){
    int auxiliary [arr_def_size] = {};
    int counter_au = 0;
    int counter_out = 0;
    for (int i = 0; i < arr_size; i++){
        auxiliary [input [i]] = 1;
    }
    int flag = 0;
    int k = 0;
    int i = 1;
    for (int i = 0; i < arr_size; i++){
        flag = 0;
        k = input[i];
        if (k + shift < arr_def_size){
            if (auxiliary [k + shift] == 0){
                flag = 1;
            }
        }
        if (flag == 0){
            if (auxiliary [abs(k - shift)] == 0){
                flag = 1;
            }
        }
        if (flag == 0){
            output [counter_out] = k;
            counter_out++;
        }
    }

    return counter_out;
}

