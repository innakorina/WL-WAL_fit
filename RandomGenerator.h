#define A_SCHRAGE 16807
#define M_SCHRAGE 2147483647
#define Q_SCHRAGE 127773
#define R_SCHRAGE 2836




class RandGenerator{
private:
	double x;
	long z;
	long z_next;

public:
	void SetSeed(long);
	double Rand();
};

void RandGenerator::SetSeed(long seed){
	z_next=seed;
}

double RandGenerator::Rand(){
	z=z_next;
	z_next=A_SCHRAGE*(z%Q_SCHRAGE)-R_SCHRAGE*long(z/Q_SCHRAGE);
	if(z_next<0)z_next+=M_SCHRAGE;
	return double(z)/double(M_SCHRAGE);
}


