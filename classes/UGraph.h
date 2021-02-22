//
// Created by Meclotfi on 30/01/2021.
//

#ifndef TP_2_GRAPH_UGRAPH_H
#define TP_2_GRAPH_UGRAPH_H
#include "Node.h"
#include "string.h"
#include "map"
class UGraph {

private:
    map<string , Node> g;
    int nb_node;

public:
    UGraph();
    UGraph(vector<string> srcs,vector<string> dests);
    UGraph(int nb_nodes,vector<int> srcs,vector<int> dests,vector<int> Weights);
    UGraph(string filename);
    // nodes related methods
    void add_Node();
    void add_Node(Node node);
    int add_Node(string inf);
    void add_Node(string inf,vector<string> succ_list);
    void del_node(int pos);
    string Adj(string inf_node,int i);
    Node Node_graph(int pos);
    Node get_node_by_inf(string inf);
    int find_node_by_inf(string inf);

    //Arcs related methods
    void add_Arc(string src,string dest);
    void del_Arc();
    int Info_Arc(int src,int dest);

    //graph related methods
    int size_graph();
    void DFS(Node v,map<string,bool> &visite);
    void Arcs_to_strings(vector<string> art_points);
    int CFC();
    vector<string> art_point();
    void to_png();

};


#endif //TP_2_GRAPH_UGRAPH_H
