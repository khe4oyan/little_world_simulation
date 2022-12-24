typedef struct{
	int energy;
} sun_t;

void sun_construct(sun_t* this) {
	this->energy = 10000;
}

int sun_get_energy(sun_t* this) {
	const int energy = 300;
	if (this->energy - energy > 0) {
		this->energy -= energy;
		return energy;
	}
	
	// sun die
	this->energy -= 0;
	return 0;
}

void sun_show_stat(sun_t* this) {
	printf("---- Sun ----\n");
	printf("Energy: %d\n", this->energy);
	printf("------ ------\n");
}