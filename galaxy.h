typedef struct{
	sun_t sun;
	world_t worlds[1];
} galaxy_t;

void galaxy_divided_energy_at_all_worlds(galaxy_t* this, int sun_energy) {
	const int worlds_count = 1;
	const int energy_every_world = sun_energy / worlds_count;

	for (int i = 0; i < worlds_count; ++i) {
		world_take_energy(&(this->worlds[i]), energy_every_world);
	}
}

void galaxy_energy_converter(galaxy_t* this) {
	for (int i = 0; i < 1; ++i) {
		world_energy_converter(&(this->worlds[i]));
	}
}

void galaxy_behaviour(galaxy_t* this) {
	for (int i = 0; i < 1; ++i) {
		world_behaviour(&(this->worlds[i]));
	}
}

void galaxy_show_stat(galaxy_t* this) {
	printf("======= Statistic =======\n");
	sun_show_stat(&(this->sun));
	for (int i = 0; i < 1; ++i) {
		world_show_stat(&(this->worlds[i]));
	}
	printf("=======  === ===  =======\n");
}

void galaxy_life_cycle(galaxy_t* this) {
	const int sun_energy = sun_get_energy(&(this->sun));
	if (sun_energy == 0) { return; }

	galaxy_divided_energy_at_all_worlds(this, sun_energy);
	galaxy_energy_converter(this);
	galaxy_behaviour(this);
	galaxy_show_stat(this);
}

void galaxy_constructor(galaxy_t* this) {
	sun_construct(&(this->sun));

	for (int i = 0; i < 1; ++i) {
		world_construct(&(this->worlds[i]));
	}

	// start infinity cycle
	while(this->sun.energy != 0) {
		galaxy_life_cycle(this);
	}

	printf("Sun die..");
}