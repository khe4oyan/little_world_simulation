typedef struct{
	organism_t org;
	bool is_hangry;
	bool is_dead;
} frog_t;

void frog_construct(frog_t* this) {
	organism_construct(&(this->org), 100);
	this->is_hangry = false;
	this->is_dead = false;
}

void frog_energy_convert(frog_t* this) {
	if (this->org.energy > 200) { this->org.energy = 200; }

	if (this->org.energy < 30) {
		this->is_hangry = true;
	} else {
		this->is_hangry = false;
	}
}

void frog_get_energy(frog_t* this, int sun_energy) {
	organism_get_energy(&(this->org), sun_energy);
}

void frog_expend_energy(frog_t* this, int energy) {
	organism_expend_energy(&(this->org), energy);
} 

void frog_show_stat(frog_t* this) {
	printf("---- Frog ----\n");
	if (this->is_hangry == true) { printf("Is hangry\n"); }
	if (this->is_dead == true) { printf("Is dead\n"); }
	printf("Energy: %d", this->org.energy);
	printf("------ ------\n");
}


