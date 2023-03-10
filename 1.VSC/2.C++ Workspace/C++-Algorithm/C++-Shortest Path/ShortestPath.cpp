#include<climits>
#include<cstdio>
#include<vector>
#include<list>
/**
 * @brief This graph is Create only for Shortest Path algorithm and it may not work properly for any other algorithm.
 * @warning This graph max capacity is 99.
 */
class Graph{
    protected:

        /** 
         * @brief 2 Dimenstion Vector declare the connection status between 2 vertex. 
         * @note The size of connection 2D vector depend on max_VERTEX value.
         */
        int max_VERTEX;
    public:
        int connection[100][100];

    private:

        /**
         * @brief Check the connection between 2 vertex.
         * 
         * @param vertex_1 
         * @param vertex_2 
         * @return "true" if 2 vertex are connect.
         * @return "false" if 2 vertex are not connect.
         */
        bool adjecent(int vertex_1, int vertex_2){
            return connection[vertex_1][vertex_2] != 0;
        }
    public:


        /**
         * @brief Construct a new Graph object
         * @param _number_of_VERTEX initialize the max number of vertex in Graph.
         */
        Graph(int max_vertex) : max_VERTEX(max_vertex){
            for(size_t vertex1 = 1; vertex1 <= max_VERTEX; vertex1++)
                for(size_t vertex2 = 1; vertex2 <= max_VERTEX ; vertex2++) connection[ vertex1 ][ vertex2 ] = 0;
        }



        /**
         * @brief Adds a directed edge between two vertices of the graph with a given weight.
         * @param start_VERTEX Starting vertex of the edge.
         * @param end_VERTEX Ending vertex of the edge.
         * @param weight Weight of the edge.
         * @return void.
         */
        void add(int start_VERTEX, int end_VERTEX, int weight){
            connection[start_VERTEX][end_VERTEX] = weight;
        }

        
        /**
         * @brief Returns a list of neighbors of a given vertex in the graph.
         * @param vertex The vertex to find the neighbors of.
         * @return A std::list<int> containing the neighbors of the given vertex.
        */
        std::list<int> neighbors(int vertex){
            std::list<int>res;
            for(size_t other_vertex = 1; other_vertex <= max_VERTEX; other_vertex++)
                if(connection[vertex][other_vertex] != 0) res.push_back(other_vertex);
            return res;
        }
};

class Graph_Algorithm : public Graph{
    public:
        using  Graph::Graph;
        /**
         * @brief Dijstra Algorithm implementation.
         * 
         * @details After the function called. Vector p_t_i and b_i will be overriding by path_to_i vector and before_i vector.
         * 
         * @param starting_point The starting Vertex.

         */
        void Dijstra_Algorithm(int starting_point){
            int inf = INT_MAX;
            /* 
             * Mark which vertex already been check
            */
            std::vector<int>visited  (this->max_VERTEX+1, 0);      
        
            /* 
             * Represent the current shortest path from starting_point to i vertex.
             * Set path from starting point to all others vertex to default value(inf) and path to itseft is 0.
            */                              
            std::vector<int>path_to_ (this->max_VERTEX+1, inf); path_to_[starting_point] = 0;  
            
            /* 
             * This vector represent the previous vertex of vertex at index i. 
             * Set before_[starting_point] = -1 because this is starting vertex.
            */
            std::vector<int>before_ (this->max_VERTEX+1, 0); before_[starting_point] = -1;      
       
            /*
             * Loop max_VERTEX times or max_VERTEX times-1 are aceptable. 
            */
            for(size_t times = 1; times < max_VERTEX; times++){
                /*
                 * Find unvisited vertex which have shortest path from starting_vetex to it. Which mean when the function very first start 
                 * will choose starting_point as chosen vertex.
                */
                int min_path = inf;
                int chosen_vertex;
                for(size_t vertex = 1; vertex <= max_VERTEX; vertex++){
                    if( !visited[ vertex ] && path_to_[ vertex ] < min_path){
                        min_path      = path_to_[ vertex ];
                        chosen_vertex = vertex;
                    }
                }
                // Mark chosen_vertex is visited.
                visited[ chosen_vertex ] = 1;
                // Update shortest path from chosen_vertex to its ajecent, and its previous vertex.
                for(size_t other_vertex = 1; other_vertex <= max_VERTEX; other_vertex++){
                    // Check if there is a connection between Chosen_vertex and it haven`t visited yet. 
                    if( connection[ chosen_vertex ][ other_vertex ] && !visited[ other_vertex ]){
                        if(path_to_[ chosen_vertex ] + connection[ chosen_vertex ][ other_vertex ] < path_to_[ other_vertex ]){
                            path_to_[ other_vertex ] = path_to_[ chosen_vertex ] + connection[ chosen_vertex ][ other_vertex ];
                            before_[ other_vertex ] = chosen_vertex;
                        }
                    }
                }
            }

            // Print the result.
            for(size_t vertex = 1; vertex <= max_VERTEX ; vertex++){
                printf("Path from %d to %d = %d , Previous of %d is %d\n", starting_point, vertex, path_to_[ vertex ] == inf ? -1 : path_to_[ vertex ], vertex, before_[ vertex ]);
            }

        }

        void Bellman_Algorithm(int starting_point){
            int inf = INT_MAX;

            std::vector<int> path_to ( this->max_VERTEX+1, inf);
            path_to[ starting_point ] = 0;

            std::vector<int> previous( this->max_VERTEX+1, 0);
            previous[ starting_point ] = -1;

            // Loop max_VERTEX -1 times.
            for(size_t loop = 1; loop < max_VERTEX; loop++){
                
                for(size_t vertex = 1; vertex <= max_VERTEX; vertex++){
                    
                    std::list<int> list = neighbors( vertex );
                    for(auto i : list){
                        if(path_to[vertex] != inf && path_to[vertex] + connection[vertex][i] < path_to[i]){
                            path_to[ i ] = path_to[vertex] + connection[vertex][i];
                            previous[ i ] = vertex;
                        }
                    }

                }

            }
            for(size_t vertex = 1; vertex <= max_VERTEX; vertex++){
                printf("Shortest path from %d to %d is %d, pre of %d is %d\n", starting_point, vertex, path_to[ vertex ], vertex, previous[ vertex ]);
            }
            
        }
};

#include<iostream>


int main(){
    Graph_Algorithm g(6);
    g.add(1, 2, 7);
    g.add(1, 3, 1);
    g.add(2, 4, 4);
    g.add(2, 6, 1);
    g.add(3, 2, 5);
    g.add(3, 5, 2);
    g.add(3, 6, 7);
    g.add(5, 4, 5);
    g.add(5, 2, 2);
    g.add(6, 5, 3);    
    
    g.Bellman_Algorithm(1);
}





