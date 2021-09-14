# STL_BAR_GRAPH

## Prerequisites

- node js (version 14.17.6)
- Visual Studio (2019)

## Command line arguments

```bash
stl_bar_graph <FILENAME> --min=<integer> --max=<integer> --cells=<integer>
```

## Run instruction

- Build the project with Release configuration
- From the root directory run the following;
    - ```<FILENAME>``` - STL file to be tested
    - ```<TARGET>``` - target platform
```bash
.\bin\<TARGET>\Release\stl_bar_graph.exe <FILENAME> > graph.json
```
- To display the result run the following
```bash
cd .\stl_graph_viewer && npm install && node index.js < ..\graph.json
```