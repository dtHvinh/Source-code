#include<iostream>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<list>

#define space " "
#define enter std::endl



class Graph{
    protected:
    int _max_VERTEX;
    int edges[100][100];

    private:
    /// @brief Check if 2 VERTEX ARE ADJECENT.
    /// @param _VERTEX_1 
    /// @param _VERTEX_2 
    /// @return True/False if 2 VERTEX adjecent or not.
    bool adjecent(int _VERTEX_1, int _VERTEX_2){
        return this->edges[_VERTEX_1][_VERTEX_2];
    }

    void init_Graph(){
        for (int i = 1; i <= _max_VERTEX; i++)
        {
            for (int j = 0; j <= _max_VERTEX; j++)
            {
                this->edges[i][j] = 0;
            }
        }
    }

    public:
    /// @brief Graph Initialization 
    /// @param No_of_VERTEX Initialize the number of vertex in Graph.
    Graph(int No_of_VERTEX){
        this->_max_VERTEX = No_of_VERTEX;
        init_Graph();
    }

    /// @brief Add Conecction between 2 VERTEX.
    /// @param _VERTEX_1 first vertex.
    /// @param _VERTEX_2 second vertex.
    /// @param type_ "1" if one way connect and "2" if two ways connect.
    void add(int _VERTEX_1, int _VERTEX_2, int type_){
        this->edges[_VERTEX_1][_VERTEX_2] = 1;
        if(type_ == 2) 
            this->edges[_VERTEX_2][_VERTEX_1] = 1;
    }

    /// @brief 
    /// @param _VERTEX_ 
    /// @return Return the list of _VERTEX_`s neighbors.
    protected:
    std::list<int> neighbors(int _VERTEX_){
        std::list<int>res;

        for(int i = 1; i <= _max_VERTEX; i++){
            if( adjecent(_VERTEX_, i) )
                res.push_back(i);
        }
        return res;
    }
};

class Traversal_Algorithm : public Graph{
    public:
        using  Graph::Graph;
        /**
         * @brief DFS algorithm start with a vertex.
         * 
         * @param _Start_VERTEX The starting vertex. "Default" = 1.
         */
        void DFS(int _Start_VERTEX = 1){
            std::vector<int>visited(this->_max_VERTEX+1, 0);
            std::stack<int> st;

            int x = _Start_VERTEX;
        
            st.push(x);
            while(!st.empty())
            {
                int token = st.top();st.pop();

                std::cout<<token<<space;
                visited[token] = 1;

                std::list<int> _neighbors_of_token = neighbors(token);
                for(auto i : _neighbors_of_token )
                {
                    if( !visited[i] )
                    {
                        st.push(i);
                    }
                }
            }
        }


        /**
         * @brief BFS algorithm start with a vertex.
         * 
         * @param _Start_VERTEX The starting vertex.
         */
        void BFS(int _Start_VERTEX = 1){
            std::vector<int>visited(this->_max_VERTEX+1, 0);
            std::queue<int> q;

            int x = _Start_VERTEX;

            std::cout<<x<<space;
            visited[x] = 1;

            q.push(x);
            while (!q.empty())
            {
                int token = q.front();q.pop();

                std::list<int> _neighbors_of_token = neighbors(token);
                for(auto i : _neighbors_of_token){
                    if(!visited[i]){
                        std::cout<<i<<space;
                        visited[i] = 1;
                        q.push(i);
                    }
                }    
                
            }
        }
};

class connected : public Graph{
    public:
        using Graph::Graph;
    private:
        /**
         * @brief Using this function to detect each connected component.
         * 
         * @details This is recursion implementation.
         * 
         * @param visited A reference to a vector of integers(numberic vertex) that keeps track of the visited vertices.
         * @param cur_vertex A current vertex being visited.
         * @see neighbors();
         */
        void travel(std::vector<int>&visited, int cur_vertex){
            visited[ cur_vertex ] = 1;
            std::list<int> list = neighbors( cur_vertex );
            for(auto i : list ){
                if(!visited[i])
                    travel(visited, i);
            }
        }

        void strong_connect(std::vector<int>&on_stack, std::stack<int>&st, int &k, int cur_vertex, std::vector<int>&num, std::vector<int>&min_num){
            num[ cur_vertex ] = min_num[ cur_vertex ] = k++;
            st.push ( cur_vertex );
            on_stack[ cur_vertex ] = 1;

            std::list<int> list = neighbors( cur_vertex );
            for(auto vertex : list){
                if( num[ vertex ] < 0){
                    strong_connect(on_stack, st, k, vertex, num, min_num);
                    min_num[ vertex ] = std::min(min_num[ cur_vertex ], min_num[ vertex ]);
                }
                else if( on_stack[ vertex ]){
                    min_num[ vertex ] = std::min(min_num[ cur_vertex ], num[ vertex ]);
                }
            }

            printf("min_num[%d] = %d\n", cur_vertex, min_num[ cur_vertex ]);

            if( num[ cur_vertex ] == min_num[ cur_vertex ]){
                printf("%d la dinh khop.\n", cur_vertex);
                int w;
                do{
                    w = st.top();
                    st.pop();
                    on_stack[ w ] = 0;
                }while( w != cur_vertex );
            }
        }

    public:
        /**
         * @see travel();
         * @return number of component.
         */
        int number_of_components(){
            int count = 0;
            std::vector<int>visited(_max_VERTEX+1, 0);
            for(int i = 1; i <= _max_VERTEX; i++){
                if( !visited[i] ){
                    count++;
                    travel(visited, i);
                }
            }
            return count;
        }

        void strong_connect(){
            std::stack<int>st;
            std::vector<int>on_stack(_max_VERTEX+1, 0), num(_max_VERTEX+1, -1), min_num(_max_VERTEX+1, 0);
            int k = 1;
            for(int i = 1; i <= _max_VERTEX; i++)
                if(num[i] == -1)
                    strong_connect(on_stack, st, k, i, num, min_num);
        }

        


};


int main(){
    connected a(8);

    a.add(1, 2, 1);
    a.add(1, 3, 1);
    
    a.add(2, 1, 1);
    a.add(2, 8, 1);
    
    a.add(3, 4, 1);
    a.add(3, 5, 1);
    
    a.add(4, 2, 1);
    a.add(4, 7, 1);
    a.add(4, 8, 1);

    a.add(5, 3, 1);
    a.add(5, 7, 1);
    
    a.add(6, 7, 1);

    a.add(7, 6, 1);

    a.add(8, 7, 1);



    a.strong_connect();

    


}










