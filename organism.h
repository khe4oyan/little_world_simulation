typedef struct{
	int energy;
} organism_t;

void organism_construct(organism_t* this, int energy) {
	this->energy = energy;
}

void organism_get_energy(organism_t* this, int sun_energy) {
	this->energy += sun_energy;
}

void organism_expend_energy(organism_t* this, int energy) {
	this->energy -= energy;
}