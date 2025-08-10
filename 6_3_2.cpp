

int main(){
    int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; ++i) {
        get(ia, i) = i;
    }
}


int &get(int *array, int index) {
    return array[index];
}
