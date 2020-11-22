#ifndef SOLVERDATA_H
#define SOLVERDATA_H

#include "SolverKind.h"

#include <Eigen/Dense>
#include<vector>

class SolverData
{
public:
    SolverData(const SolverKind &kind) : m_kind(kind), m_accuracy(0.0), 
    m_maxIterNumber(0), m_relaxParam(0.0), m_albedo(1, 0.0) {}
	
    void setKind(SolverKind kind) {m_kind = kind;}
    SolverKind getKind() {return m_kind;}
    void setAccuracy(double accuracy) {m_accuracy = accuracy;}
    double getAccuracy() {return m_accuracy;}
    void setMaxIterNumber(int maxIterNumber) {m_maxIterNumber = maxIterNumber;}
    int getMaxIterNumber() {return m_maxIterNumber;}
    void setRelaxationParameter(double param) {m_relaxParam = param;}
    double getRelaxationParameter() {return m_relaxParam;}
    void setAlbedo(std::vector<double> albedo) {m_albedo = albedo;}
    std::vector<double> getAlbedo() {return m_albedo;}
    void setHeatBoundaryConditions(std::vector<std::string> &values);
    std::pair<Eigen::VectorXd, Eigen::VectorXd> getHeatBoundaryConditions();
	
private:
    SolverKind m_kind;
	double m_accuracy;
    int m_maxIterNumber;
    double m_relaxParam;
    std::vector<double> m_albedo;
    Eigen::VectorXd m_heatBoundaryConditions;
};

#endif