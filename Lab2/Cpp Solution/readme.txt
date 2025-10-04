in order to visualise the c++ code:

install graphviz:

(macOS) open terminal and run:
    brew install graphviz

verify installation:
    dot -V
should return:
    dot - graphviz version 14.0.0 (or similar)

run the 'lab2Main.cpp' file 
open a new terminal in vscode and run:
    dot -Tpng adjMatrix.dot -o adjMatrix.png
    dot -Tsvg adjList.dot -o adjList.svg
    
view the 2 new '.png' files created and verify

