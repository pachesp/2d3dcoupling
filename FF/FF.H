#ifndef FF_H
#define FF_H

#include "Interface.H"

#include "FF/Velocity.H"

#include "fvCFD.H"

// YAML reader - Used to read the adapter's configuration file.
#include "yaml-cpp/yaml.h"

namespace preciceAdapter
{
namespace FF
{

class FluidFluid
{

protected:

    //- OpenFOAM fvMesh object
    const Foam::fvMesh& mesh_;

    // TODO: Create a struct for all the parameter names

    //- Solver type
    std::string solverType_ = "none";

    //- Name of the velocity field
    std::string nameU_ = "U";

    //- Determine the solver type
    std::string determineSolverType();

    //- Read the FF-related options from the adapter's configuration file
    bool readConfig(const YAML::Node adapterConfig);

public:

    //- Constructor
    FluidFluid(const Foam::fvMesh& mesh);

    //- Configure
    bool configure(const YAML::Node adapterConfig);
    
    //- Add coupling data writers
    void addWriters(std::string dataName, Interface * interface);
    
    //- Add coupling data readers
    void addReaders(std::string dataName, Interface * interface);
};

}
}

#endif