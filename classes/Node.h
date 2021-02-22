//
// Created by Meclotfi on 30/01/2021.
//
#include <vector>
#include<string>
using namespace std;
#ifndef TP_2_GRAPH_NODE_H
#define TP_2_GRAPH_NODE_H
class Node
        {
    private:
        string info;
        bool pond=false;
        vector<string> Successors;
        vector<int> Weights;
    public:
            Node();
            Node(string inf);
            Node(vector<string> succ_list);
            Node(string inf,vector<string> succ_list);
            Node(vector<string> succ_list,vector<int> w_list);
            Node(string inf,vector<string> succ_list,vector<int> w_list);
    //info related functions
        string get_info();
        void change_info(char inf);

        //succors related functions
        int degree();
        vector<string> get_succ_all();
        void add_Succ(string pos);
        int Is_succ(string pos);
        void delete_succ(string pos);
        string Succ(int index);

        //weight related functions
        int get_weight(string pos);
        int set_weight(string pos,int w);


    };



#endif //TP_2_GRAPH_NODE_H
