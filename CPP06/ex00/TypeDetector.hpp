#ifndef TYPE_DETECTOR_HPP
# define TYPE_DETECTOR_HPP

# include <string>

class TypeDetector {

private:
	TypeDetector();
	TypeDetector(const TypeDetector &src);
	TypeDetector &operator=(const TypeDetector &rhs);
	~TypeDetector();

	static bool detectChar(const std::string &target);
	static bool detectInt(double dVal, char *end);
	static bool detectFloat(char *end);
	static bool detectDouble(char *end);

public:
	enum Type { 
		kCHAR,
		kINT,
		kFLOAT,
		kDOUBLE,
		kINVALID = -1
	};

	static Type	detect(const std::string &target, double *dVal);

};

#endif // TYPE_DETECTOR_HPP
