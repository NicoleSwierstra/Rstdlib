//Random collection
//Useful for whenever you need to have a collection of items (say in a collectible card game) with varying "rarities"
//template class for easy usability

#include <vector>

namespace rstdpp {
    template <class T>
    class randcol{
        std::vector<T> data;
        std::vector<double> lut;
        double total = 0;
        
        randcol(){
            srand (time(NULL)); //init random
        }

        void add(T thing, double weight){
            data.push_back(thing); 
            lut.push_back(total);
            total += weight;
        }

        T roll(){
            double n = ((double)rand() / RAND_MAX) * total;
            int i = 0;
            while(lut[i] < n)
            i++;
            return data[i];
        }
    };
}