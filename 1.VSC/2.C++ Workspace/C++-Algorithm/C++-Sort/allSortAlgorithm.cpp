#include<vector>
#include<iostream>

class elements{
    protected:
        std::vector<int>&vt;
    public:
        elements(std::vector<int>&_get_VECTOR) : vt(_get_VECTOR){};

        void print(){
            for(auto i : this->vt)
                std::cout<<i<<" ";
        }
};
class number_manipulation{
    public:
        /**
         * @brief Swap two Value of 2 posititon.
         * @param _pos1_VALUE Position 1 which will be swap with Position 2.
         * @param _pos2_VALUE Position 2 which will be swap with Position 1.
        */
        static void swap(int &_pos1_VALUE, int &_pos2_VALUE){
            int temp_VALUE = _pos2_VALUE;
            _pos2_VALUE = _pos1_VALUE;
            _pos1_VALUE = temp_VALUE;
        }
};

class Array_manipulation{
    public: 
        /**
         * @brief Add all elements of VECTOR2 at the end of the VECTOR1.
         * @details
         * VECTOR1 will be changed.
         * VECTOR2 will not be changed.
         * @param VECTOR1 Vector which will be added by VECTOR2.
         * @param VECTOR2 All elements of this vector will be added to VECTOR1.
         */
        static void add(std::vector<int>&VECTOR1, std::vector<int>VECTOR2){
            for(auto iterator : VECTOR2){
                VECTOR1.push_back(iterator);
            }
        }
        /**
         * @brief Print all elements of the VECTOR.
         * @details each element separated by a comma.
         * @param VECTOR Vector which will be print to the screen.
         */
        static void print(std::vector<int>VECTOR){
            if(!VECTOR.size()) return;
            for (auto &&i : VECTOR){
                std::cout<<i<<" ";
            }
            std::cout<<std::endl;
        }
};

class Algorithm : public elements{
    public:

        /**
         * @brief Swap two Value of 2 posititon.
         * @param _pos1_VALUE Position 1 which will be swap with Position 2.
         * @param _pos2_VALUE Position 2 which will be swap with Position 1.
        */
        void swap(int &_pos1_VALUE, int &_pos2_VALUE){
            int temp_VALUE = _pos2_VALUE;
            _pos2_VALUE = _pos1_VALUE;
            _pos1_VALUE = temp_VALUE;
        }

    private:

        /**
         * @brief Arranging all elements according to Pivot Value.
         * @note  All elements in the left < Pivot and All elements in the right > Pivot
         * @param _S_POS Start index of Arranging Field.
         * @param _E_POS End index of Arranging Field.
         * @return Index of Pivot. 
        */
        int partition(int _S_POS, int _E_POS){
            int _pivot_VALUE = vt[_S_POS];
            int _left_INDEX  = _S_POS+1;
            int _right_INDEX = _E_POS;
            while (_left_INDEX <= _right_INDEX){
                while( _left_INDEX <= _right_INDEX && vt[_left_INDEX]  <= _pivot_VALUE) _left_INDEX++;
                while( _left_INDEX <= _right_INDEX && vt[_right_INDEX] >= _pivot_VALUE) _right_INDEX--;
                if(_left_INDEX < _right_INDEX){
                    swap(vt[_left_INDEX], vt[_right_INDEX]);
                }
            }
            swap( vt[_S_POS], vt[_right_INDEX]);
            return _right_INDEX;
        }

        /**
         * @brief Call recursion of quickSort.
         * @param _S_POS Start index of Arranging Field. 
         * @param _E_POS End index of Arranging Field.
         * @see partition();
         * @see quickSort();
        */
        void quickSort(int _S_POS, int _E_POS){
                if(_S_POS >= _E_POS) return;
                int _pivot_INDEX = partition(_S_POS, _E_POS);
                quickSort(_S_POS, _pivot_INDEX -1);
                quickSort(_pivot_INDEX+1, _E_POS);
        }
        /**
         * @brief Counting_sort with parameter.
         * @param INPUT_vector Which will change after call the function.  
         */
        void counting_Sort( std::vector<int>&INPUT_vector ){
            size_t _last_index = INPUT_vector.size()-1;
            std::vector<int>frequency(255,0);
            int max_val = 0;
            for (auto i : INPUT_vector){
                if(i > max_val) max_val = i;
                frequency[i] ++;
            }
            for(size_t i = 2; i <= max_val; i++){
                frequency[i] += frequency[i-1]; 
            }
            std::vector<int>res(_last_index+1, 0);

            for(size_t i = 0; i <= _last_index; i++){
                res[ frequency[INPUT_vector[i]] -1] = INPUT_vector[i];
            }
            INPUT_vector = res;
        }

