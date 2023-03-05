#include<vector>
#include<list>
/**
 * @brief This graph is Create only for Shortest Path algorithm and it may not work properly for any other algorithm.
 */
class Graph{
    protected:


        /** 
         * @brief 2 Dimenstion Vector declare the connection status between 2 vertex. 
         * @note The size of connection 2D vector depend on max_VERTEX value.
         */
        int max_VERTEX;
        std::vector<std::vector<int>>connection;
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
        Graph(int max_vertex) : max_VERTEX(max_vertex), connection(max_vertex, std::vector<int>(max_vertex, 0)) {}



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
        Graph_Algorithm(int number_of_vertex) : Graph(number_of_vertex){};

        void Dijkstra_Algorithm(){
            
        }

};


