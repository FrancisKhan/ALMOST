class MatGeom : 
{
public:
    MatGeom(int n) : m_radii(n, 0.0) {};
	void setGeometry();
	void setMaterials();
	
private:
	std::vector<double> m_radii;
	
}