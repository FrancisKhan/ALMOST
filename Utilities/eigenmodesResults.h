#ifndef EIGENMODESRESULTS_H
#define EIGENMODESRESULTS_H
    
#include "DirectionKind.h"
#include "EigenmodesKind.h"
#include <Eigen/Dense>

typedef struct eigenmodesResults_
{ 
    Eigen::VectorXd fundamentalNeutronFlux;
    double fundamentalKFactor;
    std::vector< std::pair<double, Eigen::VectorXd> > eigenmodes;
    DirectionKind directionKind_;
    EigenmodesKind eigenmodeKind_;

    eigenmodesResults_() 
    {
        fundamentalNeutronFlux = Eigen::VectorXd::Zero(1);
        fundamentalKFactor = 0.0;
    } 

    eigenmodesResults_(const Eigen::VectorXd& flux, const double& kFactor) 
    {
        fundamentalNeutronFlux = flux; 
        fundamentalKFactor = kFactor;
        eigenmodes.push_back(std::make_pair(kFactor, flux));
    }

    eigenmodesResults_(const std::vector< std::pair<double, Eigen::VectorXd> >& modes)
    {
        eigenmodes = modes;
        fundamentalKFactor = eigenmodes.front().first;
        fundamentalNeutronFlux = eigenmodes.front().second;
    }

    Eigen::VectorXd getFundamentalNeutronFLux() const {return fundamentalNeutronFlux;}
    double getFundamentalKFactor() const {return fundamentalKFactor;}
    std::vector< std::pair<double, Eigen::VectorXd> > getModes() const {return eigenmodes;}

    std::vector<double> getEigenvalues() const 
    {
        std::vector<double> result;
        
        for(const auto& i : eigenmodes)
            result.push_back(i.first);

        return result;
    }

    size_t getEigenmodesNumber() const {return eigenmodes.size();}

    DirectionKind getDirectionKind() const {return directionKind_;}
    void setDirectionKind(DirectionKind kind) {directionKind_ = kind;}
    EigenmodesKind getEigenmodeKind() const {return eigenmodeKind_;}
    void setEigenmodeKind(EigenmodesKind kind) {eigenmodeKind_ = kind;}

} eigenmodesResults;

#endif