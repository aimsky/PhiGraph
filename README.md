#PhiGraph-基于MIC体系结构的单机图计算系统
##编译
```
mkdir build
cd build
cmake ..
make
```
##安装
```
make install
```
##运行
测试代码所生成的执行文件在build/bin目录下
```
cd bin
```
对于只需要CSR格式的图数据,例如BFS
```
./bfs filename
```
对于需要CSR和CSC两种格式的图数据，例如PageRank
```
./pagerank csrfilename -c cscfilename
```
如果有权值，还需要加上-w,例如SSSP
```
./sssp filename -w
```
