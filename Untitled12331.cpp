#include "iostream"
#include "math.h"

using namespace std;

struct combined {
    string array_;
    int quan;
    int maxim;
};

const int base = 87;
const int n = 10;
const int arr_def_size = 1500;


int BinSearch(int arr[], int count_, int key);
combined rec_func (int free_num [], int start_int, int arr_size, int limit);
int and_merge (int input[],int arr_size ,int shift, int output[]);


int main(){
    int data [arr_def_size] = {};
    for (int i = 0; i < arr_def_size/2; i++){
        data [i] = i - arr_def_size/2;
    }
    for (int i = arr_def_size/2; i < arr_def_size; i++){
        data [i] = i - arr_def_size/2 + 1;
    }
    for (int i = 0; i < arr_def_size; i++){
        //std::cout << data [i] << " ";
    }
    combined temp  = rec_func (data, 1, arr_def_size, base);
    std::cout <<temp.quan << "\n" ;
    for (int i = 1; i < temp.array_.size(); i++){
        std::cout << temp.array_[i];
    }
    std::cout << "\n" << temp.maxim;

}


combined rec_func (int free_num [], int start_int, int arr_size, int limit){
    //std::cout << "Entered:";
    for (int i = 0; i < arr_size; i++){
        //std::cout << free_num [i] << " ";
    }
    //std::cout <<"\n";
    int start_place = BinSearch(free_num, arr_size, start_int);
    combined max_;
    int index_of_max = -1;
    max_.array_ = "";
    max_.quan = 0;
    for (int i = start_place; free_num [i] < limit; i++){
        int transl [arr_def_size] = {};
        int tr_size = and_merge(free_num, arr_size, free_num[i], transl);
        //std::cout << "Gone with " << free_num [i] <<"\n";
        combined now = rec_func (transl, free_num[i] + 1, tr_size, limit);
        if (now.quan >= max_.quan){
            if (now.quan > max_.quan){
                max_ = now;
                index_of_max = i;
            }else{
                if (now.maxim < max_.maxim){
                    max_ = now;
                    index_of_max = i;
                }
            }
        }
    }
    string str;
    if (index_of_max != -1){
            str = " " + to_string(free_num [index_of_max]);
    }else{
        str = "";
    }
    max_.quan++;
    if (max_.quan == 2){
        max_.maxim = free_num [index_of_max];
    }
    max_.array_ = max_.array_ + str;
    //std::cout << "Finised with" << max_.array_ << "\n";
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

