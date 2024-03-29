#ifndef SOLVERDATA_H
#define SOLVERDATA_H

#include "SolverKind.h"
#include "DirectionKind.h"
#include "EigenmodesKind.h"

#include <Eigen/Dense>
#include <vector>

class SolverData
{
public:
    SolverData(const SolverKind &kind) : m_kind(kind), m_accuracy(0.0), 
    m_maxIterNumber(0), m_relaxParam(0.0), m_albedo(1, 0.0), m_energies(0),
    m_DirKind(DirectionKind::UNDEFINED), m_EigenKind(EigenmodesKind::UNDEFINED) {}
	
    void setKind(SolverKind kind) {m_kind = kind;}
    SolverKind getKind() const {return m_kind;}
    void setAccuracy(double accuracy) {m_accuracy = accuracy;}
    double getAccuracy() const {return m_accuracy;}
    void setMaxIterNumber(int maxIterNumber) {m_maxIterNumber = maxIterNumber;}
    int getMaxIterNumber() const  {return m_maxIterNumber;}
    void setRelaxationParameter(double param) {m_relaxParam = param;}
    double getRelaxationParameter() {return m_relaxParam;}
    void setAlbedo(std::vector<double> albedo) {m_albedo = albedo;}
    std::vector<double> getAlbedo() {return m_albedo;}
    void setHeatBoundaryConditions(std::vector<std::string> &values);
    std::pair<Eigen::VectorXd, Eigen::VectorXd> getHeatBoundaryConditions();
    void setEnergies(int energies) {m_energies = energies;}
    int getEnergies() const {return m_energies;}
    void setDirection(DirectionKind kind) {m_DirKind = kind;}
    DirectionKind getDirection() const {return m_DirKind;}
    void setEigenmodes(EigenmodesKind kind) {m_EigenKind = kind;}
    EigenmodesKind getEigenmodes() {return m_EigenKind;}
	
private:
    SolverKind m_kind;
	double m_accuracy;
    int m_maxIterNumber;
    double m_relaxParam;
    std::vector<double> m_albedo;
    Eigen::VectorXd m_heatBoundaryConditions;
    int m_energies;
    DirectionKind m_DirKind;
    EigenmodesKind m_EigenKind;
    std::pair<double, int> m_extSource;
};

#endif