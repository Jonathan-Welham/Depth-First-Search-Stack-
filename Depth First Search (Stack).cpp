/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/dfs-4/submissions/code/1321573074
 * Title: hw5_3.cpp
 * Abstract: This program is an implementation of the Depth First Search algorithm using a stack and a mark array
 * Author: Jonathan Welham
 * ID: 6781
 * Date: 03/06/2020
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    vector<int> track;
    vector<bool> visited;
    stack <int> s;
    int vertices;
    int edges;
    vector<vector<bool>> graph;

    cin >> vertices >> edges;

    for(int i = 0; i < vertices; i++){
        vector<bool> num;
        for(int j = 0; j < vertices; j++){
            num.push_back(false);
        }

        visited.push_back(0);
        graph.push_back(num);
    }
    for(int i = 0; i < edges; i++){
        int from, to;
        cin >> from >> to;
        graph[from][to] = true;
    }

    s.push(0);
    track.push_back(0);

    while(true){
        for(int i = 0; i < graph[s.top()].size();i++){
            if(graph[s.top()][i] == 1){
                if(visited[i] == true){
                    graph[s.top()][i] = false;
                    continue;
                }
                visited[i] = true;
                track.push_back(i);
                s.push(graph[s.top()][i]);
                graph[s.top()][i] = false;
                s.push(i);
                break;
            }

            if(i == graph[s.top()].size()-1){
                s.pop();
                break;
            }
        }
        if(s.empty()){
            break;
        }
    }
    for(int i = 0; i < track.size(); i++){
        cout << "Mark[" << i << "]:";
        for(int j = 0; j < track.size(); j++){
            if(track[j]== i){
                cout << j + 1 << endl;
                break;
            }
        }
    }
}