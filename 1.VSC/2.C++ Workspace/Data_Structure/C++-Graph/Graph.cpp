#include<iostream>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<list>

#define space " "
#define enter std::cout<<std::endl

class print{
    public:
        static void vector(std::vector<int>vector){
            for (auto &&i : vector)
            {
                std::cout<<i<<space;
            }
            enter;
        }
};



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

        /// @brief Initialize the Graph.
        void init_Graph();

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
        void add(int _VERTEX_1, int _VERTEX_2, int type_);

        /// @brief 
        /// @param _VERTEX_ 
        /// @return Return the list of _VERTEX_`s neighbors.
    protected:
        std::list<int> neighbors(int _VERTEX_);
};

class Traversal_Algorithm : public Graph{
    public:
        using  Graph::Graph;

        
        ///@brief DFS algorithm start with a vertex.
        ///@param _Start_VERTEX The starting vertex. "Default" = 1.
        void DFS(int _Start_VERTEX = 1);


        ///@brief BFS algorithm start with a vertex.
        ///@param _Start_VERTEX The starting vertex.
        void BFS(int _Start_VERTEX = 1);
};

class connected : public Graph{
    public:
        using Graph::Graph;
    private:


        ///@brief Using this function to detect each connected component.
        ///@details This is recursion implementation.
        ///@param visited A reference to a vector of integers(numberic vertex) that keeps track of the visited vertices.
        ///@param cur_vertex A current vertex being visited.
        ///@see neighbors();
        void travel(std::vector<int>&visited, int cur_vertex);

    public:

        ///@brief Return the count of component.
        ///@see travel();
        ///@return number of component.
        int number_of_components();

        /// @brief Recursion function that travel all the graph and return strongly connected components if it satisfied certain conditions.
        /// @param cur_ver Current vertex.
        /// @param index Current index.
        /// @param num num value.
        /// @param min_num min num value.
        /// @param st Input stack.
        /// @param on_stack Input vector.
        /// @param sccs Every components wull be add to 2-d vector as an vector.
        void strong_connect(int cur_ver, int &index, std::vector<int>&num, 
                            std::vector<int>&min_num, std::stack<int>&st, std::vector<bool>&on_stack, 
                            std::vector<std::vector<int>>&sccs);

        /// @brief Print all strongly connected components on screen.
        void SCC();
        

        
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

    a.SCC();
        


}























// Function details declaration.

// Graph implementation.
void Graph::init_Graph(){
    for (int i = 1; i <= _max_VERTEX; i++)
    {
        for (int j = 0; j <= _max_VERTEX; j++)
        {
            this->edges[i][j] = 0;
        }
    }
}

void Graph::add(int _VERTEX_1, int _VERTEX_2, int type_){
    this->edges[_VERTEX_1][_VERTEX_2] = 1;
    if(type_ == 2) 
        this->edges[_VERTEX_2][_VERTEX_1] = 1;
}

std::list<int> Graph::neighbors(int _VERTEX_){
    std::list<int>res;

    for(int i = 1; i <= _max_VERTEX; i++){
        if( adjecent(_VERTEX_, i) )
            res.push_back(i);
    }
    return res;
}


// "Traversal Algorithm" Class methods implementation.
void Traversal_Algorithm::DFS(int _Start_VERTEX){
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

void Traversal_Algorithm::BFS(int _Start_VERTEX){
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


// "connected" Class methods implementation.
int connected::number_of_components(){
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

void connected::travel(std::vector<int>&visited, int cur_vertex){
    visited[ cur_vertex ] = 1;
    std::list<int> list = neighbors( cur_vertex );
    for(auto i : list ){
        if(!visited[i])
            travel(visited, i);
    }
}


void connected::strong_connect(int cur_ver, int &index, std::vector<int>&num, 
std::vector<int>&min_num, std::stack<int>&st, std::vector<bool>&on_stack, std::vector<std::vector<int>>&sccs){
    // Initialize current vertex min and min num as index.
    num[ cur_ver ] = min_num[ cur_ver ] = index;
    // Increase index each time this function is called.
    index++;
    // Push current vertex to the stack.
    st.push(cur_ver);
    // Mark current vertex to represent that current vertex is currently on the stack.
    on_stack[ cur_ver ] = true;

    std::list<int> list = neighbors( cur_ver );
    for(auto vertex : list){
        // If vertex hasn`t visited yet.
        if( num[ vertex ] == -1){
            strong_connect( vertex, index, num, min_num, st, on_stack, sccs);
            min_num[ cur_ver ] = std::min(min_num[ cur_ver ], min_num[ vertex ]);
        }
        else if( on_stack[ vertex ]){
            min_num[ cur_ver ] = std::min(min_num[ cur_ver ], num[ vertex ]);
        }
    }

    if( num[ cur_ver ] == min_num[ cur_ver ]){
        std::vector<int>scc;
        int w;
        do{
            w = st.top(); st.pop();
            on_stack[ w ] = false;
            scc.push_back(w);
        }while( w != cur_ver);

        // Push scc to sccs.
        sccs.push_back(scc);
    }
}

void connected::SCC(){
    int index = 1;
    std::vector<int> num( _max_VERTEX + 1, -1);
    std::vector<int> min_num( _max_VERTEX + 1, 0);
    std::vector<bool>on_stack(_max_VERTEX +1, false);
    std::stack<int>st;
    std::vector<std::vector<int>> res;

    for(int i = 1; i <= _max_VERTEX; i++)
        if( num[ i ] == -1){
            strong_connect(i, index, num, min_num, st, on_stack, res);
        }
    for (auto &&i : res)
    {
        print::vector(i);        
    }
}




// Bug recorded:
/**
 * In SCC function:
    Missed:
       for(int i = 1; i <= _max_VERTEX; i++)
        if( num[ i ] == -1)
            strong_connect(i, index, num, min_num, st, on_stack, res);
    SCC function will call strong_connect /max_VERTEX/ times.
 *  
    min_num[ vertex ] instead of min_num[ cur_ver ] lead to error.
 * 
 */