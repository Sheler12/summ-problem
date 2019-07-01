#include "iostream"
#include "math.h"

using namespace std;

struct combined {
    string array_;
    int quan;
};


int BinSearch(int arr[], int count_, int key);
combined rec_func (int free_num [], int start_int, int arr_size, int limit);
int and_merge (int input[],int arr_size ,int shift, int output[]);

const int arr_def_size = 2000;

int main(){
    int data [arr_def_size] = {};
    for (int i = 0; i < 1000; i++){
        data [i] = i - 1000;
    }
    for (int i = 1000; i < 2000; i++){
        data [i] = i - 999;
    }
    combined temp  = rec_func (data, 1, 2000, 88);
    std::cout << temp.quan << "\n" << temp.array_;
}


combined rec_func (int free_num [], int start_int, int arr_size, int limit){
    int start_place = BinSearch(free_num, arr_size, start_int);
    combined max_;
    int index_of_max = -1;
    max_.array_ = "";
    max_.quan = 0;
    for (int i = start_place; free_num [i] < limit; i++){
        int transl [arr_def_size] = {};
        int tr_size = and_merge(free_num, arr_size, free_num[i], transl);
        combined now = rec_func (transl, free_num[i] + 1, tr_size, limit);
        if (now.quan > max_.quan){
            max_ = now;
            index_of_max = i;
        }
    }
    string str;
    if (index_of_max != -1) str = " " + to_string(free_num [index_of_max]);
    else str = "";
    max_.quan++;
    max_.array_ = max_.array_ + str;
    return max_;
}

int BinSearch(int arr [], int border, int key) {
  int l = 0;
  int u = border - 1;
  while (l <= u) {
    int m = (l + u) / 2;
    if (arr[m] == key) return m;
    if (arr[m] < key) l = m + 1;
    if (arr[m] > key) u = m - 1;
  }
  return l;
}

int and_merge (int input[],int arr_size ,int shift, int output[]){
    int auxiliary1 [arr_def_size] = {};
    int auxiliary2 [arr_def_size] = {};
    int temp_container [arr_def_size] = {};
    int counter_a1 = 0;
    int counter_a2 = 0;
    int counter_temp = 0;
    int counter_inp = 0;
    int counter_out = 0;
    for (int i = 0; i < arr_size; i++){
        auxiliary1 [i] = input [i] + shift;
        auxiliary2 [i] = input [i] - shift;
    }
    while ((counter_a1 != arr_size) and (counter_a2 != arr_size)){
        if (auxiliary1[counter_a1] > auxiliary2[counter_a2]){
            counter_a2++;
        }else{
            if (auxiliary1[counter_a1] < auxiliary2[counter_a2]){
                counter_a1++;
            }else{
                temp_container [counter_temp] = auxiliary1[counter_a1];
                counter_temp++;
                counter_a1++;
                counter_a2++;

            }
        }
    }
    int temp_size = counter_temp;
    counter_temp = 0;
    while ((counter_temp != temp_size) and (counter_inp != arr_size)){
        if (temp_container[counter_temp] > input[counter_inp]){
            counter_inp++;
        }else{
            if (temp_container[counter_temp] < input[counter_inp]){
                counter_temp++;
            }else{
                output [counter_out] = input[counter_inp];
                counter_temp++;
                counter_inp++;
                counter_out++;
            }
        }
    }
    return counter_out;
}
