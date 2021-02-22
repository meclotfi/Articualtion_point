//
// Created by Meclotfi on 30/01/2021.
//

#include "Node.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

Node::Node():info("A"), Successors({}), Weights({}){};
Node::Node(string inf)
{
info=inf;
Successors={};
}
Node::Node(vector<string> succ_list)
{
Successors=succ_list;
pond=false;
}
Node::Node(string inf,vector<string> succ_list)
{
info=inf;
Successors=succ_list;
pond=false;
}
Node::Node(vector<string> succ_list,vector<int> w_list)
{
if(succ_list.size()==w_list.size())
{
Successors=succ_list;
Weights=w_list;
pond= true;
}

else
{
throw new exception;
}
}
Node::Node(string inf,vector<string> succ_list,vector<int> w_list)
{
if(succ_list.size()==w_list.size())
{
info=inf;
Successors=succ_list;
Weights=w_list;
pond= true;
}

else
{
throw new exception;
}
}

    //info related functions

    string Node::get_info()
    {
        return info;
    }
    void Node::change_info(char inf)
    {
        info=inf;
    }

    //succors related functions

    int Node::degree()
    {
        return Successors.size();
    }
    vector<string> Node::get_succ_all()
    {
        return Successors;
    }
    void Node::add_Succ(string pos)
    {
    int i=Is_succ(pos);
    if(i<0) Successors.push_back(pos);

    }
    int Node::Is_succ(string pos)
    {
        int i=0;
        printf("size== %d",Successors.size());
        for (i = 0; i < Successors.size(); i++) {
            if (Successors[i].compare(pos) == 0) return i;
        }
        return -1;
    }
    void Node::delete_succ(string pos)
    {
        int index=Is_succ(pos);
        if(index!=0)
        {
            //Successors.erase(index);
            //Weights.erase(index);
        }

    }
    string Node::Succ(int index)
    {
        if(index<Successors.size())
        {
            return Successors[index];
        }
        else{
            return NULL;
        }
    }

    //weight related functions

    int Node::get_weight(string pos)
    {
        auto it = find(Successors.begin(), Successors.end(), pos);

        // If element was found
        if (it != Successors.end())
        {

            // calculating the index
            int index = it - Successors.begin();
            return Weights[index];
        }
        else {
            // If the element is not
            // present in the vector
            return -1;
        }
    }
    int Node::set_weight(string pos,int w)
    {
        int index=Is_succ(pos);
        if(index>=0)
        {
            Weights[index]=w;
        }

    }
