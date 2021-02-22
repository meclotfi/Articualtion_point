//
// Created by Meclotfi on 30/01/2021.
//
#include <fstream>
#include "UGraph.h"
#include <iostream>
#include "algorithm"
#include "set"
/*
UGraph::UGraph(char *filename) {
    ifstream myfile(filename);
    string line;
    string src,dest;
    getline(myfile,line);
    cout<<line<<endl;
    //
    while(line!=<O)
    myfile << "}";
    myfile.close();
    return "";
}*/
UGraph::UGraph(vector<string> srcs,vector<string> dests)
{
    for (int i = 0; i < srcs.size(); ++i) {
        int ind=add_Node(srcs[i]);
        g[srcs[i]].add_Succ(dests[i]);
        int ind2=add_Node(dests[i]);
        g[dests[i]].add_Succ(srcs[i]);

    }
}
// nodes related methods
void UGraph::UGraph::add_Node()
{
    Node n;
    g.insert({n.get_info(),n});
    nb_node++;
}
void UGraph::add_Node(Node node)
{

    g.insert({node.get_info(),node});
    nb_node++;
    printf("node added successfully");
}
int UGraph::add_Node(string inf)
{
    g.insert({inf,Node(inf)});
}
void UGraph::add_Node(string inf,vector<string> succ_list)
{
    Node n(inf,succ_list);
    g.insert({inf,n});
}
void UGraph::del_node(int pos)
{
    //g.erase(pos)
    nb_node--;
}
string UGraph::Adj(string inf_node,int i)
{
    return g[inf_node].Succ(i);
}
Node UGraph::Node_graph(int pos)
{
    int i=0;
    string info;
    for (auto item : g)
    {
        if(i==pos)
        {
            info=item.first;
            break;
        }
        i++;
    }
    return g[info];
}
Node UGraph::get_node_by_inf(string inf)
{
    return g[inf];
}

//Arcs related methods
void UGraph::add_Arc(string src,string dest)
{
    g.insert({src,Node(src)});
    g[src].add_Succ(dest);
    g.insert({dest,Node(dest)});
    g[dest].add_Succ(src);
}
void UGraph::del_Arc(){}

//graph related methods
int UGraph::size_graph()
{
    return nb_node;
}
void UGraph::Arcs_to_strings(vector<string> art_points)
{
    set<string> checker;
    ofstream myfile("graph.dot");
    myfile << "graph G { \n";
    for (auto item : g)
    {
        checker.insert(item.first);
        myfile << item.first <<"\n";
        for (int j = 0; j < item.second.degree(); j++) {
            if(checker.find(item.second.Succ(j)) == checker.end()) {
                myfile << item.first << " -- " << item.second.Succ(j) << "\n";
            }
        }
    }
    for (auto pt :art_points) {
        myfile << pt << " [fillcolor=green,style=filled]" << "\n";
    }

    myfile << "}";
    myfile.close();
}
void UGraph::DFS(Node v,map<string,bool> &visite)
{
    visite[v.get_info()] = true;
    cout<< "noued "<< v.get_info()<<endl;
    for(int i = 0; i< v.degree(); i++) {
       string adj=v.Succ(i);
       if(g.count(adj)!=0)
        {
           if(!visite[adj])
           {
               cout<< "noued "<< adj<<endl;
               DFS(g[adj],visite);
           }
        }
    }
}
int UGraph::CFC()
{
    map<string,bool> visite;
    for (auto item : g) {
        visite[item.first]=false;
    }
    int cfc=0;
    for (auto item : g)
    {
        if(!visite[item.first])
        {
            DFS(item.second,visite);
            cfc++;
        }
    }
    printf("number of cfc %d",cfc);
    return cfc;
}
vector<string> UGraph::art_point()
{
    vector<string> keys;
    for (auto item : g)
    {
        keys.push_back(item.first);
    }
    int cfc_g=CFC();
    vector<string> art_points;
    for (auto item : keys) {
        Node node=g.find(item)->second;
        g.erase(item);
        cout<< "after deleting "<<item<<endl;
        int cfc=CFC();
        if(cfc>cfc_g)
        {
            art_points.push_back(item);
        }
        add_Node(node);
    }
    return art_points;
}
void UGraph::to_png()
{
    Arcs_to_strings(art_point());
    std::system("dot -Tpng ..\\cmake-build-debug\\graph.dot -o graph.png");
    std::system("..\\cmake-build-debug\\graph.png");
}