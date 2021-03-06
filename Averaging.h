#include <stdint.h>
/***********************
* Generic implementation of Averaging class
* implements protected variables and methods:
* get_samples() - returns the number of samples as unsigned 16 bit int (uint16_t)
* reset() - resets all internal variables to show zero samples
***********************/
class Average
{
public:
	uint16_t get_samples();
	void reset();
	protected :
	uint16_t _size;
	uint8_t _bytesize;
	uint16_t _samples_added;
	uint16_t _index;
	void *_total;
	void *_samples;
};

class int8_Average : public Average
{
public:
	int8_Average(uint16_t array_size);
	void add_sample(int8_t sample);
	int8_t get_average();
	int8_t& operator[] (uint16_t index);
};

class uint8_Average : public Average
{
public:
	uint8_Average(uint16_t array_size);
	void add_sample(uint8_t sample);
	uint8_t get_average();
	uint8_t& operator[] (uint16_t index);
};

class int16_Average : public Average
{
public:
	int16_Average(uint16_t array_size);
	void add_sample(int16_t sample);
	int16_t get_average();
	int16_t& operator[] (uint16_t index);
};

class uint16_Average : public Average
{
public:
	uint16_Average(uint16_t array_size);
	void add_sample(uint16_t sample);
	uint16_t get_average();
	uint16_t& operator[] (uint16_t index);
};
