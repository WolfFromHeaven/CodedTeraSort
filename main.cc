#include <iostream>
#include <mpi.h>

#include "Master.h"
#include "Worker.h"

using namespace std;

int main()
{
  MPI::Init();
  int nodeRank = MPI::COMM_WORLD.Get_rank();
  int nodeTotal = MPI::COMM_WORLD.Get_size();

  if ( nodeRank == 0 ) {
    Master masterNode( nodeRank, nodeTotal );
    masterNode.run();
  }
  else {
    Worker workerNode( nodeRank );
    workerNode.run();
  }
  cout<<"nodeRank : "<<nodeRank<<"\n";
  MPI::Finalize();
  
  return 0;
}