    public:
        Algorithm(std::vector<int>&_get_VECTOR) : elements(_get_VECTOR){};

        void quick_Sort(){
            size_t _last_index = vt.size()-1;
            quickSort(0, _last_index);
        }

        /**
         * @brief Sorts the elements of the vector in ascending order using bubble sort algorithm.
         * @details This function sorts the elements of the vector using bubble sort algorithm.
         * Bubble sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.
         * This process is repeated for each element of the vector until the entire vector is sorted.
         * @param None.
         * @return None.
        */
        void bubble_Sort(){
            size_t _size = vt.size();
            for(size_t last_index = _size -1; last_index >= 0 ; last_index--){
                for(int pos = 1 ; pos <= last_index; pos++){
                    if( vt[pos-1] > vt[pos]) 
                        swap(vt[pos], vt[pos-1]);
                }
            }
        }

        /**
         * @brief For each full loop of pos index will determind the smallest numbers at current_pos position.
        */
        void insertion_Sort(){
            const size_t last_index = vt.size()-1;
            const size_t second_to_last_index = last_index -1;
            for(size_t current_pos = 0; current_pos <= second_to_last_index; current_pos++){
                for(size_t next_pos = current_pos + 1; next_pos <= last_index; next_pos++){
                    if(vt[current_pos] > vt[next_pos]) 
                        swap(vt[current_pos], vt[next_pos]);
                }
            }
        }
        /**
         * @brief Insertion_sort with parameter.
         * @param VECTOR The vector which will be sort.
         */
        static void insertion_Sort(std::vector<int>&VECTOR){
            const size_t last_index = VECTOR.size()-1;
            if(last_index == -1) return;
            const size_t second_to_last_index = last_index -1;
            for(size_t current_pos = 0; current_pos <= second_to_last_index; current_pos++){
                for(size_t next_pos = current_pos + 1; next_pos <= last_index; next_pos++){
                    if(VECTOR[current_pos] > VECTOR[next_pos]) 
                        number_manipulation::swap(VECTOR[current_pos], VECTOR[next_pos]);
                }
            }
        }

        /**
         * @brief Find the smallest element of all elements from start to end.
         *        After full loop start index +1 until start = end.
         */
        void selection_Sort(){
            const size_t last_index = vt.size()-1;
            size_t pos = 0;
            while (pos <= last_index){
                /**
                 * @brief pair<first, second>.
                 * @param first Min value.
                 * @param second Min value position.
                */
                std::pair<int, int>min(10000,pos);

                for(size_t current_pos = pos; current_pos <= last_index; current_pos++){
                    if(vt[current_pos] < min.first){
                        min.first  = vt[current_pos];
                        min.second = current_pos;
                    }
                }

                swap(vt[pos], vt[min.second]);
                pos++;
            }  
        }
        /**
         * @brief Nothing to say.
         * @note The input vector is modified in place.
         */
        void counting_Sort(){
            size_t _last_index = vt.size()-1;
            std::vector<int>frequency(255,0);
            int max_val = 0;
            for (auto i : vt){
                if(i > max_val) max_val = i;
                frequency[i] ++;
            }
            for(size_t i = 2; i <= max_val; i++){
                frequency[i] += frequency[i-1]; 
            }
            std::vector<int>res(_last_index+1, 0);

            for(size_t i = 0; i <= _last_index; i++){
                res[ frequency[vt[i]] -1] = vt[i];
            }

            vt = res;
        }
        
        /**
         * @brief Sorts the elements of the vector in ascending order using the bucket sort algorithm.
         *
         * The bucket sort algorithm works by dividing the input list into several "buckets," each of which 
         * is sorted individually using an auxiliary sorting algorithm. In this implementation, each bucket 
         * is represented by a vector that stores all the elements that share the same least significant digit 
         * (i.e., those whose value modulo 10 is the same). 
         * The insertion sort algorithm is then used to sort each individual bucket, after which their contents are concatenated into a single output vector.
         *
         * This implementation assumes that the input vector contains only non-negative integers.
         * @warning The vector should contains only 2-digits numbers.
         * @see insertion_sort();
         * @note The input vector is modified in place.
         */
        void bucket_Sort(){
            std::vector<std::vector<int>>bucket(10);
            for(auto i : vt){
                bucket[i / 10].push_back(i);
            }
            std::vector<int>res;
            for(auto i : bucket){
                Algorithm::insertion_Sort(i);
                Array_manipulation::add(res, i);
            }
            vt = res;
        }
};





int main(){
    std::vector<int>array = {1,41,1,2,7,5,6,12,11,23,43,56,27,19,35,52,32,10,20,30};

    Algorithm a(array);
    
    a.bucket_Sort();
    a.print();

}