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
	static bool detectInt(const std::string &target);
	static bool detectFloat(const std::string &target);
	static bool detectDouble(const std::string &target);

public:
	enum Type { 
		kCHAR,
		kINT,
		kFLOAT,
		kDOUBLE,
		kINVALID = -1
	};

	static Type	detect(const std::string &target);

};

#endif // TYPE_DETECTOR_HPP
