#include "graph_io.h"



PhiGraphIO::PhiGraphIO() {
  offset = NULL;
  inEdges = NULL;
  outEdges = NULL;
  split = "\n\t\r ";

}
PhiGraphIO::PhiGraphIO(phiLong vn,phiLong en,uphiLong* o,uphiLong* out,phiDouble* outw){
  vertexNum = vn;
  edgeNum = en;
  offset = o;
  outEdges = out;
  outWeight = outw;
}
void PhiGraphIO::writeGraphToFile(char* filename){
  ofstream file(filename, ios::out | ios::binary | ios::ate);
  if (!file.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    abort();
  }
  file << "AdjacencyGraph"<<endl;
  file << vertexNum <<endl;
  file << edgeNum <<endl;
  for(phiLong i = 0;i < vertexNum;++i){
    file << offset[i] << endl;
  }
  for(phiLong j = 0;j < edgeNum;++j){
    file << outEdges[j] << endl;
  }
  if(outWeight != NULL){
    for(phiLong j = 0;j < edgeNum;++j){
      file << outWeight[j] << endl;
    }
  }
  file.close();

}

Graph<Vertex>* PhiGraphIO::loadGraphFromFile(char* csrfileName,char* cscfileName){
  seq<char> csr_temp = readStringFromFile(csrfileName);

  char * _string = csr_temp.get();

  stringToArray(_string,true);
  //set vertex
  Vertex *v = new Vertex[vertexNum];
  parallel_for (phiLong i = 0; i < vertexNum; i++) {
    phiLong start = offset[i];
    phiLong l = ((i == vertexNum-1) ? edgeNum : offset[i+1])-offset[i];
    v[i].setOutDegree(l);
    v[i].setOutVertexes(outEdges+start);
    #ifdef WEIGHTED
    v[i].setOutWeight(outWeight+start);
    #endif
  }
  if(cscfileName != NULL){

    seq<char> csc_temp = readStringFromFile(cscfileName);

    stringToArray(csc_temp.get(),false);
    for (phiLong i=0; i < vertexNum; i++) {
      phiLong start = offset[i];
      phiLong l = ((i == vertexNum-1) ? edgeNum : offset[i+1])-offset[i];
      v[i].setInDegree(l);
      v[i].setInVertexes(inEdges+start);
      #ifdef WEIGHTED
      v[i].setInWeight(inWeight+start);
      #endif
    }
  }
  return new Graph<Vertex>(v,vertexNum,edgeNum);
}



void PhiGraphIO::stringToArray(char * _string,bool val){
  char * word = strtok (_string,split);
  uphiLong* _edges = NULL;
  phiDouble* _weight = NULL;

  //get graph vertex num and edges num
  if(word == (string)"AdjacencyGraph"){
    word = strtok (NULL,split);
    vertexNum = atol(word);
    //printf("vertexNum=%ld\n",vertexNum );
    word = strtok (NULL,split);
    edgeNum = atol(word);
    //printf("edgeNum=%ld\n",edgeNum );
    if(offset == NULL)
      offset = phimalloc(uphiLong,vertexNum);
    if(val){
      //offset = phimalloc(uphiLong,vertexNum);
      outEdges = phimalloc(uphiLong,edgeNum);
      #ifdef WEIGHTED
      outWeight = phimalloc(double,edgeNum);
      _weight = outWeight;
      #endif
      _edges = outEdges;

    }else{
      inEdges = phimalloc(uphiLong,edgeNum);
      #ifdef WEIGHTED
      inWeight = phimalloc(double,edgeNum);
      _weight = inWeight;
      #endif
      _edges = inEdges;
    }

  }
  //set string to long
  for(long i = 0; i < vertexNum; i++){
    word = strtok (NULL,split);
    offset[i] = atol(word);
    //printf("%ld\n",offset[i] );
  }
  for(long i = 0; i < edgeNum; i++){
    word = strtok (NULL,split);
    _edges[i] = atol(word);
    //printf("%ld\n",edges[i] );
  }
  #ifdef WEIGHTED
  for(long i = 0; i < edgeNum; i++){
    word = strtok (NULL,split);
    _weight[i] = atof(word);
    //printf("%ld ",weight[i] );
  }
  //printf("\n" );
  #endif
}

seq<char> PhiGraphIO::readStringFromFile(char *fileName) {
  ifstream file(fileName, ios::in | ios::binary | ios::ate);
  if (!file.is_open()) {
    cout << "Unable to open file: " << fileName << endl;
    abort();
  }
  long end = file.tellg();
  file.seekg(0, ios::beg);
  long n = end - file.tellg();
  char *bytes = phimalloc(char, n + 1);
  file.read(bytes, n);
  file.close();
  return seq<char>(bytes, n);
}
void PhiGraphIO::iofree(){
  free(offset);
  free(outEdges);
}
