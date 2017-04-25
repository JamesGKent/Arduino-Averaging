#include "Averaging.h"
#include <string.h>

/*********************************************************************
* Generic implementation of Averaging class
* implements protected variables and methods:
* get_samples() - returns the number of samples as unsigned 16 bit int (uint16_t)
* reset() - resets all internal variables to show zero samples
*********************************************************************/
uint16_t Average::get_samples(){
	return _samples_added;
}

void Average::reset(){
	_samples_added = 0;
	_index = 0;
	_total = 0;
	memset((char*)_samples, 0, _size * _bytesize); // zero all samples
}

/*********************************************************************
* Specific implementation of Averaging class for 8 bit signed integers
*********************************************************************/
int8_Average::int8_Average(uint16_t array_size){
	_size = array_size;
	_bytesize = 1;
	_samples = new int8_t [_size];
	reset();
}

void int8_Average::add_sample(int8_t sample){
	if (_total == 0){
		_total = new int16_t();
	}
	*((int16_t *)_total) -= ((int8_t *)_samples)[_index]; // subtract old value from total
	((int8_t *)_samples)[_index] = sample; // add the sample to list
	*((int16_t *)_total) += sample; // add new value to total

	_index++;
	if (_index == _size){ // reached limit of samples
		_index = 0; // reset index to start
	}

	if (_samples_added < _size){
		_samples_added++;
	}
}

int8_t int8_Average::get_average(){
	if ((_samples_added > 0) && (_total != 0)){ // to prevent div by zero segfault
		return *((int16_t *)_total) / _samples_added;
	} else {
		return 0;
	}
}

int8_t& int8_Average::operator[](uint16_t index){
    return ((int8_t *)_samples)[index];
}

/*********************************************************************
* Specific implementation of Averaging class for 8 bit unsigned integers
*********************************************************************/
uint8_Average::uint8_Average(uint16_t array_size){
	_size = array_size;
	_bytesize = 1;
	_samples = new uint16_t [_size];
	reset();
}

void uint8_Average::add_sample(uint8_t sample){
	if (_total == 0){
		_total = new uint8_t();
	}
	*((uint16_t *)_total) -= ((uint8_t *)_samples)[_index]; // subtract old value from total
	((uint8_t *)_samples)[_index] = sample; // add the sample to list
	*((uint16_t *)_total) += sample; // add new value to total

	_index++;
	if (_index == _size){ // reached limit of samples
		_index = 0; // reset index to start
	}

	if (_samples_added < _size){
		_samples_added++;
	}
}

uint8_t uint8_Average::get_average(){
	if ((_samples_added > 0) && (_total != 0)){ // to prevent div by zero segfault
		return *((uint16_t *)_total) / _samples_added;
	} else {
		return 0;
	}
}

uint8_t& uint8_Average::operator[](uint16_t index){
    return ((uint8_t *)_samples)[index];
}

/*********************************************************************
* Specific implementation of Averaging class for 16 bit signed integers
*********************************************************************/
int16_Average::int16_Average(uint16_t array_size){
	_size = array_size;
	_bytesize = 2;
	_samples = new int16_t [_size];
	reset();
}

void int16_Average::add_sample(int16_t sample){
	if (_total == 0){
		_total = new int32_t();
	}
	*((int32_t *)_total) -= ((int16_t *)_samples)[_index]; // subtract old value from total
	((int16_t *)_samples)[_index] = sample; // add the sample to list
	*((int32_t *)_total) += sample; // add new value to total

	_index++;
	if (_index == _size){ // reached limit of samples
		_index = 0; // reset index to start
	}

	if (_samples_added < _size){
		_samples_added++;
	}
}

int16_t int16_Average::get_average(){
	if ((_samples_added > 0) && (_total != 0)){ // to prevent div by zero segfault
		return *((int32_t *)_total) / _samples_added;
	} else {
		return 0;
	}
}

int16_t& int16_Average::operator[](uint16_t index){
    return ((int16_t *)_samples)[index];
}

/*********************************************************************
* Specific implementation of Averaging class for 16 bit signed integers
*********************************************************************/
uint16_Average::uint16_Average(uint16_t array_size){
	_size = array_size;
	_bytesize = 2;
	_samples = new uint16_t [_size];
	reset();
}

void uint16_Average::add_sample(uint16_t sample){
	if (_total == 0){
		_total = new uint32_t();
	}
	*((uint32_t *)_total) -= ((uint16_t *)_samples)[_index]; // subtract old value from total
	((uint16_t *)_samples)[_index] = sample; // add the sample to list
	*((uint32_t *)_total) += sample; // add new value to total

	_index++;
	if (_index == _size){ // reached limit of samples
		_index = 0; // reset index to start
	}

	if (_samples_added < _size){
		_samples_added++;
	}
}

uint16_t uint16_Average::get_average(){
	if ((_samples_added > 0) && (_total != 0)){ // to prevent div by zero segfault
		return *((uint32_t *)_total) / _samples_added;
	} else {
		return 0;
	}
}

uint16_t& uint16_Average::operator[](uint16_t index){
    return ((uint16_t *)_samples)[index];
}
