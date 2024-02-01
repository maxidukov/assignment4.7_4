#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

void dfs(const std::vector<std::vector<bool>>& graph, const int& vertex, std::vector<int>& cids, const int& cid);

int components(const std::vector<std::vector<bool>>& graph, std::vector<int>& cids);

  int main() {
    std::vector<std::string> fnames = {"input.txt","input2.txt"};
    for(const auto& fname:fnames){
    //std::ifstream infile("input.txt");
    std::ifstream infile(fname);
    int size{};
    infile >> size;
    //std::cout<<size<<"\n";
    std::vector<std::vector<bool>> graph(size);
    int i{};
    std::string str;
    while(std::getline(infile,str)){
      //std::cout<<str<<"\n";
      if(str.empty()) continue;
      std::istringstream ss(str);
      bool v{};
      while(ss>>v){
         graph[i].push_back(v);
      }
      i++;
    }
    std::vector<int> cids(graph.size(),0);
    int num_comps = components(graph,cids);
    std::cout << "Принадлежность вершин компонентам связности:\n";
    for(int v{}; v<graph.size();v++){
      std::cout << v+1 << " - " << cids[v] << "\n";
    }
    std::cout << "Количество компонентов связности в графе c матрицей смежности в файле \"" << fname << "\": " << num_comps << "\n\n";
  }
  }

  void dfs(const std::vector<std::vector<bool>>& graph, const int& vertex, std::vector<int>& cids, const int& cid){
     cids[vertex] = cid;
     for(int v{}; v<graph.size(); v++){
       if(graph[vertex][v]){
         if(cids[v] == 0){
           dfs(graph,v,cids,cid);
         }
       }
     }
  }


 int components(const std::vector<std::vector<bool>>& graph, std::vector<int>& cids){
    //std::vector<int> cids(graph.size(),0);
    int cid = 1;
    for(int v{}; v<graph.size();v++){
      if( cids[v] == 0 ){
        dfs(graph,v,cids,cid);
        cid++;
      }
    }
    return cid-1;
  }
