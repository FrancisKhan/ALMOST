#ifndef EIGENMODESRESULTS_H
#define EIGENMODESRESULTS_H
    
#include "DirectionKind.h"
#include "EigenmodesKind.h"
#include <Eigen/Dense>

typedef struct eigenmodesResults_
{ 
    Eigen::VectorXd fundamentalNeutronFlux_;
    double fundamentalKFactor_;
    std::vector< std::pair<double, Eigen::VectorXd> > eigenmodes_;
    DirectionKind directionKind_;

    eigenmodesResults_() 
    {
        fundamentalNeutronFlux_ = Eigen::VectorXd::Zero(1);
        fundamentalKFactor_ = 0.0;
    } 

    eigenmodesResults_(const Eigen::VectorXd& flux, const double& kFactor, DirectionKind dir) 
    {
        fundamentalNeutronFlux_ = flux; 
        fundamentalKFactor_ = kFactor;
        eigenmodes_.push_back(std::make_pair(kFactor, flux));
        directionKind_ = dir;
    }

    eigenmodesResults_(const std::vector< std::pair<double, Eigen::VectorXd> >& modes, 
                       DirectionKind dir)
    {
        eigenmodes_ = modes;
        fundamentalKFactor_ = eigenmodes_.front().first;
        fundamentalNeutronFlux_ = eigenmodes_.front().second;
        directionKind_ = dir;
    }

    Eigen::VectorXd getFundamentalNeutronFLux() const {return fundamentalNeutronFlux_;}
    double getFundamentalKFactor() const {return fundamentalKFactor_;}
    std::vector< std::pair<double, Eigen::VectorXd> > getModes() const {return eigenmodes_;}

    std::vector<double> getEigenvalues() const 
    {
        std::vector<double> result;
        
        for(const auto& i : eigenmodes_)
            result.push_back(i.first);

        return result;
    }

    size_t getEigenmodesNumber() const {return eigenmodes_.size();}

    DirectionKind getDirectionKind() const {return directionKind_;}
    void setDirectionKind(DirectionKind kind) {directionKind_ = kind;}

} eigenmodesResults;

#endif