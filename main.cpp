#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>


std::pair<int, std::vector<int> >  paint_graph(std::vector<std::vector<int> >& gr, std::vector<int>& seq) {
    std::vector<int> color(gr.size(), -1);
    int color_cnt = 0;
    for (auto cur_vert: seq) {
        std::vector<int> neighbour;
        for (auto u: gr[cur_vert]) {
            neighbour.push_back(color[u]);
        }
        std::sort(neighbour.begin(), neighbour.end());
        neighbour.push_back(gr.size() + 1);


        int mex = 0;
        for (int i = 1; i < neighbour.size(); ++i) {
            if (neighbour[i - 1] + 1 != neighbour[i]) {
                mex = neighbour[i - 1] + 1;
            }
        }
        
        color[cur_vert] = mex;
        color_cnt = std::max(color_cnt, mex);
    }

    /* DEBUG output

    for (int i = 0; i < color.size(); ++i) {
        std::cout << color[i] << " ";
    }
    std::cout << '\n';
    
    */

    return std::make_pair(color_cnt + 1, color);
}


int main() {
    int n;
    std::cout << "Enter vertexes count: \n";
    std::cin >> n;
   
    if (n < 0) {
        std::cout << "Wrong input";
        return 0;
    }

    std::vector<std::vector<int> > gr(n, std::vector<int>(0));
    
    std::cout << "Enter graph:\n";
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        if (m >= n) {
            std::cout << "Wrong input";
            return 0;
        }
        for (int j = 0; j < m; ++j) {
            int v;
            std::cin >> v;
            if (v < 0 || v >= n) {
                std::cout << "Wrong input";
                return 0;
            }
            gr[i].push_back(v);
        }
    }
    
    std::vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }
    
    int min_paint = n + 1;
    std::vector<int> optimal_paint(n);
        

    do {
        auto cur_paint = paint_graph(gr, order);
        if (cur_paint.first < min_paint) {
            min_paint = cur_paint.first;
            optimal_paint = cur_paint.second;
        }
    } while (std::next_permutation(order.begin(), order.end()));
    
    std::cout << "Chromatic number: " << min_paint << std::endl;
    std::cout << "Graph colors: ";
    for (int i = 0; i < n; ++i) {
        std::cout << optimal_paint[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
