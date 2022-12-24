typedef struct {
	organism_t org;
	int height;
	bool photosyntesis;
} grass_t;

void grass_construct(grass_t* this) {
	organism_construct(&(this->org), 0);
	this->height = 0;
	this->photosyntesis = true;
}

int grass_ear(grass_t* this) {
	int energy = this->org.energy;
	this->height = 0;
	// this->org.energy = 0;

	return energy;
}

void grass_energy_convert(grass_t* this) {
	const int energy_expend = 10;
	const int max_height = 3;

	if (this->org.energy > 100) { this->org.energy = 100; }
	if (this->org.energy >= energy_expend && this->height < max_height) {
		this->height += 1;
		organism_expend_energy(&(this->org), energy_expend);
	}
}

void grass_behaviour(grass_t* this) {
	// todo nothing
}

void grass_show_stat(grass_t* this) {
	printf("---- Grass ----\n");
	printf("Energy: %d\n", this->org.energy);
	printf("Height: %d\n", this->height);
	printf("------ ------\n");
}