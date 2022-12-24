typedef struct{
	int hours;
	int minutes;
} time_type;

void time_construct(time_type* this) {
	this->hours = rand() % 24; // real minutes
	this->minutes = rand() % 60; // real seconds
}

void time_update(time_type* this) {
	this->minutes++;

	if (this->minutes == 60) {
		this->minutes = 0;
		this->hours++;
	}

	if (this->hours == 24) {
		this->hours = 0;
	}
}

bool time_is_day(time_type* this) {
	return (this->hours > 5 && this->hours < 19) ? true : false;
}

bool time_is_night(time_type* this) {
	return !(time_is_day(this));
}