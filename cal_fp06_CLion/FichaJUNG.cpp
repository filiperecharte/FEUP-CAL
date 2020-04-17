#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
    GraphViewer *gv = new GraphViewer(600,600,true);
    gv->setBackground("../Earth.png");
    gv->createWindow(600,600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");
    int idNo=0;
    gv->addNode(idNo);
    gv->rearrange();
    idNo=1;
    gv->addNode(idNo);
    gv->rearrange();

    int idAresta=0;
    gv->addEdge(idAresta,0,1,EdgeType::UNDIRECTED);
    gv->removeNode(0);

    idNo=2;
    gv->addNode(idNo);
    gv->rearrange();

    idAresta=1;
    gv->addEdge(idAresta,1,2,EdgeType::UNDIRECTED);
    gv->setVertexLabel(idNo, "Isto e um no");
    gv->setEdgeLabel(idAresta, "Isto e uma aresta");

    gv->setVertexColor(2, "green");
    gv->setEdgeColor(1, "yellow");

    gv->rearrange();
}

void exercicio2()
{
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->setBackground("Earth.png");
    gv->createWindow(600,600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    gv->addNode(0,300,50);
    gv->addNode(1, 318,58);
    gv->addNode(2, 325,75);
    gv->addNode(3, 318,93);
    gv->addNode(4, 300,100);
    gv->addNode(5, 282,93);
    gv->addNode(6, 275,75);
    gv->addNode(7, 282,58);
    gv->addNode(8, 150,200);
    gv->addNode(9, 300,200);
    gv->addNode(10, 450,200);
    gv->addNode(11, 300,400);
    gv->addNode(12, 200,550);
    gv->addNode(13, 400,550);

    gv->addEdge(0,0,1,EdgeType::UNDIRECTED);
    gv->addEdge(1,1,2,EdgeType::UNDIRECTED);
    gv->addEdge(2,2,3,EdgeType::UNDIRECTED);
    gv->addEdge(3,3,4,EdgeType::UNDIRECTED);
    gv->addEdge(4,4,5,EdgeType::UNDIRECTED);
    gv->addEdge(5,5,6,EdgeType::UNDIRECTED);
    gv->addEdge(6,6,7,EdgeType::UNDIRECTED);
    gv->addEdge(7,7,0,EdgeType::UNDIRECTED);
    gv->addEdge(8,4,9,EdgeType::UNDIRECTED);
    gv->addEdge(9,9,8,EdgeType::UNDIRECTED);
    gv->addEdge(10,9,10,EdgeType::UNDIRECTED);
    gv->addEdge(11,9,11,EdgeType::UNDIRECTED);
    gv->addEdge(12,11,12,EdgeType::UNDIRECTED);
    gv->addEdge(13,11,13,EdgeType::UNDIRECTED);

    for (int i = 0; i < 5; i++) {
        Sleep(1000);

        gv->removeNode(12);
        gv->removeNode(13);

        gv->addNode(14, 250, 550);
        gv->addNode(15, 350, 550);

        gv->addEdge(12, 11, 14, EdgeType::UNDIRECTED);
        gv->addEdge(13, 11, 15, EdgeType::UNDIRECTED);

        gv->rearrange();

        Sleep(1000);

        gv->removeNode(14);
        gv->removeNode(15);

        gv->addNode(12, 200, 550);
        gv->addNode(13, 400, 550);

        gv->addEdge(12, 11, 12, EdgeType::UNDIRECTED);
        gv->addEdge(13, 11, 13, EdgeType::UNDIRECTED);

        gv->rearrange();
    }
}

void exercicio3()
{
    GraphViewer * gv = new GraphViewer(600, 600, false);
    gv->setBackground("../Earth.png");
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    ifstream nodeFile;
    nodeFile.open("../resources/mapa1/nos.txt");

    while (!nodeFile.eof()) {
        string line;
        int id, x, y;
        getline(nodeFile, line, ';');
        id = stoi(line);
        getline(nodeFile, line, ';');
        x = stoi(line);
        getline(nodeFile, line, '\n');
        y = stoi(line);
        gv->addNode(id, x, y);
    }

    ifstream edgeFile;
    edgeFile.open("../resources/mapa1/arestas.txt");

    while (!edgeFile.eof()) {
        string line;
        int id, n1, n2;
        getline(edgeFile, line, ';');
        id = stoi(line);
        getline(edgeFile, line, ';');
        n1 = stoi(line);
        getline(edgeFile, line, '\n');
        n2 = stoi(line);
        gv->addEdge(id, n1, n2, EdgeType::UNDIRECTED);
    }
}

int main() {
    /*
     * Uncomment the line below to run Exercise 1
     */
    exercicio1();

    /*
      * Uncomment the line below to run Exercise 2
      */
    //exercicio2();

    /*
      * Uncomment the line below to run Exercise 3
      */
	//
	//exercicio3();

	getchar();
	return 0;
}
