#include<iostream>
#include<vector>
#include<stack>
#include<list>


class Graph{
    private:
    int _max_VERTEX;
    int edges[100][100];
    
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
    /// @brief Initialize Graph
    /// @param No_of_VERTEX 
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
    std::list<int> neighbors(int _VERTEX_){
        std::list<int>res;

        for(int i = 1; i <= _max_VERTEX; i++){
            if( adjecent(_VERTEX_, i) )
                res.push_back(i);
        }
        return res;
    }

    void DFS(int _Start_VERTEX){
        std::vector<int>visited(this->_max_VERTEX+1, 0);
        std::stack<int> st;

        int x = _Start_VERTEX;
    
        st.push(x);
        while(!st.empty())
        {
            int token = st.top();st.pop();

            cout<<token<<endl;
            visited[token] = 1;

            list<int> _neighbors_of_token = neighbors(token);
            for(auto i : _neighbors_of_token )
            {
                if( !visited[i] )
                {
                    st.push(i);
                }
            }
        }
    }

    void BFS(int _Start_VERTEX){
        std::vector<int>visited(this->_max_VERTEX+1, 0);
        std::queue<int> q;

        int x = _Start_VERTEX;

        cout<<x;
        visited[x] = 1;

        q.push(x);
        while (!q.empty())
        {
            cout<<endl;
            int token = q.front();q.pop();

            list<int> _neighbors_of_token = neighbors(token);
            for(auto i : _neighbors_of_token){
                if(!visited[i]){
                    cout<<i<<" ";
                    visited[i] = 1;
                    q.push(i);
                }
            }    
            
        }
    }

};










