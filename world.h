typedef struct {
	time_type time;
	int energy;
	grass_t in_world_grass[10];
	frog_t in_world_frog[1];
} world_t;

void world_construct(world_t* this) {
	time_construct(&(this->time));

	for (int i = 0; i < 10; ++i) {
		grass_construct(&(this->in_world_grass[i]));
	}

	for (int i = 0; i < 1; ++i) {
		frog_construct(&(this->in_world_frog[i]));
	}

	this->energy = 0;
}

void world_energy_converter(world_t* this) {
	for (int i = 0; i < 1; ++i) {
		frog_energy_convert(&(this->in_world_frog[i]));
	}

	for (int i = 0; i < 10; ++i) {
		grass_energy_convert(&(this->in_world_grass[i]));
	}
}

void world_divided_energy(world_t* this) {
	const int energ = this-> energy / 11;

	for (int i = 0; i < 10; ++i) {
		organism_get_energy(&(this->in_world_grass[i].org), energ);
	}
}

void world_take_energy(world_t* this, int sun_energy) {
	if (time_is_night(&(this->time))) { return; }

	this->energy = sun_energy;

	world_divided_energy(this);
}

void world_show_stat(world_t* this) {
	printf("---- World ----\n");
	printf("Energy: %d\n", this->energy);
	printf("Time: %d:%d", this->time.hours, this->time.minutes);
	for (int i = 0; i < 10; ++i) {
		grass_show_stat(&(this->in_world_grass[i]));
	}

	for (int i = 0; i < 1; ++i) {
		frog_show_stat(&(this->in_world_frog[i]));
	}

	printf("------ ------\n");
}

void frog_find_food(frog_t* this, grass_t* in_world) {
	for (int i = 0; i < 10; ++i) {
		frog_get_energy(this, grass_ear(&(in_world[i])));
		if (this->org.energy > 30) {
			return;
		}
	}
}

void frog_behaviour(frog_t* this, grass_t* in_world) {
	if (this->is_hangry == true) {
		frog_find_food(this, in_world);
		organism_expend_energy(&(this->org), 10);
	}else{
		organism_expend_energy(&(this->org), 2);
	}

	if (this->org.energy <= 0) {
		this->is_dead = true;
		this->is_hangry = false;
		this->org.energy = 0;
	}
}


void world_behaviour(world_t* this) {
	time_update(&(this->time));

	for (int i = 0; i < 10; ++i) {
		grass_behaviour(&(this->in_world_grass[i]));
	}

	for (int i = 0; i < 1; ++i) {
		if (this->in_world_frog[i].is_dead == true) { continue; }
		frog_behaviour(&(this->in_world_frog[i]), this->in_world_grass);
	}
}