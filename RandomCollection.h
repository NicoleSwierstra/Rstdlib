//Random collection
//Useful for whenever you need to have a collection of items (say in a collectible card game) with varying "rarities"
//templates dont exist in c so this uses void pointers

namespace rstd {

    struct _rand_col_node {
        void* data;
        double num;
    };

    class randcol{
        _rand_col_node* data;
        int length = 0;
        double total = 0;

        //returns index of last element
        int allocMem(int number){
            length = number;
            realloc(data, length * sizeof(_rand_col_node));
            return number-1;
        }
        
        randcol(){
            srand (time(NULL)); //init random
            allocMem(length);
        }

        void add(void* thing, double weight){
            data[allocMem(length+1)] = {thing, total};
            total += weight;
        }

        void* roll(){
            double n = ((double)rand() / RAND_MAX) * total;
            int i = 0;
            while(data[i]->num < n)
            i++;
            return data[i]->data;
        }
    };
}