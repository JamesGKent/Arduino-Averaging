# Arduino-Averaging
The purpose of this library is to average data from sensors in a rolling array with minimal overhead

it supports the following datatypes:
 - int8_t (int8_Average)
 - uint8_t (uint8_Average)
 - int16_t (int16_Average)
 - uint16_t (uint16_Average)
 
Array sizes of 65536 are supported, but most arduinos will not have that much memory.

to use this library create an instance of one of the classes:
```
int8_Average myaverage = int8_Average(10);
```

then add values to it:
```
myaverage.add_sample(x);
```

and to get the average:
```
value = myaverage.get_average();
```
