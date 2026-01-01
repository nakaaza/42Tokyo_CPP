ex00: static_cast
	check type first. (specials values -> normal values)
	hold value as double, which has most vast representation range
	then, convert to each value and print
	care for non displayable values for char

ex01: reinterpret_cast
	Serialize and Deserialize with reinterpret_cast<>

ex02: dynamic_cast
	functions are outside any class.
	dynamic_cast<T>(foo) returns T instance if foo is interpretable as T,
	if not, returns NULL if foo is a pointer, or throw error.
	identify(Base* p) needs NULL handling, while identify(Base& p) needs try catch

